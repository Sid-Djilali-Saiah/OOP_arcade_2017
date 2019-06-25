/*
** EPITECH PROJECT, 2021
** OOP_arcade_2018
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#include <iostream>
#include "ILib.hpp"
#include "sfml.hpp"

extern "C"  std::unique_ptr<ILib> initializer()
{
	return (std::unique_ptr<ILib>(new SfmlLib));
}

static inline Event eventConverter(const sf::Event &event)
{
	Event Event;

	if (event.type == sf::Event::EventType::KeyPressed)
	{
		Event.type = EventType::KeyPressed;
		switch (event.key.code) {
		case (sf::Keyboard::Up):
			Event.key.code = KeyCode::Up;
			break ;
		case (sf::Keyboard::Down):
			Event.key.code = KeyCode::Down;
			break ;
		case (sf::Keyboard::Left):
			Event.key.code = KeyCode::Left;
			break ;
		case (sf::Keyboard::Right):
			Event.key.code = KeyCode::Right;
			break ;
		case (sf::Keyboard::K):
			Event.key.code = KeyCode::K;
			break ;
		case (sf::Keyboard::L):
			Event.key.code = KeyCode::L;
			break ;
		case (sf::Keyboard::M):
			Event.key.code = KeyCode::M;
			break ;
		case (sf::Keyboard::I):
			Event.key.code = KeyCode::I;
			break ;
		case (sf::Keyboard::O):
			Event.key.code = KeyCode::O;
			break ;
		case (sf::Keyboard::P):
			Event.key.code = KeyCode::P;
			break ;
		case (sf::Keyboard::Escape):
			Event.key.code = KeyCode::Escape;
			break ;
		case (sf::Keyboard::Return):
			Event.key.code = KeyCode::Return;
			break ;
		case (sf::Keyboard::Space):
			Event.key.code = KeyCode::Space;
			break ;		default:
			Event.key.code = KeyCode::Unknown;
		}
	}
	return (Event);
}

void SfmlLib::close()
{
	this->_window->close();
}

bool SfmlLib::isOpen() const
{
	return (this->_window->isOpen());
}

void SfmlLib::create(std::string const &title, const Vector2i &size,
	RenderSettings const &settings)
{
	(void)settings;
	this->_window = new sf::RenderWindow(sf::VideoMode(size.x, size.y), title);
}

bool SfmlLib::pollEvent(Event &event)
{
	sf::Event Event;

	if (!this->_window->pollEvent(Event))
		return (false);
	event = eventConverter(Event);
	return (true);
}

void SfmlLib::clear()
{
	this->_window->clear(sf::Color::Black);
}

void SfmlLib::draw(const Drawable &drawable)
{
	drawable.draw(*this);
}

void SfmlLib::display()
{
	this->_window->display();
}

void SfmlLib::drawSprite(const Sprite &sprite)
{
	sf::Texture Texture;
	sf::Sprite Sprite;
	float textureSize[2];
	float size[2];

	if (sprite.getAsciiFile() == "Black")
		return ;
	Texture.loadFromFile(sprite.getImageFile());
	Sprite.setTexture(Texture);
	if (sprite.getSize().x > 0 && sprite.getSize().y > 0)
	{
		textureSize[0] = Texture.getSize().x;
		textureSize[1] = Texture.getSize().y;
		size[0] = sprite.getSize().x;
		size[1] = sprite.getSize().y;
		Sprite.setScale(size[0] / textureSize[0], size[1] / textureSize[1]);
	}
	Sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y);
	Sprite.setRotation(sprite.getRotation());
	this->_window->draw(Sprite);
}

void SfmlLib::drawText(const LibText &text)
{
	sf::Text libtext;
	sf::Font Font;
	Color color;

	libtext.setString(text.getText());
	Font.loadFromFile(text.getFont());
	libtext.setPosition(text.getPosition().x, text.getPosition().y);
	libtext.setCharacterSize(text.getSize());
	libtext.setFont(Font);
	color = text.getColor();
	this->_window->draw(libtext);
}