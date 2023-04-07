#include "surface.h"
#include "game.h"
#include "Ball.h"


void Ball::DrawBall(Tmpl8::Surface* screen) {
	ball.Draw(screen, poz.x, poz.y);
	poz.y += speed;
	poz.x += move;
	speed++;
	if (poz.y > (ScreenHeight - ball.GetHeight())) {
		poz.y = ScreenHeight -2* ball.GetHeight();
		speed = -(speed * 0.8);
	}
	if (poz.x > (ScreenWidth - ball.GetWidth())) {
		poz.x = ScreenWidth - ball.GetWidth();
		move = -move;
	}
	else if (poz.x < 0) {
		poz.x = 0;
		move = 5;
	}
}