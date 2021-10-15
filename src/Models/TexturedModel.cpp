/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** TexturedModel
*/

#include "TexturedModel.hpp"

IS::TexturedModel::TexturedModel(const RawModel &model, float shineDamper, float reflectivity)
    : RawModel(model)
{
    sf::Image image;
    image.create(1, 1, sf::Color::White);
    _texture = new sf::Texture();
    _texture->loadFromImage(image);
    _shineDamper = shineDamper;
    _reflectivity = reflectivity;
}

IS::TexturedModel::TexturedModel(const RawModel &model, sf::Texture &texture, float shineDamper, float reflectivity)
    : RawModel(model)
{
    _texture = &texture;
    _shineDamper = shineDamper;
    _reflectivity = reflectivity;
}

IS::TexturedModel::~TexturedModel()
{
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

bool IS::TexturedModel::operator==(const TexturedModel &model) const
{
    if (getVao() == model.getVao())
        return (true);
    return (false);
}

bool IS::TexturedModel::operator<(const TexturedModel &model) const
{
    if (getVao() == model.getVao())
        return (false);
    return (true);
}