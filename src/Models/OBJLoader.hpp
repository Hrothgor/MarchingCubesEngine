/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** OBJLoader
*/

#ifndef OBJLOADER_HPP_
#define OBJLOADER_HPP_

#include "../global.hpp"
#include "RawModel.hpp"
#include "../RenderEngine/Loader.hpp"

namespace IS {
    class OBJLoader {
        public:
            OBJLoader();
            ~OBJLoader();

            static RawModel loadObjModel(std::string fileName);

        protected:
        private:
            static std::vector<std::string> string_split(std::string s, const char delimiter);
    };
}

#endif /* !OBJLOADER_HPP_ */
