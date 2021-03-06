/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** ShaderProgram
*/

#include "ShaderProgram.hpp"

IS::ShaderProgram::ShaderProgram()
{
}

IS::ShaderProgram::~ShaderProgram()
{
}

void IS::ShaderProgram::start() const
{
    glUseProgram(_programID);
}

void IS::ShaderProgram::stop() const
{
    glUseProgram(0);
}

void IS::ShaderProgram::destroy() const
{
    stop();
}

int IS::ShaderProgram::loadShader(std::string file, unsigned int type) const
{
    std::ifstream fs(file);

    if (!fs.is_open()) {
        std::cout << "Couldn't open " << file << " shader file" << std::endl;
        exit(84);
    }
    std::string source((std::istreambuf_iterator<char>(fs)), std::istreambuf_iterator<char>());
    const GLchar *const src = source.c_str();
    GLuint shaderID = glCreateShader(type);
    glShaderSource(shaderID, 1, &src, NULL);
    glCompileShader(shaderID);
    GLint succes;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &succes);
    GLchar infolog[512];
    if (!succes) {
        glGetShaderInfoLog(shaderID, 512, NULL, infolog);
        std::cout << "Could not compile shader : " << file << " : " << infolog << std::endl;
    }
    return (shaderID);
}

void IS::ShaderProgram::bindAttribute(int attribute, const std::string name) const
{
    glBindAttribLocation(_programID, attribute, name.c_str());
}

int IS::ShaderProgram::getUniformLocation(std::string uniformName)
{
    return (glGetUniformLocation(_programID, uniformName.c_str()));
}

void IS::ShaderProgram::loadFloat(int location, float value)
{
    glUniform1f(location, value);
}

void IS::ShaderProgram::loadVector2(int location, sf::Vector2f value)
{
    glUniform2f(location, value.x, value.y);
}

void IS::ShaderProgram::loadVector3(int location, sf::Vector3f value)
{
    glUniform3f(location, value.x, value.y, value.z);
}

void IS::ShaderProgram::loadBool(int location, bool value)
{
    if (value == true)
        glUniform1f(location, 1);
    else
        glUniform1f(location, 0);
}

void IS::ShaderProgram::loadMatrix(int location, std::vector<float> value)
{
    glUniformMatrix4fv(location, 1, false, &value[0]);
}