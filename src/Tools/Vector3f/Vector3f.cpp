/*
** EPITECH PROJECT, 2021
** Engine_Marching_Cubes
** File description:
** Vector3f
*/

#include "Vector3f.hpp"

sf::Vector3f IS::Cross(sf::Vector3f v1, sf::Vector3f v2)
{
    return {v1.y*v2.z-v1.z*v2.y, v1.z*v2.x-v1.x*v2.z, v1.x*v2.y-v1.y*v2.x};
}

sf::Vector3f IS::Normalize(sf::Vector3f v)
{
    float length = sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
    if (!length)
        return v;
    v.x /= length;
    v.y /= length;
    v.z /= length;
    return v;
}

float IS::length(sf::Vector3f vec)
{
    return (sqrtf(vec.x*vec.x + vec.y*vec.y + vec.z*vec.z));
}

sf::Vector3f IS::floor(sf::Vector3f vec)
{
    return {floorf(vec.x), floorf(vec.y), floorf(vec.z)};
}

float IS::dot(sf::Vector3f v1, sf::Vector3f v2) {
    float product = 0;

    product += v1.x * v2.x;
    product += v1.y * v2.y;
    product += v1.z * v2.z;
    return product;
}