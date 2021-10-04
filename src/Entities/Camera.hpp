/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "../global.hpp"

namespace IS {
    class Camera {
        public:
            Camera();
            ~Camera();

            void move(std::vector<bool> keys, sf::RenderWindow *window);

            sf::Vector3f getPosition() const;
            float getPitch() const;
            float getYaw() const;
            float getRoll() const;

        protected:
        private:
            sf::Vector3f _position;
            float _pitch; //x rotation
            float _yaw; //y rotation
            float _roll; //z rotation
    };
}

#endif /* !CAMERA_HPP_ */
