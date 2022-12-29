#include <Novice.h>
#include "Player.h"
#include "Bullet.h"

PLAYER::PLAYER() 
{

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
	isFlay_ = 0;
	isMove_ = 0;
	isPlayerAlive_ = 1;
	isPlayerDie_ = 0;
	isExplosion_[16] = { 0 };
	isFall_ = 0;

	//ライフ
	playerLifePosX_[3] = { 0 };
	playerLifePosY_[3] = { 0 };
	playerDieSrcX_ = 0;
	playerDieSrcY_ = 0;
	deathPosX_;
	deathPosY_;
	playerLife_ = 3;

}

void PLAYER::Update(char* keys, char* preKeys)
{

	///---------- プレイヤー操作 ----------///

	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && isPlayerAlive_)
	{
		isMove_ = true;
	}

	if (isMove_ && isPlayerAlive_)
	{
		//プレイヤーのX座標とスクロール値に速度を足す
		player_.pos.x += player_.vel.x;
		player_.scr += player_.vel.x;
	}

	for (int i = 0; i <= 2; i++)
	{
		playerLifePosX_[i] = player_.monitor - player_.radius * 1.5;
		playerLifePosY_[i] = player_.pos.y - player_.radius * 2;
	}

	player_.monitor = player_.pos.x - player_.scr;//posX - scrXでmonitorXを出す

	// スクロール値固定
	if (player_.scr > 11000)
	{
		player_.scr = 11000;
	}

	/*if (player_.scr > 11000 && stage == 2)
	{
		player_.scr = 11000;
	}

	if (player_.scr > 10240 && stage == 3)
	{
		player_.scr = 10240;
	}

	if (player_.pos.x >= 9000 && stage == 3 )
	{
		player_.pos.x = 9000;
		if (player_.scr >= 8700)
		{
			player_.vel.x = 0;
		}
	}
	if (!isBossAlive && player_.pos.x >= 9000 && stage == 3)
	{
		player_.vel.x = 3;
	}*/
	// 重力加速度を常に初期化する
	player_.acc.y = -0.6f;

	// スペースを押してジャンプ
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && isPlayerAlive_ && isMove_)
	{
		player_.vel.y = 15.0f;
		isFlay_ = true;
	}

	// 加速度や速度、位置の計算を行う
	if (isFlay_ && isPlayerAlive_ && isMove_)
	{
		// ボールの速度に加速度を足す
		player_.vel.y += player_.acc.y;

		// ボールの位置に速度を引く
		player_.pos.y -= player_.vel.y;
	}

	//画面外に出ようとすると、跳ね返りが発生する
	if (player_.pos.y - player_.radius < 0)
	{
		player_.vel.y = 0;
		// 重力加速度を初期化する
		player_.acc.y = -2.8f;

		// ボールの速度に加速度を足す
		player_.vel.y += player_.acc.y;

		// ボールの位置に速度を引く
		player_.pos.y -= player_.vel.y;
	}

	///---------- ここまでプレイヤー操作----------///

}

void PLAYER::Draw() {
	Novice::ScreenPrintf(0, 0, "%f", player_.pos.x);
	Novice::ScreenPrintf(0, 20, "%f", player_.scr);
	Novice::ScreenPrintf(0, 40, "%f", player_.monitor);
	/*Novice::DrawBox(0 - player_.scr, 0, 1280, 720, 0, RED, kFillModeSolid);
	Novice::DrawBox(1280 - player_.scr, 0, 1280, 720, 0, BLUE, kFillModeSolid);
	Novice::DrawBox(1280 * 2 - player_.scr, 0, 1280, 720, 0, GREEN, kFillModeSolid);
	Novice::DrawBox(1280 * 3 - player_.scr, 0, 1280, 720, 0, BLACK, kFillModeSolid);*/
	//プレイヤー
	if (isPlayerAlive_)
	{
		Novice::DrawEllipse(player_.monitor, player_.pos.y, player_.radius, player_.radius, 0.0f, player_.color, kFillModeSolid);
		//Novice::DrawSpriteRect(player_.monitor - player_.radius * 2, player_.pos.y - player_.radius * 1.6, player_.src.x, player_.src.y, 256, 256, playerHundle, 0.15, 0.4, 0, WHITE);
		if (!isMove_)
		{
			if (playerLife_ >= 3)
			{
				Novice::DrawEllipse(playerLifePosX_[2] + 40 * 2, playerLifePosY_[2], 20, 20, 0, WHITE, kFillModeSolid);
				//Novice::DrawSprite(playerLifePosX_[2] + 70, playerLifePosY_[2] - 20 * 2, playerLifeHundle, 0.45, 0.45, 0, WHITE);
			}
			if (playerLife_ >= 2)
			{
				Novice::DrawEllipse(playerLifePosX_[1] + 40 * 1, playerLifePosY_[1], 20, 20, 0, WHITE, kFillModeSolid);
				//Novice::DrawSprite(playerLifePosX[1] + 18, playerLifePosY[1] - 20 * 2, playerLifeHundle, 0.45, 0.45, 0, WHITE);
			}
			if (playerLife_ >= 1)
			{
				Novice::DrawEllipse(playerLifePosX_[0] + 40 * 0, playerLifePosY_[0], 20, 20, 0, WHITE, kFillModeSolid);
				//Novice::DrawSprite(playerLifePosX[0] - 36, playerLifePosY[0] - 20 * 2, playerLifeHundle, 0.45, 0.45, 0, WHITE);
			}
		}
	}
}