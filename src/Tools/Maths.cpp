/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Maths
*/

#include "Maths.hpp"

Maths::Maths()
{
}

Maths::~Maths()
{
}

float Maths::randFloat()
{
    float scale = rand() / (float) RAND_MAX;
    return (scale);
}

std::vector<float> Maths::createTransformationMatrix(sf::Vector3f translation, sf::Vector3f rotation, float scale)
{
    Matrix4f matrix;

    matrix.setIdentity();
    matrix.translate(translation);
    matrix.rotate(rotation.x, sf::Vector3f(1, 0, 0));
    matrix.rotate(rotation.y, sf::Vector3f(0, 1, 0));
    matrix.rotate(rotation.z, sf::Vector3f(0, 0, 1));
    matrix.scale(sf::Vector3f(scale, scale, scale));
    return (matrix.getMatrix());
}

std::vector<float> Maths::createProjectionMatrix()
{
    Matrix4f matrix;

    float aspectRatio = WIDTH / HEIGHT;
    float y_scale = (1.0 / tanf((FOV / 2.0) * (M_PI / 180)) * aspectRatio);
    float x_scale = y_scale / aspectRatio;
    float frustum_length = FAR_PLANE - NEAR_PLANE;

    matrix.setIdentity();
    matrix[0] = x_scale;
    matrix[5] = y_scale;
    matrix[10] = -((FAR_PLANE + NEAR_PLANE) / frustum_length);
    matrix[11] = -1;
    matrix[14] = -((2 * NEAR_PLANE * FAR_PLANE) / frustum_length);
    matrix[15] = 0;
    return (matrix.getMatrix());
}

std::vector<float> Maths::createViewMatrix(sf::Vector3f pos, float pitch, float yaw, float roll)
{
    Matrix4f matrix;

    matrix.setIdentity();
    matrix.rotate(pitch, sf::Vector3f(1, 0, 0));
    matrix.rotate(yaw, sf::Vector3f(0, 1, 0));
    matrix.rotate(roll, sf::Vector3f(0, 0, 1));
    matrix.translate(sf::Vector3f(-pos.x, -pos.y, -pos.z));
    return (matrix.getMatrix());
}
