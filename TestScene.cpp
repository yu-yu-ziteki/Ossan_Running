#include "TestScene.h"
#include "Player.h"
#include "Ground.h"
#include "Engine/Camera.h"
#include "Engine/Text.h"
#include "food.h"
#include "Engine/SceneManager.h"
#include"Enemy.h"


//コンストラクタ
TestScene::TestScene(GameObject* parent)
	: GameObject(parent, "TestScene"), time(0)
{
}

//初期化
void TestScene::Initialize()
{
	//pWp = Instantiate<Weapon>(this);
	Player* pPlayer = Instantiate <Player>(this);
	Ground* pGround = Instantiate<Ground>(this);
	Enemy* enemy = Instantiate<Enemy>(this);
	pPlayer->SetGround(pGround);

	Camera::SetPosition({ 0,10,-20 });
	Camera::SetTarget({ 0,0,0 });

	pText_ = new Text;
	pText_ -> Initialize();
}

//更新
void TestScene::Update()
{
	Player* player = (Player*)FindObject("Player");
	life = player->GetLife();
	static int frameCount = 0;
	frameCount++;
	if (frameCount % 60 <= 0) {
		time++;
	}
	Food* food = (Food*)FindObject("Food");
	{
		if (food == nullptr)
		{
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			if (pSceneManager != nullptr)
			{
				pSceneManager->ChangeScene(SCENE_ID_CLEAR);
			}
		}
	}
	if (life <= 0)
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");

		if (pSceneManager != nullptr)
		{
			pSceneManager->ChangeScene(SCENE_ID_OVER);
		}
	}
}

//描画
void TestScene::Draw()
{
	Player* pPlayer = (Player*)FindObject("Player");
	if (pPlayer != nullptr)
	{
		score = pPlayer->GetScore();
	}

	std::string scrText = "SCORE: " + std::to_string(score);
	pText_->Draw(20, 20, scrText.c_str());
	std::string timeText = "TIME: " + std::to_string(time);
	pText_->Draw(20, 60, timeText.c_str());
	std::string lifeText = "LIFE: " + std::to_string(life);
	pText_->Draw(20, 100, lifeText.c_str());
}

//開放
void TestScene::Release()
{
	pText_->Release();//テキスト開放
}