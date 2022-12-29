#include <Novice.h>
#include "Pipe.h"

PIPE::PIPE() {

	////ステージ0＆1 ブロック
	//boxX_[100] = { 750 };
	//boxY_[100] = { 0 };
	//boxH_[100] = { 200, 200, 100, 300, 100, 275, 0, 0,
	//					100, 200, 300, 150, 250, 350, 325, 225 };
	//boxW_ = 150;

	////ブロック(下段)
	//boxDownX_[100] = { 0 };
	//boxDownY_[100] = { 0 };
	//boxDownH_[100] = { -200, -200, -300, -100, -300, -125, 0, 0,
	//						-300, -200, -100, -250, -150, -50, -75, -175 };

	player = new PLAYER;
	
}

PIPE::~PIPE()
{
	
}

void PIPE::Update(char* keys, char* preKeys)
{

	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0 && player->IsMove() == 0)
	{
		player->SetIsMove(true);
	}

	if (player->IsMove() == 1)
	{

		boxScr += player->GetVel().x;

	}

}

void PIPE::Draw()
{
	Novice::ScreenPrintf(0, 60, "%f", boxScr);
	//ブロック
	for (int i = 1; i < 16; i++)
	{
		Novice::DrawBox(boxX_[i] + 750 * i - boxScr, boxY_[i], boxW_, boxH_[i], 0.0f, WHITE, kFillModeSolid);
		Novice::DrawBox(boxDownX_[i] + 750 * i - boxScr, boxDownY_[i] + 720, boxW_, boxDownH_[i], 0.0f, WHITE, kFillModeSolid);
		//Novice::DrawSprite(boxX_[i] - 20 + 750 * i - player->GetScr(), boxY_[i], block_Stage0_[i] = Novice::LoadTexture("./block_Stage0.png"), 1.22, boxH[i] / 280, 0, WHITE);
		//Novice::DrawSprite(boxDownX_[i] - 20 + 750 * i - player->GetScr(), boxDownY_[i] + 720, block_Stage0_[i] = Novice::LoadTexture("./block_Stage0.png"), 1.22, boxDownH[i] / 280, 0, WHITE);

	}


}