#pragma once
#include "SceneObject.h"
class Wrog :
	public SceneObject
{
public:
	Wrog();
	Wrog(float x, float z, float s, char kierunek, std::string textureName = "");
	~Wrog();
	void Render();
	void Update();
	
	float speed;
	char k;
	int j= 0;//do animacji
	bool czy = 1;
	//do ataku
	int live = 3;
	vec3 teraz;
	std::string textureName;
};

