/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** ComputeShader
*/

#include "ComputeShader.hpp"

IS::ComputeShader::ComputeShader(std::string computeFile)
{
    _computeShaderID = loadShader(computeFile, GL_COMPUTE_SHADER);
    _programID = glCreateProgram();
    glAttachShader(_programID, _computeShaderID);
    glLinkProgram(_programID);
    glValidateProgram(_programID);
}

IS::ComputeShader::~ComputeShader()
{
}

void IS::ComputeShader::dispatch(unsigned int sizeX, unsigned int sizeY, unsigned int sizeZ) const
{
    glDispatchCompute(sizeX, sizeY, sizeZ);
}

void IS::ComputeShader::destroy() const
{
    stop();
    glDetachShader(_programID, _computeShaderID);
    glDeleteShader(_computeShaderID);
    glDeleteProgram(_programID);
}