/*
** EPITECH PROJECT, 2021
** OOP_arcade_2018
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#ifndef OOP_ARCADE_2018_SCORE_HPP
#define OOP_ARCADE_2018_SCORE_HPP

#include <iostream>
#include <fstream>
#include <map>

class Score
{
	public:
	explicit Score(std::string game);
	virtual ~Score() = default;

	void			saveScores();
	uint64_t		getPlayerScore(std::string name);
	void 			updatePlayerScore(std::string name, uint64_t score);

	std::map<std::string, uint64_t>	scoreTable;

	private:
	std::string						path;
	std::ifstream file;

	void loadScores(std::ifstream &file);

};

#endif //OOP_ARCADE_2018_SCORE_HPP
