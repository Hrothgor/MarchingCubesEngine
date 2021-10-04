/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** StaticShader
*/

#ifndef STATICSHADER_HPP_
#define STATICSHADER_HPP_

#include "../../global.hpp"
#include "../ShaderProgram.hpp"
#include "../../Entities/Light.hpp"

namespace IS {
    class StaticShader : public ShaderProgram {
        public:
            StaticShader();
            ~StaticShader();

            void getAllUniformLocation();

            void loadTransformationMatrix(std::vector<float> matrix);
            void loadProjectionMatrix(std::vector<float> matrix);
            void loadViewMatrix(std::vector<float> matrix);
            void loadLight(Light light);
            void loadShineVariable(float shineDamper, float reflectivity);

        protected:
        private:
            int loc_transformationMatrix;
            int loc_projectionMatrix;
            int loc_viewMatrix;
            int loc_lightPosition;
            int loc_lightColor;
            int loc_shineDamper;
            int loc_reflectivity;
    };
}

#endif /* !STATICSHADER_HPP_ */
