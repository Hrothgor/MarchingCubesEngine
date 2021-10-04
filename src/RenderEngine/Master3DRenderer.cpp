/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Master3DRenderer
*/

#include "Master3DRenderer.hpp"

IS::Master3DRenderer::Master3DRenderer() : _renderer(_shader)
{
}

IS::Master3DRenderer::~Master3DRenderer()
{
}

void IS::Master3DRenderer::render(Light sun, Camera camera, RawModel mesh)
{
    _renderer.prepare();
    _shader.start();
    _shader.loadLight(sun);
    _shader.loadViewMatrix(Maths::createViewMatrix(
                camera.getPosition(),
                camera.getPitch(),
                camera.getYaw(),
                camera.getRoll()));
    _renderer.render(_entities);

    if (mesh.getVao() != -1) {
        glDisable(GL_CULL_FACE);
        glBindVertexArray(mesh.getVao());
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        _shader.loadTransformationMatrix(\
            Maths::createTransformationMatrix(\
                {0, 0, 0}, \
                {0, 0, 0}, \
                1));
        glDrawElements(GL_TRIANGLES, mesh.getVertexCount(), GL_UNSIGNED_INT, 0);
        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glBindVertexArray(0);
    }

    _shader.stop();
}

void IS::Master3DRenderer::addEntity(const Entity &entity)
{
    TexturedModel entityModel = entity.getTexturedModel();
    for (auto &list : _entities) {
        if (list.first == entityModel) {
            list.second.push_back(entity);
            return;
        }
    }
    _entities[entityModel] = std::vector<Entity> { entity };
}

void IS::Master3DRenderer::destroy()
{
    _shader.destroy();
    _entities.clear();
}