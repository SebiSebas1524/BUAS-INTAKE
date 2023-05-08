#include "game.h"
#include "template.h"
#include "surface.h"
#include "Player.h"
#include "Ball.h"
#include "Bullet.h"
#include "Menu.h"
#include "Collision.h"


namespace Tmpl8
{
	Game::Game(Surface* screen)
		: m_screen{ screen }
	{	}
	
	void Game::Init() {
		menuType = Menu::Type::MENU;
		inMenu = true;
	}
	void Game::Shutdown() {}

	vec2 defaultPosPlayer = vec2(ScreenWidth / 2 - 25, ScreenHeight - 119.5);
	vec2 defaultPosBall = vec2(-50);

	Player player(defaultPosPlayer);
	Ball ball(defaultPosBall,20);
	Surface background("assets/Background/underwater.png");
	
	

	Collision collision;

	void Game::Tick(float deltaTime)
	{
		float delta = deltaTime / 1000;


		if (inMenu) {
			menu.initMenu(menuType, m_screen, mousePos,inMenu);
		}
		else {
			background.CopyTo(m_screen, 0, 0);
			player.update(m_screen, delta);
			ball.update(m_screen, delta);
			menu.initMenu(menuType, m_screen, mousePos, inMenu);

			if (collision.collisionTrace(player.getMidBullPos(), ball.getPos(), ball.getRadius()) ||
				collision.collisionBullet(ball.getPos(), player.getMidBullPos(), player.getBullWidth(), player.getBullHight(), ball.getRadius()))
				ball.stop();
				
			if (collision.collisionBallPlayer(player.getPos(), ball.getPos(), player.getWidth(), ball.getRadius()))
				player.kill();

			if (GetAsyncKeyState(0x52)) {
				restartGame();
			}

			
			//std::cout << deltaTime /100<< std::endl;

		}


		

	}

	void Game::restartGame() {
		player.setPos(defaultPosPlayer);
		player.restart();
		ball.setPos(defaultPosBall);
		ball.restart();

	}
};
