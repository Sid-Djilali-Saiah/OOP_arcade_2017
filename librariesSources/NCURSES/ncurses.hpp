/*
** EPITECH PROJECT, 2021
** OOP_arcade_2018
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#ifndef OOP_ARCADE_SFML_HPP
#define OOP_ARCADE_SFML_HPP

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Lib/RenderTarget.hpp"
#include "Lib/Sprite.hpp"
#include "Lib/Text.hpp"
#include "Lib/Event.hpp"
#include "ILib.hpp"

class NcursesLib : public ILib, public RenderTarget
{
	public:
	NcursesLib() = default;
	~NcursesLib() = default;

	NcursesLib &operator=(NcursesLib &&) = default;
	NcursesLib &operator=(NcursesLib const &) = delete;

	NcursesLib(NcursesLib const &) = delete;
	NcursesLib(NcursesLib &&) = default;

	void create(std::string const &title, Vector2i const &size,RenderSettings const &settings) override;
	void display() override;

	bool isOpen() const override;
	bool pollEvent(Event &event) override;

	void clear() override;
	void close() override;

	void drawSprite(Sprite const &sprite) override;
	void drawText(LibText const &text) override;
	void draw(Drawable const &drawable) override;

	protected:
};

#endif /*OOP_ARCADE_SFML_HPP*/
