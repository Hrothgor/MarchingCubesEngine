/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Terrain3DRenderer
*/

#include "Terrain3DRenderer.hpp"

IS::Terrain3DRenderer::Terrain3DRenderer()
{
    _shader.start();
    _shader.loadProjectionMatrix(Maths::createProjectionMatrix().getMatrix());
    _shader.loadPlanetCenter({chunkMax * chunkSize / 2, chunkMax * chunkSize / 2, chunkMax * chunkSize / 2});
    _shader.stop();
}

IS::Terrain3DRenderer::~Terrain3DRenderer()
{
}

void IS::Terrain3DRenderer::prepareShader(Camera camera)
{
    _shader.start();
    _shader.loadLight(_light);
    _shader.loadViewMatrix(Maths::createViewMatrix(
                camera.getPosition(),
                camera.getPitch(),
                camera.getYaw(),
                camera.getRoll()).getMatrix());
}


void IS::Terrain3DRenderer::render(Camera camera, int scene)
{
    prepareShader(camera);

    for (auto &list : _chunks) {
        if (list.first != scene)
            continue;
        for (Chunk *chunk : list.second) {
            chunk->update();
            prepareInstance(chunk);
            for (Mesh mesh : chunk->getModel().getMeshs()) {
                prepareModel(chunk->getModel(), mesh);
                glDrawElements(GL_TRIANGLES, mesh.getVertexCount(), GL_UNSIGNED_INT, 0);
                unbindModel();
            }
        }
    }

    _shader.stop();
    clear(scene);
}

void IS::Terrain3DRenderer::prepareModel(RawModel model, Mesh mesh)
{
    glBindVertexArray(mesh.getVao());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    _shader.loadAmbientColor(model.getMaterials(mesh.getMaterialIndex()).Ka);
}

void IS::Terrain3DRenderer::unbindModel()
{
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glBindVertexArray(0);
}

void IS::Terrain3DRenderer::prepareInstance(Chunk *chunk)
{
    sf::Vector3f vec = {chunk->getCoord().x, chunk->getCoord().y, chunk->getCoord().z};

    _shader.loadTransformationMatrix(\
        Maths::createTransformationMatrix(\
            vec, \
            {0, 0, 0}, \
            1).getMatrix());
}

void IS::Terrain3DRenderer::disableCulling() const
{
    glDisable(GL_CULL_FACE);
}

void IS::Terrain3DRenderer::enableCulling() const
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

void IS::Terrain3DRenderer::clear(int scene)
{
    for (auto &list : _chunks) {
        list.second.clear();
    }
}

void IS::Terrain3DRenderer::addChunk(Chunk *chunk, int scene)
{
    for (auto &list : _chunks) {
        if (list.first == scene) {
            list.second.push_back(chunk);
            return;
        }
    }
    _chunks[scene] = std::vector<Chunk *> { chunk };
}

void IS::Terrain3DRenderer::addLight(const Light &light, int scene)
{
    _light = light;
}