#include "Enemy.h"
#include "Engine/Model.h"
#include "Ground.h"
#include "Engine/SphereCollider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(0)
{
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0),0.8f);
	AddCollider(collision);
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Enemy.fbx");
	transform_.position_ = { 3,0,-1 };
	transform_.scale_ = { 0.6f,0.6f,0.6f };
	jumpAngle = (float)(rand() % 100);
}

void Enemy::Update()
{
	jumpAngle += 0.02f;

	
	if (jumpAngle <= 3.14f) 
	{
		transform_.position_.y = -6.0f + sin(jumpAngle) * 6.0f; 
	}
	else
	{
		jumpAngle = 0.0f; 
		transform_.position_.y =-2.0f; 
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
