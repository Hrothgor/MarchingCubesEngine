/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Terrain3DRenderer
*/

#ifndef TERRAIN3DRENDERER_HPP_
#define TERRAIN3DRENDERER_HPP_

#include "../global.hpp"
#include "../Entities/Camera.hpp"
#include "../Entities/Light.hpp"
#include "../Chunk/Chunk.hpp"
#include "../Shaders/TerrainShader/TerrainShader.hpp"

namespace IS {
    class Terrain3DRenderer {
        public:
            Terrain3DRenderer();
            ~Terrain3DRenderer();

            void prepareShader(Camera camera);

            void prepareModel(RawModel model, Mesh mesh);
            void unbindModel();

            void prepareInstance(Chunk *chunk);
            void render(Camera camera, int scene);

            void disableCulling() const;
            void enableCulling() const;

            void clear(int scene);
            void addChunk(Chunk *chunk, int scene);
            void addLight(const Light &light, int scene);

        protected:
        private:
            TerrainShader _shader;

            Light _light;
            std::map<int, std::vector<Chunk *>> _chunks;
    };
}

#endif /* !TERRAIN3DRENDERER_HPP_ */
