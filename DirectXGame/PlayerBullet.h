#pragma once
#include <3d/Model.h>
#include <3d/Camera.h>
#include <3d/WorldTransform.h>
class PlayerBullet {
public:

	void Initialize(KamataEngine::Model* model, const KamataEngine::Vector3& position);

	void Update();

	void Draw(const KamataEngine::Camera& camera);

	~PlayerBullet();

private:

	KamataEngine::WorldTransform worldtransfrom_;

	KamataEngine::Model* model_ = nullptr;

	uint32_t textureHandle_ = 0; 

};
