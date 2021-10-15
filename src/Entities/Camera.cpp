/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Camera
*/

#include "Camera.hpp"

IS::Camera::Camera()
    : _position(0, 0, 0)
{
    _pitch = 0;
    _yaw = 0;
    _roll = 0;
}

IS::Camera::~Camera()
{
}

void IS::Camera::move(std::vector<bool> keys, sf::RenderWindow *window)
{
    _pitch += ((int)(window->getSize().y / 2) - sf::Mouse::getPosition(*window).y) * 0.1;
    _yaw += ((int)(window->getSize().x / 2) - sf::Mouse::getPosition(*window).x) * 0.1;
    if (_pitch < -80)
        _pitch = -80;
    if (_pitch > 80)
        _pitch = 80;
    sf::Mouse::setPosition({(int)(window->getSize().x / 2), (int)(window->getSize().y / 2)}, *window);

    if (keys[Input::Z])
        _position.z -= 5;
    if (keys[Input::S])
        _position.z += 5;
    if (keys[Input::Q])
        _position.x -= 5;
    if (keys[Input::D])
        _position.x += 5;
    if (keys[Input::Space])
        _position.y += 5;
    if (keys[Input::LShift])
        _position.y -= 5;
}

sf::Vector3f IS::Camera::getPosition() const
{
    return (_position);
}

float IS::Camera::getPitch() const
{
    return (_pitch);
}

float IS::Camera::getYaw() const
{
    return (_yaw);
}

float IS::Camera::getRoll() const
{
    return (_roll);
}