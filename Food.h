#pragma once
#include "Engine/GameObject.h"

enum foodType {
    FOODTYPE_NORMAL,
    FOODTYPE_POWER,
    FOODTYE_MAX

};
class Food :
    public GameObject
{
public:
    Food(GameObject* parent);
    ~Food();
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;
    void SetFoodType(foodType type);
    void onCollision(GameObject* pTarget);
    foodType GetFoodType() { return type_; }
    
private:
    foodType type_;
    int hModel_;

};

