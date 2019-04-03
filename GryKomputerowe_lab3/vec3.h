#pragma once

class vec3
{
public:
	vec3(void);
	vec3(float x, float y, float z);
	~vec3(void);

	vec3 operator+(vec3 v);
	vec3 operator-(vec3 v);
	vec3 operator*(float v);
//	vec3 operator-(vec3 v);
	float x, y, z;
};