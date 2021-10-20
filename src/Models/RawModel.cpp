/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** RawModel
*/

#include "RawModel.hpp"

IS::RawModel::RawModel(std::vector<Mesh> meshs, std::vector<Material> mats)
{
    _meshs = meshs;
    _materials = mats;
}

IS::RawModel::RawModel(RawMesh rawMesh)
{
    addMaterial({"default", {1,1,1}});
    Mesh mesh;
    mesh.setRawMesh(rawMesh);
    mesh.setMaterialIndex(0);
    addMesh(mesh);
}

IS::RawModel::~RawModel()
{
}

std::vector<IS::Mesh> IS::RawModel::getMeshs() const
{
    return (_meshs);
}

std::vector<IS::Material> IS::RawModel::getMaterials() const
{
    return (_materials);
}

IS::Material IS::RawModel::getMaterials(int i) const
{
    if (i < 0 || i >= _materials.size())
        return (_materials[0]);
    return (_materials[i]);
}


void IS::RawModel::setMeshs(std::vector<Mesh> meshs)
{
    _meshs = meshs;
}

void IS::RawModel::setMaterials(std::vector<Material> mats)
{
    _materials = mats;
}

void IS::RawModel::addMesh(Mesh mesh)
{
    _meshs.push_back(mesh);
}

void IS::RawModel::addMaterial(Material material)
{
    _materials.push_back(material);
}

void IS::RawModel::changeAmbientColor(int i, sf::Vector3f value)
{
    if (i < 0 || i >= _materials.size())
        return;
    _materials[i].Ka = value;
}