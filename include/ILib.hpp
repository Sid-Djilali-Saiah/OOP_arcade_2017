/*
** EPITECH PROJECT, 2021
** OOP_arcade_2018
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#ifndef OOP_ARCADE_ILIB_HPP
#define OOP_ARCADE_ILIB_HPP

#include <cstddef>
#include <string>
#include "Lib/Drawable.hpp"
#include "Lib/Event.hpp"
#include "Lib/Vector.hpp"

#define WIN_WIDTH 1280
#define WIN_HEIGHT 736

#define SQ_HEIGHT 32
#define SQ_WIDTH 32

#define SQN_HEIGHT (WIN_HEIGHT / SQ_HEIGHT)
#define SQN_WIDTH (WIN_WIDTH / SQ_WIDTH)

#define BLUE {0, 0, 255, 255}
#define WHITE {255, 255, 255, 255}
#define GREEN {0, 255, 0, 255}
#define YELLOW {255, 255, 0, 255}
#define RED {255, 0, 0, 255}
#define BLACK {0, 0, 0, 255}


struct RenderSettings final
{
    std::size_t width;
    std::size_t height;
};

class ILib
{
	public:
	ILib() = default;
	virtual ~ILib() = default;

	ILib(ILib const &) = delete;
	ILib(ILib &&) = default;

	ILib &operator=(ILib const &) = delete;
	ILib &operator=(ILib &&) = default;


	virtual void create(std::string const &title, Vector2i const &size, RenderSettings const &settings) = 0;

	virtual void close() = 0;

	virtual bool isOpen() const = 0;

	virtual bool pollEvent(Event &event) = 0;

	virtual void clear() = 0;

	virtual void draw(Drawable const &drawable) = 0;

	virtual void display() = 0;
};

#endif //ARCADE_ILIB_HPP