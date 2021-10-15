/*
** EPITECH PROJECT, 2021
** Engine_Marching_Cubes
** File description:
** Vector3f
*/

#ifndef VECTOR3F_HPP_
#define VECTOR3F_HPP_

#include "../../global.hpp"

namespace IS {
    sf::Vector3f Cross(sf::Vector3f v1, sf::Vector3f v2);
    sf::Vector3f Normalize(sf::Vector3f v);
    float length(sf::Vector3f vec);
    sf::Vector3f floor(sf::Vector3f vec);
    float dot(sf::Vector3f v1, sf::Vector3f v2);
}

#endif /* !VECTOR3F_HPP_ */
