/*
** EPITECH PROJECT, 2021
** sid_arcade
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#ifndef SID_ARCADE_ARCADE_HPP
#define SID_ARCADE_ARCADE_HPP

#include <iostream>
#include <cstring>
#include <vector>
#include <bits/unique_ptr.h>
#include <Lib/Color.hpp>
#include "../include/ILib.hpp"
#include "../include/IGame.hpp"
#include "Score.hpp"

class Arcade
{
public:

    explicit Arcade(std::string lib);
    virtual ~Arcade() = default;

    enum e_mode {GAME, LIBRARY, ALL};
    bool		initialize();
    bool 		loadMode(e_mode mode);
    bool		loadGamesList(std::string path);
    bool		loadLibsList(std::string path);
    bool 		loadLib();
    bool 		loadGame();
	void 		drawMenu();
	void 		launchMenu();
	void		displayScores();
    bool		run();
    LibText        *addText(const std::string &text,
                  Color color, const Vector2f &position,
                  const std::string &font);
    Sprite *addSprite(const std::string &image,
                              const std::string &ascii, const Vector2f &position,
                              const Vector2f &size
    );
    void handleMenu(Event const &evt);
    bool        gameIsRunning();
    void handleGame(Event const &evt);
    bool		loop();
    enum e_lib {UP, DOWN};
    bool		switchLibrary(e_lib dir);

    std::vector<std::string> gamesList;
    std::vector<std::string> libsList;


    std::vector<LibText*> myTexts;
    std::vector<LibText*> myScores;
    std::vector<Sprite*> mySprites;
    Sprite* cursor;
    bool changelib = false;
    bool changegame = false;
    float cursorIndex = 0;


    std::string currentLib;
    std::string currentGame;

    void	*libPtr;
    void	*gamePtr;
	Score 	*score;

    std::unique_ptr<ILib> (*loadDynamicLibrary)();
    std::unique_ptr<IGame> (*loadDynamicGame)();

    std::unique_ptr <ILib> lib;
    std::unique_ptr <IGame> game;

    std::string				 player;
    int                      libIndex = 0;
    bool                     gameQuitted = false;
};

#endif //SID_ARCADE_ARCADE_HPP
