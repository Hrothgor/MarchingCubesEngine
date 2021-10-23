/*
** EPITECH PROJECT, 2021
** MarchingCubesEngine
** File description:
** MarchingCubeShader
*/

#include "MarchingCubeShader.hpp"

IS::MarchingCubeShader::MarchingCubeShader() : ComputeShader("src/Shaders/MarchingCubeShader/computeShader.comp")
{
    getAllUniformLocation();
}

IS::MarchingCubeShader::~MarchingCubeShader()
{
}

void IS::MarchingCubeShader::getAllUniformLocation()
{
}