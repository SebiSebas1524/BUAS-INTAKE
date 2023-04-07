#pragma once
#include "template.h"
#include "surface.h"


class Player
{
public:
	Player(const Tmpl8::vec2& pos) :
		pos(pos),
		player(new Tmpl8::Surface("assets/primu_peste.png"), 1)
	{}

	void draw(Tmpl8::Surface* surface);
	void move();
	void update();
	void setPos(Tmpl8::vec2& newPos) {pos = newPos; }
	const Tmpl8::vec2& getPos() const {	return pos; };
	int getHeight() { return monsterHeight; };

private:
	Tmpl8::vec2 pos;
	Tmpl8::Sprite player;
	float monsterHeight = player.GetHeight();
	float monsterWidth = player.GetWidth();
};


