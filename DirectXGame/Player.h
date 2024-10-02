#pragma once
#include "KamataEngine.h"
using namespace KamataEngine;

class Player {
public:
	void Initialize(Model* model, uint32_t textureHandle, Camera* Camera);
	void Update();
	void Draw();

private:
	WorldTransform worldtransfrom_;

	Model* model_ = nullptr;
	
	Camera* camera_ = nullptr;

	uint32_t textureHandle_ = 0u;

};