#include "stdafx.h"
#include "Cube.h"


Cube::Cube(vec3 pos, vec3 color, float size)
{
	this->pos = pos;
	this->color = color;
	this->size = size;
}


Cube::~Cube()
{
}

void Cube::Render()
{
	//glColor3f(color.x, color.y, color.z);

	glPushMatrix();

		glTranslatef(pos.x, pos.y, pos.z);

		glBegin(GL_QUADS);

			// dolna �ciana
			glVertex3f( size / 2, -size / 2, -size / 2);
			glVertex3f( size / 2, -size / 2,  size / 2);
			glVertex3f(-size / 2, -size / 2,  size / 2);
			glVertex3f(-size / 2, -size / 2, -size / 2);

			// g�rna �ciana
			glVertex3f(-size / 2,  size / 2, -size / 2);
			glVertex3f(-size / 2,  size / 2,  size / 2);
			glVertex3f( size / 2,  size / 2,  size / 2);
			glVertex3f( size / 2,  size / 2, -size / 2);

			// lewa �ciana
			glVertex3f(-size / 2, -size / 2, -size / 2);
			glVertex3f(-size / 2, -size / 2,  size / 2);
			glVertex3f(-size / 2,  size / 2,  size / 2);
			glVertex3f(-size / 2,  size / 2, -size / 2);

			// prawo �ciana
			glVertex3f( size / 2,  size / 2, -size / 2);
			glVertex3f( size / 2,  size / 2,  size / 2);
			glVertex3f( size / 2, -size / 2,  size / 2);
			glVertex3f( size / 2, -size / 2, -size / 2);

			// tylna �ciana
			glVertex3f(-size / 2,  size / 2, -size / 2);
			glVertex3f( size / 2,  size / 2, -size / 2);
			glVertex3f( size / 2, -size / 2, -size / 2);
			glVertex3f(-size / 2, -size / 2, -size / 2);

			// przednia �ciana
			glVertex3f( size / 2,  size / 2,  size / 2);
			glVertex3f(-size / 2,  size / 2,  size / 2);
			glVertex3f(-size / 2, -size / 2,  size / 2);
			glVertex3f( size / 2, -size / 2,  size / 2);

		glEnd();

	glPopMatrix();
}

void Cube::Update()
{

}