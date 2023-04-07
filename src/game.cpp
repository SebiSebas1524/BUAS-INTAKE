#include "game.h"
#include "surface.h"
#include "Player.h"
#include "Ball.h"

namespace Tmpl8
{

	
	void Game::Init() {}
	void Game::Shutdown() {}

	Player player(vec2(ScreenWidth / 2- 25, ScreenHeight - 119.5));
	Ball ball1(vec2(100));
	Surface background("assets/underwater.png");
	



	void Game::Tick(float deltaTime)
	{
		screen->Clear(0x001484);
		background.CopyTo(screen,0,0);
		player.draw(screen);
		player.move();
		player.update();
		//screen->Bar(0, ScreenHeight -50, ScreenWidth-0.1, ScreenHeight-0.1, 0x102590);
		
		//ball1.DrawBall(screen);

		//TODO: De pus mai multe mingi
		// si verificare in ce directie sa mearga
		// si unde isi dau bounce

	}
};