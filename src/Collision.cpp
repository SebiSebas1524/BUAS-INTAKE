#include "Collision.h"
#include <template.h>

bool Collision::collisionBallPlayer(Tmpl8::vec2 playerPos, Tmpl8::vec2 ballPos, int playerWidth, int ray) {
	bool collide = false;

		/* I do a simple collision with the coordonation that verify if the ball is touching the player*/
	if (ballPos.y + 2 * ray >= playerPos.y + 3 && ballPos.x + 2 * ray >= playerPos.x && ballPos.x <= playerPos.x + playerWidth - 7)
		collide = true;

	return collide;
}

bool Collision::collisionBullet(Tmpl8::vec2 ballPos, Tmpl8::vec2 bulletPos, int bulletWidth, int bulletHeight, int ray) {
	bool collide = false;

	/* I do a simple collision with the coordonation that verify if the ball is touching the bullet*/
	if (ballPos.y + 2 * ray >= bulletPos.y && ballPos.y <= bulletPos.y + bulletHeight
		&& ballPos.x + 2 * ray >= bulletPos.x && ballPos.x <= bulletPos.x + bulletWidth)
		collide = true;

	return collide;
}

bool Collision::collisionTrace(Tmpl8::vec2 tracePos, Tmpl8::vec2 ballPos, int ray) {
	bool collide = false;

	/* I do a simple collision with the coordonation that verify if the ball is touching the trace*/
	if (ballPos.y + ray * 2 >= tracePos.y && ballPos.x >= tracePos.x - ray * 2 && ballPos.x  <= tracePos.x )
		collide = true;

	return collide;
}