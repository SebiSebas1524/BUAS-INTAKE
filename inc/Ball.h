#pragma once
#include "surface.h"
#include "template.h"
#include <iostream>


class Ball
{
public:
	Ball(Tmpl8::vec2 pos, int radius) :
		pos(pos),
		radius(radius),
		ball(new Tmpl8::Surface("assets/Sprites/bubble.png"), 8)
	{	}

	void drawBall(Tmpl8::Surface* screen);
	void update(Tmpl8::Surface* surface,float delta);
	void bounce(float delta);
	void animation();
	void setRadius(int rad) { radius = rad; }
	int getRadius() { return radius; }
	void setPos(Tmpl8::vec2 newPos) { pos = newPos; }
	Tmpl8::vec2 getPos() { return pos; }
	Tmpl8::vec2 getMidPos() { return pos + Tmpl8::vec2(ball.GetWidth() / 2.0f, ball.GetHeight() / 2.0f); }
	void stop() { active = false; }
	void restart();

private:
	/*Ball halfBall1(poz,radius);
	Ball halfBall2(poz, radius);*/

	bool inScreen = false;
	bool active = true;
	int radius;
	Tmpl8::vec2 pos;
	Tmpl8::Sprite ball;
	float gravity = 100;
	float move = 50;
	float ani = 0;
};