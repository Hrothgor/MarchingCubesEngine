/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** TerrainShader
*/

#ifndef TERRAINSHADER_HPP_
#define TERRAINSHADER_HPP_

#include "../../global.hpp"
#include "../VertFragShader.hpp"
#include "../../Entities/Light.hpp"

namespace IS {
    class TerrainShader : public VertFragShader {
        public:
            TerrainShader();
            ~TerrainShader();

            void getAllUniformLocation();

            void loadTransformationMatrix(std::vector<float> matrix);
            void loadProjectionMatrix(std::vector<float> matrix);
            void loadViewMatrix(std::vector<float> matrix);
            void loadLight(Light light);
            void loadAmbientColor(sf::Vector3f ka);
            void loadPlanetCenter(sf::Vector3f planetCenter);

        protected:
        private:
            int loc_transformationMatrix;
            int loc_projectionMatrix;
            int loc_viewMatrix;
            int loc_lightPosition;
            int loc_lightColor;
            int loc_ambientColor;
            int loc_planetCenter;
    };
}

#endif /* !TERRAINSHADER_HPP_ */
