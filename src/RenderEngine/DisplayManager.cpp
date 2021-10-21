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
    // _window->setFramerateLimit(120);
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
    GLOBAL::_camera = new Camera;

    GLOBAL::_noise = new FastNoiseLite;
    GLOBAL::_noise->SetNoiseType(FastNoiseLite::NoiseType::NoiseType_Perlin);
    GLOBAL::_noise->SetFrequency(0.01);
    GLOBAL::_noise->SetSeed(rand());

    GLOBAL::_texturedModels["bomberman"] = new TexturedModel("bomberman");

    GLOBAL::_entities.push_back(new Entity(*GLOBAL::_texturedModels["bomberman"], { 0, 0, 0 }, { 0, 0, 0 }, 3));

    sf::Clock clock;

    int textureSize = chunkMax * chunkSize;
    int planetSize = textureSize / 3;

    for (int i = 0; i < chunkMax; i++) {
        for (int j = 0; j < chunkMax; j++) {
            for (int k = 0; k < chunkMax; k++) {
                std::vector<IS::ScalarPoint> mcPoints;   
                sf::Vector3f coord(i * chunkSize, j * chunkSize, k * chunkSize);
                Chunk *chunk = new Chunk(coord, chunkSize + 1);
                for(float x=0; x < chunkSize + 1; x++)
                    for(float y=0; y < chunkSize + 1; y++)
                        for(float z=0; z < chunkSize + 1; z++) {
                            IS::ScalarPoint vert;
                            vert.pos = {x, y, z};
                            sf::Vector3f worldPos = {vert.pos.x + coord.x, vert.pos.y + coord.y, vert.pos.z + coord.z};
                            if (worldPos.x == 0 || worldPos.y == 0 || worldPos.z == 0 ||
                                worldPos.x == textureSize || worldPos.y == textureSize || worldPos.z == textureSize) {
                                vert.value = 1;
                                mcPoints.push_back(vert);
                                continue;
                            }
                            float distance = sqrt((worldPos.x - (textureSize / 2 - 1))*(worldPos.x - (textureSize / 2 - 1)) + (worldPos.y - (textureSize / 2 - 1))*(worldPos.y - (textureSize / 2 - 1)) + (worldPos.z - (textureSize / 2 - 1))*(worldPos.z - (textureSize / 2 - 1)));
                            float mapValue = distance - planetSize;
                            
                            float freq = 3;
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
                GLOBAL::_chunks.push_back(chunk);
            }
        }
    }
    sf::Time elapsed = clock.getElapsedTime();
    std::cout << elapsed.asSeconds() << std::endl;
}

void IS::DisplayManager::run()
{
    load();
    ///// 3D INIT /////
    Master3DRenderer _3Drenderer;

    _3Drenderer.add(Light({0, 20000, 0}, {1, 1, 1}));

    RayCasting ray;
    Terraforming terraform;
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
        ////////////

        for (Entity *entity : GLOBAL::_entities)
            _3Drenderer.add(entity);
        for (Chunk *chunk : GLOBAL::_chunks)
            _3Drenderer.add(chunk);

        ray.update(_window);
        if (ray.intersect()) {
            GLOBAL::_entities[0]->setPosition(ray.getCurrentIntersectPoint());
            terraform.setBrushCenter(ray.getCurrentIntersectPoint());
        }
        if (_keysSmooth[Input::LMouse]) {
            terraform.terraform(TerraformType::Out);
        }
        if (_keysSmooth[Input::RMouse]) {
            terraform.terraform(TerraformType::In);
        }

        //// 3D ////
        GLOBAL::_camera->move(_keysSmooth, _window);
        _3Drenderer.render(*GLOBAL::_camera);
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