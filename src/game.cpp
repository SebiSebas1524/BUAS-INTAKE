#include "game.h"
#include "template.h"
#include "surface.h"
#include "Player.h"
#include "Ball.h"
#include "Bullet.h"
#include "Menu.h"
#include "Collision.h"
#include <string>


namespace Tmpl8
{
	Collision collision;
	Surface background("assets/Background/underwater.png");

	//Default position for Player and Ball
	const vec2 defaultPosPlayer = vec2(ScreenWidth / 2 - 25, ScreenHeight - 119.5);
	const vec2 defaultPosLBall = vec2(-40, 150);
	const vec2 defaultPosRBall = vec2(ScreenWidth + 40, 150);

	Player player(defaultPosPlayer);

	/* All the constructors for balls with diferent function*/
	/* Each ball have a radius (radius*2 is the width of the ball) , direction and bounce speed  */
	Ball ball1[]{ Ball(defaultPosLBall, 20,true,5),Ball(defaultPosRBall, 20,false,5) };

	Ball ball2[]{ Ball(defaultPosLBall, 30,true,3),Ball(defaultPosRBall, 32,false,3) ,
				  Ball(defaultPosLBall, 25,true,6),Ball(defaultPosRBall, 26,false,6) ,
				  Ball(defaultPosLBall, 19,true,9),Ball(defaultPosRBall, 15,false,9) };

	Ball ball3[]{ Ball(defaultPosLBall, 30,true,2),Ball(defaultPosRBall, 32,false,2) ,
				  Ball(defaultPosLBall, 25,true,3),Ball(defaultPosRBall, 13,false,3) ,
				  Ball(defaultPosLBall, 15,true,9),Ball(defaultPosRBall, 17,false,9) ,
				  Ball(defaultPosLBall, 31,true,5),Ball(defaultPosRBall, 35,false,5) ,
				  Ball(defaultPosLBall, 25,true,10),Ball(defaultPosRBall, 33,false,10),
				  Ball(defaultPosLBall, 19,true,7),Ball(defaultPosRBall, 13,false,7) };

	void Game::Init() {
		menuType = Menu::Type::MENU; // Initializes the menu
		level = EASY; // Initializes the type level
		bgMusic.setVolume(0.5f);// set the volume from background music
	}
	void Game::Shutdown() {}

	void Game::Tick(float deltaTime)
	{
		bgMusic.play();

		// Clamp deltaTime 
		delta = Min(deltaTime, 33.33333333f);
		// convert deltaTime to seconds 
		delta = delta / 1000;

		if (inMenu) {
			menu.updateMenu(menuType, m_screen, mousePos, inMenu); //update the menu
			m_screen->Print("Best score: ", ScreenWidth - ScreenWidth / 3 + 5, 5, 0xffffff, 2);		// Display the best score
			m_screen->Print(std::to_string(player.getBestScore()).c_str(), ScreenWidth - ScreenWidth / 6, 5, 0xffffff, 2);
			if (menuType != Menu::Type::PAUSE && menuType != Menu::Type::PLAYS) restartGame();  //Restart the game only in menus, not pause.
		}
		else {
			background.CopyTo(m_screen, 0, 0); // put the backround
			player.update(m_screen, delta); 

			menu.updateMenu(menuType, m_screen, mousePos, inMenu); //update the menu

			if (GetAsyncKeyState(0x52)) { //if R key is press the game restart
				restartGame();
			}

			m_screen->Print("Level: ", ScreenWidth - ScreenWidth / 4 , ScreenHeight - 25, 0xffffff, 2);

			switch (level)		// change the level
			{
			case Game::EASY:
				m_screen->Print("EASY", ScreenWidth - ScreenWidth / 6 , ScreenHeight - 25, 0x00ff00, 2); // write the difficulty level

				for (int a = 0; a < 2; a++) {			/* check the collision Ball-Player and Ball-Bullet */
					colisionBall_Bullet(ball1[a]);
					colisionBall_Player(ball1[a]);
				}
				
				/* This update all the ball from level 1*/

				ball1[0].update(m_screen, delta);
				if (timer >= 10) {						//this spawn the ball after some time
					ball1[1].update(m_screen, delta);
				}

				timer += 0.02;

				if (!ball1[0].getActive() && !ball1[1].getActive()) { //verify if all the balls are DISABLED and change the level
					level = MEDIUM;
					timer = 0;
				}
				break;
			case Game::MEDIUM:
				m_screen->Print("MEDIUM", ScreenWidth - ScreenWidth / 6, ScreenHeight - 25, 0xffff00, 2); // write the difficulty level

				for (int a = 0; a < 6; a++) {			/* check the collision Ball-Player and Ball-Bullet */
					colisionBall_Bullet(ball2[a]);
					colisionBall_Player(ball2[a]);
				}
					
				/* This update all the ball from level 2*/
				ball2[0].update(m_screen, delta);
				if (timer >= 10) ball2[1].update(m_screen, delta);
				if (timer >= 15) ball2[2].update(m_screen, delta);
				if (timer >= 18) ball2[3].update(m_screen, delta);   //spawn ball diferent times
				if (timer >= 21) ball2[4].update(m_screen, delta);
				if (timer >= 27) ball2[5].update(m_screen, delta);

				timer += 0.02;

				if (!ball2[0].getActive() && !ball2[1].getActive() && !ball2[2].getActive()
					&& !ball2[3].getActive() && !ball2[4].getActive() && !ball2[5].getActive()) {
					level = HARD;
					timer = 0;
				}
				break;
			case Game::HARD:
				m_screen->Print("HARD", ScreenWidth - ScreenWidth / 6, ScreenHeight - 25, 0xff0000, 2); // write the difficulty level

				for (int a = 0; a < 12; a++) {			/* check the collision Ball-Player and Ball-Bullet */
					colisionBall_Bullet(ball3[a]);
					colisionBall_Player(ball3[a]);
				}

				/* This update all the ball from level 1*/
				ball3[0].update(m_screen, delta);
				if (timer >= 10) ball3[1].update(m_screen, delta);
				if (timer >= 15) ball3[2].update(m_screen, delta);
				if (timer >= 18) ball3[3].update(m_screen, delta);
				if (timer >= 21) ball3[4].update(m_screen, delta);
				if (timer >= 27) ball3[5].update(m_screen, delta);
				if (timer >= 35) ball3[6].update(m_screen, delta);   //spawn ball diferent times
				if (timer >= 40) ball3[7].update(m_screen, delta);
				if (timer >= 42) ball3[8].update(m_screen, delta);
				if (timer >= 47) ball3[9].update(m_screen, delta);
				if (timer >= 49) ball3[10].update(m_screen, delta);
				if (timer >= 50) ball3[11].update(m_screen, delta);

				timer += 0.02;

				if (!ball3[0].getActive() && !ball3[1].getActive() && !ball3[2].getActive()
					&& !ball3[3].getActive() && !ball3[4].getActive() && !ball3[5].getActive()
					&& !ball3[6].getActive() && !ball3[7].getActive() && !ball3[8].getActive()       //verify if all the balls are DISABLED and change the level
					&& !ball3[9].getActive() && !ball3[10].getActive() && !ball3[11].getActive()) {
					menuType = Menu::Type::WIN;
					restartGame();
					timer = 0;
				}
				break;
			default:
				break;
			}

			m_screen->Print("Score: ", ScreenWidth - ScreenWidth / 4, 5, 0xffffff, 2);      //print the score in the play
			m_screen->Print(std::to_string(player.getPoints()).c_str(), ScreenWidth - ScreenWidth / 6, 5, 0xffffff, 2);

			

		}
	}

	void Game::restartGame() { /*Restart all to the first position */
		timer = 0;
		level = EASY;

		player.setPos(defaultPosPlayer);
		player.restart();

		for (int a = 0; a < 2; a++) { ball1[a].restart(); }
		for (int a = 0; a < 6; a++) { ball2[a].restart(); }
		for (int a = 0; a < 12; a++) { ball3[a].restart(); }
	}

	void Game::colisionBall_Player(Ball& ball) {	/* Checking the colision Ball with Player */
		if (collision.collisionBallPlayer(player.getPos(), ball.getPos(), player.getWidth(), ball.getRadius())) {
			player.restart();
			restartGame();
			menuType = Menu::Type::DEAD;
		}
	}
	void Game::colisionBall_Bullet(Ball& ball) {	/* Checking the colision Ball with Bullet (and the trace from the bullet) */
		if (collision.collisionTrace(player.getMidBullPos(), ball.getPos(), ball.getRadius()) ||
			collision.collisionBullet(ball.getPos(), player.getMidBullPos(), player.getBullWidth(), player.getBullHight()- 25, ball.getRadius())) {
			ball.stop();
			ball.pop(m_screen); //pop animation 
			pop.play();
			ball.setPos(-40); // draw the ball in this position not to colide with anyhing
			player.setPoints(ball.getRadius() * rand() % 100 + 1);  //put random points to the score
		}
	}
};
