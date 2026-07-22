#include "Food.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Engine/Debug.h"

Food::Food(GameObject* parent)
	:GameObject(parent, "Food"), type_(FOODTYPE_NORMAL), hModel_(-1)
	{
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0, 0), 1.2f);
	AddCollider(collision);
}

Food::~Food()
{
}

void Food::Initialize()
{
	transform_.scale_ = {0.3f, 0.3f,0.3f};

	
}

void Food::Update()
{

}

void Food::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Food::Release()
{
}

void Food::SetFoodType(foodType type)
{
	type_ = type;
	if (type_ == foodType::FOODTYPE_NORMAL)
	{
		hModel_ = Model::Load("food.fbx");

	}
	else if (type_ == foodType::FOODTYPE_POWER)
	{
		hModel_ = Model::Load("Enemy.fbx");

	}


}

void Food::onCollision(GameObject* pTarget)
{

}
