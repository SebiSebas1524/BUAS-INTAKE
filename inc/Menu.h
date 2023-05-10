#pragma once
#include "template.h"
#include "surface.h"
#include "Windows.h"
#include "SDL.h"
#include <Sound.hpp>

class Menu
{
public:
    enum class Type {
        MENU,
        PLAYS,
        PAUSE,
        CONTROLS,
        DEAD,
        WIN
    };

    Menu() :  /* Initializes the sprite buttons*/
        menuBackground(new Tmpl8::Surface("assets/Background/underwaterMenu.png"), 1),
        startButton1(new Tmpl8::Surface("assets/Buttons/START.png"), 1),
        exitButton1(new Tmpl8::Surface("assets/Buttons/EXIT.png"), 1),
        startButton2(new Tmpl8::Surface("assets/Buttons/START2.png"), 1),
        exitButton2(new Tmpl8::Surface("assets/Buttons/EXIT2.png"), 1),
        backButton1(new Tmpl8::Surface("assets/Buttons/BackB.png"), 1),
        backButton2(new Tmpl8::Surface("assets/Buttons/BackB2.png"), 1),
        controlButton1(new Tmpl8::Surface("assets/Buttons/ControlsB.png"), 1),
        controlButton2(new Tmpl8::Surface("assets/Buttons/ControlsB2.png"), 1),
        controlMenu(new Tmpl8::Surface("assets/Background/ControlsMenu.png"), 1),
        replayButton1(new Tmpl8::Surface("assets/Buttons/ReplayButton.png"), 1),
        replayButton2(new Tmpl8::Surface("assets/Buttons/ReplayButton2.png"), 1),
        deadMenu(new Tmpl8::Surface("assets/Background/DeadMenu.png"), 1),
        pauseMenu(new Tmpl8::Surface("assets/Background/pauseMenu.png"), 1),
        menuButton(new Tmpl8::Surface("assets/Buttons/ButtoneMenu.png"), 1),
        menuButton2(new Tmpl8::Surface("assets/Buttons/ButtonMenu.png"), 1),
        resumeButton(new Tmpl8::Surface("assets/Buttons/ResumeButton.png"), 1),
        resumeButton2(new Tmpl8::Surface("assets/Buttons/ResumeButton2.png"), 1),
        winMenu(new Tmpl8::Surface("assets/Background/WinMenu.png"), 1)
    {}

    /*Update for menu*/
    void updateMenu(Menu::Type& menuType, Tmpl8::Surface* screen, const Tmpl8::vec2& posMouse, bool& inMenu);
    void updatePrincipalMenu(Menu::Type& menuType, Tmpl8::Surface* screen, const Tmpl8::vec2& posMouse, bool& inMenu);
    void updatePlays(Menu::Type& menuType, Tmpl8::Surface* screen, const Tmpl8::vec2& posMouse, bool& inMenu);
    void updateControls(Menu::Type& menuType, Tmpl8::Surface* screen, const Tmpl8::vec2& posMouse, bool& inMenu);
    void updateDead(Menu::Type& menuType, Tmpl8::Surface* screen, const Tmpl8::vec2& posMouse, bool& inMenu);
    void updateWin(Menu::Type& menuType, Tmpl8::Surface* screen, const Tmpl8::vec2& posMouse, bool& inMenu);
    void updatePause(Menu::Type& menuType, Tmpl8::Surface* screen, const Tmpl8::vec2& posMouse, bool& inMenu);
   
    /* Function for drawing diferent menu*/
    void drawPrincipalMenu(Tmpl8::Surface* screen);
    void drawPlays(Tmpl8::Surface* screen);
    void drawControls(Tmpl8::Surface* screen);
    void drawDead(Tmpl8::Surface* screen);
    void drawWin(Tmpl8::Surface* screen);
    void drawPause(Tmpl8::Surface* screen);
    



private:
    Audio::Sound click{ "assets/SFX/click.wav" };
    Audio::Sound winS{ "assets/SFX/windoot.wav" };
    Audio::Sound loseS{ "assets/SFX/loseS.wav" };

    bool played{ false };
    //All the sprites for menu
    Tmpl8::Sprite exitButton1;
    Tmpl8::Sprite exitButton2;
    Tmpl8::Sprite backButton1;
    Tmpl8::Sprite backButton2;
    Tmpl8::Sprite menuBackground;
    Tmpl8::Sprite controlMenu;
    Tmpl8::Sprite startButton1;
    Tmpl8::Sprite startButton2;
    Tmpl8::Sprite controlButton1;
    Tmpl8::Sprite controlButton2;
    Tmpl8::Sprite replayButton1;
    Tmpl8::Sprite replayButton2;
    Tmpl8::Sprite deadMenu;
    Tmpl8::Sprite pauseMenu;
    Tmpl8::Sprite menuButton;
    Tmpl8::Sprite menuButton2;
    Tmpl8::Sprite resumeButton;
    Tmpl8::Sprite resumeButton2;
    Tmpl8::Sprite winMenu;
};