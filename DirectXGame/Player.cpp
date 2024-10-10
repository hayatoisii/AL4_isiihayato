#include "Player.h"
#include <cassert>
#include <algorithm>

Player::~Player() {
	model_ = nullptr;
	camera_ = nullptr;
	modelbullet_ = nullptr;
	bullet_ = nullptr;
}

void Player::Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const Vector3& pos) {

	assert(model);
	model_ = model;
	camera_ = camera;
	modelbullet_ = KamataEngine::Model::CreateFromOBJ("cube", true);
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

	// キャラクターの攻撃処理
	Attack();

	// 弾更新
	if (bullet_) {
		bullet_->Update();
	}

	ImGui::Begin("Setmove");
	ImGui::SliderFloat("Move X", &worldtransfrom_.translation_.x, -1.0f, 1.0f);
	ImGui::SliderFloat("Move Y", &worldtransfrom_.translation_.y, -1.0f, 1.0f);
	ImGui::End();

	worldtransfrom_.UpdateMatarix();

}

void Player::Attack() {

	if (input_->TriggerKey(DIK_SPACE)) {

		if (bullet_) {
			delete bullet_;
			bullet_ = nullptr;
		}

		Vector3 moveBullet = {0, 0, 0};

		moveBullet = worldtransfrom_.translation_;

		// 弾を生成し、初期化
		PlayerBullet* newBullet = new PlayerBullet();
		newBullet->Initialize(modelbullet_, moveBullet);

		// 弾を登録する
		bullet_ = newBullet;
	}
}

void Player::Draw() { 

	model_->Draw(worldtransfrom_, *camera_);

	// 弾描画
	if (bullet_) {
		bullet_->Draw(*camera_);
	}
}