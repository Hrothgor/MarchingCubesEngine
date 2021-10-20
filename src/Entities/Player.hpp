/*
** EPITECH PROJECT, 2021
** MarchingCubesEngine
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "../global.hpp"
#include "Entity.hpp"

namespace IS {
    class Player : public Entity {
        public:
            Player(Entity entity);
            ~Player();

            bool update();

        protected:
        private:
    };
}

#endif /* !PLAYER_HPP_ */