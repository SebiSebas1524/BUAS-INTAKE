#include "Player.h"
#include "template.h"
#include "surface.h"
#include "windows.h"

void Player::draw(Tmpl8::Surface* surface) {
	player.Draw(surface, pos.x, pos.y);
	//player.DrawScaled(pos.x, pos.y-200, 200, 300, false, surface);
}

void Player::move() {
	if (GetAsyncKeyState(VK_LEFT)|| GetAsyncKeyState(0x41)){ pos.x -= 5; }
	if (GetAsyncKeyState(VK_RIGHT)|| GetAsyncKeyState(0x44)) { pos.x += 5; }
}

void Player::update() {
	if (pos.x < 0) pos.x = 0;
	if (pos.x > ScreenWidth - player.GetWidth()) pos.x = ScreenWidth - player.GetWidth();
}