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
            void setAllVertex(std::vector<sf::Vector3f> allVertex);

            RawMesh getRawMesh() const;
            int getVao() const;
            int getVertexCount() const;
            std::string getName() const;
            int getMaterialIndex() const;
            std::vector<sf::Vector3f> getAllVertex() const;

        protected:
        private:
            std::string _name = "default";
            RawMesh _mesh;
            std::vector<sf::Vector3f> _allVertex;
            int _materialIndex = 0;
    };
}

#endif /* !MESH_HPP_ */
