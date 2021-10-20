/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** ModelLoader
*/

#include "ModelLoader.hpp"
#include "OBJ_Loader.h"

IS::ModelLoader::ModelLoader()
{
}

IS::ModelLoader::~ModelLoader()
{
}

sf::Vector3f objlVecTosfVec(objl::Vector3 vec)
{
    sf::Vector3f v;
    v.x = vec.X;
    v.y = vec.Y;
    v.z = vec.Z;
    return v;
}

IS::RawModel IS::ModelLoader::loadModelFromObj(std::string fileName)
{
    objl::Loader _loader;
    RawModel rawModel;

    if (!_loader.LoadFile(fileName)) {
        std::cout << fileName << " is a wrong OBJ file" << std::endl;
        exit(84);
    }
    for (objl::Material mat : _loader.LoadedMaterials) {
        IS::Material material;
        material.name = mat.name;
        material.Ka = objlVecTosfVec(mat.Ka);
        rawModel.addMaterial(material);
    }
    if (_loader.LoadedMaterials.size() == 0)
        rawModel.addMaterial({"default", {1,1,1}});

    for (objl::Mesh m : _loader.LoadedMeshes) {
        IS::Mesh mesh;
        mesh.setName(m.MeshName);
        mesh.setMaterialIndex(0);
        int i = 0;
        for (IS::Material mat : rawModel.getMaterials()) {
            if (mat.name == m.MeshMaterial.name)
                mesh.setMaterialIndex(i);
            i++;
        }
        std::vector<float> vertices;
        std::vector<float> textures;
        std::vector<float> normals;
        std::vector<int> indices;
        for (objl::Vertex vert : m.Vertices) {
            vertices.push_back(vert.Position.X);
            vertices.push_back(vert.Position.Y);
            vertices.push_back(vert.Position.Z);
            textures.push_back(vert.TextureCoordinate.X);
            textures.push_back(vert.TextureCoordinate.Y);
            normals.push_back(vert.Normal.X);
            normals.push_back(vert.Normal.Y);
            normals.push_back(vert.Normal.Z);
        }
        for (int ind : m.Indices) {
            indices.push_back(ind);
        }
        mesh.setRawMesh(GLOBAL::_loader->LoadToVAO(
                vertices, 
                textures, 
                normals, 
                indices));
        rawModel.addMesh(mesh);
    }
    return rawModel;
}

IS::RawModel IS::ModelLoader::loadModel(std::vector<float> vertices, std::vector<float> normals, std::vector<int> indices)
{
    RawModel rawModel;

    rawModel.addMesh(GLOBAL::_loader->LoadToVAO(vertices, normals, indices));
    rawModel.addMaterial({"default", {1,1,1}});
    return rawModel;
}