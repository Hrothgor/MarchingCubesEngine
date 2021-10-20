/*
** EPITECH PROJECT, 2021
** MarchingCubesEngine
** File description:
** Mesh
*/

#include "Mesh.hpp"

IS::Mesh::Mesh(int vao, int vertexCount, std::string name, int materialIndex)
{
    _mesh.vao = vao;
    _mesh.vertexCount = vertexCount;
    _name = name;
    _materialIndex = materialIndex;
}

IS::Mesh::Mesh(RawMesh mesh, std::string name, int materialIndex)
{
    _mesh.vao = mesh.vao;
    _mesh.vertexCount = mesh.vertexCount;
    _name = name;
    _materialIndex = materialIndex; 
}

IS::Mesh::Mesh(const Mesh &mesh)
{
    _mesh.vao = mesh.getVao();
    _mesh.vertexCount = mesh.getVertexCount();
    _name = mesh.getName();
    _materialIndex = mesh.getMaterialIndex();
    _allVertex = mesh.getAllVertex();
}

IS::Mesh::~Mesh()
{

}

void IS::Mesh::setRawMesh(IS::RawMesh rawMesh)
{
    _mesh = rawMesh;
}

void IS::Mesh::setName(std::string name)
{
    _name = name;
}

void IS::Mesh::setMaterialIndex(int i)
{
    _materialIndex = i;
}

void IS::Mesh::setAllVertex(std::vector<sf::Vector3f> allVertex)
{
    _allVertex = allVertex;
};

IS::RawMesh IS::Mesh::getRawMesh() const
{
    return (_mesh);
}

int IS::Mesh::getVao() const
{
    return (_mesh.vao);
}

int IS::Mesh::getVertexCount() const
{
    return (_mesh.vertexCount);
}

std::string IS::Mesh::getName() const
{
    return (_name);
}

int IS::Mesh::getMaterialIndex() const
{
    return (_materialIndex);
}

std::vector<sf::Vector3f> IS::Mesh::getAllVertex() const
{ 
    return (_allVertex); 
}