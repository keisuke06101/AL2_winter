#pragma once

typedef struct Vector2
{

	float x;
	float y;

};

struct Player              //プレイヤー構造体
{
	Vector2 pos;           //ボールの位置
	Vector2 vel;           //ボールの速度
	Vector2 acc;           //ボールの加速度
	float scr;             //スクロール値   
	float monitor;         //モニター座標
	Vector2 src;           //アニメーションスクロール
	float radius;          //ボールの半径
	unsigned int color;    //ボールの色
};

struct Bullet              //弾の構造体
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