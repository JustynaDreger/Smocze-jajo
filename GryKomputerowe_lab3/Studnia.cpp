#include "stdafx.h"
#include "Studnia.h"


Studnia::Studnia(std::string textureName)
{
	this->textureName = textureName;
}


Studnia::~Studnia()
{
}

void Studnia::Render() {
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

	float height = 0.5;
	int slides = 24;
	float radius = 0.1;
	//glColor3f(0, 0, 1);
	glPushMatrix();
	glTranslatef(2, 0.5, 3);
	//glRotatef(90, 0.0f, 0.0f, 1.0f);
	//glRotatef(90 + i, 1.0f, 0.0f, 0.0f);
	// Górna podstawa
	glBegin(GL_TRIANGLE_FAN);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, height, 0.0f);
	//glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	//slides - na ile dzielimy ko³o
	for (int i = 0; i <= slides; i++)
	{
		glVertex3f(radius * sin(float(i) * 2 * PI / float(slides)), height, radius * cos(float(i) * 2 * PI / float(slides)));
	}
	glEnd();

	// Dolna podstawa
	glBegin(GL_TRIANGLE_FAN);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, -height, 0.0f);
	//glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	for (int i = slides; i >= 0; i--)
	{
		glVertex3f(radius * sin(float(i) * 2 * PI / float(slides)), -height, radius * cos(float(i) * 2 * PI / float(slides)));
	}
	glEnd();

	// Œciany boczne
	glBegin(GL_TRIANGLE_STRIP);
	//glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	for (int i = 0; i <= slides; i++)
	{
		glNormal3f(sin(float(i) * 2 * PI / float(slides)), 0, cos(float(i) * 2 * PI / float(slides)));
		glVertex3f(radius * sin(float(i) * 2 * PI / float(slides)), height, radius * cos(float(i) * 2 * PI / float(slides)));
		glVertex3f(radius * sin(float(i) * 2 * PI / float(slides)), -height, radius * cos(float(i) * 2 * PI / float(slides)));
	}
	glEnd();
	glPopMatrix();

}
void Studnia::Update() {}