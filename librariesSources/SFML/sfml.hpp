/*
** EPITECH PROJECT, 2021
** OOP_arcade_2018
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#ifndef ARCADE_SFML_HPP
#define ARCADE_SFML_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Lib/RenderTarget.hpp"
#include "Lib/Event.hpp"
#include "Lib/Text.hpp"
#include "Lib/Sprite.hpp"
#include "ILib.hpp"

class SfmlLib : public ILib, public RenderTarget
{
	public:
	SfmlLib() = default;
	~SfmlLib() = default;

	SfmlLib &operator=(SfmlLib &&) = default;
	SfmlLib &operator=(SfmlLib const &) = delete;

	SfmlLib(SfmlLib const &) = delete;
	SfmlLib(SfmlLib &&) = default;

	void close() override;
	void draw(Drawable const &drawable) override;
	bool pollEvent(Event &event) override;
	void display() override;
	bool isOpen() const override;
	void drawText(LibText const &text) override;
	void create(std::string const &title, Vector2i const &size,RenderSettings const &settings) override;
	void clear() override;
	void drawSprite(Sprite const &sprite) override;
	
	protected:
	sf::RenderWindow *_window = 0;
};

#endif /*ARCADE_SFML_HPP*/
