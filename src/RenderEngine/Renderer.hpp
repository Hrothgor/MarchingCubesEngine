/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Renderer
*/

#ifndef RENDERER_HPP_
#define RENDERER_HPP_

#include "../global.hpp"
#include "../Entities/Camera.hpp"
#include "../Entities/Light.hpp"
#include "../Entities/Entity.hpp"
#include "../Shaders/StaticShader/StaticShader.hpp"

namespace IS {
    class Renderer {
        public:
            Renderer();
            ~Renderer();

            void prepareShader(Camera camera);

            void prepareTextureModel(TexturedModel texturedModel);
            void unbindTextureModel();

            void prepareInstance(Entity *entity);
            void render(Camera camera, int scene);

            void disableCulling() const;
            void enableCulling() const;

            void addEntity(Entity *entity, int scene);
            void addLight(const Light &light, int scene);

        protected:
        private:
            StaticShader _shader;

            Light _light;
            std::map<int, std::vector<Entity *>> _entities;
    };
}

#endif /* !RENDERER_HPP_ */
