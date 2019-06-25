/*
** EPITECH PROJECT, 2021
** sid_arcade
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#include "Lib/Sprite.hpp"



void
Sprite::move(Vector2f const &offset)
{
    this->objPosition.x += offset.x;
    this->objPosition.y += offset.y;
}

Vector2f const&
Sprite::getPosition() const
{
    return (this->objPosition);
}

void
Sprite::setImageFile(std::string const &filepath)
{
    this->imgfd = filepath;
}

void Sprite::setAsciiFile(std::string const &filepath)
{
    this->asciiF = filepath;
}

void
Sprite::setSize(Vector2f const &size)
{
    this->objSize = size;
}

float
Sprite::getRotation() const
{
    return (this->objRotate);
}


void Sprite::setRotation(float rotation)
{
    this->objRotate = rotation;
}

std::string const&
Sprite::getImageFile() const
{
    return (this->imgfd);
}

std::string const&
Sprite::getAsciiFile() const
{
    return (this->asciiF);
}

Vector2f const&
Sprite::getSize() const
{
    return (this->objSize);
}


void
Sprite::draw(RenderTarget &renderer) const
{
    renderer.drawSprite(*this);
}

void
Sprite::moveTo(Vector2f const &newPos)
{
    this->objPosition = newPos;
}