/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** RawModel
*/

#ifndef RAWMODEL_HPP_
#define RAWMODEL_HPP_

#include "../global.hpp"

namespace IS {
    class RawModel {
        public:
            RawModel() {};
            RawModel(int vao, int vertexCount);
            RawModel(const RawModel &model);
            ~RawModel();

            int getVao() const;
            int getVertexCount() const;

        protected:
        private:
            int _vao = -1;
            int _vertexCount = 0;
    };
}

#endif /* !RAWMODEL_HPP_ */
