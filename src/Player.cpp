#include "Player.h"
#include "template.h"
#include "surface.h"
#include "windows.h"
#include <iostream>

void Player::update(Tmpl8::Surface* surface, float delta) {
	if (alive) {
#ifdef _DEBUG
		surface->Box(static_cast<int>(pos.x), static_cast<int>(pos.y + 3), static_cast<int>(pos.x + player.GetWidth() - 7), static_cast<int>(pos.y + player.GetHeight()), 0xffff00);
#endif
		move(delta);
		shoot(surface, delta);
		animation();
		if (pos.x < 0) pos.x = 0;							// stops the player from walking off screen
		if (pos.x > ScreenWidth - player.GetWidth())
			pos.x = static_cast<float> (ScreenWidth - player.GetWidth());
		draw(surface);
	}
}

/* This function is for drawing the player */
void Player::draw(Tmpl8::Surface* surface) {
	player.Draw(surface, static_cast<int>(pos.x), static_cast<int> (pos.y));
}

/* This function is for walking */
void Player::move(float delta) { 
	if (!(GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(0x44)))	dir = 'I';
	if ((GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(0x41)) && (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(0x44))) { 
		dir = 'I'; return;			// this is for when you press left and and right same time and not move
	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(0x44) ) { //move to right
		pos.x += speed * delta;
		dir = 'R';//right
	}
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(0x41)) { //move to left
		pos.x -= speed * delta;
		dir = 'L';//left
	}
}

/* This function is for animation*/
void Player::animation() {					/* I set the direction with a char that store the direction */
	if (dir == 'R') {	
		frame += 0.5;								 /* For each direction is a loop and sets the frame */
		if (frame > 12) frame = 7;
		player.SetFrame(static_cast<int>(frame));
	}
	if (dir == 'L') {
		frame -= 0.5;
		if (frame < 0) frame = 4; 
		player.SetFrame(static_cast<int>(frame));
	}
	if (dir == 'I') player.SetFrame(6);
	if (dir == 'S') player.SetFrame(13);
}

/* This function is for shooting*/
void Player::shoot(Tmpl8::Surface* surface, float delta) {
	if ((GetAsyncKeyState(VK_SPACE)) && isFire == false) {
		laser.setVolume(0.07f);
		laser.replay();
		actT = 0; //reset animation time
		isFire = true;
		bullet.setStartPos(Tmpl8::vec2(pos.x + player.GetWidth() / 4 -5, pos.y)); //sets first posision for the bullet
		bullet.setPos(Tmpl8::vec2(pos.x + player.GetWidth()/4 - 5, pos.y));
	}
	if (isFire) {
		if (actT < 5) dir = 'S';  
		actT += 0.3;
		bullet.update(surface , delta);
		if (bullet.getPosY() < - 20) {   //if the bullet reach the top - restet the bullet
			isFire = false;
			bullet.setPos(Tmpl8::vec2(-100));
		}
	}
	timerShooter += 0.2;
}

/* This function is for restart the player and the bullet*/
void Player::restart(){ 
	alive = true; 
	bullet.setPos(Tmpl8::vec2(-1000));
	bullet.setStartPos(Tmpl8::vec2(-1000));
	if (points > bestScore)bestScore = points; // put the best score is is bigger then actual points
	points = 0; //reset the points
}