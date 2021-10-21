/*
** EPITECH PROJECT, 2021
** MarchingCubesEngine
** File description:
** Terraforming
*/

#include "Terraforming.hpp"

IS::Terraforming::Terraforming()
{
}

IS::Terraforming::~Terraforming()
{
}

void IS::Terraforming::terraform(IS::TerraformType type)
{
    int textureSize = chunkMax * chunkSize;

    for (Chunk *chunk : GLOBAL::_chunks) {
        sf::Vector3f coord = chunk->getCoord();
        int size = chunk->getSize();
        for(float x = 0; x < size; x++)
            for(float y = 0; y < size; y++)
                for(float z = 0; z < size; z++) {
                    sf::Vector3f worldPos = {coord.x + x, coord.y + y, coord.z + z};
                    if (worldPos.x == 0 || worldPos.y == 0 || worldPos.z == 0 ||
                        worldPos.x == textureSize || worldPos.y == textureSize || worldPos.z == textureSize) {
                        continue;
                    }
                    int dist = length(_brushCenter - worldPos);
                    if (dist <= _brushRadius) {
                        float brushWeight = 1;
                        float value =  _weight * brushWeight;
                        if (type == TerraformType::Out) {
                            value *= -1;
                        } else if (type == TerraformType::In) {
                            value *= 1;
                        }
                        chunk->changePointValue({x, y, z}, value);
                    }
                }
    }
}

void IS::Terraforming::setBrushCenter(sf::Vector3f pos)
{
    _brushCenter = pos;
}

void IS::Terraforming::setBrushRadius(int radius)
{
    _brushRadius = radius;
}

void IS::Terraforming::setWeight(float weight)
{
    _weight = weight;
}