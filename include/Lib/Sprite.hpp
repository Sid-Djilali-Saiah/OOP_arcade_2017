/*
** EPITECH PROJECT, 2021
** OOP_arcade_2018
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#ifndef OOP_ARCADE_2018_SPRITE_HPP
#define OOP_ARCADE_2018_SPRITE_HPP

#include <string>
#include "Transformable.hpp"
#include "Drawable.hpp"
#include "Vector.hpp"
#include "RenderTarget.hpp"

class Sprite final : public Transformable, public Drawable
{
public:
	Sprite() = default;
	virtual ~Sprite() = default;

	Sprite(Sprite const &) = delete;
	Sprite(Sprite &&) = default;

	Sprite &operator=(Sprite const &) = delete;
	Sprite &operator=(Sprite &&) = default;

	void draw(RenderTarget &renderer) const;
	void moveTo(Vector2f const &newPos);

	float getRotation() const;
	void setImageFile(std::string const &filepath);

	void setAsciiFile(std::string const &filepath);

	void setSize(Vector2f const &size);

	std::string const &getImageFile() const;

	Vector2f const &getPosition() const;


	void move(Vector2f const &offset);
	std::string const &getAsciiFile() const;
	void setRotation(float rotation);



	Vector2f const &getSize() const;


private:

	Vector2f objPosition;
	std::string asciiF;
	float objRotate;
	Vector2f objSize;
	std::string imgfd;
};

#endif //ARCADE_SPRITE_HPP