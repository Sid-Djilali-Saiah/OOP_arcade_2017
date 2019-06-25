/*
** EPITECH PROJECT, 2021
** OOP_arcade_2018
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#ifndef OOP_ARCADE_IGAME_HPP
#define OOP_ARCADE_IGAME_HPP

#include <string>
#include <memory>
#include <map>
#include "Lib/Event.hpp"
#include "ILib.hpp"

class IGame
{
    public:

        IGame() = default;
        virtual ~IGame() = default;

        IGame(IGame const &) = delete;
        IGame(IGame &&) = default;

        IGame &operator=(IGame const &) = delete;
        IGame &operator=(IGame &&) = default;

        virtual void handleEvent(Event const &event) = 0;
        virtual void update() = 0;
        virtual void pause() = 0;
        virtual void resume() = 0;
        virtual void quit() = 0;
        virtual void start() = 0;
        virtual void restart() = 0;
        virtual bool isPaused() const = 0;
        virtual bool isRunning() const = 0;
        virtual int getScore() const = 0;
        virtual void render(std::unique_ptr<ILib> &window) = 0;
};


#endif //ARCADE_IGAME_HPP
