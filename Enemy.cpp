#include <Novice.h>
#include "Enemy.h"

ENEMY::ENEMY()
{
	player = new PLAYER;
	pipe = new PIPE;
	for (int i = 5; i < 16; i++)
	{
		enemyColor_[i] = WHITE;
		isEnemyAlive_[i] = true;
		enemyPosX_[i] = (pipe->GetBoxX(i) + 750.0f * i) + pipe->GetBoxW() / 2.0f;
		enemyPosY_[i] = pipe->GetBoxH(i) + 150.0f;
		enemySpeed_[i] = 3.0f;
		enemyLife_[i] = 3;
	}

}

void ENEMY::Update(char* keys, char* preKeys)
{
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && player->IsMove() == 0)
	{
		player->SetIsMove(true);
	}

	if (player->IsMove() == 1)
	{

		enemyScr += player->GetVel().x;

	}

	for (int i = 5; i < 16; i++)
	{
		//敵サークルの可動域
		if (isEnemyAlive_[i] && player->IsMove() == 1)
		{
			enemyPosY_[i] -= enemySpeed_[i];
			if (enemyPosY_[i] + enemyRadius_ >= pipe->GetBoxH(i) + 320 || enemyPosY_[i] - enemyRadius_ <= pipe->GetBoxH(i))
			{
				enemySpeed_[i] = -enemySpeed_[i];
				break;
			}
		}
	}

}

void ENEMY::Draw()
{
	Novice::ScreenPrintf(0, 100, "%f", enemyPosX_[5]);
	Novice::ScreenPrintf(0, 120, "%f", enemyPosY_[5]);
	Novice::ScreenPrintf(0, 140, "%d", isEnemyAlive_[5]);
	Novice::ScreenPrintf(0, 160, "%d", enemyLife_[5]);

	//敵サークル
	for (int i = 5; i < 16; i++)
	{
		if (isEnemyAlive_[i] && enemyLife_[i] > 0)
		{
			Novice::DrawEllipse(enemyPosX_[i] - enemyScr, enemyPosY_[i], enemyRadius_, enemyRadius_, 0.0f, enemyColor_[i], kFillModeSolid);
			//Novice::DrawSpriteRect(enemyPosX_[i] - enemyScr - enemyRadius_ * 1.2, enemyPosY_[i] - enemyRadius_ / 0.84, enemySrcX_, enemySrcY_, 400, 400, enemyCircle_[i] = Novice::LoadTexture("./enemyCircle.png"), 0.06, 0.3, 0, enemyColor_[i]);
		}
		/*if (!isEnemyAlive_[i] && isExplosion_[i])
		{
			Novice::DrawSpriteRect(enemyP_osX_[i] - player.scr - enemyRadius_ * 1.9, enemyPosY_[i] - enemyRadius_ / 0.94, explosionSrcX_[i], explosionSrcY_, 400, 400, explosion[i] = Novice::LoadTexture("./Explosion1.png"), 0.06, 0.3, 0, WHITE);
		}*/
	}

}