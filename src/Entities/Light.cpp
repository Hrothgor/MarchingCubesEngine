/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Light
*/

#include "Light.hpp"

IS::Light::Light(sf::Vector3f position, sf::Vector3f color)
{
    _position = position;
    _color = color;
}

IS::Light::~Light()
{
}

sf::Vector3f IS::Light::getPosition() const
{
    return (_position);
}

sf::Vector3f IS::Light::getColor() const
{
    return (_color);
}

void IS::Light::setPosition(sf::Vector3f position)
{
    _position = position;
}

void IS::Light::setColor(sf::Vector3f color)
{
    _color = color;
}