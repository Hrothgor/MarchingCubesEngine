/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** TerrainShader
*/

#include "TerrainShader.hpp"

IS::TerrainShader::TerrainShader() : ShaderProgram( "src/Shaders/TerrainShader/vertexShader.txt", "src/Shaders/TerrainShader/fragmentShader.txt")
{
    bindAttribute(0, "position"); // 0 = VAOID des vertex pos, "position" = nom de variable dans le vertexShader.txt
    bindAttribute(2, "normal"); // 2 = VAOID des textures coord, "textureCoords" = nom de variable dans le vertexShader.txt

    getAllUniformLocation();
}

IS::TerrainShader::~TerrainShader()
{
}

void IS::TerrainShader::getAllUniformLocation()
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

void IS::TerrainShader::loadTransformationMatrix(std::vector<float> matrix)
{
    loadMatrix(loc_transformationMatrix, matrix);
}

void IS::TerrainShader::loadProjectionMatrix(std::vector<float> matrix)
{
    loadMatrix(loc_projectionMatrix, matrix);
}

void IS::TerrainShader::loadViewMatrix(std::vector<float> matrix)
{
    loadMatrix(loc_viewMatrix, matrix);
}

void IS::TerrainShader::loadLight(Light light)
{
    loadVector3(loc_lightPosition, light.getPosition());
    loadVector3(loc_lightColor, light.getColor());
}

void IS::TerrainShader::loadShineVariable(float shineDamper, float reflectivity)
{
    loadFloat(loc_shineDamper, shineDamper);
    loadFloat(loc_reflectivity, reflectivity);
}

void IS::TerrainShader::loadAmbientColor(sf::Vector3f ka)
{
    loadVector3(loc_ambientColor, ka);
}