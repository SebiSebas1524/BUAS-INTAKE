#pragma once
#include "template.h"
#include "surface.h"
#include "Bullet.h"
#include <Sound.hpp>

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
	void move(float delta);   /* This function is for walking (movement) */
	void animation();		  /* This function is for animation*/
	void kill() { alive = false; }
	void restart();			  /* This function is for restart the player and the bullet*/
	void update(Tmpl8::Surface* surface, float delta);
	void shoot(Tmpl8::Surface* surface, float delta); /* This function is for shooting*/
	void setPoints(int point) { points += point; }  
	int getPoints() { return points; }
	int getBestScore() { return bestScore; }
	void setPos(Tmpl8::vec2 newPos) { pos = newPos; }
	Tmpl8::vec2 getPos() { return pos; }
	Tmpl8::vec2 getMidBullPos() { return bullet.getMidPos(); } // get the middle bllet position
	Tmpl8::vec2 betBullPos() { return bullet.getPos(); }	   // get the middle bllet position
	int getWidth() { return player.GetWidth(); } // get player width

	int getBullHight() { return bullet.getHeight(); } // get bullet height
	int getBullWidth() { return bullet.getWidth(); }  // get bullet width

private:
	bool alive = true;
	char dir = 'I';  //direction:  I-idle L-left R-right S-shooting (this is for direction - to set the frame of the sprite)
	float frame = 6;
	Tmpl8::vec2 pos;
	Tmpl8::Sprite player;
	Bullet bullet;
	bool isFire = false;
	float timerShooter = 10;
	float actT = 0;
	float speed = 300;
	int points{ 0 }, bestScore{ 0 };
	
	Audio::Sound laser{ "assets/SFX/laserShoot.wav" };
};


