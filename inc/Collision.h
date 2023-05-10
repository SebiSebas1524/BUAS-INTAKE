#pragma once
#include "template.h"

class Collision
{
public:
	bool collisionBullet(Tmpl8::vec2 ballPos, Tmpl8::vec2 bulletPos, int bulletWidth, int bulletHeight, int ray); //Colision BALL-BULET
	bool collisionTrace(Tmpl8::vec2 tracePos, Tmpl8::vec2 ballPos, int ray); // Colision BALL_TRACE
	bool collisionBallPlayer(Tmpl8::vec2 playerPos, Tmpl8::vec2 ballPos,int playerWidth, int ray); // Colision BALL-PLAYER
};


