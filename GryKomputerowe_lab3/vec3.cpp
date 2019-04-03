#include "stdafx.h"
#include "vec3.h"


vec3::vec3(void)
{
}

vec3::vec3(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}


vec3::~vec3(void)
{
}
vec3 vec3::operator+(vec3 v)
{
	vec3 newV;

	newV.x = x + v.x;
	newV.y = y + v.y;
	newV.z = z + v.z;

	return newV;
}

vec3 vec3::operator-(vec3 v)
{
	vec3 newV;

	newV.x = x - v.x;
	newV.y = y - v.y;
	newV.z = z - v.z;

	return newV;
}

vec3 vec3::operator*(float v)
{
	vec3 newV;

	newV.x = x * v;
	newV.y = y * v;
	newV.z = z * v;

	return newV;
}
