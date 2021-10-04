/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Master3DRenderer
*/

#ifndef MASTER3DRENDERER_HPP_
#define MASTER3DRENDERER_HPP_

#include "../global.hpp"
#include "Renderer.hpp"
#include "../Entities/Camera.hpp"
#include "../Entities/Light.hpp"
#include "../Entities/Entity.hpp"
#include "../Shaders/StaticShader/StaticShader.hpp"

namespace IS {
    class Master3DRenderer {
        public:
            Master3DRenderer();
            ~Master3DRenderer();

            void render(Light sun, Camera camera, RawModel mesh);
            void addEntity(const Entity &entity);
            void destroy();

        protected:
        private:
            StaticShader _shader;
            Renderer _renderer;
            std::map<TexturedModel, std::vector<Entity>> _entities;
    };
}

#endif /* !MASTER3DRENDERER_HPP_ */
