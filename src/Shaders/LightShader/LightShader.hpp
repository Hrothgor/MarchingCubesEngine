/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** LightShader
*/

#ifndef LIGHTSHADER_HPP_
#define LIGHTSHADER_HPP_

#include "../../global.hpp"
#include "../VertFragShader.hpp"
#include "../../Entities/Light.hpp"

namespace IS {
    class LightShader : public VertFragShader {
        public:
            LightShader();
            ~LightShader();

            void getAllUniformLocation();

            void loadTransformationMatrix(std::vector<float> matrix);
            void loadProjectionMatrix(std::vector<float> matrix);
            void loadViewMatrix(std::vector<float> matrix);
            void loadLight(Light light);
            void loadShineVariable(float shineDamper, float reflectivity);
            void loadAmbientColor(sf::Vector3f ka);

        protected:
        private:
            int loc_transformationMatrix;
            int loc_projectionMatrix;
            int loc_viewMatrix;
            int loc_lightPosition;
            int loc_lightColor;
            int loc_shineDamper;
            int loc_reflectivity;
            int loc_ambientColor;
    };
}

#endif /* !LIGHTSHADER_HPP_ */
