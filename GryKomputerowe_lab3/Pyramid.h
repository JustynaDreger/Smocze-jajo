#pragma once
#include "SceneObject.h"
class Pyramid :
	public SceneObject
{
public:
	Pyramid(vec3 pos, vec3 color, float bazeSize, float height);
	~Pyramid();

	void Render();
	void Update();

	vec3 color;
	float baseSize;
	float height;
};

