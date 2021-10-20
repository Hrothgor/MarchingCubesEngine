/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** DisplayManager
*/

#ifndef DISPLAYMANAGER_HPP_
#define DISPLAYMANAGER_HPP_

#include "../global.hpp"
#include "Master3DRenderer.hpp"
#include "RayCasting.hpp"

#include "../Entities/Light.hpp"
#include "../Models/Loader.hpp"
#include "../Entities/Camera.hpp"
#include "../Chunk/Chunk.hpp"

namespace IS {
    class DisplayManager {
        public:
            DisplayManager();
            ~DisplayManager();

            void load();
            void run();
            void event();
            void updateDisplay();

        protected:
        private:
            sf::RenderWindow *_window;
            std::vector<bool> _keysRough; //for name input for example
            std::vector<bool> _keysSmooth; //for movement
    };
}

#endif /* !DISPLAYMANAGER_HPP_ */
