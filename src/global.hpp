/*
** EPITECH PROJECT, 2021
** indieStudio
** File description:
** global
*/

#ifndef GLOBAL_HPP_
#define GLOBAL_HPP_

#include "include.hpp"

class FastNoiseLite;
namespace IS {
    inline int chunkMax;
    inline int chunkSize;

    class TexturedModel;
    class Entity;
    class Chunk;
    
    class Loader;
    class Camera;

    namespace GLOBAL {
        inline std::map<std::string, TexturedModel *> _texturedModels;
        
        inline std::vector<Entity *> _entities;
        inline std::vector<Chunk *> _chunks;

        inline IS::Camera *_camera;
        inline IS::Loader *_loader;
        inline FastNoiseLite *_noise;

    };
}

#endif /* !GLOBAL_HPP_ */
