/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Renderer
*/

#ifndef RENDERER_HPP_
#define RENDERER_HPP_

#include "../global.hpp"
#include "../Entities/Entity.hpp"
#include "../Shaders/StaticShader/StaticShader.hpp"

namespace IS {
    class Renderer {
        public:
            Renderer(const StaticShader &shader);
            ~Renderer();

            void prepare() const;
            void prepareTextureModel(TexturedModel texturedModel);
            void unbindTextureModel();
            void prepareInstance(Entity entity);
            void render(std::map<TexturedModel, std::vector<Entity>> entities);
            void disableCulling() const;
            void enableCulling() const;

        protected:
        private:
            StaticShader _shader;
    };
}

#endif /* !RENDERER_HPP_ */
