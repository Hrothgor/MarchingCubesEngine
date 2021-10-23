/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** VertFragShader
*/

#ifndef VERTFRAGSHADER_HPP_
#define VERTFRAGSHADER_HPP_

#include "../global.hpp"
#include "ShaderProgram.hpp"

namespace IS {
    class VertFragShader : public ShaderProgram {
        public: 
            VertFragShader(std::string vertexFile, std::string fragmentFile);
            ~VertFragShader();

            void destroy() const;
        protected:
        private:
            int _vertexShaderID;
            int _fragmentShaderID;
    };
}

#endif /* !VERTFRAGSHADER_HPP_ */
