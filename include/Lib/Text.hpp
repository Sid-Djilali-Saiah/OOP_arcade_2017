/*
** EPITECH PROJECT, 2021
** OOP_arcade_2018
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#ifndef OOP_ARCADE_2018_TEXT_HPP
#define OOP_ARCADE_2018_TEXT_HPP

#include <string>

#include "Lib/Color.hpp"
#include "Lib/Drawable.hpp"
#include "Lib/RenderTarget.hpp"
#include "Lib/Transformable.hpp"
#include "Lib/Vector.hpp"

class LibText final : public Transformable, public Drawable
{
public:
	LibText() = default;
	virtual ~LibText() = default;

	LibText(LibText const &) = delete;
	LibText(LibText &&) = default;

	LibText &operator=(LibText const &) = delete;
	LibText &operator=(LibText &&) = default;


	std::string const &getFont() const;

	void move(Vector2f const &offset);
	void draw(RenderTarget &renderer) const;

	void moveTo(Vector2f const &newPos);


	void setText(std::string const &text);
	void setColor(Color const &color);
	Vector2f const &getPosition() const;

	void setSize(std::size_t size);

	std::size_t getSize() const;

	std::string const &getText() const;
	void setFont(std::string const &fontpath);


	Color const &getColor() const;

private:
	std::string objText;
	std::string objFont;
	Vector2f objPosition;
	std::size_t objSize;
	Color objColor;
};

#endif //ARCADE_TEXT_HPP