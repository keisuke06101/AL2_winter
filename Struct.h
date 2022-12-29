#pragma once

typedef struct Vector2
{

	float x;
	float y;

};

struct Player              //�v���C���[�\����
{
	Vector2 pos;           //�{�[���̈ʒu
	Vector2 vel;           //�{�[���̑��x
	Vector2 acc;           //�{�[���̉����x
	float scr;             //�X�N���[���l   
	float monitor;         //���j�^�[���W
	Vector2 src;           //�A�j���[�V�����X�N���[��
	float radius;          //�{�[���̔��a
	unsigned int color;    //�{�[���̐F
};

struct Bullet              //�e�̍\����
{
	Vector2 pos;
	Vector2 vel;
	Vector2 src;
	float radius;
};

struct Rect {
	Vector2 center;
	Vector2 size;
	unsigned int color;
};