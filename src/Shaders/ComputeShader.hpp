/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** ComputeShader
*/

#ifndef COMPUTESHADER_HPP_
#define COMPUTESHADER_HPP_

#include "../global.hpp"
#include "ShaderProgram.hpp"

namespace IS {
    class ComputeShader : public ShaderProgram {
        public: 
            ComputeShader(std::string computeFile);
            ~ComputeShader();

            void dispatch(unsigned int sizeX, unsigned int sizeY, unsigned int sizeZ) const;
            void destroy() const;
        protected:
        private:
            int _computeShaderID;
    };
}

#endif /* !COMPUTESHADER_HPP_ */
