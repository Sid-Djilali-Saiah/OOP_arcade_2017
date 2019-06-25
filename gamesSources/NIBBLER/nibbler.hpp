#include "IGame.hpp"
#include "Lib/Sprite.hpp"
#include "Lib/Text.hpp"
#include <vector>
#include <ctime>
#include <chrono>
#include <iostream>

class Nibbler : public IGame
{
    public:
    
    void handleEvent(Event const &event) override;

    void update() override;

    void pause() override;

    void resume() override;

    void quit() override;

    void start() override;

    void restart() override;

    bool isPaused() const override;

    bool isRunning() const override;

    void render(std::unique_ptr<ILib> &window) override;

    void drawWalls();

    void drawFloor();

    void spawnApples();

    LibText *addText(const std::string &text,
        Color color, const Vector2f &position,
        const std::string &font);

    Sprite *addSprite(const std::string &image,
        const std::string &ascii,
        const Vector2f &position,
        const Vector2f &size);

    Sprite *addSnake(const std::string &image, const std::string &ascii,
    const Vector2f &position, const Vector2f &size);

    int getScore() const override;

    private:
    bool running = false;
    Sprite *snake;
    std::vector<Sprite *> walls;
    std::vector<Sprite *> floor;
    Sprite *apple;
    int snakeRotation = 0;
    int score = 0;
    LibText *text;
    KeyCode lastKeyCode;
    std::chrono::milliseconds ms;
    int level;
};