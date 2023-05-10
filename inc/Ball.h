#pragma once
#include "surface.h"
#include "template.h"
#include <iostream>
#include <Sound.hpp>

class Ball
{
public:
	Ball(Tmpl8::vec2 pos, int radius, bool dirRight, float incr) :
		pos(pos),
		firstPos(pos),
		radius(radius),
		ball(new Tmpl8::Surface("assets/Sprites/bubble.png"), 8),
		bounceSpeed(incr)
	{
		/*Verify if the direction is to right, if not change the direction to left*/
		if (!dirRight) move = -move;
	}

	void drawBall(Tmpl8::Surface* screen);
	void update(Tmpl8::Surface* surface, float delta);
	void bounce(float delta); /*This funcion make the ball bonce equaly*/
	void animation(); /*This funcion animate the ball with a variable that cycle*/
	void setRadius(int rad) { radius = rad; }
	int getRadius() { return radius; }
	void setPos(Tmpl8::vec2 newPos) { pos = newPos; }
	Tmpl8::vec2 getPos() { return pos; }
	void stop() { active = false; } // desactivete the ball
	void restart();
	bool getActive() { return active; }
	void pop(Tmpl8::Surface* screen); 

private:

	bool inScreen = false;
	bool active = true;
	int radius;
	Tmpl8::vec2 pos;
	Tmpl8::Sprite ball;
	float gravity = 100;
	float bounceSpeed;
	float move = 70;
	float ani = 0;
	Tmpl8::vec2 firstPos;

	Audio::Sound bounceSound{ "assets/SFX/bounce.wav" };
};