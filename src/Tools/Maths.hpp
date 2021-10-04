/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Maths
*/

#ifndef MATHS_HPP_
#define MATHS_HPP_

#include "../global.hpp"
#include "Matrix4f/Matrix4f.hpp"
#include "Vector3f/Vector3f.hpp"

class Maths {
    public:
        Maths();
        ~Maths();

        static float randFloat();

        static std::vector<float> createTransformationMatrix(sf::Vector3f translation, sf::Vector3f rotation, float scale);
        static std::vector<float> createProjectionMatrix();
        static std::vector<float> createViewMatrix(sf::Vector3f pos, float pitch, float yaw, float roll);

    protected:
    private:
};

#endif /* !MATHS_HPP_ */
