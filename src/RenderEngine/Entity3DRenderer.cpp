/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Entity3DRenderer
*/

#include "Entity3DRenderer.hpp"

IS::Entity3DRenderer::Entity3DRenderer()
{
    _shader.start();
    _shader.loadProjectionMatrix(Maths::createProjectionMatrix().getMatrix());
    _shader.stop();
}

IS::Entity3DRenderer::~Entity3DRenderer()
{
}

void IS::Entity3DRenderer::prepareShader(Camera camera)
{
    _shader.start();
    _shader.loadLight(_light);
    _shader.loadViewMatrix(Maths::createViewMatrix(
                camera.getPosition(),
                camera.getPitch(),
                camera.getYaw(),
                camera.getRoll()).getMatrix());
}

void IS::Entity3DRenderer::render(Camera camera, int scene)
{
    prepareShader(camera);

    for (auto &list : _entities) {
        if (list.first != scene)
            continue;
        for (Entity *entity : list.second) {
            entity->update();
            prepareInstance(entity);
            for (Mesh mesh : entity->getTexturedModel().getModel().getMeshs()) {
                prepareTextureModel(entity->getTexturedModel(), mesh);
                glDrawElements(GL_TRIANGLES, mesh.getVertexCount(), GL_UNSIGNED_INT, 0);
                unbindTextureModel();
            }
        }
    }

    _shader.stop();
    clear(scene);
}

void IS::Entity3DRenderer::prepareTextureModel(TexturedModel texturedModel, Mesh mesh)
{
    glBindVertexArray(mesh.getVao());
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    glActiveTexture(GL_TEXTURE0);
    sf::Texture::bind(texturedModel.getTexture());
    
    _shader.loadShineVariable(texturedModel.getShineDamper(), texturedModel.getReflectivity());
    _shader.loadAmbientColor(texturedModel.getModel().getMaterials(mesh.getMaterialIndex()).Ka);
}

void IS::Entity3DRenderer::unbindTextureModel()
{
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    sf::Texture::bind(0);
    glBindVertexArray(0);
}

void IS::Entity3DRenderer::prepareInstance(Entity *entity)
{
    _shader.loadTransformationMatrix(\
        Maths::createTransformationMatrix(\
            entity->getPosition(), \
            entity->getRotation(), \
            entity->getScale()).getMatrix());
}

void IS::Entity3DRenderer::disableCulling() const
{
    glDisable(GL_CULL_FACE);
}

void IS::Entity3DRenderer::enableCulling() const
{
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

void IS::Entity3DRenderer::clear(int scene)
{
    for (auto &list : _entities) {
        list.second.clear();
    }
}

void IS::Entity3DRenderer::addEntity(Entity *entity, int scene)
{
    for (auto &list : _entities) {
        if (list.first == scene) {
            list.second.push_back(entity);
            return;
        }
    }
    _entities[scene] = std::vector<Entity *> { entity };
}

void IS::Entity3DRenderer::addLight(const Light &light, int scene)
{
    _light = light;
}