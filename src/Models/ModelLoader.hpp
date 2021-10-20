/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** ModelLoader
*/

#ifndef MODELLOADER_HPP_
#define MODELLOADER_HPP_

#include "../global.hpp"
#include "RawModel.hpp"
#include "Loader.hpp"

namespace IS {
    class ModelLoader {
        public:
            ModelLoader();
            ~ModelLoader();

            static RawModel loadModelFromObj(std::string fileName);
            static RawModel loadModel(std::vector<float> vertices, std::vector<float> normals, std::vector<int> indices);
        protected:
        private:
    };
}

#endif /* !MODELLOADER_HPP_ */
