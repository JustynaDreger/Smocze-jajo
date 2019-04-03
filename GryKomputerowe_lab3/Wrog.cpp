#include "stdafx.h"
#include "Wrog.h"


Wrog::Wrog()
{
}

//kierunek P - prawo L - lewo G - góra D - dó³  w któr¹ stronê bêdzie siê poruszaæ

Wrog::Wrog(float x, float z, float s, char kierunek, std::string textureName) {
	pos.x = x;
	//zmieniæ na 0 przy wstawianiu modelu!!!
	pos.y = 0.3;
	pos.z = z;
	speed = s;
	k = kierunek;
	teraz = pos;
	this->diffuse = vec3(1, 1,1);
	this->textureName = textureName;
}
Wrog::~Wrog()
{
}
void Wrog::Render()
{
	if (!textureName.empty())
	{
		//w³¹czenie tekstury
		glEnable(GL_TEXTURE_2D);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		TextureManager::getInstance()->BindTexture(textureName);
	}
	glMaterialfv(GL_FRONT, GL_AMBIENT, &ambient.x);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, &diffuse.x);
	glMaterialfv(GL_FRONT, GL_SPECULAR, &specular.x);

	float size = 0.1;
	//glColor3f(0,1,0);

	glPushMatrix();

	if (k == 'L') {
		glTranslatef(pos.x + j*0.1, pos.y, pos.z);
		teraz.x = pos.x + j * 0.1;
	}
	if (k == 'P') {
		glTranslatef(pos.x - j * 0.1, pos.y, pos.z);
		teraz.x = pos.x - j * 0.1;
	}
	if (k == 'G') {
		glTranslatef(pos.x, pos.y, pos.z + j * 0.1);
		teraz.z = pos.z + j * 0.1;
	}
	if (k == 'D') {
		glTranslatef(pos.x, pos.y, pos.z - j * 0.1);
		teraz.z = pos.z - j * 0.1;
	}

	//glTranslatef(pos.x, pos.y, pos.z);

	glBegin(GL_QUADS);

	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0, 1);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glTexCoord2f(0, 0);
	glVertex3f(size / 2, -size / 2, size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(-size / 2, -size / 2, -size / 2);

	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0, 1);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glTexCoord2f(0, 0);
	glVertex3f(-size / 2, size / 2, size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(size / 2, size / 2, size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(size / 2, size / 2, -size / 2);

	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0, 0);
	glVertex3f(-size / 2, -size / 2, -size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glTexCoord2f(1, 1);
	glVertex3f(-size / 2, size / 2, size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-size / 2, size / 2, -size / 2);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(1, 1);
	glVertex3f(size / 2, size / 2, -size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(size / 2, size / 2, size / 2);
	glTexCoord2f(0, 0);
	glVertex3f(size / 2, -size / 2, size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(size / 2, -size / 2, -size / 2);

	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(1, 1);
	glVertex3f(-size / 2, size / 2, -size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(size / 2, size / 2, -size / 2);
	glTexCoord2f(0, 0);
	glVertex3f(size / 2, -size / 2, -size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(-size / 2, -size / 2, -size / 2);

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(1, 1);
	glVertex3f(size / 2, size / 2, size / 2);
	glTexCoord2f(0, 1);
	glVertex3f(-size / 2, size / 2, size / 2);
	glTexCoord2f(0, 0);
	glVertex3f(-size / 2, -size / 2, size / 2);
	glTexCoord2f(1, 0);
	glVertex3f(size / 2, -size / 2, size / 2);
	glEnd();

	glPopMatrix();
}

void Wrog::Update()
{

	if (czy == 1) {
		j = j + 1;
		if (j >= 15) czy = 0;
	}
	else {
		j = j - 1;
		if (j <= 0) czy = 1;
	}
	
	///
	//if (live == 0) isAlive = false;
}