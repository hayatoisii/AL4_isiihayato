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
	const float kCharacterSpeed = 0.3f;

	move.z -= kCharacterSpeed;

	worldtransfrom_.translation_.x += move.x;
	worldtransfrom_.translation_.y += move.y;
	worldtransfrom_.translation_.z += move.z;

	worldtransfrom_.UpdateMatarix();
}

void Enemy::Draw() {

	model_->Draw(worldtransfrom_, *camera_);

}
