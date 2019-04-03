#include "stdafx.h"
#include "Bron.h"


Bron::Bron(float x, float y, float z, std::string textureName)
{
	pos.x = x;
	pos.y = y;
	pos.z = z;
	this->textureName = textureName;
}


Bron::~Bron()
{
}
void Bron::Render() {
	if (!textureName.empty())
	{
		//w³¹czenie tekstury
		glEnable(GL_TEXTURE_2D);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
		TextureManager::getInstance()->BindTexture(textureName);
	}
	float size = 0.1;
	//glColor3f(1,0, 1);
	glMaterialfv(GL_FRONT, GL_AMBIENT, &ambient.x);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, &diffuse.x);
	glMaterialfv(GL_FRONT, GL_SPECULAR, &specular.x);

	glPushMatrix();

	glTranslatef(pos.x, pos.y, pos.z);

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
void Bron::Update() {
	
}