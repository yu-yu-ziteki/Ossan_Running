#pragma once
#include "Engine/GameObject.h"
class MovingFloor :
    public GameObject


{
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	MovingFloor(GameObject* parent);
	//初期化
	void Initialize() override;
	//更新
	void Update() override;
	//描画
	void Draw() override;
	//開放
	void Release() override;

	void SetPosition(XMFLOAT3 pos) {
		transform_.position_ = pos;
		startPos_ = pos;
	}
	float GetDeltaX() const { return deltaX_; }
private:
	int hModel_;
	XMFLOAT3 startPos_; // 移動の基準になる初期位置
	float moveTimer_;   // 往復運動用のタイマー
	float deltaX_;


};