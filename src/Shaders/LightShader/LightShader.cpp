/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** LightShader
*/

#include "LightShader.hpp"

IS::LightShader::LightShader() : VertFragShader("src/Shaders/LightShader/vertexShader.vert", "src/Shaders/LightShader/fragmentShader.frag")
{
    bindAttribute(0, "position"); // 0 = VAOID des vertex pos, "position" = nom de variable dans le vertexShader.txt
    bindAttribute(1, "textureCoords"); // 1 = VAOID des textures coord, "textureCoords" = nom de variable dans le vertexShader.txt
    bindAttribute(2, "normal"); // 2 = VAOID des textures coord, "textureCoords" = nom de variable dans le vertexShader.txt

    getAllUniformLocation();
}

IS::LightShader::~LightShader()
{
}

void IS::LightShader::getAllUniformLocation()
{
    loc_transformationMatrix = getUniformLocation("transformationMatrix");
    loc_projectionMatrix = getUniformLocation("projectionMatrix");
    loc_viewMatrix = getUniformLocation("viewMatrix");
    loc_lightPosition = getUniformLocation("lightPosition");
    loc_lightColor = getUniformLocation("lightColor");
    loc_shineDamper = getUniformLocation("shineDamper");
    loc_reflectivity = getUniformLocation("reflectivity");
    loc_ambientColor = getUniformLocation("ambientColor");
}

void IS::LightShader::loadTransformationMatrix(std::vector<float> matrix)
{
    loadMatrix(loc_transformationMatrix, matrix);
}

void IS::LightShader::loadProjectionMatrix(std::vector<float> matrix)
{
    loadMatrix(loc_projectionMatrix, matrix);
}

void IS::LightShader::loadViewMatrix(std::vector<float> matrix)
{
    loadMatrix(loc_viewMatrix, matrix);
}

void IS::LightShader::loadLight(Light light)
{
    loadVector3(loc_lightPosition, light.getPosition());
    loadVector3(loc_lightColor, light.getColor());
}

void IS::LightShader::loadShineVariable(float shineDamper, float reflectivity)
{
    loadFloat(loc_shineDamper, shineDamper);
    loadFloat(loc_reflectivity, reflectivity);
}

void IS::LightShader::loadAmbientColor(sf::Vector3f ka)
{
    loadVector3(loc_ambientColor, ka);
}