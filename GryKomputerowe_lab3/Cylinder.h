#pragma once
#include "SceneObject.h"
class Cylinder :
	public SceneObject
{
public:
	Cylinder(vec3 pos, vec3 color, float r, float h, float slides);
	~Cylinder();

	void Render();
	void Update();

	vec3 color;
	float radius;
	float height;
	float slides;
};

