/*
** EPITECH PROJECT, 2021
** MarchingCubesEngine
** File description:
** RayCasting
*/

#ifndef RAYCASTING_HPP_
#define RAYCASTING_HPP_

#include "../global.hpp"
#include "../Entities/Camera.hpp"

namespace IS {
    class RayCasting {
        public:
            RayCasting();
            ~RayCasting();

            void update(sf::RenderWindow *window);

            bool intersect(std::vector<sf::Vector3f> _triangles, sf::Vector3f meshPos);
            bool rayIntersectTriangle(sf::Vector3f v0, sf::Vector3f v1, sf::Vector3f v2);

            sf::Vector3f calculateRay(float x, float y);
            sf::Vector3f toWorldCoord(Vector4f eyeCoords);
            Vector4f toEyeCoords(Vector4f clipCoords);
            sf::Vector2f getNormalisedDeviceCoords(float x, float y);

            sf::Vector3f getRay() const;
            sf::Vector3f getCurrentIntersectPoint() const;

        protected:
        private:
            sf::Vector3f _ray;
            Matrix4f _viewMatrix;
            Matrix4f _projectionMatrix;

            sf::Vector3f _origin;
            sf::Vector3f _tmpIntersectPoint;
            sf::Vector3f _currentIntersectPoint;
    };
}

#endif /* !RAYCASTING_HPP_ */
