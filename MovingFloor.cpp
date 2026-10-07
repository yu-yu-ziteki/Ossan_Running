#include "MovingFloor.h"
#include "Engine/Model.h"
#include <cmath>
#include "Engine/BoxCollider.h"
using namespace std;

MovingFloor::MovingFloor(GameObject* parent)
	:GameObject(parent, "MovingFloor"), hModel_(-1), moveTimer_(0.0f), startPos_({ 0, 0, 0 })
{
	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1.0f, 0.7f, 1.0f));
	AddCollider(collision);
}

void MovingFloor::Initialize()
{
	hModel_ = Model::Load("BrickG.fbx");
}

void MovingFloor::Update()
{
	float oldX = transform_.position_.x;

	moveTimer_ += 0.03f;

	transform_.position_.x = startPos_.x + sin(moveTimer_) * 2.0f;
	deltaX_ = transform_.position_.x - oldX;
}

void MovingFloor::Draw()
{
	Transform blockTransform;
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void MovingFloor::Release()
{
}
