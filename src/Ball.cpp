#include "surface.h"
#include "game.h"
#include "Ball.h"


void Ball::drawBall(Tmpl8::Surface* surface) {
	ball.DrawScaled(static_cast<int>(pos.x), static_cast<int>(pos.y), radius * 2, radius * 2, false, surface);
}

void Ball::update(Tmpl8::Surface* surface,float delta) {
#ifdef _DEBUG
	surface->Box(static_cast<int>(pos.x), static_cast<int>(pos.y), static_cast<int>(pos.x + radius * 2), static_cast<int>(pos.y + radius * 2), 0xffff00);
#endif
	if (active) {
		if (pos.x >= 0 && pos.y >= 0 && pos.x <= ScreenWidth-radius*2 && pos.y <= ScreenHeight) inScreen = true;
		drawBall(surface);
		bounce(delta);
		animation();
	}
}

/*This funcion make the ball bonce equaly*/
void Ball::bounce(float delta){
	pos.x += move * delta;                         // move is for move the ball side-by-side
	if (inScreen) {								   // inScreen is for the ball not to bounce off the screen
		pos.y += gravity * delta;				   // bounceSpeed sets the down speen for the ball
		gravity += bounceSpeed;
		if (pos.y >= ScreenHeight - 45 - radius * 2) {
			bounceSound.replay();
			pos.y =static_cast<float>( ScreenHeight - 45 - radius * 2);  // I am doing this not to glitch the ball in the floor
			gravity = -1 * (gravity - bounceSpeed);
		}
		if (inScreen)
			if (pos.x > (ScreenWidth - radius * 2 + 5) || pos.x < -5)
				move = -1 * move;
	}
}

/*This funcion animate the ball with a variable that cycle*/
void Ball::animation() {
	if (radius >= 20) {
		ball.SetFrame((unsigned int)ani);
		ani += 0.01;
		if (ani > 3) ani = 0;
	}
	if (radius <= 15) {
		ball.SetFrame((unsigned int)ani);
		ani += 0.01;
		if (ani > 7) ani = 4;
	}
}

void Ball::restart() {
	active = true;
	gravity = 100;
	setPos(firstPos);
	inScreen = false;
}

void Ball::pop(Tmpl8::Surface* screen) {
	ball.DrawScaled(static_cast<int>(pos.x), static_cast<int>(pos.y), radius * 3 , radius * 3 ,false, screen);
}