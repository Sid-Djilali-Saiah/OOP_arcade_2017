/*
** EPITECH PROJECT, 2021
** OOP_arcade_2018
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#ifndef OOP_ARCADE_2018_RENDERTARGET_HPP
#define OOP_ARCADE_2018_RENDERTARGET_HPP

class Sprite;
class LibText;

class RenderTarget
{
public:
	RenderTarget() = default;
	virtual ~RenderTarget() = default;

	RenderTarget(RenderTarget const &) = delete;
	RenderTarget(RenderTarget &&) = default;

	RenderTarget &operator=(RenderTarget const &) = delete;
	RenderTarget &operator=(RenderTarget &&) = default;

	virtual void drawSprite(Sprite const &sprite) = 0;

	virtual void drawText(LibText const &txt) = 0;
};

#endif //ARCADE_RENDERTARGET_HPP