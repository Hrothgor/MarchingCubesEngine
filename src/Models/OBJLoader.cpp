/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** OBJLoader
*/

#include "OBJLoader.hpp"

IS::OBJLoader::OBJLoader()
{
}

IS::OBJLoader::~OBJLoader()
{
}

std::vector<std::string> IS::OBJLoader::string_split(std::string s, const char delimiter)
{
    std::vector<std::string> output;
    size_t start = 0;
    size_t end = s.find_first_of(delimiter);

    while (end <= std::string::npos)
    {
        output.emplace_back(s.substr(start, end - start));
        if (end == std::string::npos)
            break;
        start = end + 1;
        end = s.find_first_of(delimiter, start);
    }
    return (output);
}

IS::RawModel IS::OBJLoader::loadObjModel(std::string fileName)
{
    std::ifstream fs(fileName);
    std::vector<sf::Vector2f> textures;
    std::vector<sf::Vector3f> normals;
    std::vector<float> verticesSorted;
    std::vector<float> texturesSorted;
    std::vector<float> normalsSorted;
    std::vector<int> indices;

    if (fs.is_open()) { 
        std::string str;
        try {
            while (std::getline(fs, str)) {
                std::vector<std::string> array = string_split(str, ' ');
                if (array.empty())
                    continue;
                if (array[0] == "v") {
                    verticesSorted.push_back(std::stof(array[1]));
                    verticesSorted.push_back(std::stof(array[2]));
                    verticesSorted.push_back(std::stof(array[3]));
                    texturesSorted.resize(texturesSorted.size() + 2);
                    normalsSorted.resize(normalsSorted.size() + 3);
                } else if (array[0] == "vt") {
                    textures.push_back(sf::Vector2f(std::stof(array[1]), std::stof(array[2])));
                } else if (array[0] == "vn") {
                    normals.push_back(sf::Vector3f(std::stof(array[1]), std::stof(array[2]), std::stof(array[3])));
                } else if (array[0] == "f") {
                    std::vector<std::string> vec[3];
                    vec[0] = string_split(array[1], '/');
                    vec[1] = string_split(array[2], '/');
                    vec[2] = string_split(array[3], '/');
                    for (std::vector<std::string> data : vec) {
                        int currentVertexPointer = std::stoi(data[0]) - 1;
                        sf::Vector2f currentTex = textures[std::stoi(data[1]) - 1];
                        sf::Vector3f currentNorm = normals[std::stoi(data[2]) - 1];
                        indices.push_back(currentVertexPointer);
                        texturesSorted[currentVertexPointer * 2] = currentTex.x;
                        texturesSorted[currentVertexPointer * 2 + 1] = 1 - currentTex.y;
                        normalsSorted[currentVertexPointer * 3] = currentNorm.x;
                        normalsSorted[currentVertexPointer * 3 + 1] = currentNorm.y;
                        normalsSorted[currentVertexPointer * 3 + 2] = currentNorm.z;
                    }
                }
            }
        } catch (std::exception) {
            std::cout << fileName << " is a wrong OBJ file" << std::endl;
            exit(84);
        }
    } else {
        std::cout << "Couldn't open " << fileName << " OBJ file" << std::endl;
        exit(84);
    }
    return (GLOBAL::loader->LoadToVAO(verticesSorted, texturesSorted, normalsSorted, indices));
}
