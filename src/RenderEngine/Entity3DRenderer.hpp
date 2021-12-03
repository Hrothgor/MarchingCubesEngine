/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Entity3DRenderer
*/

#ifndef ENTITY3DRENDERER_HPP_
#define ENTITY3DRENDERER_HPP_

#include "../global.hpp"
#include "../Entities/Camera.hpp"
#include "../Entities/Light.hpp"
#include "../Entities/Entity.hpp"
#include "../Shaders/LightShader/LightShader.hpp"

#include "../Shaders/MarchingCubeShader/MarchingCubeShader.hpp"

namespace IS {
    class Entity3DRenderer {
        public:
            Entity3DRenderer();
            ~Entity3DRenderer();

            void prepareShader(Camera camera);

            void prepareTextureModel(TexturedModel texturedModel, Mesh mesh);
            void unbindTextureModel();

            void prepareInstance(Entity *entity);
            void render(Camera camera, int scene);

            void disableCulling() const;
            void enableCulling() const;

            void clear(int scene);
            void addEntity(Entity *entity, int scene);
            void addLight(const Light &light, int scene);

        protected:
        private:
            LightShader _shader;

            Light _light;
            std::map<int, std::vector<Entity *>> _entities;

            GLuint tex_output;
            GLuint atomicsBuffer;
            GLuint tmp;
            MarchingCubeShader shader;
    };
}

#endif /* !ENTITY3DRENDERER_HPP_ */
