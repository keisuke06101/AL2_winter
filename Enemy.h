#pragma once
#include "Player.h"
#include "Pipe.h"
#include <Novice.h>

class ENEMY
{

private:

	//敵サークル
	float enemyPosX_[16] = { 0 };
	float enemyPosY_[16] = { 0 };
	float enemyRadius_ = 50;
	float enemySrcX_ = 0;
	float enemySrcY_ = 0;
	float enemySpeed_[16] = { 0 };
	int enemyColor_[16];
	float enemyScr = 0;

	//フラグ
	bool isEnemyAlive_[16] = { 0 };

	//ライフ
	int enemyLife_[16] = { 0 };

	//テクスチャ
	int enemyCircle_[16];

	PLAYER* player;
	PIPE* pipe;

public:

	//行動処理
	void Update(char* keys, char* preKeys);

	//描画
	void Draw();

	ENEMY();

	~ENEMY();

};

