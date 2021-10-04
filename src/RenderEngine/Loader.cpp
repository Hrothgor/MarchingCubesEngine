/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Loader
*/

#include "Loader.hpp"

IS::Loader::Loader()
{
}

IS::Loader::~Loader()
{
}

sf::Texture IS::Loader::LoadTexture(std::string file)
{
    sf::Texture texture;

    if (!texture.loadFromFile(file)) {
        std::cout << "Couldn't open " << file << " texture file" << std::endl;
        exit(84);
    }
    _textures.push_back(texture);
    return (texture);
}

IS::RawModel IS::Loader::LoadToVAO(std::vector<float> vertices, std::vector<float> textureCoord, std::vector<float> normals, std::vector<int> indices)
{
    int vaoID = createVAO();

    bindIndicesBuffer(indices);
    storeDataInAttributeList(0, vertices, 3);
    storeDataInAttributeList(1, textureCoord, 2);
    storeDataInAttributeList(2, normals, 3);
    unbindVAO();
    RawModel model(vaoID, indices.size());
    return (model);
}

IS::RawModel IS::Loader::LoadToVAO(std::vector<float> vertices, std::vector<float> normals, std::vector<int> indices)
{
    int vaoID = createVAO();

    bindIndicesBuffer(indices);
    storeDataInAttributeList(0, vertices, 3);
    storeDataInAttributeList(1, normals, 3);
    unbindVAO();
    RawModel model(vaoID, indices.size());
    return (model);
}

IS::RawModel IS::Loader::LoadToVAO(std::vector<float> vertices, std::vector<float> normals)
{
    int vaoID = createVAO();

    storeDataInAttributeList(0, vertices, 3);
    storeDataInAttributeList(1, normals, 3);
    unbindVAO();
    RawModel model(vaoID, vertices.size());
    return (model);
}

void IS::Loader::storeDataInAttributeList(int attributeNumber, std::vector<float> data, int nb)
{
    GLuint VBO;

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * data.size(), &data[0], GL_STATIC_DRAW);
    glVertexAttribPointer(attributeNumber, nb, GL_FLOAT, GL_FALSE, 0, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    _vbos.push_back(VBO);
}

void IS::Loader::bindIndicesBuffer(std::vector<int> indices)
{
    GLuint VBO;

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, VBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indices.size(), &indices[0], GL_STATIC_DRAW);
    _vbos.push_back(VBO);
}

unsigned int IS::Loader::createVAO()
{
    GLuint VAO;

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    _vaos.push_back(VAO);
    return (VAO);
}

void IS::Loader::unbindVAO()
{
    glBindVertexArray(0);
}

void IS::Loader::destroy()
{
    _vaos.clear();
    _vbos.clear();
    _textures.clear();
}