#pragma once
#include "PlayerBullet.h"
#include <list>
#include <KamataEngine.h>
using namespace KamataEngine;

namespace KamataEngine { class Input; };


class Player {
public:
	void Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const Vector3& pos);
	void Update();
	void Draw();
	~Player();

	void Attack();

private:
	
	WorldTransform worldtransfrom_;

	Model* model_ = nullptr;

	Input* input_ = nullptr;
	
	Camera* camera_ = nullptr;

	Model* modelbullet_ = nullptr;

	// 弾
	//PlayerBullet* bullet_ = nullptr;
	std::list<PlayerBullet*> bullets_;

};