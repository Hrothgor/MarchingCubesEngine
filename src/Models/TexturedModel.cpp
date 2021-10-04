/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** TexturedModel
*/

#include "TexturedModel.hpp"

IS::TexturedModel::TexturedModel(const RawModel &model, sf::Texture &texture, float shineDamper, float reflectivity)
{
    _rawModel = model;
    _texture = &texture;
    _shineDamper = shineDamper;
    _reflectivity = reflectivity;
}

IS::TexturedModel::~TexturedModel()
{
}

IS::RawModel IS::TexturedModel::getModel() const
{
    return (_rawModel);
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
    if (this->getModel().getVao() == model.getModel().getVao())
        return (true);
    return (false);
}

bool IS::TexturedModel::operator<(const TexturedModel &model) const
{
    if (this->getModel().getVao() == model.getModel().getVao())
        return (false);
    return (true);
}