#pragma once
#include "Player.h"
#include "Pipe.h"
#include <Novice.h>

class ENEMY
{

private:

	//�G�T�[�N��
	float enemyPosX_[16] = { 0 };
	float enemyPosY_[16] = { 0 };
	float enemyRadius_ = 50;
	float enemySrcX_ = 0;
	float enemySrcY_ = 0;
	float enemySpeed_[16] = { 0 };
	int enemyColor_[16];
	float enemyScr = 0;

	//�t���O
	bool isEnemyAlive_[16] = { 0 };

	//���C�t
	int enemyLife_[16] = { 0 };

	//�e�N�X�`��
	int enemyCircle_[16];

	PLAYER* player;
	PIPE* pipe;

public:

	//�s������
	void Update(char* keys, char* preKeys);

	//�`��
	void Draw();

	ENEMY();

	~ENEMY();

};

