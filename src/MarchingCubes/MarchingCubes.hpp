/*
** EPITECH PROJECT, 2021
** Engine_Marching_Cubes
** File description:
** MarchingCubes
*/

#ifndef MARCHINGCUBES_HPP_
#define MARCHINGCUBES_HPP_

#include "../global.hpp"
#include "MarchingCubesTables.hpp"
#include "../Models/ModelLoader.hpp"

namespace IS {
    struct ScalarPoint {
        sf::Vector3f pos;
        float value;
    };

    class MarchingCubes {
        public:
            MarchingCubes(int size = 0, float minValue = 0);
            ~MarchingCubes();

            RawModel loadMarchingCubesModel(std::vector<ScalarPoint> points);


        protected:
        private:
            sf::Vector3f LinearInterp(IS::ScalarPoint p1, IS::ScalarPoint p2, float value);
            void pushVertex(sf::Vector3f pos1, sf::Vector3f pos2, sf::Vector3f vertex, sf::Vector3f normal);
            int indexFromCoord(sf::Vector3f coord);
            void clear();

            std::map<std::pair<int, int>, int> _vertexIndexMap;
            std::vector<sf::Vector3f> _allVertex;
            std::vector<float> _vertices;
            std::vector<int> _indices;
            std::vector<float> _normals;
            int _vertexCount = 0;
            int _sizeX;
            int _sizeY;
            int _sizeZ;
            float _isoValue;
    };
}

#endif /* !MARCHINGCUBES_HPP_ */
