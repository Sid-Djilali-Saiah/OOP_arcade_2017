/*
** EPITECH PROJECT, 2021
** sid_arcade
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#include "Lib/Text.hpp"



void
LibText::move(Vector2f const &offset)
{
    this->objPosition.x += offset.x;
    this->objPosition.y += offset.y;
}



void
LibText::setText(std::string const &text)
{
    this->objText = text;
}

void
LibText::setFont(std::string const &fontpath)
{
    this->objFont = fontpath;
}



void
LibText::setSize(std::size_t size)
{
    this->objSize = size;
}


void
LibText::setColor(Color const &color)
{
    this->objColor = color;
}

const Vector2f &
LibText::getPosition() const
{
    return (this->objPosition);
}

const std::string &
LibText::getText() const
{
    return (this->objText);
}

const std::string &
LibText::getFont() const
{
    return (this->objFont);
}

std::size_t
LibText::getSize() const
{
    return (this->objSize);
}

void
LibText::moveTo(Vector2f const &newPos)
{
    this->objPosition = newPos;
}



void
LibText::draw(RenderTarget &renderer) const
{
    renderer.drawText(*this);
}


const Color &
LibText::getColor() const
{
    return (this->objColor);
}
