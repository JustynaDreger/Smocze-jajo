#include "stdafx.h"
void dziedziniec();
void sala_1();
void sala_2();
void sala_3();
void korytarz_1();
void korytarz_2();
void korytarz_3();
void korytarz_4();
void korytarz_5();
void korytarz_6();
void skarbiec();
void wyjscie();
void OnRender();
void OnReshape(int, int);
void OnKeyPress(unsigned char, int, int);
void OnKeyDown(unsigned char, int, int);
void OnKeyUp(unsigned char, int, int);
void OnTimer(int);
void OnMouseMove(int, int);
void OnMouseClick(int, int, int, int);
Player* player;
Scene scene;
Bron *bron;
Jajo *jajo;
Model3D *strzala;
int window_width, window_height;
vec3 mousePosition;
Moneta* m1;Moneta* m2;Moneta* m3;Moneta* m4;Moneta* m5;Moneta* m6;
Moneta* m7;Moneta* m8;Moneta* m9;Moneta* m10;Moneta* m11;
Moneta* m12;
//
Moneta* m21;Moneta* m22;Moneta* m23;Moneta* m24;Moneta* m25;Moneta* m26;
Moneta* m27;Moneta* m28;Moneta* m29;Moneta* m30;Moneta* m31;
//
Wrog* w1;Wrog* w2;Wrog* w3;Wrog* w4;Wrog* w5;Wrog* w6;Wrog* w7;
Wrog* w8;Wrog* w9;Wrog* w10;Wrog* w11;

bool captureMouse;
float theta;

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 360);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("Gry Komputerowe: Lab 3");

	glutDisplayFunc(OnRender);
	glutReshapeFunc(OnReshape);
	glutKeyboardFunc(OnKeyPress);
	glutKeyboardUpFunc(OnKeyUp);
	glutTimerFunc(17, OnTimer, 0);
	glutPassiveMotionFunc(OnMouseMove);
	glutMotionFunc(OnMouseMove);
	glutMouseFunc(OnMouseClick);
	
	glClearColor(0.1f, 0.2f, 0.3f, 0.0);

	glEnable(GL_DEPTH_TEST);

	float gl_amb[] = { 0.0f, 0.0f, 0.0f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, gl_amb);

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_CULL_FACE); // W³¹czenie face culling'u, czyli nie renderowanie dwóch stron prymitywów
	glFrontFace(GL_CCW); // Interpretacja jako przednich œcian tych, które s¹ rysowane w kierunku przeciwnym do ruchu zegara. Alternatywa : GL_CW
	glCullFace(GL_BACK); // Ustawienie cullingu na tylne œciany, wiêc tylko przednie bêd¹ renderowane

	glutSetCursor(GLUT_CURSOR_NONE);
	captureMouse = true;
	glutWarpPointer(window_width / 2, window_height / 2);
	
	player = new Player();
	player->radius = 0.5f;
	scene.AddObject(player);
	//bron
	bron = new Bron(player->pos.x, player->pos.y+0.5, player->pos.z,"pochodnia");
	scene.AddObject(bron);
	bron->ambient= vec3(0.7f, 0.7f, 0.7f);
	strzala = new Model3D(vec3(0,0,0),vec3(1,0,0));
	//strzala->load("../Resources/Models/st.obj");
	scene.AddObject(strzala);
	///
	jajo = new Jajo(vec3(0,0.2,34),"jajo_t");
	scene.AddObject(jajo);
	Model3D *jajo_t = new Model3D(vec3(0,0,0),vec3(1,1,1),"jajo_t");
	jajo_t->load("..\Resources\Models\jajo.obj");
	scene.AddObject(jajo_t);
///MONETY
		m1= new Moneta(vec3(4, 0, 4),"moneta");
		scene.AddObject(m1);
		m2 = new Moneta(vec3(7, 0, 23), "moneta");
		scene.AddObject(m2);
		m3 = new Moneta(vec3(-19, 0, 17), "moneta");
		scene.AddObject(m3);
		m4 = new Moneta(vec3(2, 0, 32), "moneta");
		m5 = new Moneta(vec3(2, 0, 31.5), "moneta");
		m6 = new Moneta(vec3(-2, 0, 31.5), "moneta");
		m7 = new Moneta(vec3(-2, 0, 32), "moneta");
		scene.AddObject(m4);
		scene.AddObject(m5);
		scene.AddObject(m6);
		scene.AddObject(m7);
		m8 = new Moneta(vec3(-13, 0, 5), "moneta");
		m9 = new Moneta(vec3(-13, 0, 4), "moneta");
		m10 = new Moneta(vec3(-17, 0, 5), "moneta");
		m11 = new Moneta(vec3(-17, 0, 4), "moneta");
		m12 = new Moneta(vec3(-15,0,3), "moneta");
		scene.AddObject(m8);
		scene.AddObject(m9);
		scene.AddObject(m10);
		scene.AddObject(m11);
		scene.AddObject(m12);
//WROGOWIE
		w1 = new Wrog(0,3,10,'P', "wrog");//dziedziniec
		w2 = new Wrog(-3, 14.5, 10, 'D', "wrog");//sala1
		w3 = new Wrog(4, 8.5, 10, 'G', "wrog");
		w4 = new Wrog(8.5, 10, 10, 'P', "wrog");
		w5 = new Wrog(1, 21, 10, 'G', "wrog");//sala2
		w6 = new Wrog(7, 23, 10, 'L', "wrog");
		w7 = new Wrog(3, 24.5, 10, 'P', "wrog");
		w8 = new Wrog(4, 30.5, 10, 'L', "wrog");//skarbiec
		w9 = new Wrog(-2, 30.2, 10, 'P', "wrog");
		w10 = new Wrog(-18, 13, 10, 'L', "wrog");//sala3
		w11 = new Wrog(-18, 5, 10, 'L', "wrog");//wyjscie

		scene.AddObject(w1);
		scene.AddObject(w2);
		scene.AddObject(w3);
		scene.AddObject(w4);
		scene.AddObject(w5);
		scene.AddObject(w6);
		scene.AddObject(w7);
		scene.AddObject(w8);
		scene.AddObject(w9);
		scene.AddObject(w10);
		scene.AddObject(w11);
///
		//Studnia* studnia = new Studnia();
		//scene.AddObject(studnia);

//tekstury
		//mury
		TextureManager::getInstance()->LoadTexture("mur", "../Resources/Textures/mur.jpg", GL_LINEAR, GL_LINEAR_MIPMAP_NEAREST);
		//jajo
		TextureManager::getInstance()->LoadTexture("jajo", "../Resources/textures/jajo_t.jpg", GL_NEAREST, GL_NEAREST);
		//niebo
		TextureManager::getInstance()->LoadTexture("niebo", "../Resources/textures/sky.bmp", GL_LINEAR, GL_LINEAR_MIPMAP_NEAREST);
		//moneta
		TextureManager::getInstance()->LoadTexture("moneta", "../Resources/textures/moneta.jpg", GL_NEAREST, GL_NEAREST);
		//pochodnia
		TextureManager::getInstance()->LoadTexture("pochodnia", "../Resources/textures/pochodnia.jpg", GL_LINEAR, GL_LINEAR_MIPMAP_NEAREST);
		//wrog
		TextureManager::getInstance()->LoadTexture("wrog", "../Resources/textures/wrog.jpg", GL_LINEAR, GL_LINEAR_MIPMAP_NEAREST);
	glutMainLoop();

	return 0;
}

bool keystate[256];

void OnKeyPress(unsigned char key, int x, int y) {
	if (!keystate[key]) {
		OnKeyDown(key, x, y);
	}
	keystate[key] = true;
}

void OnKeyDown(unsigned char key, int x, int y) {
	if (key == 27) {
		glutLeaveMainLoop();
	}
	
	if (key == 'm')
	{
		if (captureMouse)
		{
			glutSetCursor(GLUT_CURSOR_LEFT_ARROW);
			captureMouse = false;
		}
		else
		{
			glutSetCursor(GLUT_CURSOR_NONE);
			glutWarpPointer(window_width / 2, window_height / 2);
			captureMouse = true;
		}
	}
}

void OnKeyUp(unsigned char key, int x, int y) {
	keystate[key] = false;
}

void OnMouseMove(int x, int y)
{
	mousePosition.x = x;
	mousePosition.y = y;
}

void OnTimer(int id) {

	if (keystate['w']) {
		player->velocity_vertical = 1;
		//glDisable(GL_LIGHT0);
	}
	if (keystate['s']) {
		player->velocity_vertical = -1;
	}
	if (keystate['a']) {
		player->velocity_horizontal = 1;
	}
	if (keystate['d']) {
		player->velocity_horizontal = -1;
	}

	if (captureMouse)
	{
		theta = atan2(player->dir.z, player->dir.x);
		float phi = asin(player->dir.y);

		theta += (mousePosition.x - window_width / 2) * 0.01;
		phi -= (mousePosition.y - window_height / 2) * 0.01;

		player->dir.x = cos(theta) * cos(phi);
		player->dir.y = sin(phi);
		player->dir.z = sin(theta) * cos(phi);

		glutWarpPointer(window_width / 2, window_height / 2);
	}
	bron->pos.x = player->pos.x - 0.5;
	bron->pos.z = player->pos.z + 0.5;
	scene.Update();
	glutTimerFunc(17, OnTimer, 0);
}

void OnRender() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	scene.hud.monety = player->monety;
	scene.hud.zycie = player->zycie;
	scene.hud.maxZycie = player->maxZycie;
	scene.HeadUpDisplay();

	gluLookAt(
		player->pos.x, player->pos.y, player->pos.z,
		player->pos.x + player->dir.x, player->pos.y + player->dir.y, player->pos.z + player->dir.z,
		0.0f, 1.0f, 0.0f
	);
	//œwiat³o
	GLfloat l0_ambient[] = { 0.2f, 0.2f, 0.2f };
	GLfloat l0_diffuse[] = { 1.0f, 1.0f, 1.0 };
	GLfloat l0_specular[] = { 0.5f, 0.5f, 0.5f };
	GLfloat l0_position[] = { player->pos.x, player->pos.y, player->pos.z, 1.0f };

	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, l0_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, l0_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, l0_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, l0_position);
	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.2);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0);


	//DZIEDZINIEC ||
	//dzia³a usuwanie z renderowania i monety
	if (player->pos.x >= -5 && player->pos.x <= 5.0 && player->pos.z >= 0.0 && player->pos.z <= 5.0) {
		dziedziniec();
		korytarz_1();
		//moneta
		if (abs(player->pos.x - m1->pos.x) <= 0.1 && abs(player->pos.z - m1->pos.z) <= 0.1) {
			if (m1->isAlive == true) player->monety = player->monety + 5;
			m1->isAlive = false;
		}
		if (abs(player->pos.x - w1->pos.x) <= 0.1 && abs(player->pos.z - w1->pos.z) <= 0.1) {
			player->zycie -= 1;
		}
		//wrog
		if (abs(bron->pos.x - w1->pos.x) <= 0.3 && abs(bron->pos.z - w1->pos.z) <= 0.3) {
			w1->live -= 1;
			if (w1->live == 0) {
				if (w1->isAlive == true) player->monety = player->monety + 5;
				w1->isAlive = false;
			}
		}

	}
	//KORYTARZ 1
	if (player->pos.x >= -5 && player->pos.x <= -3.0 && player->pos.z >= 5.0 && player->pos.z <= 8.0) {
		korytarz_1();
		dziedziniec();
		sala_1();
	}
	//SALA 1
	if (player->pos.x >= -5 && player->pos.x <= 8.0 && player->pos.z >= 8.0 && player->pos.z <= 15.0) {
		sala_1();
		korytarz_1();
		korytarz_2();
		korytarz_5();
		if (abs(bron->pos.x - w2->pos.x) <= 0.3 && abs(bron->pos.z - w2->pos.z) <= 0.3) {
			w2->live -= 1;
			if (w2->live == 0) {
				if (w2->isAlive == true) player->monety = player->monety + 5;
				w2->isAlive = false;
			}
		}
		if (abs(bron->pos.x - w3->pos.x) <= 0.3 && abs(bron->pos.z - w3->pos.z) <= 0.3) {
			w3->live -= 1;
			if (w3->live == 0) {
				if (w3->isAlive == true) player->monety = player->monety + 5;
				w3->isAlive = false;
			}
		}
		if (abs(bron->pos.x - w4->pos.x) <= 0.3 && abs(bron->pos.z - w4->pos.z) <= 0.3) {
			w4->live -= 1;
			if (w4->live == 0) {
				if (w4->isAlive == true) player->monety = player->monety + 5;
				w4->isAlive = false;
			}
		}
		if (abs(player->pos.x - w2->pos.x) <= 0.1 && abs(player->pos.z - w2->pos.z) <= 0.1) {
			player->zycie -= 1;
		}
		if (abs(player->pos.x - w3->pos.x) <= 0.1 && abs(player->pos.z - w3->pos.z) <= 0.1) {
			player->zycie -= 1;
		}
		if (abs(player->pos.x - w4->pos.x) <= 0.1 && abs(player->pos.z - w4->pos.z) <= 0.1) {
			player->zycie -= 1;
		}
	}
	//KORYTARZ 2
	if (player->pos.x >= 6 && player->pos.x <= 8.0 && player->pos.z >= 15.0 && player->pos.z <= 17.0) {
		korytarz_2();
		sala_2();
		sala_1();
	}
	//SALA 2
	if (player->pos.x >= 0 && player->pos.x <= 8.0 && player->pos.z >= 17.0 && player->pos.z <= 25.0) {
		sala_2();
		korytarz_2();
		korytarz_3();
		korytarz_4();
		if (abs(player->pos.x - m2->pos.x) <= 0.1 && abs(player->pos.z - m2->pos.z) <= 0.1) {
			if (m2->isAlive == true) player->monety = player->monety + 5;
			m2->isAlive = false;
		}
		if (abs(bron->pos.x - w5->pos.x) <= 0.3 && abs(bron->pos.z - w5->pos.z) <= 0.3) {
			w5->live -= 1;
			if (w5->live == 0) {
				if (w5->isAlive == true) player->monety = player->monety + 5;
				w5->isAlive = false;
			}
		}
		if (abs(bron->pos.x - w6->pos.x) <= 0.3 && abs(bron->pos.z - w6->pos.z) <= 0.3) {
			w6->live -= 1;
			if (w6->live == 0) {
				if (w6->isAlive == true) player->monety = player->monety + 5;
				w6->isAlive = false;
			}
		}
		if (abs(bron->pos.x - w7->pos.x) <= 0.3 && abs(bron->pos.z - w7->pos.z) <= 0.3) {
			w7->live -= 1;
			if (w7->live == 0) {
				if (w7->isAlive == true) player->monety = player->monety + 5;
				w7->isAlive = false;
			}
		}
		if (abs(player->pos.x - w5->pos.x) <= 0.1 && abs(player->pos.z - w5->pos.z) <= 0.1) {
			player->zycie -= 1;
		}
		if (abs(player->pos.x - w6->pos.x) <= 0.1 && abs(player->pos.z - w6->pos.z) <= 0.1) {
			player->zycie -= 1;
		}
		if (abs(player->pos.x - w7->pos.x) <= 0.1 && abs(player->pos.z - w7->pos.z) <= 0.1) {
			player->zycie -= 1;
		}
	}
	//SALA 3
	if (player->pos.x >= -20 && player->pos.x <= -10.0 && player->pos.z >= 12.0 && player->pos.z <= 20.0) {
		sala_3();
		korytarz_4();
		korytarz_5();
		korytarz_6();
		if (abs(player->pos.x - m3->pos.x) <= 0.1 && abs(player->pos.z - m3->pos.z) <= 0.1) {
			if (m3->isAlive == true) player->monety = player->monety + 5;
			m3->isAlive = false;
		}
		if (abs(bron->pos.x - w10->pos.x) <= 0.3 && abs(bron->pos.z - w10->pos.z) <= 0.3) {
			w10->live -= 1;
			if (w10->live == 0) {
				if (w10->isAlive == true) player->monety = player->monety + 5;
				w10->isAlive = false;
			}
		}
		if (abs(player->pos.x - w10->pos.x) <= 0.1 && abs(player->pos.z - w10->pos.z) <= 0.1) {
			player->zycie -= 1;
		}
	}
	//KORYTARZ 3
	if (player->pos.x >= 0 && player->pos.x <= 2.0 && player->pos.z >= 25.0 && player->pos.z <= 30.0) {
		korytarz_3();
		skarbiec();
		sala_2();
	}
	//KORYTARZ 4
	if (player->pos.x >= -10 && player->pos.x <= 0 && player->pos.z >= 17.0 && player->pos.z <= 20.0) {
		korytarz_4();
		sala_2();
		sala_3();
	}
	//KORYTARZ 5
	if (player->pos.x >= -10 && player->pos.x <= -5.0 && player->pos.z >= 12.0 && player->pos.z <= 15.0) {
		korytarz_5();
		sala_1();
		sala_3();
	}
	//KORYTARZ 6
	//zmieniæ szerokosc z 1 na 2?????
	if (player->pos.x >= -20 && player->pos.x <= -19.0 && player->pos.z >= 8.0 && player->pos.z <= 12.0) {
		korytarz_6();
		sala_3();
		wyjscie();
	}
	//SKARBIEC
	if (player->pos.x >= -4 && player->pos.x <= 6.0 && player->pos.z >= 30.0 && player->pos.z <= 35.0)
	{
		skarbiec();
		korytarz_3();
		if (abs(player->pos.x - m4->pos.x) <= 0.1 && abs(player->pos.z - m4->pos.z) <= 0.1) {
			if (m4->isAlive == true) player->monety = player->monety + 5;
			m4->isAlive = false;
		}
		if (abs(player->pos.x - m5->pos.x) <= 0.1 && abs(player->pos.z - m5->pos.z) <= 0.1) {
			if (m5->isAlive == true) player->monety = player->monety + 5;
			m5->isAlive = false;
		}
		if (abs(player->pos.x - m6->pos.x) <= 0.1 && abs(player->pos.z - m6->pos.z) <= 0.1) {
			if (m6->isAlive == true) player->monety = player->monety + 5;
			m6->isAlive = false;
		}
		if (abs(player->pos.x - m7->pos.x) <= 0.1 && abs(player->pos.z - m7->pos.z) <= 0.1) {
			if (m7->isAlive == true) player->monety = player->monety + 5;
			m7->isAlive = false;
		}
		if (abs(bron->pos.x - w8->pos.x) <= 0.3 && abs(bron->pos.z - w8->pos.z) <= 0.3) {
			w8->live -= 1;
			if (w8->live == 0) {
				if (w8->isAlive == true) player->monety = player->monety + 5;
				w8->isAlive = false;
			}
		}
		if (abs(bron->pos.x - w9->pos.x) <= 0.3 && abs(bron->pos.z - w9->pos.z) <= 0.3) {
			w9->live -= 1;
			if (w9->live == 0) {
				if (w9->isAlive == true) player->monety = player->monety + 5;
				w9->isAlive = false;
			}
		}
		if (abs(player->pos.x - w8->pos.x) <= 0.1 && abs(player->pos.z - w8->pos.z) <= 0.1) {
			player->zycie -= 1;
		}
		if (abs(player->pos.x - w9->pos.x) <= 0.1 && abs(player->pos.z - w9->pos.z) <= 0.1) {
			player->zycie -= 1;
		}
	}
	//WYJSCIE
	if (player->pos.x >= -20 && player->pos.x <= -10.0 && player->pos.z >= 3.0 && player->pos.z <= 8.0){
		wyjscie();
		korytarz_6();
		if (abs(player->pos.x - m8->pos.x) <= 0.1 && abs(player->pos.z - m8->pos.z) <= 0.1) {
			if (m8->isAlive == true) player->monety = player->monety + 5;
			m8->isAlive = false;
		}
		if (abs(player->pos.x - m9->pos.x) <= 0.1 && abs(player->pos.z - m9->pos.z) <= 0.1) {
			if (m9->isAlive == true) player->monety = player->monety + 5;
			m9->isAlive = false;
		}
		if (abs(player->pos.x - m10->pos.x) <= 0.1 && abs(player->pos.z - m10->pos.z) <= 0.1) {
			if (m10->isAlive == true) player->monety = player->monety + 5;
			m10->isAlive = false;
		}
		if (abs(player->pos.x - m11->pos.x) <= 0.1 && abs(player->pos.z - m11->pos.z) <= 0.1) {
			if (m11->isAlive == true) player->monety = player->monety + 5;
			m11->isAlive = false;
		}
		if (abs(bron->pos.x - w11->pos.x) <= 0.3 && abs(bron->pos.z - w11->pos.z) <= 0.3) {
			w11->live -= 1;
			if (w11->live == 0) {
				if (w11->isAlive == true) player->monety = player->monety + 5;
				w11->isAlive = false;
			}
		}
		if (abs(player->pos.x - w11->pos.x) <= 0.1 && abs(player->pos.z - w11->pos.z) <= 0.1) {
			player->zycie -= 1;
		}
	}
	scene.Render();
	
	//printf("Ile monet : %d\n", player->monety);
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

void OnReshape(int width, int height) {

	window_width = width;
	window_height = height;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, width, height);
	gluPerspective(60.0f, (float)width / height, .01f, 250.0f);
}
void dziedziniec() {

	glEnable(GL_TEXTURE_2D);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	TextureManager::getInstance()->BindTexture("mur");
	
	glBegin(GL_QUADS);
	// Pod³oga
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 1.0f, 0.0f);
		//glColor3f(0.4f, 0.4f, 0.4f);
		glTexCoord2f(0, 1);
		glVertex3f(5.0f, 0.0f, 5.0f);
		glTexCoord2f(0,0);
		glVertex3f(5.0f, 0.0f, 0.0f);
		glTexCoord2f(1, 0);
		glVertex3f(-5.0f, 0.0f, 0.0f);
		glTexCoord2f(1,1);
		glVertex3f(-5.0f, 0.0f, 5.0f);
	}
	//sufit
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, -1.0f, 0.0f);
		//glColor3f(0.8f, 0.8f, 0.8f);
		glTexCoord2f(0, 1);
		glVertex3f(-5.0f, 2.0f, 5.0f);
		glTexCoord2f(0, 0);
		glVertex3f(-5.0f, 2.0f, 0.0f);
		glTexCoord2f(1, 0);
		glVertex3f(5.0f, 2.0f, 0.0f);
		glTexCoord2f(1, 1);
		glVertex3f(5.0f, 2.0f, 5.0f);
	}
	//lewa
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		//glColor3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0, 0);
		glVertex3f(5.0f, 2.0f, 5.0f);
		glTexCoord2f(1,0);
		glVertex3f(5.0f, 2.0f, 0.0f);
		glTexCoord2f(1,1);
		glVertex3f(5.0f, 0.0f, 0.0f);
		glTexCoord2f(0,1);
		glVertex3f(5.0f, 0.0f, 5.0f);
	}
	//prawa
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(1.0f, 0.0f, 0.0f);
		//glColor3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(1,1);
		glVertex3f(-5.0f, 0.0f, 5.0f);
		glTexCoord2f(0,1);
		glVertex3f(-5.0f, 0.0f, 0.0f);
		glTexCoord2f(0,0);
		glVertex3f(-5.0f, 2.0f, 0.0f);
		glTexCoord2f(1,0);
		glVertex3f(-5.0f, 2.0f, 5.0f);
	}
	//tylnia
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, 1.0f);
		//glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(1,1);
		glVertex3f(-5.0f, 2.0f, 0.0f);
		glTexCoord2f(0,1);
		glVertex3f(-5.0f, 0.0f, 0.0f);
		glTexCoord2f(0,0);
		glVertex3f(5.0f, 0.0f, 0.0f);
		glTexCoord2f(1,0);

		glVertex3f(5.0f, 2.0f, 0.0f);
	}
	//przednia
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, -1.0f);
		//glColor3f(0.6f, 0.6f, 0.6f);
		glTexCoord2f(1,1);
		glVertex3f(-3.0f, 0.0f, 5.0f);
		glTexCoord2f(0,1);
		glVertex3f(-3.0f, 2.0f, 5.0f);
		glTexCoord2f(0,0);
		glVertex3f(5.0f, 2.0f, 5.0f);
		glTexCoord2f(1,0);
		glVertex3f(5.0f, 0.0f, 5.0f);
	}
	//
	glEnd();
	//Wrog* w1 = new Wrog(2, 1, 0.3, 'G');
	//scene.AddObject(w1);	
}
void korytarz_1() {
	glEnable(GL_TEXTURE_2D);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	TextureManager::getInstance()->BindTexture("mur");
	glBegin(GL_QUADS);
	// Pod³oga
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 1.0f, 0.0f);
		//glColor3f(0.4f, 0.4f, 0.4f);
		glTexCoord2f(0,1);
		glVertex3f(-3.0f, 0.0f, 8.0f);
		glTexCoord2f(0,0);
		glVertex3f(-3.0f, 0.0f, 5.0f);
		glTexCoord2f(1,0);
		glVertex3f(-5.0f, 0.0f, 5.0f);
		glTexCoord2f(1,1);
		glVertex3f(-5.0f, 0.0f, 8.0f);
	}
	//sufit
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, -1.0f, 0.0f);
		//glColor3f(0.8f, 0.8f, 0.8f);
		glTexCoord2f(0, 1);
		glVertex3f(-5.0f, 2.0f, 8.0f);
		glTexCoord2f(0, 0);
		glVertex3f(-5.0f, 2.0f, 5.0f);
		glTexCoord2f(1, 0);
		glVertex3f(-3.0f, 2.0f, 5.0f);
		glTexCoord2f(1, 1);
		glVertex3f(-3.0f, 2.0f, 8.0f);

	}
	//lewa
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		//glColor3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0,0);
		glVertex3f(-3.0f, 2.0f, 8.0f);
		glTexCoord2f(1,0);
		glVertex3f(-3.0f, 2.0f, 5.0f);
		glTexCoord2f(1,1);
		glVertex3f(-3.0f, 0.0f, 5.0f);
		glTexCoord2f(0,1);
		glVertex3f(-3.0f, 0.0f, 8.0f);
	}

	//prawa
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(1.0f, 0.0f, 0.0f);
		//glColor3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(1,1);
		glVertex3f(-5.0f, 0.0f, 8.0f);
		glTexCoord2f(0,1);
		glVertex3f(-5.0f, 0.0f, 5.0f);
		glTexCoord2f(0,0);
		glVertex3f(-5.0f, 2.0f, 5.0f);
		glTexCoord2f(1,0);
		glVertex3f(-5.0f, 2.0f, 8.0f);
	}
	/*//tylnia
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, 1.0f);
		//glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-5.0f, 2.0f, 5.0f);
		glVertex3f(-5.0f, 0.0f, 5.0f);
		glVertex3f(-3.0f, 0.0f, 5.0f);
		glVertex3f(-3.0f, 2.0f, 5.0f);
	}
	//przednia
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, -1.0f);
		//glColor3f(0.6f, 0.6f, 0.6f);
		glVertex3f(-5.0f, 0.0f, 8.0f);
		glVertex3f(-5.0f, 2.0f, 8.0f);
		glVertex3f(-3.0f, 2.0f, 8.0f);
		glVertex3f(-3.0f, 0.0f, 8.0f);
	}*/
	glEnd();
}
void sala_1() {
	glEnable(GL_TEXTURE_2D);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	TextureManager::getInstance()->BindTexture("mur");
	glBegin(GL_QUADS);
	// Pod³oga
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 1.0f, 0.0f);
		//glColor3f(0.4f, 0.4f, 0.4f);
		glTexCoord2f(0,1);
		glVertex3f(8.0f, 0.0f, 15.0f);
		glTexCoord2f(0,0);
		glVertex3f(8.0f, 0.0f, 8.0f);
		glTexCoord2f(1,0);
		glVertex3f(-5.0f, 0.0f, 8.0f);
		glTexCoord2f(1,1);
		glVertex3f(-5.0f, 0.0f, 15.0f);
	}
	//sufit
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, -1.0f, 0.0f);
		//glColor3f(0.8f, 0.8f, 0.8f);
		glTexCoord2f(0,1);
		glVertex3f(-5.0f, 2.0f, 15.0f);
		glTexCoord2f(0,0);
		glVertex3f(-5.0f, 2.0f, 8.0f);
		glTexCoord2f(1,0);
		glVertex3f(8.0f, 2.0f, 8.0f);
		glTexCoord2f(1,1);
		glVertex3f(8.0f, 2.0f, 15.0f);
	}
	//lewa
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		//glColor3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0,0);
		glVertex3f(8.0f, 2.0f, 15.0f);
		glTexCoord2f(1,0);
		glVertex3f(8.0f, 2.0f, 8.0f);
		glTexCoord2f(1,1);
		glVertex3f(8.0f, 0.0f, 8.0f);
		glTexCoord2f(0,1);
		glVertex3f(8.0f, 0.0f, 15.0f);
	}
	//prawa
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(1.0f, 0.0f, 0.0f);
		//glColor3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(1,1);
		glVertex3f(-5.0f, 0.0f, 12.0f);
		glTexCoord2f(0,1);
		glVertex3f(-5.0f, 0.0f, 8.0f);
		glTexCoord2f(0,0);
		glVertex3f(-5.0f, 2.0f, 8.0f);
		glTexCoord2f(1,0);
		glVertex3f(-5.0f, 2.0f, 12.0f);
	}
	//tylnia
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, 1.0f);
		//glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(1,1);
		glVertex3f(-3.0f, 2.0f, 8.0f);
		glTexCoord2f(0,1);
		glVertex3f(-3.0f, 0.0f, 8.0f);
		glTexCoord2f(0,0);
		glVertex3f(8.0f, 0.0f, 8.0f);
		glTexCoord2f(1,0);
		glVertex3f(8.0f, 2.0f, 8.0f);
	}
	//przednia
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, -1.0f);
		//glColor3f(0.6f, 0.6f, 0.6f);
		glTexCoord2f(1,1);
		glVertex3f(-5.0f, 0.0f, 15.0f);
		glTexCoord2f(0,1);
		glVertex3f(-5.0f, 2.0f, 15.0f);
		glTexCoord2f(0,0);
		glVertex3f(6.0f, 2.0f, 15.0f);
		glTexCoord2f(1,0);
		glVertex3f(6.0f, 0.0f, 15.0f);
	}
	glEnd();
}
void korytarz_2() {
	glEnable(GL_TEXTURE_2D);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	TextureManager::getInstance()->BindTexture("mur");
	glBegin(GL_QUADS);
	// Pod³oga
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 1.0f, 0.0f);
		//glColor3f(0.4f, 0.4f, 0.4f);
		glTexCoord2f(0,1);
		glVertex3f(8.0f, 0.0f, 17.0f);
		glTexCoord2f(0,0);
		glVertex3f(8.0f, 0.0f, 15.0f);
		glTexCoord2f(1,0);
		glVertex3f(6.0f, 0.0f, 15.0f);
		glTexCoord2f(1,1);
		glVertex3f(6.0f, 0.0f, 17.0f);
	}
	//sufit
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, -1.0f, 0.0f);
		//glColor3f(0.8f, 0.8f, 0.8f);
		glTexCoord2f(0,1);
		glVertex3f(6.0f, 2.0f, 17.0f);
		glTexCoord2f(0,0);
		glVertex3f(6.0f, 2.0f, 15.0f);
		glTexCoord2f(1,0);
		glVertex3f(8.0f, 2.0f, 15.0f);
		glTexCoord2f(1,1);
		glVertex3f(8.0f, 2.0f, 17.0f);
	}
	//lewa
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		//glColor3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0,0);
		glVertex3f(8.0f, 2.0f, 17.0f);
		glTexCoord2f(1,0);
		glVertex3f(8.0f, 2.0f, 15.0f);
		glTexCoord2f(1,1);
		glVertex3f(8.0f, 0.0f, 15.0f);
		glTexCoord2f(0,1);
		glVertex3f(8.0f, 0.0f, 17.0f);
	}
	//prawa
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(1.0f, 0.0f, 0.0f);
		//glColor3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(1,1);
		glVertex3f(6.0f, 0.0f, 17.0f);
		glTexCoord2f(0,1);
		glVertex3f(6.0f, 0.0f, 15.0f);
		glTexCoord2f(0,0);
		glVertex3f(6.0f, 2.0f, 15.0f);
		glTexCoord2f(1,0);
		glVertex3f(6.0f, 2.0f, 17.0f);
	}
	//tylnia
	/*{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, 1.0f);
		//glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(6.0f, 2.0f, 15.0f);
		glVertex3f(6.0f, 0.0f, 15.0f);
		glVertex3f(8.0f, 0.0f, 15.0f);
		glVertex3f(8.0f, 2.0f, 15.0f);
	}
	//przednia
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, -1.0f);
		//glColor3f(0.6f, 0.6f, 0.6f);
		glVertex3f(6.0f, 0.0f, 17.0f);
		glVertex3f(6.0f, 2.0f, 17.0f);
		glVertex3f(8.0f, 2.0f, 17.0f);
		glVertex3f(8.0f, 0.0f, 17.0f);
	}*/
	glEnd();
}
void sala_2() {
	glEnable(GL_TEXTURE_2D);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	TextureManager::getInstance()->BindTexture("mur");
	glBegin(GL_QUADS);
	// Pod³oga
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 1.0f, 0.0f);
		//glColor3f(0.4f, 0.4f, 0.4f);
		glTexCoord2f(0,1);
		glVertex3f(8.0f, 0.0f, 25.0f);
		glTexCoord2f(0,0);
		glVertex3f(8.0f, 0.0f, 17.0f);
		glTexCoord2f(1,0);
		glVertex3f(0.0f, 0.0f, 17.0f);
		glTexCoord2f(1,1);
		glVertex3f(0.0f, 0.0f, 25.0f);
	}
	//sufit
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, -1.0f, 0.0f);

		//glColor3f(0.8f, 0.8f, 0.8f);
		glTexCoord2f(0,1);
		glVertex3f(0.0f, 2.0f, 25.0f);
		glTexCoord2f(0,0);
		glVertex3f(0.0f, 2.0f, 17.0f);
		glTexCoord2f(1,0);
		glVertex3f(8.0f, 2.0f, 17.0f);
		glTexCoord2f(1,1);
		glVertex3f(8.0f, 2.0f, 25.0f);
	}
	//lewa
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f,1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		//glColor3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0,0);
		glVertex3f(8.0f, 2.0f, 25.0f);
		glTexCoord2f(1,0);
		glVertex3f(8.0f, 2.0f, 17.0f);
		glTexCoord2f(1,1);
		glVertex3f(8.0f, 0.0f, 17.0f);
		glTexCoord2f(0,1);
		glVertex3f(8.0f, 0.0f, 25.0f);
	}
	//prawa
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(1.0f, 0.0f, 0.0f);
		//glColor3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(1,1);
		glVertex3f(0.0f, 0.0f, 25.0f);
		glTexCoord2f(0,1);
		glVertex3f(0.0f, 0.0f, 20.0f);
		glTexCoord2f(0,0);
		glVertex3f(0.0f, 2.0f, 20.0f);
		glTexCoord2f(1,0);
		glVertex3f(0.0f, 2.0f, 25.0f);
	}
	//tylnia
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, 1.0f);
		//glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(1,1);
		glVertex3f(0.0f, 2.0f, 17.0f);
		glTexCoord2f(0,1);
		glVertex3f(0.0f, 0.0f, 17.0f);
		glTexCoord2f(0,0);
		glVertex3f(6.0f, 0.0f, 17.0f);
		glTexCoord2f(1,0);
		glVertex3f(6.0f, 2.0f, 17.0f);
	}
	//przednia
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, -1.0f);
		//glColor3f(0.6f, 0.6f, 0.6f);
		glTexCoord2f(1,1);
		glVertex3f(2.0f, 0.0f, 25.0f);
		glTexCoord2f(0,1);
		glVertex3f(2.0f, 2.0f, 25.0f);
		glTexCoord2f(0,0);
		glVertex3f(8.0f, 2.0f, 25.0f);
		glTexCoord2f(1,0);
		glVertex3f(8.0f, 0.0f, 25.0f);
	}
	glEnd();
	
}
void sala_3() {
	glEnable(GL_TEXTURE_2D);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	TextureManager::getInstance()->BindTexture("mur");
	glBegin(GL_QUADS);
	// Pod³oga
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 1.0f, 0.0f);
		//glColor3f(0.4f, 0.4f, 0.4f);
		glTexCoord2f(0,1);
		glVertex3f(-10.0f, 0.0f, 20.0f);
		glTexCoord2f(0,0);
		glVertex3f(-10.0f, 0.0f, 12.0f);
		glTexCoord2f(1,0);
		glVertex3f(-20.0f, 0.0f, 12.0f);
		glTexCoord2f(1, 1);
		glVertex3f(-20.0f, 0.0f, 20.0f);
	}
	//sufit
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, -1.0f, 0.0f);
		//glColor3f(0.8f, 0.8f, 0.8f);
		glTexCoord2f(0,1);
		glVertex3f(-20.0f, 2.0f, 20.0f);
		glTexCoord2f(0,0);
		glVertex3f(-20.0f, 2.0f, 12.0f);
		glTexCoord2f(1,0);
		glVertex3f(-10.0f, 2.0f, 12.0f);
		glTexCoord2f(1,1);
		glVertex3f(-10.0f, 2.0f, 20.0f);
	}
	//lewa
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		//glColor3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0,0);
		glVertex3f(-10.0f, 2.0f, 17.0f);
		glTexCoord2f(1,0);
		glVertex3f(-10.0f, 2.0f, 15.0f);
		glTexCoord2f(1,1);
		glVertex3f(-10.0f, 0.0f, 15.0f);
		glTexCoord2f(0,1);
		glVertex3f(-10.0f, 0.0f, 17.0f);
	}
	//prawa
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(1.0f, 0.0f, 0.0f);
		//glColor3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(1,1);
		glVertex3f(-20.0f, 0.0f, 20.0f);
		glTexCoord2f(0,1);
		glVertex3f(-20.0f, 0.0f, 12.0f);
		glTexCoord2f(0,0);
		glVertex3f(-20.0f, 2.0f, 12.0f);
		glTexCoord2f(1,0);
		glVertex3f(-20.0f, 2.0f, 20.0f);
	}
	//tylnia
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, 1.0f);
		//glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(1,1);
		glVertex3f(-19.0f, 2.0f, 12.0f);
		glTexCoord2f(0, 1);
		glVertex3f(-19.0f, 0.0f, 12.0f);
		glTexCoord2f(0, 0);
		glVertex3f(-10.0f, 0.0f, 12.0f);
		glTexCoord2f(1,0);
		glVertex3f(-10.0f, 2.0f, 12.0f);
	}
	//przednia
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, -1.0f);
		//glColor3f(0.6f, 0.6f, 0.6f);
		glTexCoord2f(1,1);
		glVertex3f(-20.0f, 0.0f, 20.0f);
		glTexCoord2f(0,1);
		glVertex3f(-20.0f, 2.0f, 20.0f);
		glTexCoord2f(0,0);
		glVertex3f(-10.0f, 2.0f, 20.0f);
		glTexCoord2f(1,0);
		glVertex3f(-10.0f, 0.0f, 20.0f);
	}
	glEnd();

	
}
void korytarz_3() {
	glEnable(GL_TEXTURE_2D);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	TextureManager::getInstance()->BindTexture("mur");
	glBegin(GL_QUADS);
	// Pod³oga
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 1.0f, 0.0f);
		//glColor3f(0.4f, 0.4f, 0.4f);
		glTexCoord2f(0,1);
		glVertex3f(2.0f, 0.0f, 30.0f);
		glTexCoord2f(0,0);
		glVertex3f(2.0f, 0.0f, 25.0f);
		glTexCoord2f(1,0);
		glVertex3f(0.0f, 0.0f, 25.0f);
		glTexCoord2f(1,1);
		glVertex3f(0.0f, 0.0f, 30.0f);
	}
	//sufit
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, -1.0f, 0.0f);
		//glColor3f(0.8f, 0.8f, 0.8f);
		glTexCoord2f(0,1);
		glVertex3f(0.0f, 2.0f, 30.0f);
		glTexCoord2f(0,0);
		glVertex3f(0.0f, 2.0f, 25.0f);
		glTexCoord2f(1,0);
		glVertex3f(2.0f, 2.0f, 25.0f);
		glTexCoord2f(1,1);
		glVertex3f(2.0f, 2.0f, 30.0f);
	}
	//lewa
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		//glColor3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0,0);
		glVertex3f(2.0f, 2.0f, 30.0f);
		glTexCoord2f(1,0);
		glVertex3f(2.0f, 2.0f, 25.0f);
		glTexCoord2f(1,1);
		glVertex3f(2.0f, 0.0f, 25.0f);
		glTexCoord2f(0,1);
		glVertex3f(2.0f, 0.0f, 30.0f);
	}
	//prawa
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(1.0f, 0.0f, 0.0f);
		//glColor3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(1,1);
		glVertex3f(0.0f, 0.0f, 30.0f);
		glTexCoord2f(0,1);
		glVertex3f(0.0f, 0.0f, 25.0f);
		glTexCoord2f(0,0);
		glVertex3f(0.0f, 2.0f, 25.0f);
		glTexCoord2f(1,0);
		glVertex3f(0.0f, 2.0f, 30.0f);
	}
	//tylnia
	/*{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, 1.0f);
		//glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(0.0f, 2.0f, 25.0f);
		glVertex3f(0.0f, 0.0f, 25.0f);
		glVertex3f(2.0f, 0.0f, 25.0f);
		glVertex3f(2.0f, 2.0f, 25.0f); 
	}
	//przednia
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, -1.0f);
		//glColor3f(0.6f, 0.6f, 0.6f);
		glVertex3f(0.0f, 0.0f, 30.0f);
		glVertex3f(0.0f, 2.0f, 30.0f);
		glVertex3f(2.0f, 2.0f, 30.0f);
		glVertex3f(2.0f, 0.0f, 30.0f);
	}*/
	glEnd();
}
void korytarz_4() {
	glEnable(GL_TEXTURE_2D);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	TextureManager::getInstance()->BindTexture("mur");
	glBegin(GL_QUADS);
	{
		// Pod³oga
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 1.0f, 0.0f);
		//glColor3f(0.4f, 0.4f, 0.4f);
		glTexCoord2f(0,1);
		glVertex3f(0.0f, 0.0f, 20.0f);
		glTexCoord2f(0,0);
		glVertex3f(0.0f, 0.0f, 17.0f);
		glTexCoord2f(1,0);
		glVertex3f(-10.0f, 0.0f, 17.0f);
		glTexCoord2f(1,1);
		glVertex3f(-10.0f, 0.0f, 20.0f);
	}
	//sufit
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, -1.0f, 0.0f);
		//glColor3f(0.8f, 0.8f, 0.8f);
		glTexCoord2f(0,1);
		glVertex3f(-10.0f, 2.0f, 20.0f);
		glTexCoord2f(0,0);
		glVertex3f(-10.0f, 2.0f, 17.0f);
		glTexCoord2f(1,0);
		glVertex3f(0.0f, 2.0f, 17.0f);
		glTexCoord2f(1,1);
		glVertex3f(0.0f, 2.0f, 20.0f);
	}
	/*//lewa
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 0.0f, 1.0f, 0.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		//glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, 2.0f, 20.0f);
		glVertex3f(0.0f, 2.0f, 17.0f);
		glVertex3f(0.0f, 0.0f, 17.0f);
		glVertex3f(0.0f, 0.0f, 20.0f);
	}
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 0.0f, 0.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(1.0f, 0.0f, 0.0f);
		//prawa
		//glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-10.0f, 0.0f, 20.0f);
		glVertex3f(-10.0f, 0.0f, 17.0f);
		glVertex3f(-10.0f, 2.0f, 17.0f);
		glVertex3f(-10.0f, 2.0f, 20.0f);
	}*/
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, 1.0f);
		//tylnia
		//glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(1,1);
		glVertex3f(-10.0f, 2.0f, 17.0f);
		glTexCoord2f(0,1);
		glVertex3f(-10.0f, 0.0f, 17.0f);
		glTexCoord2f(0,0);
		glVertex3f(0.0f, 0.0f, 17.0f);
		glTexCoord2f(1,0);
		glVertex3f(0.0f, 2.0f, 17.0f);
	}
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, -1.0f);
		//przednia
		//glColor3f(0.6f, 0.6f, 0.6f);
		glTexCoord2f(1,1);
		glVertex3f(-10.0f, 0.0f, 20.0f);
		glTexCoord2f(0,1);
		glVertex3f(-10.0f, 2.0f, 20.0f);
		glTexCoord2f(0,0);
		glVertex3f(0.0f, 2.0f, 20.0f);
		glTexCoord2f(1,0);
		glVertex3f(0.0f, 0.0f, 20.0f);
	}
	glEnd();
}
void korytarz_5() {
	glEnable(GL_TEXTURE_2D);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	TextureManager::getInstance()->BindTexture("mur");
	glBegin(GL_QUADS);
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 1.0f, 0.0f);
		// Pod³oga
		//glColor3f(0.4f, 0.4f, 0.4f);
		glTexCoord2f(0,1);
		glVertex3f(-5.0f, 0.0f, 15.0f);
		glTexCoord2f(0,0);
		glVertex3f(-5.0f, 0.0f, 12.0f);
		glTexCoord2f(1,0);
		glVertex3f(-10.0f, 0.0f, 12.0f);
		glTexCoord2f(1,1);
		glVertex3f(-10.0f, 0.0f, 15.0f);
	}
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, -1.0f, 0.0f);
		//sufit
		//glColor3f(0.8f, 0.8f, 0.8f);
		glTexCoord2f(0,1);
		glVertex3f(-10.0f, 2.0f, 15.0f);
		glTexCoord2f(0,0);
		glVertex3f(-10.0f, 2.0f, 12.0f);
		glTexCoord2f(1,0);
		glVertex3f(-5.0f, 2.0f, 12.0f);
		glTexCoord2f(1,1);
		glVertex3f(-5.0f, 2.0f, 15.0f);
	}
	/*{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 0.0f, 1.0f, 0.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		//lewa
		//glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(-5.0f, 2.0f, 15.0f);
		glVertex3f(-5.0f, 2.0f, 12.0f);
		glVertex3f(-5.0f, 0.0f, 12.0f);
		glVertex3f(-5.0f, 0.0f, 15.0f);
	}
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 0.0f, 0.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(1.0f, 0.0f, 0.0f);
		//prawa
		//glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-10.0f, 0.0f, 15.0f);
		glVertex3f(-10.0f, 0.0f, 12.0f);
		glVertex3f(-10.0f, 2.0f, 12.0f);
		glVertex3f(-10.0f, 2.0f, 15.0f);
	}*/
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, 1.0f);
		//tylnia
		//glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(1,1);
		glVertex3f(-10.0f, 2.0f, 12.0f);
		glTexCoord2f(0,1);
		glVertex3f(-10.0f, 0.0f, 12.0f);
		glTexCoord2f(0,0);
		glVertex3f(-5.0f, 0.0f, 12.0f);
		glTexCoord2f(1,0);
		glVertex3f(-5.0f, 2.0f, 12.0f);
	}
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, -1.0f);
		//przednia
		//glColor3f(0.6f, 0.6f, 0.6f);
		glTexCoord2f(1,1);
		glVertex3f(-10.0f, 0.0f, 15.0f);
		glTexCoord2f(0,1);
		glVertex3f(-10.0f, 2.0f, 15.0f);
		glTexCoord2f(0,0);
		glVertex3f(-5.0f, 2.0f, 15.0f);
		glTexCoord2f(1,0);
		glVertex3f(-5.0f, 0.0f, 15.0f);
	}
	glEnd();
}
void korytarz_6() {
	glEnable(GL_TEXTURE_2D);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	TextureManager::getInstance()->BindTexture("mur");
	glBegin(GL_QUADS);
	// Pod³oga
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 1.0f, 0.0f);
		//glColor3f(0.4f, 0.4f, 0.4f);
		glTexCoord2f(0,1);
		glVertex3f(-19.0f, 0.0f, 12.0f);
		glTexCoord2f(0,0);
		glVertex3f(-19.0f, 0.0f, 8.0f);
		glTexCoord2f(1,0);
		glVertex3f(-20.0f, 0.0f, 8.0f);
		glTexCoord2f(1,1);
		glVertex3f(-20.0f, 0.0f, 12.0f);
	}
	//sufit
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, -1.0f, 0.0f);
		//glColor3f(0.8f, 0.8f, 0.8f);
		glTexCoord2f(0,1);
		glVertex3f(-20.0f, 2.0f, 12.0f);
		glTexCoord2f(0,0);
		glVertex3f(-20.0f, 2.0f, 8.0f);
		glTexCoord2f(1,0);
		glVertex3f(-19.0f, 2.0f, 8.0f);
		glTexCoord2f(1,1);
		glVertex3f(-19.0f, 2.0f, 12.0f);
	}
	//lewa
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		//glColor3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0,0);
		glVertex3f(-19.0f, 2.0f, 12.0f);
		glTexCoord2f(1,0);
		glVertex3f(-19.0f, 2.0f, 8.0f);
		glTexCoord2f(1,1);
		glVertex3f(-19.0f, 0.0f, 8.0f);
		glTexCoord2f(0,1);
		glVertex3f(-19.0f, 0.0f, 12.0f);
	}
	//prawa
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(1.0f, 0.0f, 0.0f);
		//glColor3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(1,1);
		glVertex3f(-20.0f, 0.0f, 12.0f);
		glTexCoord2f(0,1);
		glVertex3f(-20.0f, 0.0f, 8.0f);
		glTexCoord2f(0,0);
		glVertex3f(-20.0f, 2.0f, 8.0f);
		glTexCoord2f(1,0);
		glVertex3f(-20.0f, 2.0f, 12.0f);
	}
	//tylnia
	/*{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, 1.0f);
		//glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-20.0f, 2.0f, 8.0f);
		glVertex3f(-20.0f, 0.0f, 8.0f);
		glVertex3f(-19.0f, 0.0f, 8.0f);
		glVertex3f(-19.0f, 2.0f, 8.0f);
	}
	//przednia
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 1.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, -1.0f);
		//glColor3f(0.6f, 0.6f, 0.6f);
		glVertex3f(-20.0f, 0.0f, 12.0f);
		glVertex3f(-20.0f, 2.0f, 12.0f);
		glVertex3f(-19.0f, 2.0f, 12.0f);
		glVertex3f(-19.0f, 0.0f, 12.0f);
	}*/

	glEnd();

}
void skarbiec() {
	glEnable(GL_TEXTURE_2D);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	TextureManager::getInstance()->BindTexture("mur");
	glBegin(GL_QUADS);
	{
		// Pod³oga
		//glColor3f(0.4f, 0.4f, 0.4f);
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 0.0f, 0.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0,1);
		glVertex3f(6.0f, 0.0f, 35.0f);
		glTexCoord2f(0,0);
		glVertex3f(6.0f, 0.0f, 30.0f);
		glTexCoord2f(1,0);
		glVertex3f(-4.0f, 0.0f, 30.0f);
		glTexCoord2f(1,1);
		glVertex3f(-4.0f, 0.0f, 35.0f);
	}
	{//sufit
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 0.0f, 0.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, -1.0f, 0.0f);
		//glColor3f(0.8f, 0.8f, 0.8f);
		glTexCoord2f(0,1);
		glVertex3f(-4.0f, 2.0f, 35.0f);
		glTexCoord2f(0,0);
		glVertex3f(-4.0f, 2.0f, 30.0f);
		glTexCoord2f(1,0);
		glVertex3f(6.0f, 2.0f, 30.0f);
		glTexCoord2f(1,1);
		glVertex3f(6.0f, 2.0f, 35.0f);
	}
	{//lewa
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 0.0f, 0.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		//glColor3f(0.0f, 1.0f, 0.0f);
		glTexCoord2f(0, 0);
		glVertex3f(6.0f, 2.0f, 35.0f);
		glTexCoord2f(1,0);
		glVertex3f(6.0f, 2.0f, 30.0f);
		glTexCoord2f(1,1);
		glVertex3f(6.0f, 0.0f, 30.0f);
		glTexCoord2f(0,1);
		glVertex3f(6.0f, 0.0f, 35.0f); 
	}
	{//prawa
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 0.0f, 0.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(1.0f, 0.0f, 0.0f);
		//glColor3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(1,1);
		glVertex3f(-4.0f, 0.0f, 35.0f);
		glTexCoord2f(0, 1);
		glVertex3f(-4.0f, 0.0f, 30.0f);
		glTexCoord2f(0,0);
		glVertex3f(-4.0f, 2.0f, 30.0f);
		glTexCoord2f(1,0);
		glVertex3f(-4.0f, 2.0f, 35.0f); 
	}
	{//tylnia
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 0.0f, 0.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, 1.0f);
		//glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(1,1);
		glVertex3f(2.0f, 2.0f, 30.0f);
		glTexCoord2f(0,1);
		glVertex3f(2.0f, 0.0f, 30.0f);
		glTexCoord2f(0,0);
		glVertex3f(6.0f, 0.0f, 30.0f);
		glTexCoord2f(1,0);
		glVertex3f(6.0f, 2.0f, 30.0f);
	}
		{float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 0.0f, 0.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, 1.0f);
		//glColor3f(1.0f, 1.0f, 1.0f);
		glTexCoord2f(1,1);
		glVertex3f(-4.0f, 2.0f, 30.0f);
		glTexCoord2f(0,1);
		glVertex3f(-4.0f, 0.0f, 30.0f);
		glTexCoord2f(0,0);
		glVertex3f(0.0f, 0.0f, 30.0f);
		glTexCoord2f(1,0);
		glVertex3f(0.0f, 2.0f, 30.0f);
	}
	{//przednia
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 1.0f, 0.0f, 0.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, -1.0f);
		//glColor3f(0.6f, 0.6f, 0.6f);
		glTexCoord2f(1,1);
		glVertex3f(-4.0f, 0.0f, 35.0f);
		glTexCoord2f(0,1);
		glVertex3f(-4.0f, 2.0f, 35.0f);
		glTexCoord2f(0,0);
		glVertex3f(6.0f, 2.0f, 35.0f);
		glTexCoord2f(1,0);
		glVertex3f(6.0f, 0.0f, 35.0f);
	}
	glEnd();

	if (abs(player->pos.x - jajo->pos.x) <= 0.4 && abs(player->pos.z - jajo->pos.z) <= 0.4) {
		if (jajo->isAlive == true) {
			player->zycie = player->maxZycie;
			player->monety += 100;
			player->wyjscie_otw = true;
		}
			jajo->isAlive = false;
	}
}
void wyjscie() {
	glEnable(GL_TEXTURE_2D);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	TextureManager::getInstance()->BindTexture("mur");
	glBegin(GL_QUADS);
	// Pod³oga
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 0.0f, 0.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 1.0f, 0.0f);
		//glColor3f(0.4f, 0.4f, 0.4f);
		glTexCoord2f(0,1);
		glVertex3f(-10.0f, 0.0f, 8.0f);
		glTexCoord2f(0,0);
		glVertex3f(-10.0f, 0.0f, 3.0f);
		glTexCoord2f(1,0);
		glVertex3f(-20.0f, 0.0f, 3.0f);
		glTexCoord2f(1,1);
		glVertex3f(-20.0f, 0.0f, 8.0f);
	}
	//sufit
	//glColor3f(0.8f, 0.8f, 0.8f);
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 0.0f, 0.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, -1.0f, 0.0f);
		glTexCoord2f(0,1);
		glVertex3f(-20.0f, 2.0f, 8.0f);
		glTexCoord2f(0,0);
		glVertex3f(-20.0f, 2.0f, 3.0f);
		glTexCoord2f(1,0);
		glVertex3f(-10.0f, 2.0f, 3.0f);
		glTexCoord2f(1,1);
		glVertex3f(-10.0f, 2.0f, 8.0f);
	}
	//lewa
	//glColor3f(0.0f, 1.0f, 0.0f);
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 0.0f, 0.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(-1.0f, 0.0f, 0.0f);
		glTexCoord2f(0,0);
		glVertex3f(-10.0f, 2.0f, 8.0f);
		glTexCoord2f(1,0);
		glVertex3f(-10.0f, 2.0f, 3.0f);
		glTexCoord2f(1,1);
		glVertex3f(-10.0f, 0.0f, 3.0f);
		glTexCoord2f(0,1);
		glVertex3f(-10.0f, 0.0f, 8.0f); 
	}
	//prawa
	//glColor3f(1.0f, 0.0f, 0.0f);
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 0.0f, 0.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(1.0f, 0.0f, 0.0f);
		glTexCoord2f(1,1);
		glVertex3f(-20.0f, 0.0f, 8.0f);
		glTexCoord2f(0,1);
		glVertex3f(-20.0f, 0.0f, 3.0f);
		glTexCoord2f(0,0);
		glVertex3f(-20.0f, 2.0f, 3.0f);
		glTexCoord2f(1,0);
		glVertex3f(-20.0f, 2.0f, 8.0f);
	}
	//tylnia
	//glColor3f(1.0f, 1.0f, 1.0f);
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 0.0f, 0.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(1,1);
		glVertex3f(-20.0f, 2.0f, 3.0f);
		glTexCoord2f(0,1);
		glVertex3f(-20.0f, 0.0f, 3.0f);
		glTexCoord2f(0,0);
		glVertex3f(-10.0f, 0.0f, 3.0f);
		glTexCoord2f(1,0);
		glVertex3f(-10.0f, 2.0f, 3.0f);
	}
	//przednia
	//glColor3f(0.6f, 0.6f, 0.6f);
	{
		float ambient[] = { 0.0f, 0.0f, 0.0f };
		float diffuse[] = { 0.0f, 0.0f, 1.0f };
		float specular[] = { 0.0f, 0.0f, 0.0f };

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);

		glNormal3f(0.0f, 0.0f, -1.0f);
		glTexCoord2f(1,1);
		glVertex3f(-19.0f, 0.0f, 8.0f);
		glTexCoord2f(0,1);
		glVertex3f(-19.0f, 2.0f, 8.0f);
		glTexCoord2f(0,0);
		glVertex3f(-10.0f, 2.0f, 8.0f);
		glTexCoord2f(1,0);
		glVertex3f(-10.0f, 0.0f, 8.0f);
	}
	glEnd();

	if (abs(player->pos.x - (-15)) <= 0.4 && abs(player->pos.z -3 ) <= 0.4) {
		if (player->wyjscie_otw == true) {
			glutLeaveMainLoop();
		}
	}
}
void OnMouseClick(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		printf("MYSZ!!!\n");//dzia³a
		//if (player->energy >= 5)
		//{
			Sphere* newSphere = new Sphere(player->pos+ player->dir*3, vec3(0, 0, 1), 0.1, 2,theta);
			newSphere->force = player->dir *0.00000000001f;
			//player->energy -= 5;
			newSphere->radiusChangePerUpdate = -0.005f;
			scene.AddObject(newSphere);
		//}
	}
}