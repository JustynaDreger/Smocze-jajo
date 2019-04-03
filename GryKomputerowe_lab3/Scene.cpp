#include "stdafx.h"
#include "Scene.h"


Scene::Scene(void)
{
}


Scene::~Scene(void)
{
	for(unsigned int i = 0 ; i < sceneObjects.size() ; i++)
		delete sceneObjects[i];

	sceneObjects.clear();
}

void Scene::AddObject(SceneObject* object)
{
	sceneObjects.push_back(object);
}
void Scene::UsunOb(SceneObject* object) {
	sceneObjects.pop_back();

}
void renderBitmapString(float x, float y, char* text) {
	char *c;
	glRasterPos3f(x, y, 0);
	for (c = text; *c != '\0'; c++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}

void Scene::HeadUpDisplay()
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
	glDisable(GL_LIGHTING);
	glDisable(GL_CULL_FACE);

	glBegin(GL_QUADS);
	
	
	
	glColor3f(1, 0, 0);
	glVertex2f(2, 97);
	glVertex2f(2, 95);
	glVertex2f(2 + 30 * (hud.zycie / hud.maxZycie), 95);
	glVertex2f(2 + 30 * (hud.zycie / hud.maxZycie), 97);

	glColor3f(0, 0, 0);
	glVertex2f(2 + 30 * (hud.zycie / hud.maxZycie), 97);
	glVertex2f(2 + 30 * (hud.zycie / hud.maxZycie), 95);
	glVertex2f(32, 95);
	glVertex2f(32, 97);

	glColor3f(0, 0.3, 0);
	glVertex2f(1, 98);
	glVertex2f(1, 94);
	glVertex2f(33, 94);
	glVertex2f(33, 98);
	glEnd();


	char text[50];
	sprintf(text, "%d monet", (int)hud.monety);

	glColor3f(0, 0, 0);
	renderBitmapString(3, 85, text);

	glEnable(GL_LIGHTING);
	glEnable(GL_CULL_FACE);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}
//nie dzia³a
void Scene::Koniec()
{
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, 100, 0, 100);
	glDisable(GL_LIGHTING);
	glDisable(GL_CULL_FACE);

	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);
	glVertex2f(2, 97);
	glVertex2f(2, 95);
	glVertex2f(2 + 30 * (hud.zycie / hud.maxZycie), 95);
	glVertex2f(2 + 30 * (hud.zycie / hud.maxZycie), 97);

	glColor3f(0, 0, 0);
	glVertex2f(2 + 30 * (hud.zycie / hud.maxZycie), 97);
	glVertex2f(2 + 30 * (hud.zycie / hud.maxZycie), 95);
	glVertex2f(32, 95);
	glVertex2f(32, 97);

	glColor3f(0, 0.3, 0);
	glVertex2f(1, 98);
	glVertex2f(1, 94);
	glVertex2f(33, 94);
	glVertex2f(33, 98);
	glEnd();

	char text[50];
	sprintf(text, "%d monet", (int)hud.monety);

	glColor3f(0, 0, 0);
	renderBitmapString(90, 95, text);

	//glEnable(GL_LIGHTING);
	glEnable(GL_CULL_FACE);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}
void Scene::Render()
{
	for(unsigned int i = 0 ; i < sceneObjects.size() ; i++)
		sceneObjects[i]->Render();

}

void Scene::Update()
{
	for(unsigned int i = 0 ; i < sceneObjects.size() ; i++)
		sceneObjects[i]->Update();

	for (std::vector<SceneObject*>::iterator it = sceneObjects.begin(); it != sceneObjects.end();)
	{
		if ((*it)->isAlive)
		{
			it++;
		}
		else
		{
			it = sceneObjects.erase(it);
		}
	}
}
