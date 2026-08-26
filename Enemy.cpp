#include "Enemy.h"
#include "Engine/Model.h"
#include "Ground.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(0)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Enemy.fbx");
	transform_.position_ = { 3,0,-1 };
	transform_.scale_ = { 0.6,0.6,0.6 };
	Ground* ground = (Ground*)FindObject("Ground");
	 mapData_ = ground->GetMapData();
}

void Enemy::Update()
{
	static float jumpAngle = 0.0f;
	jumpAngle += 0.02f;

	
	if (jumpAngle <= 3.14f) 
	{
		transform_.position_.y = -6.0f + sin(jumpAngle) * 6.0f; 
	}
	else
	{
		jumpAngle = 0.0f; 
		transform_.position_.y = -2.0f; 
	}
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}
