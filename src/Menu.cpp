#include "game.h"
#include "surface.h"
#include "template.h"
#include "windows.h"
#include "Menu.h"
#include <conio.h>
#include <iostream>


void Menu::initMenu(Menu::Type& menuType, Tmpl8::Surface* screen ,const Tmpl8::vec2& posMouse, bool& inMenu) {
    switch (menuType)
    {
    case Menu::Type::MENU:
        updateMenu(menuType, screen, posMouse, inMenu);
        break;
    case Menu::Type::PLAYS:
        updatePlays(menuType, screen, posMouse, inMenu);
        break;
    case Menu::Type::PAUSE:
        updatePause(menuType, screen, posMouse, inMenu);
        break;
    case Menu::Type::CONTROLS:
        updateControls(menuType, screen, posMouse, inMenu);
        break;
    case Menu::Type::DEAD:
        updateDead(menuType, screen, posMouse, inMenu);
        break;
    case Menu::Type::WIN:
        updateWin(menuType, screen, posMouse, inMenu);
        break;
    default:
        break;
    }
}

void Menu::drawMenu(Tmpl8::Surface* screen)
{
    menuBackground.Draw(screen, 0, 0);
    startButton1.Draw(screen, 360, 220);
    controlButton1.Draw(screen, 360, 300);
    exitButton1.Draw(screen, 360, 380);
}

void Menu::drawPlays(Tmpl8::Surface* screen) {
    backButton1.Draw(screen, 10, ScreenHeight - backButton1.GetHeight() -5);
}

void Menu::drawPause(Tmpl8::Surface* screen) {
    pauseMenu.Draw(screen, 0, 0);
    menuButton.Draw(screen, ScreenWidth-menuButton.GetWidth()-5, ScreenHeight-menuButton.GetHeight() -5);
    resumeButton.Draw(screen, 360, 300);
}

void Menu::drawControls(Tmpl8::Surface* screen) {
    controlMenu.Draw(screen, 0, 0);
    backButton1.Draw(screen, 10, ScreenHeight - backButton1.GetHeight() - 5);
}

void Menu::drawDead(Tmpl8::Surface* screen) {

}

void Menu::drawWin(Tmpl8::Surface* screen) {

}

void Menu::updateMenu(Menu::Type& menuType,Tmpl8::Surface* screen, const Tmpl8::vec2& posMouse, bool& inMenu)
{
    drawMenu(screen);

    bool leftPressed = GetAsyncKeyState(VK_LBUTTON);

    bool collidesLevelsButton = (posMouse.x >= 360  && posMouse.x <= 520) && (posMouse.y >= 220 && posMouse.y <= 295);
    if (collidesLevelsButton)
    {
        startButton2.Draw(screen, 360, 220);
        if (leftPressed) menuType = Type::PLAYS;
    }

    bool collidesControlsButton = (posMouse.x >= 360 && posMouse.x <= 520) && (posMouse.y >= 300 && posMouse.y <= 375);
    if (collidesControlsButton)
    {
        controlButton2.Draw(screen, 360, 300);
        if (leftPressed) {
            if (leftPressed) menuType = Type::CONTROLS;
        }
    }

    bool collidesExitButton = (posMouse.x >= 360 && posMouse.x <= 520) && (posMouse.y >= 380 && posMouse.y <= 455);
    if (collidesExitButton)
    { 
       exitButton2.Draw(screen, 360, 380);
       if (leftPressed) {
           SDL_Event user_event;
           user_event.type = SDL_QUIT;
           SDL_PushEvent(&user_event);
       }
    }

}

void Menu::updatePlays(Menu::Type& menuType, Tmpl8::Surface* screen, const Tmpl8::vec2& posMouse, bool& inMenu) {
    drawPlays(screen);
    bool leftPressed = GetAsyncKeyState(VK_LBUTTON);
    float yPos = ScreenHeight - backButton1.GetHeight() - 5;
    inMenu = false;

    bool collidesBackButton = (posMouse.x >= 10 && posMouse.x <= 80) && 
        (posMouse.y >= yPos && posMouse.y <= yPos + 36);
    if (collidesBackButton)
    {
        backButton2.Draw(screen, 10, yPos);
        if (leftPressed) {
            menuType = Type::MENU;
            inMenu = true;
        }
    }


    bool pause = GetAsyncKeyState(VK_ESCAPE);
        if (pause) {
            menuType = Type::PAUSE;
            inMenu = true;
        }
}

void Menu::updatePause(Menu::Type& menuType, Tmpl8::Surface* screen, const Tmpl8::vec2& posMouse, bool& inMenu) {
    drawPause(screen);
    bool leftPressed = GetAsyncKeyState(VK_LBUTTON);

    bool collidesMenuButton = (posMouse.x >= ScreenWidth - menuButton.GetWidth() - 5 && posMouse.x <= ScreenWidth - 5) &&
        (posMouse.y >= ScreenHeight - menuButton.GetHeight() - 5 && posMouse.y <= ScreenHeight - 5);
    if (collidesMenuButton)
    {
        menuButton2.Draw(screen, ScreenWidth - menuButton.GetWidth() - 5, ScreenHeight - menuButton.GetHeight() - 5);
        if (leftPressed) {
            menuType = Type::MENU;
            inMenu = true;
        }
    }

    bool collidesResumeButton = (posMouse.x >= 360 && posMouse.x <= 520) &&
        (posMouse.y >= 300 && posMouse.y <= 381);
    if (collidesResumeButton)
    {
        resumeButton2.Draw(screen, 360, 300);
        if (leftPressed) {
            menuType = Type::PLAYS;
            inMenu = true;
        }
    }
}

void Menu::updateControls(Menu::Type& menuType, Tmpl8::Surface* screen, const Tmpl8::vec2& posMouse, bool& inMenu) {
    drawControls(screen);
    bool leftPressed = GetAsyncKeyState(VK_LBUTTON);
    float yPos = ScreenHeight - backButton1.GetHeight() - 5;
    inMenu = false;

    bool collidesLevelsButton = (posMouse.x >= 10 && posMouse.x <= 80) &&
        (posMouse.y >= yPos && posMouse.y <= yPos + 36);
    if (collidesLevelsButton)
    {
        backButton2.Draw(screen, 10, yPos);
        if (leftPressed) {
            menuType = Type::MENU;
            inMenu = true;
        }
    }
    bool back = GetAsyncKeyState(SDLK_ESCAPE);
    if (back) {
        menuType = Type::MENU;
        inMenu = true;
    }
}

void Menu::updateDead(Menu::Type& menuType, Tmpl8::Surface* screen, const Tmpl8::vec2& posMouse, bool& inMenu) {

}

void Menu::updateWin(Menu::Type& menuType, Tmpl8::Surface* screen, const Tmpl8::vec2& posMouse, bool& inMenu) {

}