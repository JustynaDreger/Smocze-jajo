#pragma once
#include "SceneObject.h"
class Moneta :
	public SceneObject
{
public:
	Moneta(vec3 pos, std::string textureName = "");
	~Moneta(); 
	
	void Render();
	void Update();

	int wart = 1;

	int k = 1;
	int czy = 0;
	std::string textureName;
};

