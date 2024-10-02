#include "Player.h"
#include <cassert>

void Player::Initialize(Model* model, uint32_t textureHandle, Camera* camera) { 

	model_ = model;
	camera_ = camera;
	textureHandle_ = textureHandle;
	worldtransfrom_.Initialize();
}

void Player::Update() { worldtransfrom_.TransferMatrix(); }

void Player::Draw() { 

	model_->Draw(worldtransfrom_, *camera_, textureHandle_);

}