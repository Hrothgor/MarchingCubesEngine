/*
** EPITECH PROJECT, 2021
** Engine_Marching_Cubes
** File description:
** Chunk
*/

#include "Chunk.hpp"

IS::Chunk::Chunk(sf::Vector3i coord, int size)
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

std::vector<IS::ScalarPoint> IS::Chunk::getScalarPoints() const
{
    return (_points);
}

void IS::Chunk::setScalarPoints(std::vector<IS::ScalarPoint> scalarpoints)
{
    _points = scalarpoints;
}

IS::RawModel IS::Chunk::getModel() const
{
    return (_model);
}

void IS::Chunk::setModel(RawModel model)
{
    _model = model;
}

sf::Vector3i IS::Chunk::getCoord() const
{
    return (_id);
}

bool IS::Chunk::update()
{
    if (_regenerate == true) {

    }
    _regenerate = false;
    return (true);
} 