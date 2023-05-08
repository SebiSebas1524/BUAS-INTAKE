#include"Bullet.h"
#include"Player.h"
#include "game.h"

void Bullet::drawBullet(Tmpl8::Surface* surface) {
	bullet.Draw(surface,static_cast<int>(pos.x), static_cast<int>(pos.y));
	surface->Line(startPos.x+bullet.GetWidth()/2, startPos.y + bullet.GetHeight() + bullet.GetHeight()/4,
		pos.x +bullet.GetWidth()/2, pos.y + bullet.GetHeight()/5, 0xffffff);
}
void Bullet::animation() {
	bullet.SetFrame((unsigned int) ani);
	ani += 0.2;
	if (ani >= 5) ani = 0;
}
void Bullet::update(Tmpl8::Surface* surface,float delta) {
		drawBullet(surface);
		animation();
		pos.y -= speed * delta;
		
}
void Bullet::startBullet(Tmpl8::Surface* surface) {
	bullet.Draw(surface,static_cast<int>(startPos.x), static_cast<int>(startPos.y));
}