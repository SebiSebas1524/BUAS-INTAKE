#pragma once
#include "template.h"
#include "Menu.h"

namespace Tmpl8 {

class Surface;
class Game
{
public:
	Game(Surface* screen);

	//void SetTarget( Surface* surface ) { screen = surface; }
	void Init();
	void Shutdown();
	void Tick( float deltaTime );
	void restartGame();
	void MouseUp( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseDown( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseMove(int x, int y) {mousePos.x = static_cast <float> (x);mousePos.y = static_cast <float> (y); }
	void KeyUp( int key ) { /* implement if you want to handle keys */ }
	void KeyDown( int key ) { /* implement if you want to handle keys */ }

	

private:
	Surface* m_screen{ nullptr };

	vec2 mousePos;

	Menu::Type menuType;
	Menu menu;
	bool inMenu;
};

}; // namespace Tmpl8



//https://pzuh.itch.io/free-bubble-game-button-pack  ::butons