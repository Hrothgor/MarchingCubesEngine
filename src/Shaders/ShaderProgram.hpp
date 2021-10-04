/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** ShaderProgram
*/

#ifndef SHADERPROGRAM_HPP_
#define SHADERPROGRAM_HPP_

#include "../global.hpp"

namespace IS {
    class ShaderProgram {
        public: 
            ShaderProgram(std::string vertexFile, std::string fragmentFile);
            ~ShaderProgram();

            void start() const;
            void stop() const;
            void destroy() const;
            int loadShader(std::string file, unsigned int type) const;
            void bindAttribute(int attribute, const std::string name) const;

            int getUniformLocation(std::string uniformName);
            virtual void getAllUniformLocation() {};
            void loadFloat(int location, float value);
            void loadBool(int location, bool value);
            void loadVector2(int location, sf::Vector2f value);
            void loadVector3(int location, sf::Vector3f value);
            void loadMatrix(int location, std::vector<float> value);

        protected:
        private:
            int _programID;
            int _vertexShaderID;
            int _fragmentShaderID;
    };
}

#endif /* !SHADERPROGRAM_HPP_ */
