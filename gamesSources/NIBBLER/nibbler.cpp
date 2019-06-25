#include "Lib/Event.hpp"
#include <bits/unique_ptr.h>
#include "nibbler.hpp"

extern "C"  std::unique_ptr<IGame> initializer()
{
    return (std::unique_ptr<IGame>(new Nibbler));
}

void Nibbler::handleEvent(const Event &event)
{
     switch (event.key.code) {
        case (KeyCode::Up):
                this->lastKeyCode = event.key.code;
            break;
        case (KeyCode::Down):
                this->lastKeyCode = event.key.code;
            break;
        case (KeyCode::Left):
                this->lastKeyCode = event.key.code;
            break;
        case (KeyCode::Right):
                this->lastKeyCode = event.key.code;
            break;
        default:
            break;
    }
}

void Nibbler::update()
{
    int height = rand() % (736 - 64) + 32;
    height = height / 32 * 32;
    int width = rand() % (1280 - 64) + 32;
    width = width / 32 * 32;

    if ((std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch() - this->ms).count() > this->level))
    {
        switch (this->lastKeyCode)
        {
        case (KeyCode::Up):
                this->snake->move(Vector2f{0, -SQ_HEIGHT});
                this->snakeRotation = 180;
            break;
        case (KeyCode::Down):
                this->snake->move(Vector2f{0, SQ_HEIGHT});
                this->snakeRotation = 0;
            break;
        case (KeyCode::Left):
                this->snake->move(Vector2f{-SQ_HEIGHT, 0});
                this->snakeRotation = 90;
            break;
        case (KeyCode::Right):
                this->snake->move(Vector2f{SQ_HEIGHT, 0});
                this->snakeRotation = 270;
            break;
        default:
            break;
        }
        ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    }
    if (this->snake->getPosition().x == this->apple->getPosition().x && this->snake->getPosition().y == this->apple->getPosition().y)
        {
            this->apple->moveTo(Vector2f{width * 1.0f, height * 1.0f});
            this->score += 10;
            this->text->setText(std::to_string(score));
        }
    if (this->snake->getPosition().x == 1248 || this->snake->getPosition().x == 0 || this->snake->getPosition().y == 704 || this->snake->getPosition().y == 0)
        this->running = false;
    if (this->score != 0 && this->level > 80 && this->score % 30 == 0)
        this->level = this->level - 20;
    
}

void Nibbler::pause()
{
}

void Nibbler::resume()
{
}

void Nibbler::quit()
{
    this->floor.clear();
    this->walls.clear();
    this->running = false;
}

void Nibbler::drawFloor()
{
    for (int i = 32; i < 704; i += 32)
    {
        for (int j = 32; j < 1248; j += 32)
        {
            this->floor.push_back(this->addSprite("assets/floor.png",
            "W:F", Vector2f{(float)j , (float)i},
            Vector2f{SQ_WIDTH, SQ_HEIGHT}));
        }
        
    }
}

void Nibbler::drawWalls()
{
    for (float i = 0; i < 1280; i += 32)
    {
        this->walls.push_back(this->addSprite("assets/wall.png",
            "G:F", Vector2f{i , 0},
            Vector2f{32, SQ_HEIGHT}));
        this->walls.push_back(this->addSprite("assets/wall.png",
            "G:F", Vector2f{i , 704},
            Vector2f{32, SQ_HEIGHT}));
    }
    for (float i = 0; i < 736; i += 32)
    {
        this->walls.push_back(this->addSprite("assets/wall.png",
            "G:F", Vector2f{0 , i},
            Vector2f{32, SQ_HEIGHT}));
        this->walls.push_back(this->addSprite("assets/wall.png",
            "G:F", Vector2f{1248 , i},
            Vector2f{32, SQ_HEIGHT}));
    }
}

void Nibbler::start()
{
    running = true;
    this->score = 0;
    this->snakeRotation = 0;
    this->level = 280;
    this->ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    this->lastKeyCode = KeyCode::Down;
    this->drawWalls();
    this->drawFloor();
    this->spawnApples();
    this->snake = this->addSnake("assets/snake.png",
                               "B:F", Vector2f{64, 64},
                                Vector2f{32, SQ_HEIGHT});
    this->snake->moveTo(Vector2f{64, 64});
    this->text = addText(std::to_string(score), WHITE,
                                        Vector2f{1100, 64}, "./assets/font/font.ttf");
}

void Nibbler::restart()
{
}

bool Nibbler::isPaused() const
{
    return false;
}

bool Nibbler::isRunning() const
{
    return running;
}

void Nibbler::render(std::unique_ptr<ILib> &window)
{
    for (auto &it : this->floor)
    {
        window->draw(*it);
    }
    for (auto &it : this->walls)
    {
        window->draw(*it);
    }
    window->draw(*apple);
    window->draw(*snake);
    window->draw(*text);
}

void Nibbler::spawnApples()
{
    int height = rand() % (736 - 64) + 32;
    height = height / 32 * 32;
    int width = rand() % (1280 - 64) + 32;
    width = width / 32 * 32;
    this->apple = this->addSprite("assets/apple.png",
            "R:F", Vector2f{width * 1.0f, height * 1.0f},
            Vector2f{SQ_WIDTH, SQ_HEIGHT});
}

LibText *Nibbler::addText(const std::string &text,
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

Sprite *Nibbler::addSnake(const std::string &image, const std::string &ascii,
    const Vector2f &position, const Vector2f &size)
{
    Sprite *sprite = new Sprite();
    sprite->setImageFile(image);
    sprite->setAsciiFile(ascii);
    sprite->moveTo(position);
    sprite->setSize(size);
    sprite->setRotation(this->snakeRotation);;
    return (sprite);
}

Sprite *Nibbler::addSprite(const std::string &image, const std::string &ascii,
    const Vector2f &position, const Vector2f &size)
{
    Sprite *sprite = new Sprite();
    sprite->setImageFile(image);
    sprite->setAsciiFile(ascii);
    sprite->moveTo(position);
    sprite->setSize(size);
    sprite->setRotation(0);
    return (sprite);
}

int Nibbler::getScore() const
{
    return score;
}
