#pragma once
#include "template.h"
#include "Menu.h"
#include "Ball.h"
#include <Sound.hpp>

namespace Tmpl8 {

class Surface;
class Game
{
public:

	void SetTarget( Surface* surface ) { m_screen = surface; }
	void Init();
	void Shutdown();
	void Tick( float deltaTime );
	void restartGame();
	void MouseUp( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseDown( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseMove(int x, int y) {mousePos.x = static_cast <float> (x);mousePos.y = static_cast <float> (y); }
	void KeyUp( int key ) { /* implement if you want to handle keys */ }
	void KeyDown( int key ) { /* implement if you want to handle keys */ }

	void colisionBall_Player(Ball& ball);
	void colisionBall_Bullet(Ball& ball);

	enum GameLevel { //difficulty level
		EASY,
		MEDIUM,
		HARD
	};

private:
	Surface* m_screen;
	float delta;
	float timer{ 0 };

	vec2 mousePos;

	GameLevel level;
	Menu::Type menuType;
	Menu menu;
	bool inMenu{ true };
	Audio::Sound bgMusic{ "assets/SFX/underwater.wav", Audio::Sound::Type::Stream };
	Audio::Sound pop{ "assets/SFX/pop.wav" };
};

}; // namespace Tmpl8



//https://pzuh.itch.io/free-bubble-game-button-pack  ::butons
//https://sfxr.me