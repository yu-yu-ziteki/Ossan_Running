#pragma once
#include "Engine/GameObject.h"

class Text;
//テストシーンを管理するクラス
class Enemy : public GameObject
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Enemy(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

private:
	int hModel_;
	std::vector<std::vector<int>> mapData_;
};