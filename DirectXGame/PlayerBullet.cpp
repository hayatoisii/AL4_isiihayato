#include "PlayerBullet.h"
#include <cassert>
#include "base/TextureManager.h"

void PlayerBullet::Initialize(KamataEngine::Model* model, const KamataEngine::Vector3& position) { 
	
	assert(model);
	model_ = model;
	// テクスチャ読み込み
	textureHandle_ = TextureManager::Load("sample.png");
	worldtransfrom_.translation_ = position;
	worldtransfrom_.Initialize();

}

void PlayerBullet::Update() {

	worldtransfrom_.UpdateMatarix();

}

void PlayerBullet::Draw(const KamataEngine::Camera& camera) {

	// モデルの描画
	model_->Draw(worldtransfrom_, camera, textureHandle_);

}
