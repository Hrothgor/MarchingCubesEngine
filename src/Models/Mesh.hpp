/*
** EPITECH PROJECT, 2021
** MarchingCubesEngine
** File description:
** Mesh
*/

#ifndef MESH_HPP_
#define MESH_HPP_

#include "../global.hpp"

namespace IS {
    struct RawMesh {
        int vao = -1;
        int vertexCount = 0;
        std::vector<float> vertices;
        std::vector<float> normals;
        std::vector<float> textureCoords;
        std::vector<int> indices;
    };

    class Mesh {
        public:
            Mesh() {};
            Mesh(int vao, int vertexCount, std::string name = "default", int materialIndex = 0);
            Mesh(RawMesh mesh, std::string name = "default", int materialIndex = 0);
            Mesh(const Mesh &mesh);
            ~Mesh();

            void setRawMesh(RawMesh mesh);
            void setName(std::string name);
            void setMaterialIndex(int i);

            int getVao() const;
            int getVertexCount() const;
            std::string getName() const;
            int getMaterialIndex() const;

        protected:
        private:
            std::string _name = "default";
            RawMesh _mesh;
            int _materialIndex = 0;
    };
}

#endif /* !MESH_HPP_ */
