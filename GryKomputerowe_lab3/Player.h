#pragma once
#include "SceneObject.h"
class Player :
	public SceneObject
{
public:
	Player();
	~Player();

	void Render();
	void Update();
	//void renderBitmapString(float x, float y, char* text);
	vec3 dir;
	float speed;

	float velocity_vertical;
	float velocity_horizontal;

	int zycie;
	int maxZycie = 20;
	int monety=0;
	bool wyjscie_otw = false;
};

