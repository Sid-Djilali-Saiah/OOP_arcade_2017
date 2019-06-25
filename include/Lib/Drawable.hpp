/*
** EPITECH PROJECT, 2021
** OOP_arcade_2018
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#ifndef OOP_ARCADE_2018_DRAWABLE_HPP
#define OOP_ARCADE_2018_DRAWABLE_HPP

#include "RenderTarget.hpp"

class Drawable
{
public:
	Drawable() = default;
	virtual ~Drawable() = default;

	Drawable(Drawable const &) = delete;
	Drawable(Drawable &&) = default;

	Drawable &operator=(Drawable const &) = delete;
	Drawable &operator=(Drawable &&) = default;

	virtual void draw(RenderTarget &renderer) const = 0;
};

#endif //OOP_ARCADE_2018_DRAWABLE_HPP