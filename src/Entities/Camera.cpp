/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Camera
*/

#include "Camera.hpp"

IS::Camera::Camera()
    : _position(0, 50, 50)
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
    if (_pitch < -90)
        _pitch = -90;
    if (_pitch > 90)
        _pitch = 90;
    sf::Mouse::setPosition({(int)(window->getSize().x / 2), (int)(window->getSize().y / 2)}, *window);

    float speed = 0;
    if (keys[Input::Z])
        speed = -0.2;
    if (keys[Input::S])
        speed = 0.2;

    _position.z += (speed * cos(_yaw * M_PI / 180));
    _position.x += (speed * sin(_yaw * M_PI / 180));

    if (keys[Input::Space])
        _position.y += 0.2;
    if (keys[Input::LShift])
        _position.y -= 0.2;
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