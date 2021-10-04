/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Matrix4f
*/

#include "Matrix4f.hpp"

Matrix4f::Matrix4f() : _matrix(16, 0.0)
{
}

Matrix4f::~Matrix4f()
{
}

float &Matrix4f::operator[](int i) const
{
    return (const_cast<float *>(&_matrix[0])[i]);
}

void Matrix4f::setIdentity()
{
    _matrix[0] = 1.0;
    _matrix[1] = 0.0;
    _matrix[2] = 0.0;
    _matrix[3] = 0.0;
    _matrix[4] = 0.0;
    _matrix[5] = 1.0;
    _matrix[6] = 0.0;
    _matrix[7] = 0.0;
    _matrix[8] = 0.0;
    _matrix[9] = 0.0;
    _matrix[10] = 1.0;
    _matrix[11] = 0.0;
    _matrix[12] = 0.0;
    _matrix[13] = 0.0;
    _matrix[14] = 0.0;
    _matrix[15] = 1.0;
}

void Matrix4f::scale(sf::Vector3f scale)
{
    _matrix[0] *= scale.x;
    _matrix[1] *= scale.x;
    _matrix[2] *= scale.x;
    _matrix[3] *= scale.x;
    _matrix[4] *= scale.y;
    _matrix[5] *= scale.y;
    _matrix[6] *= scale.y;
    _matrix[7] *= scale.y;
    _matrix[8] *= scale.z;
    _matrix[9] *= scale.z;
    _matrix[10] *= scale.z;
    _matrix[11] *= scale.z;
}

void Matrix4f::translate(sf::Vector3f vec)
{
    _matrix[12] += _matrix[0] * vec.x + _matrix[4] * vec.y + _matrix[8] * vec.z;
    _matrix[13] += _matrix[1] * vec.x + _matrix[5] * vec.y + _matrix[9] * vec.z;
    _matrix[14] += _matrix[2] * vec.x + _matrix[6] * vec.y + _matrix[10] * vec.z;
    _matrix[15] += _matrix[3] * vec.x + _matrix[7] * vec.y + _matrix[11] * vec.z;
}

void Matrix4f::rotate(float angle, sf::Vector3f axis)
{
    float x = angle * axis.x * (M_PI / 180);
    float y = angle * axis.y * (M_PI / 180);
    float z = angle * axis.z * (M_PI / 180);

    std::vector<float> rotx {
        1.0, 0.0, 0.0, 0.0,
        0.0, cosf(x), -sinf(x), 0.0,
        0.0, sinf(x), cosf(x), 0.0,
        0.0, 0.0, 0.0, 1.0
    };
    std::vector<float> roty {
        cosf(y), 0.0, sinf(y), 0.0,
        0.0, 1.0, 0.0, 0.0,
        -sinf(y), 0.0, cosf(y), 0.0,
        0.0, 0.0, 0.0, 1.0
    };
    std::vector<float> rotz {
        cosf(z), -sinf(z), 0.0, 0.0,
        sinf(z), cosf(z), 0.0, 0.0,
        0.0, 0.0, 1.0, 0.0,
        0.0, 0.0, 0.0, 1.0
    };
    multiply(rotx);
    multiply(roty);
    multiply(rotz);
}

void Matrix4f::multiply(std::vector<float> mat)
{
    std::vector<float> m(16, 0.0);

    for (int i = 0; i < 4 * 4; i++)
        for (int j = 0; j < 4; j++)
            m[i] += mat[((i/4) * 4) + j] * _matrix[(i%4) + (j*4)];
    _matrix = m;
}

std::vector<float> Matrix4f::getMatrix()
{
    return (_matrix);
}