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
    class Loader;
    class Chunk;

    struct ScalarPoint {
        sf::Vector3f pos;
        float value;
    };

    namespace GLOBAL {
        inline IS::Loader *loader;
        inline FastNoiseLite *noise;

        inline std::vector<Chunk> *chunks;
    };
}

#endif /* !GLOBAL_HPP_ */
