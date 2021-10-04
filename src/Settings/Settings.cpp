/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** Settings
*/

#include "Settings.hpp"

IS::Settings settings("ressources/config.ini");

std::string getConfigFromFile(const std::string &configFileName, const std::string &key)
{
    std::ifstream fs(configFileName);

    if (fs.is_open()) {
        std::string str;
        while (std::getline(fs, str)) {
            std::size_t pos = str.find("=");
            if (str.substr(0, pos) == key) {
                fs.close();
                return (str.substr(pos + 1));
            }
        }
    }
    fs.close();
    return ("");
}

IS::Settings::Settings(const std::string &configFileName)
{
    try {
    } catch (std::exception) {
        std::cout << "Error in config file" << std::endl;
        exit(84);
    }
}

IS::Settings::~Settings()
{
}