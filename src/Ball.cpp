#include "surface.h"
#include "game.h"
#include "Ball.h"


void Ball::drawBall(Tmpl8::Surface* surface) {
	//ball.Draw(surface, poz.x, poz.y);
	ball.DrawScaled(static_cast<int>(pos.x), static_cast<int>(pos.y), radius * 2, radius * 2, false, surface);
}

void Ball::update(Tmpl8::Surface* surface,float delta) {
#ifdef _DEBUG
	surface->Box(pos.x, pos.y, pos.x + radius * 2, pos.y + radius * 2, 0xffff00);
#endif
	if (active) {
		std::cout << pos.x << " " << pos.y << std::endl;
		if (pos.x >= 0 && pos.y >= 0 && pos.x <= ScreenWidth && pos.y <= ScreenHeight) inScreen = true;
		drawBall(surface);
		bounce(delta);
		animation();
	}
}

void Ball::bounce(float delta){
	pos.y += gravity * delta;
	pos.x += move*delta;
	gravity +=5;
	if (pos.y >= (ScreenHeight - 45.5 - radius * 2)) {
		gravity = -1 * (gravity- 5);
	}
	if(inScreen)
		if (pos.x > (ScreenWidth - radius * 2 + 5) || pos.x < -5)
			move = -1 * move;
}

void Ball::animation() {
	if (radius == 20) {
		ball.SetFrame((unsigned int)ani);
		ani += 0.01;
		if (ani > 3) ani = 0;
	}
	if (radius == 10) {
		ball.SetFrame((unsigned int)ani);
		ani += 0.01;
		if (ani > 7) ani = 4;
	}
}

void Ball::restart() {
	active = true;
	gravity = 250;
	move = 0.7;

}