#pragma once
#include "Player.h"
#include <Novice.h>

class PIPE
{

private:

	//ステージ0＆1 ブロック
	float boxX_[100] = { 750.0f };
	float boxY_[100] = { 0.0f };
	float boxH_[100] = { 200.0f, 200.0f, 100.0f, 300.0f, 100.0f, 275.0f, 0.0f, 0.0f,
						100.0f, 200.0f, 300.0f, 150.0f, 250.0f, 350.0f, 325.0f, 225.0f };
	float boxW_ = 150.0f;

	//ブロック(下段)
	float boxDownX_[100] = { 0.0f };
	float boxDownY_[100] = { 0.0f };
	float boxDownH_[100] = { -200.0f, -200.0f, -300.0f, -100.0f, -300.0f, -125.0f, 0.0f, 0.0f,
							-300.0f, -200.0f, -100.0f, -250.0f, -150.0f, -50.0f, -75.0f, -175.0f };

	float boxScr = 0.0f;

	PLAYER* player;

public:

	void Update(char* keys, char* preKeys);

	void Draw();

	//ゲッター
	float GetBoxX(int i)
	{
		return boxX_[i];
	}

	float GetBoxY(int i)
	{
		return boxY_[i];
	}

	float GetBoxH(int i)
	{
		return boxH_[i];
	}

	float GetBoxW()
	{
		return boxW_;
	}

	//セッター


	//
	PIPE();

	~PIPE();

};

