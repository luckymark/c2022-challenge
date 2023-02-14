#pragma once
#include "People_one.h"
#include "People_two.h"
#include "AI.h"
#include "Chess.h"
#include <graphics.h>
#include <math.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include <conio.h>

class ChessGame
{
public:
	ChessGame(People_one* people_one, People_two* people_two, AI* ai, Chess* chess);
	void play();//开始对局
private:
	People_one* people_one;
	People_two* people_two;
	AI* ai;
	Chess* chess;
	IMAGE backgroundImg;
};