/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Renderer
*/

#include "Renderer.hpp"

IS::Renderer::Renderer()
{
    _shader.start();
    _shader.loadProjectionMatrix(Maths::createProjectionMatrix());
    _shader.stop();
}

IS::Renderer::~Renderer()
{
}

void IS::Renderer::prepareShader(Camera camera)
{
    _shader.start();
    _shader.loadLight(_light);
    _shader.loadViewMatrix(Maths::createViewMatrix(
                camera.getPosition(),
                camera.getPitch(),
                camera.getYaw(),
                camera.getRoll()));
}

void IS::Renderer::render(Camera camera, int scene)
{
    prepareShader(camera);

    for (auto &list : _entities) {
        if (list.first != scene)
            continue;
        for (Entity *entity : list.second) {
            prepareTextureModel(entity->getTexturedModel());
            prepareInstance(entity);
            glDrawElements(GL_TRIANGLES, entity->getTexturedModel().getVertexCount(), GL_UNSIGNED_INT, 0);
            unbindTextureModel();
        }
    }

    _shader.stop();
}

void IS::Renderer::prepareTextureModel(TexturedModel texturedModel)
{
    glBindVertexArray(texturedModel.getVao());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glActiveTexture(GL_TEXTURE0);
    sf::Texture::bind(texturedModel.getTexture());
    _shader.loadShineVariable(texturedModel.getShineDamper(), texturedModel.getReflectivity());
}

void IS::Renderer::unbindTextureModel()
{
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    sf::Texture::bind(0);
    glBindVertexArray(0);
}

void IS::Renderer::prepareInstance(Entity *entity)
{
    _shader.loadTransformationMatrix(\
        Maths::createTransformationMatrix(\
            entity->getPosition(), \
            entity->getRotation(), \
            entity->getScale()));
}

void IS::Renderer::disableCulling() const
{
    glDisable(GL_CULL_FACE);
}

void IS::Renderer::enableCulling() const
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

void IS::Renderer::addEntity(Entity *entity, int scene)
{
    for (auto &list : _entities) {
        if (list.first == scene) {
            list.second.push_back(entity);
            return;
        }
    }
    _entities[scene] = std::vector<Entity *> { entity };
}

void IS::Renderer::addLight(const Light &light, int scene)
{
    _light = light;
}