#include "game.h"
#include "surface.h"
#include "template.h"
#include "windows.h"
#include "Menu.h"
#include <conio.h>
#include <iostream>


void Menu::updateMenu(Menu::Type& menuType, Tmpl8::Surface* screen, const Tmpl8::vec2& posMouse, bool& inMenu) {
    switch (menuType)
    {
    case Menu::Type::MENU:      // PRINCIPAL MENU
        updatePrincipalMenu(menuType, screen, posMouse, inMenu);
        break;
    case Menu::Type::PLAYS:     // WHEN THE GAME PLAYS
        updatePlays(menuType, screen, posMouse, inMenu);
        break;
    case Menu::Type::PAUSE:     // PAUSE MENU
        updatePause(menuType, screen, posMouse, inMenu);
        break;
    case Menu::Type::CONTROLS:  // CONTROLS MENU
        updateControls(menuType, screen, posMouse, inMenu);
        break;
    case Menu::Type::DEAD:      // MENU WHEM YOU DIE
        updateDead(menuType, screen, posMouse, inMenu);
        break;
    case Menu::Type::WIN:       // MENU WHEN YOU WIN
        updateWin(menuType, screen, posMouse, inMenu);
        break;
    default:
        break;
    }
}



void Menu::updatePrincipalMenu(Menu::Type& menuType, Tmpl8::Surface* screen, const Tmpl8::vec2& posMouse, bool& inMenu)
{
    drawPrincipalMenu(screen);

    bool leftPressed = GetAsyncKeyState(VK_LBUTTON);

    bool collidesLevelsButton = (posMouse.x >= 360 && posMouse.x <= 520) && (posMouse.y >= 220 && posMouse.y <= 295); //if is hover on the levels button
    if (collidesLevelsButton)
    {
        startButton2.Draw(screen, 360, 220);
        if (leftPressed) {
            menuType = Type::PLAYS;
            click.play();
            inMenu = true;
        }
    }

    bool collidesControlsButton = (posMouse.x >= 360 && posMouse.x <= 520) && (posMouse.y >= 300 && posMouse.y <= 375);//if is hover on the control button
    if (collidesControlsButton)
    {
        controlButton2.Draw(screen, 360, 300);
        if (leftPressed) {
            if (leftPressed) {
                menuType = Type::CONTROLS;
                click.play();
                inMenu = true;
            }
        }
    }

    bool collidesExitButton = (posMouse.x >= 360 && posMouse.x <= 520) && (posMouse.y >= 380 && posMouse.y <= 455);//if is hover on the exit button
    if (collidesExitButton)
    {
        exitButton2.Draw(screen, 360, 380);
        //An implementation of a Exit button has been adapted from MΛX#2223 in the 3dgep.com discord server
        //Message link : https://discord.com/channels/515453022097244160/686661689894240277/1095673953734901761
        if (leftPressed) {
            click.play();
            /* Invoke an event with the type SDL_QUIT */
            SDL_Event user_event;
            user_event.type = SDL_QUIT;
            SDL_PushEvent(&user_event);
        }
    }

}

void Menu::updatePlays(Menu::Type& menuType, Tmpl8::Surface* screen, const Tmpl8::vec2& posMouse, bool& inMenu) {
    drawPlays(screen);
    bool leftPressed = GetAsyncKeyState(VK_LBUTTON);
    int yPos = ScreenHeight - backButton1.GetHeight() - 5;
    inMenu = false;

    bool collidesBackButton = (posMouse.x >= 10 && posMouse.x <= 80) &&  //if is hover on the back button
        (posMouse.y >= yPos && posMouse.y <= yPos + 36);
    if (collidesBackButton)
    {
        backButton2.Draw(screen, 10, yPos);
        if (leftPressed) {
            click.play();
            menuType = Type::MENU;
            inMenu = true;
        }
    }


    bool pause = GetAsyncKeyState(VK_ESCAPE); // if you press the esc buton open pause menu
    if (pause) {
        menuType = Type::PAUSE;
        inMenu = true;
    }
}

void Menu::updatePause(Menu::Type& menuType, Tmpl8::Surface* screen, const Tmpl8::vec2& posMouse, bool& inMenu) {
    drawPause(screen);
    bool leftPressed = GetAsyncKeyState(VK_LBUTTON);

    bool collidesMenuButton = (posMouse.x >= ScreenWidth - menuButton.GetWidth() - 5 && posMouse.x <= ScreenWidth - 5) &&
        (posMouse.y >= ScreenHeight - menuButton.GetHeight() - 5 && posMouse.y <= ScreenHeight - 5);        //if is hover on the menu button
    if (collidesMenuButton)
    {
        menuButton2.Draw(screen, ScreenWidth - menuButton.GetWidth() - 5, ScreenHeight - menuButton.GetHeight() - 5);
        if (leftPressed) {
            click.play();
            menuType = Type::MENU;
            inMenu = true;
        }
    }

    bool collidesResumeButton = (posMouse.x >= 360 && posMouse.x <= 520) &&
        (posMouse.y >= 300 && posMouse.y <= 381);               //if is hover on the resume button
    if (collidesResumeButton)
    {
        resumeButton2.Draw(screen, 360, 300);
        if (leftPressed) {
            click.play();
            menuType = Type::PLAYS;
            inMenu = false;
        }
    }
}

void Menu::updateControls(Menu::Type& menuType, Tmpl8::Surface* screen, const Tmpl8::vec2& posMouse, bool& inMenu) {
    drawControls(screen);
    bool leftPressed = GetAsyncKeyState(VK_LBUTTON);
    int yPos = ScreenHeight - backButton1.GetHeight() - 5;
    inMenu = true;

    bool collidesLevelsButton = (posMouse.x >= 10 && posMouse.x <= 80) &&
        (posMouse.y >= yPos && posMouse.y <= yPos + 36);                    //if is hover on the level  button
    if (collidesLevelsButton)
    {
        backButton2.Draw(screen, 10, yPos);
        if (leftPressed) {
            click.play();
            menuType = Type::MENU;
            inMenu = true;
        }
    }
    bool back = GetAsyncKeyState(SDLK_ESCAPE); // if you press the esc buton open principal menu
    if (back) {
        menuType = Type::MENU;
        inMenu = true;
    }
}

void Menu::updateDead(Menu::Type& menuType, Tmpl8::Surface* screen, const Tmpl8::vec2& posMouse, bool& inMenu) {
    drawDead(screen);
    inMenu = true;
    loseS.setVolume(0.09f);
    if (!played) {      //play lose sound once
        loseS.play();
        played = true;
    }

    bool leftPressed = GetAsyncKeyState(VK_LBUTTON);
    bool collidesReplayButton = (posMouse.x >= 360 && posMouse.x <= 360 + replayButton1.GetWidth())   //if is hover on the replay button
        && (posMouse.y >= 300 && posMouse.y <= 300 + replayButton1.GetHeight());
    if (collidesReplayButton)
    {
        replayButton2.Draw(screen, 360, 300);
        if (leftPressed) {
            played = false;
            click.play();
            menuType = Type::PLAYS;
        }
    }
    bool collidesMenuButton = (posMouse.x >= ScreenWidth - menuButton.GetWidth() - 5 && posMouse.x <= ScreenWidth - 5) &&
        (posMouse.y >= ScreenHeight - menuButton.GetHeight() - 5 && posMouse.y <= ScreenHeight - 5);         //if is hover on the menu button
    if (collidesMenuButton)
    {
        menuButton2.Draw(screen, ScreenWidth - menuButton.GetWidth() - 5, ScreenHeight - menuButton.GetHeight() - 5);
        if (leftPressed) {
            played = false;
            click.play();
            menuType = Type::MENU;
            inMenu = true;
        }
    }

}

void Menu::updateWin(Menu::Type& menuType, Tmpl8::Surface* screen, const Tmpl8::vec2& posMouse, bool& inMenu) {
    drawWin(screen);
    inMenu = true;

    winS.setVolume(0.10f);
    if (!played) {          //play win sound once
        winS.play();
        played = true;
    }

    bool leftPressed = GetAsyncKeyState(VK_LBUTTON);
    bool collidesReplayButton = (posMouse.x >= 360 && posMouse.x <= 360 + replayButton1.GetWidth())
        && (posMouse.y >= 300 && posMouse.y <= 300 + replayButton1.GetHeight());         //if is hover on the replay  button
    if (collidesReplayButton)
    {
        replayButton2.Draw(screen, 360, 300);
        if (leftPressed) {
            played = false;
            click.play();
            menuType = Type::PLAYS;
        }
    }
    bool collidesMenuButton = (posMouse.x >= ScreenWidth - menuButton.GetWidth() - 5 && posMouse.x <= ScreenWidth - 5) &&
        (posMouse.y >= ScreenHeight - menuButton.GetHeight() - 5 && posMouse.y <= ScreenHeight - 5);     //if is hover on the menu button
    if (collidesMenuButton)
    {
        menuButton2.Draw(screen, ScreenWidth - menuButton.GetWidth() - 5, ScreenHeight - menuButton.GetHeight() - 5);
        if (leftPressed) {
            played = false;
            click.play();
            menuType = Type::MENU;
            inMenu = true;
        }
    }
    bool collidesExitButton = (posMouse.x >= ScreenWidth - exitButton1.GetWidth() * 2 - 5 && posMouse.x <= ScreenWidth - exitButton1.GetWidth() - 5) &&
        (posMouse.y >= ScreenHeight - exitButton1.GetHeight() - 5 && posMouse.y <= ScreenHeight - 5);    //if is hover on the exit button
    if (collidesExitButton)
    {
        exitButton2.Draw(screen, ScreenWidth - exitButton1.GetWidth() * 2 - 5, ScreenHeight - exitButton1.GetHeight() - 5);
        if (leftPressed) {
            click.play();
            /* Invoke an event with the type SDL_QUIT */
            SDL_Event user_event;
            user_event.type = SDL_QUIT;
            SDL_PushEvent(&user_event);
        }
    }
}
  
///////////////////////////////////////////////////////////////////////////////////////////////////////

void Menu::drawPrincipalMenu(Tmpl8::Surface* screen)
{
    menuBackground.Draw(screen, 0, 0);
    startButton1.Draw(screen, 360, 220);
    controlButton1.Draw(screen, 360, 300);
    exitButton1.Draw(screen, 360, 380);
}

void Menu::drawPlays(Tmpl8::Surface* screen) {
    backButton1.Draw(screen, 10, ScreenHeight - backButton1.GetHeight() - 5);
}

void Menu::drawPause(Tmpl8::Surface* screen) {
    pauseMenu.Draw(screen, 0, 0);
    menuButton.Draw(screen, ScreenWidth - menuButton.GetWidth() - 5, ScreenHeight - menuButton.GetHeight() - 5);
    resumeButton.Draw(screen, 360, 300);
}

void Menu::drawControls(Tmpl8::Surface* screen) {
    controlMenu.Draw(screen, 0, 0);
    backButton1.Draw(screen, 10, ScreenHeight - backButton1.GetHeight() - 5);
}

void Menu::drawDead(Tmpl8::Surface* screen) {
    deadMenu.Draw(screen, 0, 0);
    replayButton1.Draw(screen, 360, 300);
    menuButton.Draw(screen, ScreenWidth - menuButton.GetWidth() - 5, ScreenHeight - menuButton.GetHeight() - 5);
}

void Menu::drawWin(Tmpl8::Surface* screen) {
    winMenu.Draw(screen, 0, 0);
    replayButton1.Draw(screen, 360, 300);
    menuButton.Draw(screen, ScreenWidth - menuButton.GetWidth() - 5, ScreenHeight - menuButton.GetHeight() - 5);
    exitButton1.Draw(screen, ScreenWidth - exitButton1.GetWidth() * 2 - 5, ScreenHeight - exitButton1.GetHeight() - 5);
}