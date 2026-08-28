#include "OverScene.h"
#include "Engine/Text.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

namespace {
	int count = 0;
}

OverScene::OverScene(GameObject* parent)
	:GameObject(parent, "OverScene"), hModel_(0)
{
}

void OverScene::Initialize()
{
	pText_ = new Text;
	pText_->Initialize();
}

void OverScene::Update()
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

void OverScene::Draw()
{
	count = count % 100;
	std::string scrText = "ReTray to Space...!";
	if (count <= 50) {
		pText_->Draw(550, 350, scrText.c_str());
	}
}

void OverScene::Release()
{
	pText_->Release();
}
