/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Loader
*/

#ifndef LOADER_HPP_
#define LOADER_HPP_

#include "../global.hpp"
#include "../Models/RawModel.hpp"

namespace IS {
    class Loader {
        public:
            Loader();
            ~Loader();

            RawModel LoadToVAO(std::vector<float> vertex, std::vector<float> textureCoord, std::vector<float> normals, std::vector<int> indices);
            RawModel LoadToVAO(std::vector<float> vertex, std::vector<float> normals, std::vector<int> indices);
            RawModel LoadToVAO(std::vector<float> vertex, std::vector<float> normals);
            sf::Texture LoadTexture(std::string file);
            void storeDataInAttributeList(int attributeNumber, std::vector<float> vertex, int nb);
            void bindIndicesBuffer(std::vector<int> indices);
            unsigned int createVAO();
            void unbindVAO();
            void destroy();

        protected:
        private:
            std::vector<int> _vaos;
            std::vector<int> _vbos;
            std::vector<sf::Texture> _textures;
    };
}

#endif /* !LOADER_HPP_ */
