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

namespace IS {
    class Master3DRenderer {
        public:
            Master3DRenderer();
            ~Master3DRenderer();

            void prepare();
            void render(Camera camera, RawModel mesh);

            void addEntity(Entity *entity, int scene = 0);
            void addLight(const Light &light, int scene = 0);

            void destroy();

        protected:
        private:
            Renderer _renderer;
    };
}

#endif /* !MASTER3DRENDERER_HPP_ */
