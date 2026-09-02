#pragma once
#include "Engine/GameObject.h"

class Ground;//前方宣言

class Player :
	public GameObject
{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Player(GameObject* parent);
	//初期化
	void Initialize() override;
	//更新
	void Update() override;
	//描画
	void Draw() override;
	//開放
	void Release() override;
	void SetGround(Ground* ground) {
		ground_ = ground;
	}
	void OnCollision(GameObject* pTarget) override;
	//void AddScore(int value) { score_ += value; }
	int GetScore() { return score_; }
	int GetLife() { return life_; }
private:
	int hWalkModel_;//歩きアニメーションのモデルハンドル
	int hIdleModel_;//待機アニメーションのモデルハンドル
	Ground* ground_;//地面オブジェクトのポインタ
	int score_ = 0;
	int life_ = 5;
	float invTimer_ = 0;
	float jumpVelocity_ = 0.0f; 
	bool isJump_ = false;       

};