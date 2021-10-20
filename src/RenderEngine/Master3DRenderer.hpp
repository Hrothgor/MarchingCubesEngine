/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Master3DRenderer
*/

#ifndef MASTER3DRENDERER_HPP_
#define MASTER3DRENDERER_HPP_

#include "../global.hpp"
#include "Entity3DRenderer.hpp"
#include "Terrain3DRenderer.hpp"

namespace IS {
    class Master3DRenderer {
        public:
            Master3DRenderer();
            ~Master3DRenderer();

            void prepare();
            void render(Camera camera);

            void add(Entity *entity, int scene = 0);
            void add(Chunk *chunk, int scene = 0);
            void add(const Light &light, int scene = 0);

            void destroy();

            void disableCulling() const;
            void enableCulling() const;

        protected:
        private:
            Entity3DRenderer _entityRenderer;
            Terrain3DRenderer _terrainRenderer;
    };
}

#endif /* !MASTER3DRENDERER_HPP_ */
