/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** RawModel
*/

#ifndef RAWMODEL_HPP_
#define RAWMODEL_HPP_

#include "../global.hpp"
#include "Mesh.hpp"

namespace IS {
    struct Material {
        std::string name = "default";
        sf::Vector3f Ka = {0, 0, 0};
    };

    class RawModel {
        public:
            RawModel() {};
            RawModel(std::vector<Mesh> meshs, std::vector<Material> mats);
            RawModel(RawMesh mesh);
            ~RawModel();

            void changeAmbientColor(int i, sf::Vector3f value);

            std::vector<Mesh> getMeshs() const;
            std::vector<Material> getMaterials() const;
            Material getMaterials(int i) const;

            void setMeshs(std::vector<Mesh> meshs);
            void setMaterials(std::vector<Material> mats);

            void addMesh(Mesh mesh);
            void addMaterial(Material mat);

        protected:
        private:
            std::vector<Mesh> _meshs;
            std::vector<Material> _materials;
    };
}

#endif /* !RAWMODEL_HPP_ */
