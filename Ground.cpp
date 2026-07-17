#include "Ground.h"
#include "Engine/Model.h"
#include "Engine/CsvReader.h"
#include "Player.h"
#include "Food.h"


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
	csvData.Load("map.csv");

	mapWidth_ = csvData.GetWidth();
	mapHeight_ = csvData.GetHeight();

	mapData_ = vector<vector<int>>(mapHeight_ / 2, vector<int>(mapWidth_, 0));

	for (int x = 0; x < mapWidth_; x++) {
		for (int y = 0;y < mapHeight_ / 2;y++) {
			mapData_[y][x] = csvData.GetValue(x, y);
		}
	}
	objmap_ = vector<vector<int>>(mapHeight_ / 2, vector<int>(mapWidth_, 0));
	for (int x = 0; x < mapWidth_; x++) {
		for (int y = 0; y < mapHeight_ / 2; y++) {

			objmap_[y][x] = csvData.GetValue(x, y + (mapHeight_ / 2));

			if (objmap_[y][x] == 1 || objmap_[y][x] == 2) {
				Food* food = Instantiate<Food>(this);

				food->SetPosition({ -9.0f + x * 2.0f, 0.0f, 9.0f - y * 2.0f });

				if (objmap_[y][x] == 1) {
					food->SetFoodType(foodType::FOODTYPE_NORMAL);
				}
				else if (objmap_[y][x] == 2) {
					food->SetFoodType(foodType::FOODTYPE_POWER);
				}
			}
		}
	}
}

void Ground::Initialize()
{
	hModel_ = Model::Load("jimen3.fbx");
	model_t = Model::Load("BrickV.fbx");
	ftr.scale_ = { 0.5,0.5,0.5 };
}

void Ground::Update()
{
}

void Ground::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
	for (int j = 0;j < 10;j++) {
		for (int i = 0;i < 10;i++) {
			if (mapData_[j][i] == 1) {
				Transform tr;
				tr.position_ = { -9.0f + i * 2.0f, 0.0f, 9.0f - j * 2.0f };
				Model::SetTransform(model_t, tr);
				Model::Draw(model_t);
			}

		}
	}


}

void Ground::Release()
{
}