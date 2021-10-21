/*
** EPITECH PROJECT, 2021
** MarchingCubesEngine
** File description:
** Terraforming
*/

#ifndef TERRAFORMING_HPP_
#define TERRAFORMING_HPP_

#include "../global.hpp"
#include "../Chunk/Chunk.hpp"

namespace IS {
    enum TerraformType {
        Out,
        In,
    };

    class Terraforming {
        public:
            Terraforming();
            ~Terraforming();

            void terraform(TerraformType type);

            void setBrushCenter(sf::Vector3f pos);
            void setBrushRadius(int radius);
            void setWeight(float weight);

        protected:
        private:
            int _brushRadius = 3;
            sf::Vector3f _brushCenter;
            float _weight = 1;
    };
}

#endif /* !TERRAFORMING_HPP_ */
