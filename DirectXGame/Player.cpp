#include "Player.h"
#include <cassert>
#include <algorithm>

Player::~Player() {
	model_ = nullptr;
	camera_ = nullptr;
}

void Player::Attack() {

	if (/*/発射キーをトリガーしたら/*/) {
	
		// 弾を生成し、初期化
		PlayerBullet* newBullet = new PlayerBullet();
		newBullet->Initialize(model_, )
	}

}

void Player::Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const Vector3& pos) {

	assert(model);
	model_ = model;
	camera_ = camera;
	worldtransfrom_.translation_ = pos;
	input_ = Input::GetInstance();
	worldtransfrom_.Initialize();

}

void Player::Update() {
	// キャラクターの移動ベクトル
	Vector3 move = {0, 0, 0};

	// キャラクターの移動速さ
	const float kCharacterSpeed = 0.3f;
	// 回転速さ[ラジアン/frame]
	const float kRotSpeed = 0.02f;

	// 押した方向で移動ベクトルを変更(左右)
	if (input_->PushKey(DIK_LEFT)) {
		move.x -= kCharacterSpeed;
	} else if (input_->PushKey(DIK_RIGHT)) {
		move.x += kCharacterSpeed;
	}

	// 押した方向で移動ベクトルを変更(上下)
	if (input_->PushKey(DIK_UP)) {
		move.y += kCharacterSpeed;
	} else if (input_->PushKey(DIK_DOWN)) {
		move.y -= kCharacterSpeed;
	}

	// 押した方向で移動ベクトルを変更
	if (input_->PushKey(DIK_A)) {
		worldtransfrom_.rotation_.y += kRotSpeed;
	} else if (input_->PushKey(DIK_D)) {
		worldtransfrom_.rotation_.y -= kRotSpeed;
	}


	worldtransfrom_.translation_.x += move.x;
	worldtransfrom_.translation_.y += move.y;

	const float kMoveLimitX = 30;
	const float kMoveLimitY = 15;

	worldtransfrom_.translation_.x = std::clamp(worldtransfrom_.translation_.x, -kMoveLimitX, kMoveLimitX);
	worldtransfrom_.translation_.y = std::clamp(worldtransfrom_.translation_.y, -kMoveLimitY, kMoveLimitY);

	ImGui::Begin("Setmove");
	ImGui::SliderFloat("Move X", &worldtransfrom_.translation_.x, -1.0f, 1.0f);
	ImGui::SliderFloat("Move Y", &worldtransfrom_.translation_.y, -1.0f, 1.0f);
	ImGui::End();

	worldtransfrom_.UpdateMatarix();

}

void Player::Draw() { 

	model_->Draw(worldtransfrom_, *camera_);

}