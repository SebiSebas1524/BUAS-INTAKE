#pragma once
#include "template.h"
#include "surface.h"
#include "Bullet.h"


class Player
{
public:
	Player(const Tmpl8::vec2& pos) :
		pos(pos),
		bullet(pos),
		player(new Tmpl8::Surface("assets/Sprites/playerAnimation.png"), 14)
	{
		player.SetFrame(static_cast<int>(frame));
	}


	
	void draw(Tmpl8::Surface* surface);
	void move(float delta);
	void animation();
	void kill() { alive = false; }
	void restart();
	void update(Tmpl8::Surface* surface,float delta);
	void shoot(Tmpl8::Surface* surface,float delta);
	void setPos(Tmpl8::vec2 newPos) { pos = newPos; }
	Tmpl8::vec2 getPos() { return pos; }
	Tmpl8::vec2 getMidBullPos() { return bullet.getMidPos(); }
	Tmpl8::vec2 betBullPos() { return bullet.getPos(); }
	int getWidth() { return player.GetWidth(); }

	int getBullHight() { return bullet.getHeight(); }
	int getBullWidth() { return bullet.getWidth(); }

private:
	bool alive = true;
	char dir = 'I';//direction:  I-idle L-left R-right S-shooting
	float frame = 6;
	Tmpl8::vec2 pos;
	Tmpl8::Sprite player;
	Bullet bullet;
	bool isFire = false;
	float timerShooter = 10;
	float actT = 0;
	float speed = 300;
};


