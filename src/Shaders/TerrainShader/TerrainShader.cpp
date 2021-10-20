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
    loc_ambientColor = getUniformLocation("ambientColor");
    loc_planetCenter = getUniformLocation("planetCenter");
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

void IS::TerrainShader::loadAmbientColor(sf::Vector3f ka)
{
    loadVector3(loc_ambientColor, ka);
}

void IS::TerrainShader::loadPlanetCenter(sf::Vector3f planetCenter)
{
    loadVector3(loc_planetCenter, planetCenter);
}