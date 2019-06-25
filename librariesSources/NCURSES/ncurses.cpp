/*
** EPITECH PROJECT, 2021
** OOP_arcade_2018
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#include "ILib.hpp"
#include "ncurses.hpp"
#include <unistd.h>
#include <memory>
#include <ncurses.h>

extern "C"  std::unique_ptr<ILib> initializer()
{
    return (std::unique_ptr<ILib>(new NcursesLib));
}

bool NcursesLib::isOpen() const
{
    return (true);
}

static inline Event eventConverter(const int event)
{
    Event Event;
    Event.type = EventType::KeyPressed;

    switch (event) {
        case (260):
            Event.key.code = KeyCode::Left;
            break ;
        case (261):
            Event.key.code = KeyCode::Right;
            break ;
        case (259):
            Event.key.code = KeyCode::Up;
            break ;
        case (258):
            Event.key.code = KeyCode::Down;
            break ;
        case ('i'):
            Event.key.code = KeyCode::I;
            break ;
        case ('o'):
            Event.key.code = KeyCode::O;
            break ;
        case ('p'):
            Event.key.code = KeyCode::P;
            break ;
        case (107):
            Event.key.code = KeyCode::K;
            break ;
        case ('l'):
            Event.key.code = KeyCode::L;
            break ;
        case (109):
            Event.key.code = KeyCode::M;
            break ;
        case (27):
            Event.key.code = KeyCode::Escape;
            break ;
        case ('\n'):
            Event.key.code = KeyCode::Return;
            break ;
        case (' '):
            Event.key.code = KeyCode::Space;
            break ;
        default:
            Event.key.code = KeyCode::Unknown;
    }
    return (Event);
}

void NcursesLib::create(std::string const &title,
	const Vector2i &size,
	RenderSettings const &settings)
{
	(void)title;
	(void)size;
	(void)settings;
	resizeterm(1280, 736);
	initscr();
	nodelay(stdscr, true);
	keypad(stdscr, true);
	noecho();
	curs_set(0);
	assume_default_colors(COLOR_RED, COLOR_BLACK);
	start_color();
	init_pair(0, COLOR_GREEN, COLOR_GREEN);
	init_pair(1, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(2, COLOR_RED, COLOR_RED);
	init_pair(3, COLOR_BLUE, COLOR_BLUE);
	init_pair(6, COLOR_WHITE, COLOR_WHITE);
	init_pair(7, COLOR_YELLOW, COLOR_BLACK);
	init_pair(8, COLOR_WHITE, COLOR_BLACK);
}

static inline int colorConverter(std::string grid)
{
	int color = grid.c_str()[0];
	if(grid.c_str()) {
		switch (color) {
		case ('G'):
			color = COLOR_GREEN;
			break;
		case ('Y'):
			return (1);
		case ('R'):
			return (2);
		case ('B'):
			return (3);
		case ('W'):
			return (6);
		case ('N'):
			color = COLOR_BLACK;
			break;
		default:
			color = 0;
		}
		if (grid.c_str()[2] == 'F') {
			init_pair(4, color, color);
			return (4);
		} else {
			init_pair(5, color, COLOR_BLACK);
			return (5);
		}
	}
	return (0);
}

bool NcursesLib::pollEvent(Event &event)
{
    int onClick;

    if ((onClick = getch()) == ERR)
	{
        return (false);
    }
    else
	{
        event = eventConverter(onClick);
        return (true);
    }
}

void NcursesLib::clear()
{
    usleep(1000000 / 30);
    wclear(stdscr);
}

void NcursesLib::close()
{
	endwin();
}

void NcursesLib::draw(const Drawable &drawable)
{
    drawable.draw(*this);
}

void NcursesLib::display()
{
}

void NcursesLib::drawSprite(const Sprite &sprite)
{
    int colorCode;
	int x = (int)sprite.getPosition().x == 0 ? 0 :
		(int)std::round(sprite.getPosition().x / SQ_WIDTH);
	int y = (int)sprite.getPosition().y == 0 ? 0 :
		(int)std::round(sprite.getPosition().y / SQ_HEIGHT);

    colorCode = colorConverter(sprite.getAsciiFile());
    wattron(stdscr, COLOR_PAIR(colorCode));
    //mvwaddch(stdscr, y, x != 0 ? x - 1 : 0, ACS_ULCORNER);
    mvwaddch(stdscr, y, x, ACS_URCORNER);
    // mvwaddch(stdscr, y + 1, x != 0 ? x - 1 : 0, ACS_LLCORNER);
    // mvwaddch(stdscr, y + 1, x , ACS_LRCORNER);
    wattroff(stdscr, COLOR_PAIR(colorCode));
}

void NcursesLib::drawText(const LibText &text)
{
    mvprintw((int)text.getPosition().y  == 0 ? 0 :
             (int)text.getPosition().y / SQ_HEIGHT,
             (int)text.getPosition().x == 0 ? 0 :
             (int)text.getPosition().x / SQ_WIDTH, "%s",
		text.getText().c_str());
}