#pragma once
#include "SceneObject.h"
// Klasa pozwalaj¹ca wczytanie obiektu 3D w postaci pliku OBJ.
// Takie pliki mo¿na wygenerowaæ w popularnych programach do tworzenia modeli 3D, np. Blender
// Polecana alternatywa : ASSIMP
class Model3D :
	public SceneObject
{
public:
	Model3D(vec3 pos, vec3 color, std::string textureName = "");
	~Model3D();

	bool load(std::string filepath);

	void Render();
	void Update();

	vec3 color;

	vec3 modelTranslation;

	std::vector<vec3> vertices;
	std::vector<vec3> normals;
	std::string textureName;
};

