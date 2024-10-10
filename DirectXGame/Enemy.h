#pragma once
#include <3d/Model.h>
#include <3d/WorldTransform.h>
#include <3d/Camera.h>

enum class Phase {
	Approach, // 接近する
	Leave,    // 離脱する
};

class Enemy {
public:

	void Initialize(KamataEngine::Model* model, KamataEngine::Camera* camera, const KamataEngine::Vector3& pos);
	void Update();
	void Draw();
	~Enemy();

private:

	KamataEngine::WorldTransform worldtransfrom_;
	KamataEngine::Model* model_ = nullptr;
	KamataEngine::Camera* camera_ = nullptr;

	Phase phase_ = Phase::Approach;

};
