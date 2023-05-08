#include "Player.h"
#include "template.h"
#include "surface.h"
#include "windows.h"
#include <iostream>

void Player::draw(Tmpl8::Surface* surface) {
	player.Draw(surface, static_cast<int>(pos.x), static_cast<int> (pos.y));
	//player.DrawScaled(pos.x, pos.y-200, 200, 300, false, surface);
}

void Player::move(float delta) {
	if (!(GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(0x44)))	dir = 'I';
	if ((GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(0x41)) && (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(0x44))) {
		dir = 'I'; return;
	}
	if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState(0x44) ) {
		pos.x += speed * delta;
		dir = 'R';//right
	}
	if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(0x41)) {
		pos.x -= speed * delta;
		dir = 'L';//left
	}
	
	
}

void Player::update(Tmpl8::Surface* surface,float delta) {
	if (alive) {
#ifdef _DEBUG
		surface->Box(pos.x , pos.y , pos.x +player.GetWidth() , pos.y + player.GetHeight(), 0xffff00);
#endif
		move(delta);
		shoot(surface,delta);
		animation();
		if (pos.x < 0) pos.x = 0;
		if (pos.x > ScreenWidth - player.GetWidth())
			pos.x = static_cast<float> (ScreenWidth - player.GetWidth());
		draw(surface);
	}
}

void Player::animation() {
	if (dir == 'R') {
		frame += 0.5;
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

void Player::shoot(Tmpl8::Surface* surface, float delta) {
	
	if ((GetAsyncKeyState(VK_SPACE)) && isFire == false) {
		//dir = 'S';
		actT = 0;
		isFire = true;
		bullet.setStartPos(Tmpl8::vec2(pos.x + player.GetWidth() / 4 -5, pos.y));
		bullet.setPos(Tmpl8::vec2(pos.x + player.GetWidth()/4 - 5, pos.y));
}
	if (isFire){
		if (actT < 5) dir = 'S'; 
		actT += 0.3;
		bullet.update(surface , delta);
		if (bullet.getPosY() < - 20) {
			isFire = false;
			bullet.setPos(Tmpl8::vec2(-100));
		}
	}
	timerShooter += 0.2;
}
void Player::restart(){ 
	alive = true; 
	bullet.setPos(Tmpl8::vec2(-100));
}