#pragma once
#include "surface.h"
#include "template.h"
#include "game.h"

class Bullet
{
public:
	Bullet(const Tmpl8::vec2& startPos) :
		bullet(new Tmpl8::Surface("assets/Sprites/Bullet.png"), 5)
	{
		bullet.SetFrame(0);
	}
	void drawBullet(Tmpl8::Surface* surface);
	void animation();
	void update(Tmpl8::Surface* surface,float delta);
	float getPosY() { return pos.y; }
	void setPos(const Tmpl8::vec2& newPos) { pos = newPos; }
	void setStartPos(const Tmpl8::vec2 newStartPos) { startPos = newStartPos; }
	Tmpl8::vec2 getMidPos() { return Tmpl8::vec2(pos.x + bullet.GetWidth() / 2,pos.y + bullet.GetHeight() / 5); } // get the middle position of the bullet
	Tmpl8::vec2 getPos() { return pos; }

	int getWidth() { return bullet.GetWidth(); }
	int getHeight() {return bullet.GetHeight(); }

private:
	float speed = 250;
	Tmpl8::vec2 startPos = Tmpl8::vec2(-1000);
	Tmpl8::vec2 pos = Tmpl8::vec2(-1000);
	Tmpl8::Sprite bullet;
	float ani = 0;
};
