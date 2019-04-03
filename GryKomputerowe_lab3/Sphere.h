#pragma once

#include "SceneObject.h"

class Sphere : public SceneObject
{
public:
	Sphere(vec3 pos, vec3 color, float radius, float weight,float dir);
	~Sphere(void);

	void Render();
	void Update();

	float radius;
	float weight;
	vec3 force;
	float dir;
	float radiusChangePerUpdate;
	std::string textureName;
};
