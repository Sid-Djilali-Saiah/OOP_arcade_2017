/*
** EPITECH PROJECT, 2021
** sid_arcade
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#include "Arcade.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2 || !strcmp(argv[1], "--help"))
		return (std::cerr << "Usage: ./arcade GRAPHIC_LIBRARY\n\n"
			"  GRAPHIC_LIBRARY Graphic library to load"
			<< std::endl, 0);

	std::string name;
	std::cout << "Enter your Name : ";
	std::cin >> name;
	Arcade *arcade = new Arcade(argv[1]);
	arcade->player = name;
	arcade->initialize();
	if (!arcade->run())
		return (84);
	return (0);
}