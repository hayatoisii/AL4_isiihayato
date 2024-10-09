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

	Player* player_ = nullptr;
	Vector3 playerPos = {};

	Model* modelPlayer_ = nullptr;

	//std::vector<std::vector<WorldTransform*>> worldTransformBlocks_;
	Camera camera_;

	bool isDebugCameraActive_ = false;
	// デバックカメラ
	DebugCamera* debugCamera_ = nullptr;

};