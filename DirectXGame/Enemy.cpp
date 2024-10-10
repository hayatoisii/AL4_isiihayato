#include "Enemy.h"
#include <cassert>

Enemy::~Enemy() {

	delete modelbullet_;
	for (EnemyBullet* bullet : bullets_) {
		delete bullet;
	}
}

void Enemy::Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& pos) {
	assert(model);
	model_ = model;
	camera_ = camera;
	modelbullet_ = KamataEngine::Model::CreateFromOBJ("cube", true);
	worldtransfrom_.translation_ = pos;
	worldtransfrom_.Initialize();
}

void Enemy::Fire() {

	KamataEngine::Vector3 moveBullet = {0, 0, 0};

	moveBullet = worldtransfrom_.translation_;

	// 弾の速度
	const float kBulletSpeed = 1.0f;
	KamataEngine::Vector3 velocity(0, 0, kBulletSpeed);

	// 弾を生成し、初期化
	EnemyBullet* newBullet = new EnemyBullet();
	newBullet->Initialize(modelbullet_, moveBullet, velocity);

	// 弾を登録する
	bullets_.push_back(newBullet);
}

void Enemy::Bulletaccess() {
	// 発射タイマーを初期化
	spawnTimer = kFireInterval;
	
	spawnTimer--;

	if (spawnTimer < 0.0f) {
		// 弾を発射
		Fire();
		spawnTimer = kFireInterval;
	}
}

void Enemy::Update() {

	// キャラクターの移動ベクトル
	KamataEngine::Vector3 move = {0, 0, 0};
	
	// 接近
	KamataEngine::Vector3 accessSpeed = {0.3f,0.3f,0.3f};
	// 離脱
	KamataEngine::Vector3 eliminationSpeed = {0.3f, 0.3f, 0.3f};

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
		//worldtransfrom_.translation_.y += eliminationSpeed.y;
		break;

	}


	worldtransfrom_.UpdateMatarix();
}

void Enemy::Draw() {

	model_->Draw(worldtransfrom_, *camera_);

}
