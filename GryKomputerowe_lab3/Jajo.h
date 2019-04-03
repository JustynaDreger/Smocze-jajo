#pragma once
#include "SceneObject.h"
class Jajo :
	public SceneObject
{
public:
	Jajo(vec3 pos, std::string textureName = "");
	~Jajo();
	std::string textureName;
	void Render();
	void Update();
};

