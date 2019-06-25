/*
** EPITECH PROJECT, 2021
** OOP_arcade_2018
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/


#ifndef OOP_ARCADE_2018_COLOR_HPP
#define OOP_ARCADE_2018_COLOR_HPP

#include <cstdint>

union Color
{
	struct
	{
		std::uint8_t r;
		std::uint8_t g;
		std::uint8_t b;
		std::uint8_t a;
	};

	std::uint32_t rgba;
};

#endif //OOP_ARCADE_2018_COLOR_HPP