#include "stdafx.h"
#include "Moneta.h"
using namespace std;


Moneta::Moneta(vec3 pos1, std::string textureName)
{
	pos = pos1;
	this->diffuse = vec3(1,0,0);
	this->textureName = textureName;
}


Moneta::~Moneta()
{
}

void Moneta::Render() {
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

	float height = 0.05;
	int slides = 24;
	float radius =0.1 ;
	//glColor3f(1, 1, 0);
	glPushMatrix();
	glTranslatef(pos.x, pos.y + 0.5, pos.z);
	glRotatef(90, 0.0f, 0.0f, 1.0f);
	glRotatef(k, 1.0f, 0.0f, 0.0f);
	// Górna podstawa
	glBegin(GL_TRIANGLE_FAN);
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0, 0);
	glVertex3f(0.0f, height, 0.0f);
	//glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	//slides - na ile dzielimy ko³o
	for (int i = 0; i <= slides; i++)
	{
		glTexCoord2f(0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f);
		glVertex3f(radius * sin(float(i) * 2 * PI / float(slides)), height, radius * cos(float(i) * 2 * PI / float(slides)));
	}
	glTexCoord2f(0,0);
	glVertex3f(radius, height, 0);
	glEnd();

	// Dolna podstawa
	glBegin(GL_TRIANGLE_FAN);
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0, 0);
	glVertex3f(0.0f, -height, 0.0f);
	//glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	for (int i = slides; i >= 0; i--)
	{
		glTexCoord2f(0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f);
		glVertex3f(radius * sin(float(i) * 2 * PI / float(slides)), -height, radius * cos(float(i) * 2 * PI / float(slides)));
	}
	glTexCoord2f(0, 0);
	glVertex3f(radius, height, 0);
	glEnd();

	// Œciany boczne
	glBegin(GL_TRIANGLE_STRIP);
	//glColor3f(1, 1, 1);
	//glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
	for (int i = 0; i <= slides; i++)
	{
		const float tc = (i / (float)(2 * PI));
		glTexCoord2f(tc, 0.0);
		glNormal3f(sin(float(i) * 2 * PI / float(slides)), 0, cos(float(i) * 2 * PI / float(slides)));
		glVertex3f(radius * sin(float(i) * 2 * PI / float(slides)), height, radius * cos(float(i) * 2 * PI / float(slides)));
		glTexCoord2f(tc, 1.0);
		glVertex3f(radius * sin(float(i) * 2 * PI / float(slides)), -height, radius * cos(float(i) * 2 * PI / float(slides)));
	}
	glTexCoord2f(0.0, 0.0);
	glVertex3f(radius, 0, 0);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(radius, height, 0);
	glEnd();
	glPopMatrix();
}

void Moneta::Update(){
	if (czy = 0) {
		k = k + 1;
		if (k >= 90) {
			czy = 1;
		}
	}
	else {
		k = k - 1;
		if (k <= 1) { czy = 0;}
	}
}