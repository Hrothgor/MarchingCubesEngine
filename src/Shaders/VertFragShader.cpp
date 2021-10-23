/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** VertFragShader
*/

#include "VertFragShader.hpp"

IS::VertFragShader::VertFragShader(std::string vertexFile, std::string fragmentFile)
{
    _vertexShaderID = loadShader(vertexFile, GL_VERTEX_SHADER);
    _fragmentShaderID = loadShader(fragmentFile, GL_FRAGMENT_SHADER);
    _programID = glCreateProgram();
    glAttachShader(_programID, _vertexShaderID);
    glAttachShader(_programID, _fragmentShaderID);
    glLinkProgram(_programID);
    glValidateProgram(_programID);
}

IS::VertFragShader::~VertFragShader()
{
}

void IS::VertFragShader::destroy() const
{
    stop();
    glDetachShader(_programID, _vertexShaderID);
    glDetachShader(_programID, _fragmentShaderID);
    glDeleteShader(_vertexShaderID);
    glDeleteShader(_fragmentShaderID);
    glDeleteProgram(_programID);
}