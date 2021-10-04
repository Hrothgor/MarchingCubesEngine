/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Light
*/

#ifndef LIGHT_HPP_
#define LIGHT_HPP_

#include "../global.hpp"

namespace IS {
    class Light {
        public:
            Light(sf::Vector3f position, sf::Vector3f color);
            ~Light();

            sf::Vector3f getPosition() const;
            sf::Vector3f getColor() const;
            void setPosition(sf::Vector3f position);
            void setColor(sf::Vector3f color);

        protected:
        private:
            sf::Vector3f _position;
            sf::Vector3f _color;
    };
}

#endif /* !LIGHT_HPP_ */
