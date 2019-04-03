#pragma once

#define PI 3.14159265359

class SceneObject
{
public:
	SceneObject(void);
	~SceneObject(void);

	vec3 pos;
	bool isAlive;
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	vec3 force;
	float weight;
	float radius;
	virtual void Render() = 0;
	virtual void Update() = 0;
};

