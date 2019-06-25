/*
** EPITECH PROJECT, 2021
** sid_arcade
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#include <dirent.h>
#include "Arcade.hpp"
#include <dlfcn.h>
#include "Lib/Text.hpp"
#include "Lib/Sprite.hpp"

void			printVector(std::vector<std::string> &myvector)
{
    for (std::vector<std::string>::iterator it = myvector.begin();
         it != myvector.end(); ++it)
        std::cout << *it << std::endl;
}

std::string 	generateMenuItem(std::string line)
{
	std::size_t index = line.find_last_of('_');
	std::string cleanLine = line.substr(index + 1);
	index = cleanLine.find_last_of('.');
	cleanLine.resize(cleanLine.size() - (cleanLine.size() - index));
	if (line.find("./games") == 0)
	{
		cleanLine = "Start Game : " + cleanLine;
		return (cleanLine);
	}
	else if (line.find("./lib") == 0)
	{
		cleanLine = "Load Library : " + cleanLine;
		return (cleanLine);
	}
	else return (cleanLine);
}

std::string 	generateScoreItem(std::string name, std::size_t score)
{
	std::string line;

	line = name + " -> " + std::to_string(score);
	return (line);
}

Arcade::Arcade(std::string firstLib)
{
    this->currentLib = firstLib;
    this->changegame = false;
    this->changelib = false;
}


bool Arcade::initialize()
{
    if (!loadGamesList("./games/"))
    {
        std::cout
                << "Error loading games : the directory is empty or doesn't exist"
                << std::endl;
        return false;
    }
    if (!loadLibsList("./lib/"))
    {
        std::cout
                << "Error loading libs : the directory is empty or doesn't exist"
                << std::endl;
        return false;
    }
    return true;
}

bool Arcade::loadMode(Arcade::e_mode mode)
{
    switch (mode)
    {
        case GAME:
            this->loadGame();
            break;
        case LIBRARY:
            this->loadLib();
            break;
        case ALL:
            if (!this->loadLib() || !this->loadGame())
                return false;
            break;
    }
    return true;
}

bool readDirectory(std::vector<std::string> &list, const std::string &path)
{
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(path.c_str())) == nullptr)
    {
        perror("");
        return false;
    }
    else {
        while ((ent = readdir(dir)) != nullptr)
        {
            std::string fn = ent->d_name;
            if (fn.substr(fn.find_last_of(".") + 1) == "so")
                list.emplace_back(path + fn);
        }
        closedir(dir);
    }
    return !list.empty();
}

bool Arcade::loadGamesList(std::string path)
{
    return readDirectory(gamesList, path);
}

bool Arcade::loadLibsList(std::string path)
{
    return readDirectory(libsList, path);
}

int	getIndexVector(std::vector<std::string> &myList, const std::string &str)
{
    for(unsigned i = 0; myList.size() != i; i++)
        if(myList[i] == str)
            return (i);
    return(-1);
}

bool Arcade::switchLibrary(Arcade::e_lib dir)
{
    if(dir == UP)
    {
        currentLib = libsList[getIndexVector(libsList, currentLib) + 1 % libsList.size()];
    }
    else if(dir == DOWN)
    {
        currentLib = libsList[(getIndexVector(libsList, currentLib) - 1)  < 0 ?  libsList.size() : getIndexVector(libsList, currentLib) - 1];
    }
    return false;
}

bool Arcade::loadLib()
{
    this->libPtr = dlopen(currentLib.c_str(), RTLD_LAZY);
    if (!libPtr)
    {
        std::cout << "Error loading libraries : Error dlopen" << std::endl;
        return false;
    }
    this->loadDynamicLibrary = (std::unique_ptr<ILib> (*)())dlsym(this->libPtr,
                                                                  "initializer");
    if (this->loadDynamicLibrary == nullptr)
    {
        std::cout << "Error lib: " <<  dlerror() << std::endl;
        dlclose(this->libPtr);
        return false;
    }
    this->lib = this->loadDynamicLibrary();
    return true;
}

bool Arcade::loadGame()
{
   if (this->gameIsRunning())
       return true;
    this->gamePtr = dlopen(currentGame.c_str(), RTLD_LAZY);
    if (!gamePtr)
    {
        std::cout << "Error loading games : Error dlopen" << std::endl;
        return false;
    }


    this->loadDynamicGame = (std::unique_ptr<IGame> (*)())dlsym(this->gamePtr,
                                                                "initializer");
    if (this->loadDynamicGame == NULL)
    {
        std::cout << "Error game: " <<  dlerror() << std::endl;
        dlclose(this->gamePtr);
        return false;
    }
    this->game = this->loadDynamicGame();
    return true;
}


LibText *Arcade::addText(const std::string &text,
                         Color color, const Vector2f &position,
                         const std::string &font)
{
    LibText *mytext = new LibText();
    mytext->setText(text);
    mytext->setFont(font);
    mytext->setColor(color);
    mytext->moveTo(position);
    mytext->setSize(30);
    return (mytext);
}



Sprite *Arcade::addSprite(const std::string &image,
                          const std::string &ascii, const Vector2f &position,
                          const Vector2f &size
)
{
    Sprite *sprite = new Sprite;
    sprite->setImageFile(image);
    sprite->setAsciiFile(ascii);
    sprite->moveTo(position);
    sprite->setSize(size);
    sprite->setRotation(0);
    this->mySprites.push_back(sprite);
    return (sprite);
}


void Arcade::launchMenu()
{
    float i = 0;


    for (auto &it : this->libsList)
    {
        this->myTexts.push_back(addText(generateMenuItem(it), RED,
                                        Vector2f{SQ_WIDTH * 3.f, SQ_HEIGHT * i}, "./assets/font/font.ttf"));
        i = i + 3;
    }
    for (auto &it : this->gamesList)
    {
        this->myTexts.push_back(addText(generateMenuItem(it), RED,
                                        Vector2f{SQ_WIDTH * 3, SQ_HEIGHT * i}, "./assets/font/font.ttf"));
        i = i + 3;
    }
    this->cursor = this->addSprite("assets/menu/cursor.png",
                                   "R:F", Vector2f{SQ_WIDTH * 1.f, SQ_HEIGHT * 0.f},
                                   Vector2f{SQ_WIDTH, SQ_HEIGHT});
}

void Arcade::displayScores()
{

    float i = 0;

    if (this->myScores.empty() == false)
        this->myScores.clear();
    this->myScores.push_back(addText("Scores :", RED,
			Vector2f{SQ_WIDTH * 30, SQ_HEIGHT * i++}, "./assets/font/font.ttf"));
	for (auto &it : this->score->scoreTable)
		this->myScores.push_back(addText(generateScoreItem(it.first, it.second), RED,
			Vector2f{SQ_WIDTH * 30, SQ_HEIGHT * i++}, "./assets/font/font.ttf"));
}


bool Arcade::run()
{
	this->currentGame = "./games/lib_arcade_nibbler.so";
	this->score = new Score("nibbler");
	this->displayScores();
	this->launchMenu();
	while (true) {
		if(this->loop())
			break;
	}
	return false;
}


void Arcade::drawMenu()
{
    for (auto &it : this->myTexts)
        lib->draw(*it);


    for (auto &iiss : this->mySprites)
        lib->draw(*iiss);


    for (auto &xt : this->myScores)
        lib->draw(*xt);
}

void Arcade::handleMenu(Event const &evt)
{
    switch (evt.key.code) {
        case (KeyCode::BackSpace):
            lib->close();
            break;
        case (KeyCode::Down):
            if(this->cursorIndex + 1 <=  2)
            {
                this->cursorIndex++;
                cursor->move(Vector2f{0, SQ_HEIGHT * 3});
            }
            break;
        case (KeyCode::Up):
            if(this->cursorIndex - 1 >= 0)
            {
                this->cursorIndex--;
                cursor->move(Vector2f{0, SQ_HEIGHT * -3});
            }
            break;
        case (KeyCode::Return):
            if (this->cursorIndex == 2) {
                game->start();
                // gameQuitted = false;
            } else {
                this->changelib = true;
            }
            break;
        default:
            break;
    }
}

void Arcade::handleGame(Event const &evt)
{
    switch (evt.key.code) {
        case (KeyCode::Space):
            this->changelib = true;
            if (this->libIndex == 0)
                this->libIndex++;
            else this->libIndex--;
            this->cursorIndex = this->libIndex;
            break;
        case (KeyCode::Escape):
            this->score->updatePlayerScore(this->player, this->game->getScore());
            this->score->saveScores();
            this->displayScores();
            this->game->quit();
            this->cursor->moveTo(Vector2f{SQ_WIDTH * 1.f, SQ_HEIGHT * 0.f});
            this->cursorIndex = 0;
        default:
            break;
    }
}

bool Arcade::gameIsRunning() {
    return game != nullptr && game->isRunning();
}

bool Arcade::loop()
{
    if (!this->loadMode(ALL))
    {
        std::cout << "Invalid Library please try again" << std::endl;
        exit(84);
    }
    this->changelib = false;
    lib->create("Arcade", Vector2i{WIN_WIDTH, WIN_HEIGHT}, RenderSettings{WIN_WIDTH, WIN_HEIGHT});
    lib->display();
    while (lib->isOpen()) {
        Event evt;
        while (lib->pollEvent(evt)) {
            if (this->gameIsRunning()) {
                this->handleGame(evt);
                game->handleEvent(evt);
            } else {
                this->handleMenu(evt);
            }
        }
        if(changelib) {
            this->libIndex = (int)this->cursorIndex;
            if(this->libIndex == 0 || this->libIndex == 1)
                this->currentLib = this->libsList[this->libIndex];
            lib->close();
            break;
        }
        lib->clear();
        if (this->gameIsRunning()) {
            game->render(lib);
            game->update();
            this->score->updatePlayerScore(this->player, this->game->getScore());
        // } else if (!gameQuitted) {
        //     this->cursor->moveTo(Vector2f{SQ_WIDTH * 1.f, SQ_HEIGHT * 0.f});
        //     this->cursorIndex = 0;
        //     gameQuitted = true;
        } else {
            this->score->saveScores();
            this->displayScores();
            this->drawMenu();
        }
        lib->display();
    }
    return false;
}

