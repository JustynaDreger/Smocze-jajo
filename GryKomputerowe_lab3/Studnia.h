#pragma once
#include "SceneObject.h"
class Studnia :
	public SceneObject
{
public:
	Studnia(std::string textureName = "");
	~Studnia();

	void Render();
	void Update();
	std::string textureName;
};

