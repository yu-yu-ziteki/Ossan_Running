#include "Food.h"
#include "Engine/Model.h"
Food::Food(GameObject* parent)
	:GameObject(parent, "Food"), type_(FOODTYPE_NORMAL), hModel_(-1), score_(0)
{
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
		score_ += 1;
	}
	else if (type_ == foodType::FOODTYPE_POWER)
	{
		hModel_ = Model::Load("Enemy.fbx");
		score_ += 5;
	}


}

void Food::onCollision(GameObject* pTarget)
{
}
