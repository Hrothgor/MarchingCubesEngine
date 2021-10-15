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
    glClearColor(1, 0, 0, 1);
}

void IS::Master3DRenderer::render(Camera camera, RawModel mesh)
{
    prepare();

    _renderer.enableCulling();

    _renderer.render(camera, 0);

    // if (mesh.getVao() != -1) {
    //     glDisable(GL_CULL_FACE);
    //     glBindVertexArray(mesh.getVao());
    //     glEnableVertexAttribArray(0);
    //     glEnableVertexAttribArray(1);
    //     // _shader.loadTransformationMatrix(\
    //     //     Maths::createTransformationMatrix(\
    //     //         {0, 0, 0}, \
    //     //         {0, 0, 0}, \
    //     //         1));
    //     glDrawElements(GL_TRIANGLES, mesh.getVertexCount(), GL_UNSIGNED_INT, 0);
    //     glDisableVertexAttribArray(0);
    //     glDisableVertexAttribArray(1);
    //     glBindVertexArray(0);
    // }
}

void IS::Master3DRenderer::addEntity(Entity *entity, int scene)
{
    _renderer.addEntity(entity, scene);
}

void IS::Master3DRenderer::addLight(const Light &light, int scene)
{
    _renderer.addLight(light, scene);
}

void IS::Master3DRenderer::destroy()
{
}