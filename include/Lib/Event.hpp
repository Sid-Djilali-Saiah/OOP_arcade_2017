/*
** EPITECH PROJECT, 2021
** OOP_arcade_2018
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#ifndef OOP_ARCADE_2018_EVENT_HPP
#define OOP_ARCADE_2018_EVENT_HPP

#include <cstdint>
#include <cstddef>

enum class KeyCode
{
	Unknown,
	A, B, C, D,
	E, F, G, H,
	I, J, K, L,
	M, N, O, P,
	Q, R, S, T,
	U, V, W, X,
	Y, Z, Num0,
	Num1, Num2, Num3, Num4,
	Num5, Num6, Num7, Num8,
	Num9, Escape, LControl, LShift,
	LAlt, LSystem, RControl, RShift,
	RAlt, RSystem, Menu, LBracket,
	RBracket, SemiColon, Comma, Period,
	Quote, Slash, BackSlash, Tilde,
	Equal, Dash, Space, Return,
	BackSpace, Tab, PageUp, PageDown,
	End, Home, Insert, Delete, Pause,
	Left, Right, Up, Down,
	F1, F2, F3, F4, F5, F6,
	F7, F8, F9, F10, F11,
	F12, F13, F14, F15
};

enum class EventType
{
	None,
	Closed,
	Resized,
	LostFocus,
	GainedFocus,
	TextEntered,
	KeyPressed,
	KeyReleased,
};

struct KeyEvent final
{
	KeyCode code;

	// Are those keys also pressed?
	bool alt;
	bool control;
	bool shift;
	bool system;
};

struct ResizeEvent final
{
	// New window size
	std::size_t width;
	std::size_t height;
};

struct TextEvent final
{
	// UTF-8 value of the character
	std::uint32_t unicode;
};

struct Event final
{
	EventType type{ EventType::None };

	union {
		// Keyboard
		KeyEvent key;
		TextEvent text;

		// Window
		ResizeEvent resize;
	};
};

#endif //ARCADE_EVENT_HPP