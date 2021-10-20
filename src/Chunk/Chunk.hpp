/*
** EPITECH PROJECT, 2021
** Engine_Marching_Cubes
** File description:
** Chunk
*/

#ifndef CHUNK_HPP_
#define CHUNK_HPP_

#include "../global.hpp"
#include "../MarchingCubes/MarchingCubes.hpp"

namespace IS {
    class Chunk {
        public:
            Chunk(sf::Vector3f coord, int _size);
            ~Chunk();

            bool update();

            void generateChunk();

            std::vector<ScalarPoint> getScalarPoints() const;
            RawModel getModel() const;
            sf::Vector3f getCoord() const;

            void setScalarPoints(std::vector<ScalarPoint> scalarpoints);
            void setModel(RawModel model);
        protected:
        private:
            int _size;
            sf::Vector3f _id;

            std::vector<ScalarPoint> _points;
            MarchingCubes _MC;
            RawModel _model;

            bool _regenerate = false;
    };
}

#endif /* !CHUNK_HPP_ */
