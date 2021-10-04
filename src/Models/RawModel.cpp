/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** RawModel
*/

#include "RawModel.hpp"

IS::RawModel::RawModel(int vao, int vertexCount)
{
    _vao = vao;
    _vertexCount = vertexCount;
}

IS::RawModel::~RawModel()
{
}

int IS::RawModel::getVao() const
{
    return (_vao);
}

int IS::RawModel::getVertexCount() const
{
    return (_vertexCount);
}