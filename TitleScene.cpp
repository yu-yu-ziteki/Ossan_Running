#include "TitleScene.h"
#include "Engine/Text.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

namespace {
	int count = 0;
}

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent, "TitleScene"), hModel_(0)
{
}

void TitleScene::Initialize()
{
	pText_ = new Text;
	pText_->Initialize();
}

void TitleScene::Update()
{
	count++;
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		if (pSceneManager != nullptr)
		{
			pSceneManager->ChangeScene(SCENE_ID_TEST);
		}
	}
}

void TitleScene::Draw()
{
	count = count % 100;
	std::string scrText = "Play to Space!";
	if (count <= 50) {
		pText_->Draw(550, 350, scrText.c_str());
	}
}

void TitleScene::Release()
{
	pText_->Release();
}
