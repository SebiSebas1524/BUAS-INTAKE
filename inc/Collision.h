#pragma once
#include "template.h"

class Collision
{
public:
	bool collisionBullet(Tmpl8::vec2 ballPos, Tmpl8::vec2 bulletPos, int bulletWidth, int bulletHeight, int ray);
	bool collisionTrace(Tmpl8::vec2 tracePos, Tmpl8::vec2 ballPos, int ray);
	bool collisionBallPlayer(Tmpl8::vec2 playerPos, Tmpl8::vec2 ballPos,int playerWidth, int ray);

private:

};


