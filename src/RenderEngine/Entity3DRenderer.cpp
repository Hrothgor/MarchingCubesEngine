/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Entity3DRenderer
*/

#include "Entity3DRenderer.hpp"

struct Triangle {
    sf::Vector3f pos;
    float memFillA;
    sf::Vector3f normal;
    float memFillaB;
    sf::Vector2i id;
    float memFillaC;
    float memFillaD;
};

IS::Entity3DRenderer::Entity3DRenderer()
{
    _shader.start();
    _shader.loadProjectionMatrix(Maths::createProjectionMatrix().getMatrix());
    _shader.stop();

    shader.start();

    std::vector<Triangle> data;
    for (int i = 0; i < 248 * 248 * 248; i++)
        data.push_back({{100,0,0}, 0, {0,0,0}, 0, {0,0}, 0, 0});
    GLuint tmp;
    glGenBuffers(1, &tmp);
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, tmp);
    glBufferData(GL_SHADER_STORAGE_BUFFER, 248 * 248 * 248 * sizeof(Triangle), &data[0], GL_DYNAMIC_DRAW);
    glGenBuffers(1, &tex_output);
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 1, tex_output);
    glBufferData(GL_SHADER_STORAGE_BUFFER, 248 * 248 * 248 * sizeof(Triangle), NULL, GL_DYNAMIC_DRAW);

    shader.dispatch(248 * 248 * 248, 1, 1);
    glMemoryBarrier(GL_SHADER_STORAGE_BARRIER_BIT);
    glBindBufferBase(GL_SHADER_STORAGE_BUFFER, 0, 0);

    glBindBuffer(GL_SHADER_STORAGE_BUFFER, tex_output);
    Triangle *returnArray = (Triangle *)glMapBufferRange(GL_SHADER_STORAGE_BUFFER, 0, 248 * 248 * 248 * sizeof(Triangle), GL_MAP_READ_BIT);
    glUnmapBuffer(GL_SHADER_STORAGE_BUFFER);
    glBindBuffer(GL_SHADER_STORAGE_BUFFER, 0);
    
    shader.stop();

    // int tex_w = 512, tex_h = 512;
    // glGenTextures(1, &tex_output);
    // glActiveTexture(GL_TEXTURE0);
    // glBindTexture(GL_TEXTURE_2D, tex_output);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, tex_w, tex_h, 0, GL_RGBA, GL_FLOAT,
    // NULL);
    // glBindImageTexture(0, tex_output, 0, GL_FALSE, 0, GL_WRITE_ONLY, GL_RGBA32F);
    // glBindTexture(GL_TEXTURE_2D, 0);
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
    // shader.start();
    // shader.dispatch(512 / 8, 512 / 8, 1);
    // glMemoryBarrier(GL_ALL_BARRIER_BITS);
    // shader.stop();
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
    // glBindTexture(GL_TEXTURE_2D, tex_output);
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