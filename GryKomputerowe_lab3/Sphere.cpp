#include "stdafx.h"
#include "Sphere.h"


Sphere::Sphere(vec3 pos, vec3 color, float radius, float weight,float dir)
{
	this->pos = pos;
	this->diffuse = color;
	this->radius = radius;
	this->weight = weight;
	this->dir = dir;
	radiusChangePerUpdate = 0;
	//this->textureName = textureName;
}


Sphere::~Sphere(void)
{
}

void Sphere::Render()
{
	/*if (!textureName.empty())
	{
		//w³¹czenie tekstury
		glEnable(GL_TEXTURE_2D);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		TextureManager::getInstance()->BindTexture(textureName);
	}*/
	glMaterialfv(GL_FRONT, GL_AMBIENT, &ambient.x);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, &diffuse.x);
	glMaterialfv(GL_FRONT, GL_SPECULAR, &specular.x);

	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	glutSolidSphere(radius, 24, 24);
	glPopMatrix();
	/*
	glColor3f(0.0f, 1.0f, 0.0f);
	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	//glRotatef(dir, 0.0f, 1.0f, 0.0f); POPRAWIÆ
	glutSolidCone(.05f, 0.1f, 14, 14);
	glTranslatef(0, 0, -0.07f);
	glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	glScalef(1.5f, 0.5f, 0.5f);
	glutSolidCube(0.1f);
	glPopMatrix();*/
}

void Sphere::Update()
{
	pos.x += force.x / weight;
	pos.y += force.y / weight;
	pos.z += force.z / weight;

	force.x /= 1.2;
	force.y /= 1.2;
	force.z /= 1.2;

	radius += radiusChangePerUpdate;

	if (radius <= 0)
	{
		isAlive = false;
	}
}
