/*
** EPITECH PROJECT, 2021
** MarchingCubesEngine
** File description:
** RayCasting
*/

#include "RayCasting.hpp"

IS::RayCasting::RayCasting()
{
    _projectionMatrix = Maths::createProjectionMatrix();
}

IS::RayCasting::~RayCasting()
{
}

void IS::RayCasting::update(sf::RenderWindow *window)
{
    _viewMatrix = Maths::createViewMatrix(
                GLOBAL::_camera->getPosition(),
                GLOBAL::_camera->getPitch(),
                GLOBAL::_camera->getYaw(),
                GLOBAL::_camera->getRoll());
    _ray = calculateRay(window->getSize().x / 2, window->getSize().y / 2);
    _origin = GLOBAL::_camera->getPosition();
}

bool IS::RayCasting::intersect(std::vector<sf::Vector3f> _triangles, sf::Vector3f meshPos)
{
    bool isIntersect = false; 
    float minDist = INFINITY;

    for (int i = 0; i < _triangles.size(); i += 3) { 
        sf::Vector3f v0 = _triangles[i] + meshPos;
        sf::Vector3f v1 = _triangles[i + 1] + meshPos; 
        sf::Vector3f v2 = _triangles[i + 2] + meshPos;
        if (rayIntersectTriangle(v0, v1, v2)) {
            float dist = length(_currentIntersectPoint - _origin);
            if (dist < minDist) {
                minDist = dist;
                _currentIntersectPoint = _tmpIntersectPoint;
                isIntersect = true;
            }
        }
    } 
    return (isIntersect);
}

bool IS::RayCasting::rayIntersectTriangle(sf::Vector3f v0, sf::Vector3f v1, sf::Vector3f v2)
{
    sf::Vector3f edge1 = v1 - v0;
    sf::Vector3f edge2 = v2 - v0;

    sf::Vector3f plane = Cross(_ray, edge2);
    float det = dot(edge1, plane);

    if (det > -0.0000001 && det < 0.0000001)
        return false;

    float invDet = 1 / det;
    sf::Vector3f tvec = _origin - v0;
    float u = dot(tvec, plane) * invDet;

    if (u < 0 || u > 1)
        return false;

    sf::Vector3f qvec = Cross(tvec, edge1);

    float v = dot(_ray, qvec) * invDet;

    if (v < 0 || u + v > 1)
        return false;

    float t = dot(edge2, qvec) * invDet;

    if (t > 0.0000001)
    {
        _tmpIntersectPoint = _origin + _ray * t;
        return true;
    }
    else
        return false;
}

sf::Vector3f IS::RayCasting::calculateRay(float x, float y)
{
    sf::Vector2f normalizedCoords = getNormalisedDeviceCoords(x, y);
    Vector4f clipCoords = {normalizedCoords.x, normalizedCoords.y, -1, 1};
    Vector4f eyeCoords = toEyeCoords(clipCoords);
    sf::Vector3f worldCoords = toWorldCoord(eyeCoords);
    return (worldCoords);
}

sf::Vector3f IS::RayCasting::toWorldCoord(Vector4f eyeCoords)
{
    Matrix4f invertedView = _viewMatrix;
    invertedView.invert();
    Vector4f rayWorld = invertedView.transform(eyeCoords);
    sf::Vector3f ray = Normalize({rayWorld.x, rayWorld.y, rayWorld.z});
    return (ray);
}

IS::Vector4f IS::RayCasting::toEyeCoords(IS::Vector4f clipCoords)
{
    Matrix4f invertedProjection = _projectionMatrix;
    invertedProjection.invert();
    Vector4f eyeCoords = invertedProjection.transform(clipCoords);
    return {eyeCoords.x, eyeCoords.y, -1, 0};
}

sf::Vector2f IS::RayCasting::getNormalisedDeviceCoords(float x, float y)
{
    sf::Vector2f ret;
    ret.x = (2 * x) / WIDTH - 1;
    ret.y = (2 * y) / HEIGHT - 1;
    return (ret);
}

sf::Vector3f IS::RayCasting::getRay() const
{
    return (_ray);
}

sf::Vector3f IS::RayCasting::getCurrentIntersectPoint() const
{
    return (_currentIntersectPoint);
}