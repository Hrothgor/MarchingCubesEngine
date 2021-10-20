/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Master3DRenderer
*/

#include "Master3DRenderer.hpp"

IS::Master3DRenderer::Master3DRenderer()
{
}

IS::Master3DRenderer::~Master3DRenderer()
{
}

void IS::Master3DRenderer::prepare()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0, 0, 1, 1);
}

void IS::Master3DRenderer::render(Camera camera)
{
    prepare();

    _terrainRenderer.render(camera, 0);

    _entityRenderer.render(camera, 0);
}

void IS::Master3DRenderer::add(Entity *entity, int scene)
{
    _entityRenderer.addEntity(entity, scene);
}

void IS::Master3DRenderer::add(Chunk *chunk, int scene)
{
    _terrainRenderer.addChunk(chunk, scene);
}

void IS::Master3DRenderer::add(const Light &light, int scene)
{
    _entityRenderer.addLight(light, scene);
    _terrainRenderer.addLight(light, scene);
}

void IS::Master3DRenderer::destroy()
{
}

void IS::Master3DRenderer::disableCulling() const
{
    glDisable(GL_CULL_FACE);
}

void IS::Master3DRenderer::enableCulling() const
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}