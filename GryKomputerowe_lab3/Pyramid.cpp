#include "stdafx.h"
#include "Pyramid.h"


Pyramid::Pyramid(vec3 pos, vec3 color, float baseSize, float height)
{
	this->pos = pos;
	this->color = color;
	this->baseSize = baseSize;
	this->height = height;
}


Pyramid::~Pyramid()
{
}

void Pyramid::Render()
{
	//glColor3f(color.x, color.y, color.z);

	glPushMatrix();

	glTranslatef(pos.x, pos.y, pos.z);

	// Podstawa
	glBegin(GL_QUADS);
		glVertex3f(-baseSize / 2, 0, -baseSize / 2);
		glVertex3f( baseSize / 2, 0, -baseSize / 2);
		glVertex3f( baseSize / 2, 0,  baseSize / 2);
		glVertex3f(-baseSize / 2, 0,  baseSize / 2);
	glEnd();

	// Œciany boczne
	glBegin(GL_TRIANGLES);
		
		glVertex3f( baseSize / 2, 0, -baseSize / 2);
		glVertex3f(-baseSize / 2, 0, -baseSize / 2);
		glVertex3f(0, height, 0);

		glVertex3f(-baseSize / 2, 0,  baseSize / 2);
		glVertex3f( baseSize / 2, 0,  baseSize / 2);
		glVertex3f(0, height, 0);

		glVertex3f(-baseSize / 2, 0, -baseSize / 2);
		glVertex3f(-baseSize / 2, 0,  baseSize / 2);
		glVertex3f(0, height, 0);

		glVertex3f( baseSize / 2, 0,  baseSize / 2);
		glVertex3f( baseSize / 2, 0, -baseSize / 2);
		glVertex3f(0, height, 0);
	
		
	glEnd();

	glPopMatrix();
}

void Pyramid::Update()
{

}