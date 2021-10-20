/*
** EPITECH PROJECT, 2021
** Engine_Marching_Cubes
** File description:
** MarchingCubes
*/

#include "MarchingCubes.hpp"

IS::MarchingCubes::MarchingCubes(int size, float minValue)
{
    _sizeX = size;
    _sizeY = size;
    _sizeZ = size;
    _isoValue = minValue;
}

IS::MarchingCubes::~MarchingCubes()
{
}

int IS::MarchingCubes::indexFromCoord(sf::Vector3f coord)
{
    int z = coord.z;
    int y = coord.y;
    int x = coord.x;
    int ret = z * _sizeX * _sizeX + y * _sizeX + x;
    return ret;
}

sf::Vector3f IS::MarchingCubes::LinearInterp(IS::ScalarPoint p1, IS::ScalarPoint p2, float value)
{
    sf::Vector3f p;
    if (p1.value != p2.value)
        p = p1.pos + (p2.pos - p1.pos) / (p2.value - p1.value) * (value - p1.value);
    else 
        p = p1.pos;
    return p;
}

void IS::MarchingCubes::pushVertex(sf::Vector3f pos1, sf::Vector3f pos2, sf::Vector3f vertex, sf::Vector3f normal)
{
    int index1 = indexFromCoord(pos1);
    int index2 = indexFromCoord(pos2);
    std::pair<int, int> index = std::pair<int, int>(std::min(index1, index2), std::max(index1, index2));

    std::map<std::pair<int, int>, int>::iterator it = _vertexIndexMap.find(index);
    if (it != _vertexIndexMap.end()) {
        _indices.push_back(it->second);
    } else {
        _vertices.push_back(vertex.x);
        _vertices.push_back(vertex.y);
        _vertices.push_back(vertex.z);
        _normals.push_back(normal.x);
        _normals.push_back(normal.y);
        _normals.push_back(normal.z);
        _indices.push_back(_vertexCount);
        _vertexIndexMap[index] = _vertexCount++;
    }
}

IS::RawModel IS::MarchingCubes::loadMarchingCubesModel(std::vector<ScalarPoint> points)
{
    clear();
    int YtimeZ = (_sizeY)*(_sizeZ);
    
    for(int z = 0; z < _sizeZ - 1; z++)
        for(int y = 0; y < _sizeY - 1; y++)
            for(int x = 0; x < _sizeX - 1; x++)
            {
                std::vector<ScalarPoint> cubeVertices(8);
                int ind = z * YtimeZ + y * (_sizeZ) + x;
                cubeVertices[0] = points[ind];
                cubeVertices[1] = points[ind + YtimeZ];
                cubeVertices[2] = points[ind + YtimeZ + 1];
                cubeVertices[3] = points[ind + 1];
                cubeVertices[4] = points[ind + (_sizeZ)];
                cubeVertices[5] = points[ind + YtimeZ + (_sizeZ)];
                cubeVertices[6] = points[ind + YtimeZ + (_sizeZ) + 1];
                cubeVertices[7] = points[ind + (_sizeZ) + 1];

                int cubeConfig = 0; 
                for (int n = 0; n < 8; n++)
                    if (cubeVertices[n].value < _isoValue)
                        cubeConfig |= (1 << n);

                if (!triTable[cubeConfig])
                    continue;
                    
                for (int i = 0; i < 16; i += 3) {
                    if (triTable[cubeConfig][i] == -1)
                        break;
                    int a0 = cornerIndexAFromEdge[triTable[cubeConfig][i]];
                    int a1 = cornerIndexBFromEdge[triTable[cubeConfig][i]];

                    int b0 = cornerIndexAFromEdge[triTable[cubeConfig][i + 1]];
                    int b1 = cornerIndexBFromEdge[triTable[cubeConfig][i + 1]];

                    int c0 = cornerIndexAFromEdge[triTable[cubeConfig][i + 2]];
                    int c1 = cornerIndexBFromEdge[triTable[cubeConfig][i + 2]];

                    sf::Vector3f vertexA = LinearInterp(cubeVertices[a0], cubeVertices[a1], _isoValue);
                    sf::Vector3f vertexB = LinearInterp(cubeVertices[b0], cubeVertices[b1], _isoValue);
                    sf::Vector3f vertexC = LinearInterp(cubeVertices[c0], cubeVertices[c1], _isoValue);

                    sf::Vector3f normal = -Normalize(Cross(vertexB - vertexA, vertexC - vertexA));

                    pushVertex(cubeVertices[a0].pos, cubeVertices[a1].pos, vertexA, normal);
                    pushVertex(cubeVertices[b0].pos, cubeVertices[b1].pos, vertexB, normal);
                    pushVertex(cubeVertices[c0].pos, cubeVertices[c1].pos, vertexC, normal);

                    _allVertex.push_back(vertexA);
                    _allVertex.push_back(vertexB);
                    _allVertex.push_back(vertexC);
                }
            }
    return ModelLoader::loadModel(_allVertex, _vertices, _normals, _indices);
}

void IS::MarchingCubes::clear()
{
    _vertexIndexMap.clear();
    _allVertex.clear();
    _vertices.clear();
    _indices.clear();
    _normals.clear();
    _vertexCount = 0;
}