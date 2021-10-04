/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Matrix4f
*/

#ifndef MATRIX4F_HPP_
#define MATRIX4F_HPP_

#include "../../global.hpp"

class Matrix4f {
    public:
        Matrix4f();
        ~Matrix4f();

        float &operator[](int i) const;

        void setIdentity();
        void scale(sf::Vector3f scale);
        void translate(sf::Vector3f vec);
        void rotate(float angle, sf::Vector3f axis);
        void multiply(std::vector<float> mat);
        std::vector<float> getMatrix();

    protected:
    private:
        std::vector<float> _matrix;
};

#endif /* !MATRIX4F_HPP_ */
