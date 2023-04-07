#pragma once
#include "surface.h"
#include "template.h"
#include <iostream>


class Ball
{
public:
	Ball(Tmpl8::vec2 poz) :
		poz(poz),
		ball(new Tmpl8::Surface("assets/ball.png"), 1)
	{}

	void DrawBall(Tmpl8::Surface* screen);
	void Distroy();
	void Bounce();

private:
	int Diameter;

	Tmpl8::vec2 poz;
	Tmpl8::Sprite ball;
	float speed = 0.2;
	float move = 5;

};