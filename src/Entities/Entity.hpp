/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "../global.hpp"
#include "../Models/TexturedModel.hpp"

namespace IS {
    class Entity {
        public:
            Entity(const TexturedModel &texturedModel, sf::Vector3f position, sf::Vector3f rotation, float scale);
            ~Entity();

            void increaseVelocity(sf::Vector3f vec);
            void increasePosition(sf::Vector3f vec);
            void increaseRotation(sf::Vector3f vec);

            bool update();

            TexturedModel getTexturedModel() const;
            sf::Vector3f getVelocity() const;
            sf::Vector3f getPosition() const;
            sf::Vector3f getRotation() const;
            float getScale() const;

            void setTexturedModel(TexturedModel texturedModel);
            void setVelocity(sf::Vector3f velocity);
            void setPosition(sf::Vector3f position);
            void setRotation(sf::Vector3f rotation);
            void setScale(float scale);

        protected:
        private:
            TexturedModel _texturedModel;
            sf::Vector3f _velocity = {0, 0, 0};
            sf::Vector3f _position;
            sf::Vector3f _rotation;
            float _scale;
    };
}

#endif /* !ENTITY_HPP_ */
