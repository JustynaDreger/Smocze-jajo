#pragma once

class Scene
{
public:
	Scene(void);
	~Scene(void);

	void Render();
	void Update();
	void HeadUpDisplay();
	void Koniec();
	struct HUD
	{
		float zycie;
		float maxZycie;
		float monety;
	}hud;
	void AddObject(SceneObject* object);
	void UsunOb(SceneObject* object);
private:

	std::vector<SceneObject*> sceneObjects;
};

