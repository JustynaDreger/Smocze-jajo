#pragma once
#include "SceneObject.h"
class Bron :
	public SceneObject
{
public:
	Bron(float x, float y, float z, std::string textureName = "");
	~Bron();
	void Render();
	void Update();
	std::string textureName;
};

