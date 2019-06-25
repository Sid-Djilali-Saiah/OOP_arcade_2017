/*
** EPITECH PROJECT, 2021
** OOP_arcade_2018
** Email: sid.djilali-saiah@epitech.eu
** Created by Sid Djilali Saiah,
*/

#ifndef OOP_ARCADE_2018_VECTOR_HPP
#define OOP_ARCADE_2018_VECTOR_HPP

template <class T>
struct Vector2 final
{
	T x;
	T y;
};

template <class T>
struct Vector3 final
{
	T x;
	T y;
	T z;
};

using Vector2i = Vector2<int>;
using Vector2f = Vector2<float>;
using Vector2u = Vector2<unsigned>;

using Vector3i = Vector3<int>;
using Vector3f = Vector3<float>;
using Vector3u = Vector3<unsigned>;

#endif //ARCADE_VECTOR_HPP