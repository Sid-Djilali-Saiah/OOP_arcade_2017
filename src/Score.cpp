/*
** EPITECH PROJECT, 2021
** OOP_arcade_2018
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#include <iostream>
#include <fstream>
#include "Score.hpp"

Score::Score(std::string game)
{
	path = "./" + game + ".score";
	file.open(path.c_str(), std::fstream::in);
	if (!file.is_open())
	{
		std::ofstream newFile(path.c_str());
		newFile.close();
		return;
	}
	else
	{
		loadScores(file);
		file.close();
	}
}

void Score::loadScores(std::ifstream &file)
{
	std::string line;
	uint64_t result;
	std::string name;

	while (file.good())
	{
		getline(file, line);
		result = static_cast<uint64_t>(strtol(line.c_str(), nullptr, 0));
		name = line.substr(line.find(':') + 1);
		if (!name.empty())
			scoreTable.insert(std::pair<std::string, uint64_t>(name, result));
	}
}

void Score::saveScores()
{
	std::ofstream file(path, std::fstream::out);

	if (scoreTable.empty() || !file.is_open())
		return;
	for (auto &it : scoreTable)
		file << it.second << ':' << it.first << "\n";
	file.close();
	this->loadScores(this->file);
}

uint64_t Score::getPlayerScore(std::string name)
{
	if (scoreTable.find(name) != scoreTable.end())
		return scoreTable[name];
	return (0);
}

void Score::updatePlayerScore(std::string name, uint64_t score)
{
	if (scoreTable.find(name) != scoreTable.end())
	{
		scoreTable[name] = score;
		return;
	}
	else
		scoreTable.insert(std::pair<std::string, uint64_t>(name, score));
}