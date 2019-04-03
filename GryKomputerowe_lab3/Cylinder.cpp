#include "stdafx.h"
#include "Cylinder.h"


Cylinder::Cylinder(vec3 pos, vec3 color, float r, float h, float slides)
{
	this->pos = pos;
	this->color = color;
	this->radius = r;
	this->height = h;
	this->slides = slides;
}


Cylinder::~Cylinder()
{
}

void Cylinder::Render()
{
	//glColor3f(color.x, color.y,color.z);
	glPushMatrix();
	glTranslatef(pos.x, pos.y + 0.5, pos.z);
	glRotatef(90, 0.0f, 0.0f, 1.0f);
	//glRotatef(k, 0.0f, 1.0f, 0.0f);
	// Górna podstawa
	glBegin(GL_TRIANGLE_FAN);
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
		glVertex3f(radius * sin(float(i) * 2 * PI / float(slides)), height, radius * cos(float(i) * 2 * PI / float(slides)));
		glVertex3f(radius * sin(float(i) * 2 * PI / float(slides)), -height, radius * cos(float(i) * 2 * PI / float(slides)));
	}
	glEnd();
	glPopMatrix();
}

void Cylinder::Update()
{
	
}