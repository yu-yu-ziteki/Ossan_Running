#include "Ground.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"
#include "Player.h"
#include "Food.h"
#include "Enemy.h"

namespace
{
	using std::vector;
	int model_t = -1;
	int foodModel_ = -1;
}

Ground::Ground(GameObject* parent)
	:GameObject(parent, "Ground"), hModel_(-1), mapWidth_(-1), mapHeight_(-1)
{
	CsvReader csvData;
	csvData.Load("map2D.csv");

	mapWidth_ = csvData.GetWidth();
	mapHeight_ = csvData.GetHeight();

	mapData_ = std::vector<std::vector<int>>(mapHeight_, std::vector<int>(mapWidth_, 0));

	for (int y = 0; y < mapHeight_; y++)
	{
		for (int x = 0; x < mapWidth_; x++)
		{
			mapData_[y][x] = csvData.GetValue(x, y);
		}
	}
}

void Ground::Initialize()
{
	hModel_ = Model::Load("jimen3.fbx");
	model_t = Model::Load("BrickG.fbx");
	ftr.scale_ = { 0.5,0.5,0.5 };
}

void Ground::Update()
{
}

void Ground::Draw()
{
	for (int y = 0; y < mapHeight_; y++)
	{
		for (int x = 0; x < mapWidth_; x++)
		{
			if (mapData_[y][x] == 1)
			{
				Transform blockTransform;

				blockTransform.position_ = {(float)x, -(float)y + 12, 0.5f};
				blockTransform.scale_ = { 1.0f, 1.0f, 1.0f };
				Model::SetTransform(model_t, blockTransform);
				Model::Draw(model_t);
			}
		}
	}
}

void Ground::Release()
{
}