/*
** EPITECH PROJECT, 2021
** 1
** File description:
** TexturedModel
*/

#ifndef TEXTUREDMODEL_HPP_
#define TEXTUREDMODEL_HPP_

#include "../global.hpp"
#include "ModelLoader.hpp"
#include "RawModel.hpp"

namespace IS {
    class TexturedModel {
        public:
            TexturedModel() {};
            TexturedModel(const std::string &modelPath, float shineDamper = 100, float reflectivity = 0.1);
            TexturedModel(const std::string &modelPath, const std::string &texturePath, float shineDamper = 100, float reflectivity = 0.1);
            TexturedModel(const RawModel &model, std::string texturePath = "", float shineDamper = 100, float reflectivity = 0.1);
            ~TexturedModel();

            RawModel getModel() const;
            sf::Texture *getTexture();
            float getShineDamper() const;
            float getReflectivity() const;

            void setShineDamper(float shineDamper);
            void setReflectivity(float reflectivity);

        protected:
        private:
            RawModel _model;
            sf::Texture *_texture;
            float _shineDamper; //0 is huge damper, 100+ is low
            float _reflectivity; //1+ is high reflectivity, 0.1 is low
    };
}

#endif /* !TEXTUREDMODEL_HPP_ */
