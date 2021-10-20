/*
** EPITECH PROJECT, 2021
** 3D
** File description:
** DisplayManager
*/

#include "DisplayManager.hpp"

IS::DisplayManager::DisplayManager()
    : _keysRough(Input::KeyCount, false)
    , _keysSmooth(Input::KeyCount, false)
{
    sf::ContextSettings settings(24, 8, 0, 3.3, 0, 0, 0);
    _window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT, 32), "3D", sf::Style::Default, settings);
    _window->setFramerateLimit(120);
    glViewport(0, 0, WIDTH, HEIGHT);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

IS::DisplayManager::~DisplayManager()
{
}

void IS::DisplayManager::event()
{
    sf::Event event;

    for (int i = 0; i < Input::KeyCount; i++)
        _keysRough[i] = false;
    while (_window->pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed && event.key.code != -1) {
            _keysRough[event.key.code] = true;
            _keysSmooth[event.key.code] = true;
        }
        if (event.type == sf::Event::KeyReleased && event.key.code != -1)
            _keysSmooth[event.key.code] = false;

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left)
                _keysSmooth[Input::LMouse] = true;
            if (event.mouseButton.button == sf::Mouse::Right)
                _keysSmooth[Input::RMouse] = true;
        }
        if (event.type == sf::Event::MouseButtonReleased) {
            if (event.mouseButton.button == sf::Mouse::Left)
                _keysSmooth[Input::LMouse] = false;
            if (event.mouseButton.button == sf::Mouse::Right)
                _keysSmooth[Input::RMouse] = false;
        }

        if (event.type == sf::Event::Closed)
            _window->close();
    }
}

void IS::DisplayManager::load()
{
    GLOBAL::_loader = new Loader;

    GLOBAL::_noise = new FastNoiseLite;
    GLOBAL::_noise->SetNoiseType(FastNoiseLite::NoiseType::NoiseType_Perlin);
    GLOBAL::_noise->SetFrequency(0.01);
    GLOBAL::_noise->SetSeed(rand());
}

void IS::DisplayManager::run()
{
    load();
    ///// 3D INIT /////
    Master3DRenderer _3Drenderer;

    TexturedModel texturedModelDragon("bomberman");
    Entity *entity = new Entity(texturedModelDragon, sf::Vector3f(0,0,0), sf::Vector3f(0,0,0), 1);
    _3Drenderer.add(entity);
    
    _3Drenderer.add(Light({0, 2000, 3000}, {1, 1, 1}));

    sf::Clock clock1;
    
    int chunkMax = 4;
    int chunkSize = 20;

    int textureSize = chunkMax * chunkSize;
    int planetSize = textureSize / 3;

    int i = 0;
    for (int i = 0; i < chunkMax; i++) {
        for (int j = 0; j < chunkMax; j++) {
            for (int k = 0; k < chunkMax; k++) {
                std::vector<IS::ScalarPoint> mcPoints;
                sf::Vector3i coord(i * chunkSize, j * chunkSize, k * chunkSize);
                Chunk *chunk = new Chunk(coord, chunkSize + 1);
                for(float x=0; x < chunkSize + 1; x++)
                    for(float y=0; y < chunkSize + 1; y++)
                        for(float z=0; z < chunkSize + 1; z++) {
                            IS::ScalarPoint vert;
                            vert.pos = {x, y, z};
                            sf::Vector3f worldPos = {vert.pos.x + coord.x, vert.pos.y + coord.y, vert.pos.z + coord.z};
                            if (worldPos.x == 0 || worldPos.y == 0 || worldPos.z == 0 ||
                                worldPos.x == textureSize - 1 || worldPos.y == textureSize - 1 || worldPos.z == textureSize - 1) {
                                vert.value = 1;
                                mcPoints.push_back(vert);
                                continue;
                            }
                            float distance = sqrt((worldPos.x - (textureSize / 2 - 1))*(worldPos.x - (textureSize / 2 - 1)) + (worldPos.y - (textureSize / 2 - 1))*(worldPos.y - (textureSize / 2 - 1)) + (worldPos.z - (textureSize / 2 - 1))*(worldPos.z - (textureSize / 2 - 1)));
                            float mapValue = distance - planetSize;
                            
                            float freq = 2;
                            float amplitude = 30;

                            for (int i = 0; i < 6; i++) {
                                mapValue += GLOBAL::_noise->GetNoise(worldPos.x * freq, worldPos.y * freq, worldPos.z * freq) * amplitude;
                                amplitude *= 0.5;
                                freq *= 2;
                            }

                            vert.value = mapValue;
                            mcPoints.push_back(vert);
                }
                chunk->setScalarPoints(mcPoints);
                chunk->generateChunk();
                RawModel tmp = chunk->getModel();
                tmp.changeAmbientColor(0, {((float) rand() / (RAND_MAX)), ((float) rand() / (RAND_MAX)), ((float) rand() / (RAND_MAX))});
                chunk->setModel(tmp);
                _3Drenderer.add(chunk);
            }
        }
    }

    // for (int i = 0; i < chunkMax; i++) {
    //     for (int j = 0; j < chunkMax; j++) {
    //         for (int k = 0; k < chunkMax; k++) {
    //             std::vector<IS::ScalarPoint> mcPoints;
    //             sf::Vector3i coord(i * chunkSize, j * chunkSize, k * chunkSize);
    //             Chunk *chunk = new Chunk(coord, chunkSize + 1);
    //             for(float x=0; x < chunkSize + 1; x++)
    //                 for(float y=0; y < chunkSize + 1; y++)
    //                     for(float z=0; z < chunkSize + 1; z++) {
    //                         float distance = sqrt((x - (chunkSize / 2 - 1))*(x - (chunkSize / 2 - 1)) + (y - (chunkSize / 2 - 1))*(y - (chunkSize / 2 - 1)) + (z - (chunkSize / 2 - 1))*(z - (chunkSize / 2 - 1)));
    //                         IS::ScalarPoint vert;
    //                         vert.pos = {x, y, z};
    //                         vert.value = (chunkSize / 2) - (chunkSize / 10) - distance;
    //                         // IS::ScalarPoint vert;
    //                         // vert.pos = {x, y, z};
    //                         // vert.value = GLOBAL::noise->GetNoise(coord.x + x, coord.y + y, coord.z + z);
    //                         mcPoints.push_back(vert);
    //             }
    //             chunk->setScalarPoints(mcPoints);
    //             chunk->generateChunk();
    //             RawModel tmp = chunk->getModel();
    //             tmp.changeAmbientColor(0, {((float) rand() / (RAND_MAX)), ((float) rand() / (RAND_MAX)), ((float) rand() / (RAND_MAX))});
    //             chunk->setModel(tmp);
    //             _3Drenderer.add(chunk);
    //         }
    //     }
    // }

    sf::Time elapsed1 = clock1.getElapsedTime();
    std::cout << elapsed1.asSeconds() << std::endl;

    Camera camera;
    ///////////////////

    ///// 2D INIT/////
    sf::Clock clock;
    int nbFrame = 0;
    sf::Font font;
    if (!font.loadFromFile("ressources/font.ttf"))
        exit (84);
    sf::Text text("120", font, 40);
    text.setFillColor(sf::Color::Yellow);
    ///////////////////

    while (_window->isOpen())
    {
        event();

        //// 3D ////
        camera.move(_keysSmooth, _window);
        _3Drenderer.render(camera);
        ///////////

        //// 2D ////
        _window->pushGLStates();

        nbFrame++;
        if (clock.getElapsedTime().asSeconds() > 1) {
            sf::Time frameTime = clock.restart();
            int framerate = (1 / frameTime.asSeconds() * nbFrame);
            text.setString(std::to_string(framerate));
            nbFrame = 0;
        }
        _window->draw(text);

        _window->popGLStates();
        ////////////

        _window->display();
    }
    delete _window;
    _keysRough.clear();
    _keysSmooth.clear();
    _3Drenderer.destroy();
    GLOBAL::_loader->destroy();
}