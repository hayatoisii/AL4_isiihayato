#pragma once
#include "KamataEngine.h" 
#include "Player.h"
using namespace KamataEngine;

class GameScene {
public: 

	GameScene();
	~GameScene();

	void Initialize();
	void Update();
	void Draw();

private:
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	// KamataEngine::
	uint32_t textureHandle_ = 0;

	Sprite* sprite_ = nullptr;
	Model* model_ = nullptr;

	WorldTransform worldTransform_;
	Camera camera_;

	Player* player_ = nullptr;

};