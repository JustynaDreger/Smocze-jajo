#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	pos.x = 0.0f;
	pos.y = 0.0f;
	pos.z = 0.2f;

	dir.x = 0.0f;
	dir.y = 0.0f;
	dir.z = 1.0f;

	speed = .05f;

	velocity_horizontal = 0;
	velocity_vertical = 0;
	zycie = 20;
}


Player::~Player()
{
}

void Player::Render()
{

}

void Player::Update()
{
	pos.x += dir.x * speed * velocity_vertical;
	pos.z += dir.z * speed * velocity_vertical;

	pos.x += dir.z * speed * velocity_horizontal;
	pos.z -= dir.x * speed * velocity_horizontal;


	pos.y = 0.5;

	velocity_vertical /= 1.2;
	velocity_horizontal /= 1.2;
	///
	//if (zycie == 0) isAlive = false;
	if (zycie > maxZycie)
		zycie = maxZycie;
	if (zycie == 0) {
		glutLeaveMainLoop();
	}
}