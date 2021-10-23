/*
** EPITECH PROJECT, 2021
** MarchingCubesEngine
** File description:
** MarchingCubeShader
*/

#ifndef MARCHINGCUBESHADER_HPP_
#define MARCHINGCUBESHADER_HPP_

#include "../../global.hpp"
#include "../ComputeShader.hpp"

namespace IS {
    class MarchingCubeShader : public ComputeShader {
        public:
            MarchingCubeShader();
            ~MarchingCubeShader();

            void getAllUniformLocation();
        protected:
        private:
    };
}

#endif /* !MARCHINGCUBESHADER_HPP_ */
