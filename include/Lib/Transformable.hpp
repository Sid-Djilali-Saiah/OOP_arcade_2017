/*
** EPITECH PROJECT, 2021
** OOP_arcade_2018
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#pragma once

#include "Vector.hpp"

class Transformable
{
public:
	Transformable() = default;
	virtual ~Transformable() = default;

	Transformable(Transformable const &) = delete;
	Transformable(Transformable &&) = default;

	Transformable &operator=(Transformable const &) = delete;
	Transformable &operator=(Transformable &&) = default;

	/**
     * \brief Move the transformable to the given position.
     * \param Vector2f newPos
     */
	virtual void moveTo(Vector2f const &newPos) = 0;

	/**
     * \brief Move the transformable by the given offset.
     * \param Vector2f offset
     */
	virtual void move(Vector2f const &offset) = 0;

	/**
     * \brief Get the transformable current position.
     * \return Vector2f
     */
	virtual Vector2f const &getPosition() const = 0;
};
