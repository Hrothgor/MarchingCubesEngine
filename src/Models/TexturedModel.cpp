/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** TexturedModel
*/

#include "TexturedModel.hpp"

IS::TexturedModel::TexturedModel(const std::string &modelPath, float shineDamper, float reflectivity)
{
    _texture = new sf::Texture;
    std::string path = "ressources/" + modelPath + ".obj";
    std::string pathTexture = "ressources/" + modelPath + ".png";

    if (std::filesystem::exists(path)) {
        _model = ModelLoader::loadModelFromObj(path);
        if (!std::filesystem::exists(pathTexture) || !_texture->loadFromFile(pathTexture)) {
            sf::Image image;
            image.create(1, 1, sf::Color::White);
            _texture->loadFromImage(image);
        }
    }
    _shineDamper = shineDamper;
    _reflectivity = reflectivity;
}

IS::TexturedModel::TexturedModel(const std::string &modelPath, const std::string &texturePath, float shineDamper, float reflectivity)
{
    _texture = new sf::Texture;
    std::string path = "ressources/" + modelPath + ".obj";
    std::string pathTexture = "ressources/" + texturePath + ".png";

    if (std::filesystem::exists(path)) {
        _model = ModelLoader::loadModelFromObj(path);
        if (!std::filesystem::exists(pathTexture) || !_texture->loadFromFile(pathTexture)) {
            sf::Image image;
            image.create(1, 1, sf::Color::White);
            _texture->loadFromImage(image);
        }
    }
    _shineDamper = shineDamper;
    _reflectivity = reflectivity;
}

IS::TexturedModel::TexturedModel(const RawModel &model, std::string texturePath, float shineDamper, float reflectivity)
    : _model(model)
{
    _texture = new sf::Texture;
    if (texturePath == "" || !_texture->loadFromFile(texturePath)) {
        sf::Image image;
        image.create(1, 1, sf::Color::White);
        _texture->loadFromImage(image);
    }
    _shineDamper = shineDamper;
    _reflectivity = reflectivity;
}

IS::TexturedModel::~TexturedModel()
{
}

IS::RawModel IS::TexturedModel::getModel() const
{
    return (_model);
}

sf::Texture *IS::TexturedModel::getTexture()
{
    return (_texture);
}

float IS::TexturedModel::getShineDamper() const
{
    return (_shineDamper);
}

float IS::TexturedModel::getReflectivity() const
{
    return (_reflectivity);
}

void IS::TexturedModel::setShineDamper(float shineDamper)
{
    _shineDamper = shineDamper;
}

void IS::TexturedModel::setReflectivity(float reflectivity)
{
    _reflectivity = reflectivity;
}