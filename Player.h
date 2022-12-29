#pragma once
#include "Struct.h"
#include "Bullet.h"
#include <Novice.h>

class PLAYER
{
private:
	//プレイヤー情報
	Player player_ =
	{
		{500.0f, 100.0f},
		{6.0f, 2.0f},
		{0, -0.3f },
		0.0f,
		0.0f,
		{0, 0},
		30.0f,
		WHITE
	};


	//フラグ
	bool isFlay_ = 0;
	bool isMove_ = 0;
	bool isPlayerAlive_ = 1;
	bool isPlayerDie_ = 0;
	bool isExplosion_[16] = { 0 };
	bool isExplosion_Stage2_[16] = { 0 };
	bool isFall_ = 0;

	//ライフ
	int playerLifePosX_[3] = { 0 };
	int playerLifePosY_[3] = { 0 };
	float playerDieSrcX_ = 0;
	float playerDieSrcY_ = 0;
	float deathPosX_;
	float deathPosY_;
	int playerLife_ = 3;

public:

	//行動処理
	void Update(char* keys, char* preKeys);

	//ゲッター
	Vector2 GetPos()
	{
		return player_.pos;
	}

	float GetMonitor()
	{
		return player_.monitor;
	}

	float GetScr()
	{
		return player_.scr;
	}

	bool IsMove()
	{
		return isMove_;
	}

	Vector2 GetVel()
	{
		return player_.vel;
	}

	//セッター

	void SetIsMove(bool isMove)
	{
		this->isMove_ = isMove;
	}

	void SetScr(Vector2 vel)
	{
		this->player_.scr += vel.x;
	}

	//描画
	void Draw();

	//コンストラクタの宣言
	PLAYER();

	//デストラクタの宣言
	~PLAYER();

};

