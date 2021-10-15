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

void IS::DisplayManager::load()
{
    GLOBAL::loader = new Loader;

    GLOBAL::noise = new FastNoiseLite;
    GLOBAL::noise->SetNoiseType(FastNoiseLite::NoiseType::NoiseType_Perlin);
    GLOBAL::noise->SetFrequency(0.01);
    GLOBAL::noise->SetSeed(rand());
}

void IS::DisplayManager::event()
{
    sf::Event event;

    for (int i = 0; i < Input::KeyCount; i++)
        _keysRough[i] = false;
    while (_window->pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed) {
            _keysRough[event.key.code] = true;
            _keysSmooth[event.key.code] = true;
        }
        if (event.type == sf::Event::KeyReleased)
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

void IS::DisplayManager::run()
{
    load();
    ///// 3D INIT /////
    Master3DRenderer _renderer;

    RawModel modelDragon = OBJLoader::loadObjModel("ressources/dragon.obj");
    TexturedModel texturedModelDragon(modelDragon);
    Entity *entity = new Entity(texturedModelDragon, sf::Vector3f(0,0,0), sf::Vector3f(0,0,0), 1);
    _renderer.addEntity(entity);

    // int MeshSize = 500;
    // std::vector<IS::ScalarPoint> mcPoints;
	// for(float x=0; x < MeshSize; x++)
	// 	for(float y=0; y < MeshSize; y++)
	// 		for(float z=0; z < MeshSize; z++) {
    //             float distance = sqrt((x - (MeshSize / 2 - 1))*(x - (MeshSize / 2 - 1)) + (y - (MeshSize / 2 - 1))*(y - (MeshSize / 2 - 1)) + (z - (MeshSize / 2 - 1))*(z - (MeshSize / 2 - 1)));
	// 			IS::ScalarPoint vert;
    //             vert.pos = {x, y, z};
	// 			vert.value = (MeshSize / 2) - (MeshSize / 10) - distance;
	// 			mcPoints.push_back(vert);
	// } 

    // for (int i = 0; i < CHUNK_MAX; i++) {
    //     for (int j = 0; j < CHUNK_MAX; j++) {
    //         std::vector<IS::ScalarPoint> mcPoints;
    //         sf::Vector3i coord(i * CHUNK_SIZE, 0, j * CHUNK_SIZE);
    //         Chunk chunk(coord, CHUNK_SIZE);
    //         for(float x=0; x < CHUNK_SIZE; x++)
    //             for(float y=0; y < CHUNK_SIZE; y++)
    //                 for(float z=0; z < CHUNK_SIZE; z++) {
    //                     IS::ScalarPoint vert;
    //                     vert.pos = {x, y, z};
    //                     vert.value = GLOBAL::noise->GetNoise(x, y, z);
    //                     mcPoints.push_back(vert);
    //         }
    //         chunk.setScalarPoints(mcPoints);
    //         chunk.generateChunk();
    //         GLOBAL::chunks->push_back(chunk);
    //     }
    // }
    sf::Clock clock1;

    // int MeshSize = 500;
    // std::vector<IS::ScalarPoint> mcPoints;
    // for(float x=0; x < MeshSize; x++)
    //     for(float y=0; y < MeshSize; y++)
    //         for(float z=0; z < MeshSize; z++) {
    //             IS::ScalarPoint vert;
    //             vert.pos = {x, y, z};
    //             vert.value = GLOBAL::noise->GetNoise(x, y, z);
    //             mcPoints.push_back(vert);
    // }
    // MarchingCubes MC(MeshSize, 0);
    // RawModel mesh = MC.loadMarchingCubesModel({0,0,0}, mcPoints);
    RawModel mesh;

    sf::Time elapsed1 = clock1.getElapsedTime();
    std::cout << elapsed1.asSeconds() << std::endl;

    float angle = 0;
    Light light(sf::Vector3f(0,2000,3000), sf::Vector3f(1,1,1));
    _renderer.addLight(light);

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

        angle += 0.005;
        light.setPosition({sinf(angle) * 3000, 0, cosf(angle) * 3000});

        //// 3D ////
        camera.move(_keysSmooth, _window);
        _renderer.render(camera, mesh);
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
    _renderer.destroy();
    GLOBAL::loader->destroy();
}