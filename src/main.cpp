/*
** EPITECH PROJECT, 2021
** main
** File description:
** main
*/

#include "global.hpp"
#include "RenderEngine/DisplayManager.hpp"

int main(void)
{
    srand(time(NULL));
    IS::DisplayManager win;
    win.run();
    return (0);
}