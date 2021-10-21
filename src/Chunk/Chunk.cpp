/*
** EPITECH PROJECT, 2021
** Engine_Marching_Cubes
** File description:
** Chunk
*/

#include "Chunk.hpp"

IS::Chunk::Chunk(sf::Vector3f coord, int size)
    : _id(coord)
    , _size(size)
    , _MC(size, 0)
{
    
}

IS::Chunk::~Chunk()
{
}

void IS::Chunk::generateChunk()
{
    if (_points.size() != 0) {
        _model = _MC.loadMarchingCubesModel(_points);
        _model.changeAmbientColor(0, {1, 0.75, 0.80});
    }
}

void IS::Chunk::changePointValue(sf::Vector3f pos, float value)
{
    for (ScalarPoint &_point : _points)
        if (_point.pos == pos) {
            _point.value += value;
            _regenerate = true;
            return;
        }
}

std::vector<IS::ScalarPoint> IS::Chunk::getScalarPoints() const
{
    return (_points);
}

IS::RawModel IS::Chunk::getModel() const
{
    return (_model);
}

sf::Vector3f IS::Chunk::getCoord() const
{
    return (_id);
}

int IS::Chunk::getSize() const
{
    return (_size);
}

void IS::Chunk::setScalarPoints(std::vector<IS::ScalarPoint> scalarpoints)
{
    _points = scalarpoints;
}

void IS::Chunk::setModel(RawModel model)
{
    _model = model;
}

bool IS::Chunk::update()
{
    if (_regenerate == true) {
        generateChunk();
    }
    _regenerate = false;
    return (true);
} 