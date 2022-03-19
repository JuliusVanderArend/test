#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Player.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Renderer.h"
#include "testClass.h"
#include "SceneState.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");  

    const int NUM_OBJECTS = 128;
    float frame = 0;

    Object* objects[NUM_OBJECTS];

    Player* player = new Player();
    objects[1] = player;

    sf::Shader shaders[128];

    sf::Shader testShader;
    testShader.loadFromFile("testFragment.frag", sf::Shader::Fragment);
    //sf::Shader testShader2;
    //testShader2.loadFromFile("testFragment.frag", sf::Shader::Fragment);

    sf::Texture texture;
    texture.loadFromFile("letter.png");
    sf::Texture texture2;
    texture2.loadFromFile("table.png");

    sf::Texture testNormal;
    testNormal.loadFromFile("red_bricks_04_nor_gl_1k.jpg");

    sf::Texture testNormal2;
    testNormal2.loadFromFile("rust_coarse_01_nor_gl_1k.jpg");

    Renderer renderer(&window);
    SceneState sceneState;
    sceneState.renderer = renderer;


    Material testMaterial(&testShader,texture,testNormal);
    Material testMaterial2(&testShader,texture2,testNormal2);

    Sprite testSprite(testMaterial);
    testSprite.sprite.setScale(5, 5);
    Sprite testSprite2(testMaterial2);
    testSprite2.sprite.setScale(5, 5);

    testSprite2.sprite.setPosition(500, 500);

    renderer.lights[0] = Light(sf::Vector2f(0, 0), sf::Vector3f(1.0, 0.8, 0.7), 20000);

    for (int i = 0; i < 128; i++) {
        Particle* particle = new Particle(sf::Vector2f(i * 30, 10));
        particle->renderer = renderer;
        objects[i] = particle;
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //update stuff
        sf::Vector2i localPosition = sf::Mouse::getPosition(window); 
        sf::Vector2f pos(localPosition.x, localPosition.y);
        //std::cout << sceneState.renderer.lights[0].position.x << std::endl;
      
        for (int i = 0; i < NUM_OBJECTS; i++) {
            objects[i]->update();
        }
        //std::cout << sceneState.renderer.lights[0].position.x << std::endl;

        //render stuff
        window.clear();
        renderer.lights[0].position = pos;
        renderer.setupFrame(&testShader);
        //std::cout << renderer.lights[1].position.y << std::endl;
        //renderer.debugLightsArray();
        renderer.draw(testSprite);
        renderer.draw(testSprite2);
        window.display();
        frame++;
    }
    return 0;
}