#include "Enemy.h"
#include <cassert>

Enemy::~Enemy() {}

void Enemy::Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& pos) {
	assert(model);
	model_ = model;
	camera_ = camera;
	worldtransfrom_.translation_ = pos;
	worldtransfrom_.Initialize();
}

void Enemy::Update() {

	// キャラクターの移動ベクトル
	KamataEngine::Vector3 move = {0, 0, 0};

	// キャラクターの移動速さ
	//const float kCharacterSpeed = 0.3f;
	
	// 接近
	KamataEngine::Vector3 accessSpeed = {0.3f,0.3f,0.3f};
	// 離脱
	KamataEngine::Vector3 eliminationSpeed = {0.3f, 0.3f, 0.3f};

	//worldtransfrom_.translation_.x += move.x;
	//worldtransfrom_.translation_.y += move.y;
	//worldtransfrom_.translation_.z += move.z;

	switch (phase_) { 
	case Phase::Approach:
	default:
		// 移動(ベクトルを加算)
		worldtransfrom_.translation_.z -= accessSpeed.z;
		// 規定の位置に到達したら離脱
		if (worldtransfrom_.translation_.z < 0.0f) {
			phase_ = Phase::Leave;
		}
		break;
	case Phase::Leave:
		// 移動(ベクトルを加算)
		worldtransfrom_.translation_.y += eliminationSpeed.y;
		break;

	}


	worldtransfrom_.UpdateMatarix();
}

void Enemy::Draw() {

	model_->Draw(worldtransfrom_, *camera_);

}
