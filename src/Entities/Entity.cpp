/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Entity
*/

#include "Entity.hpp"

IS::Entity::Entity(const TexturedModel &texturedModel, sf::Vector3f position, sf::Vector3f rotation, float scale)
{
    _texturedModel = texturedModel;
    _position = position;
    _rotation = rotation;
    _scale = scale;
}

IS::Entity::~Entity()
{
}

void IS::Entity::increasePosition(sf::Vector3f vec)
{
    _position.x += vec.x;
    _position.y += vec.y;
    _position.z += vec.z;
}

void IS::Entity::increaseRotation(sf::Vector3f vec)
{
    _rotation.x += vec.x;
    _rotation.y += vec.y;
    _rotation.z += vec.z;
}


IS::TexturedModel IS::Entity::getTexturedModel() const
{
    return (_texturedModel);
}

sf::Vector3f IS::Entity::getPosition() const
{
    return (_position);
}

sf::Vector3f IS::Entity::getRotation() const
{
    return (_rotation);
}

float IS::Entity::getScale() const
{
    return (_scale);
}

void IS::Entity::setTexturedModel(TexturedModel texturedModel)
{
    _texturedModel = texturedModel;
}

void IS::Entity::setPosition(sf::Vector3f position)
{
    _position = position;
}

void IS::Entity::setRotation(sf::Vector3f rotation)
{
    _rotation = rotation;
}

void IS::Entity::setScale(float scale)
{
    _scale = scale;
}