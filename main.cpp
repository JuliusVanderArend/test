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
    testNormal2.loadFromFile("metal_plate_nor_gl_1k.jpg");

    Renderer renderer(&window);
    SceneState sceneState;
    sceneState.renderer = renderer;


    Material testMaterial(&testShader,texture,testNormal);
    Material testMaterial2(&testShader,texture2,testNormal2);

    Sprite testSprite(testMaterial);
    testSprite.sprite.setScale(20, 20);
    Sprite testSprite2(testMaterial2);
    testSprite2.sprite.setScale(10, 10);

    testSprite2.sprite.setPosition(200, 200);

    renderer.lights[0] = Light(sf::Vector2f(0, 0), sf::Vector3f(1.0, 0.8, 0.7), 20);

    for (int i = 0; i < 100; i++) {
        Particle* particle = new Particle(sf::Vector2f(i * 30, 10));
        particle->renderer = &renderer;
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
      
        for (int i = 0; i < NUM_OBJECTS; i++) {
            if (objects[i]->tag != "default") {
                objects[i]->update();
            }
            //std::cout << objects[i]->tag;
        }

        //render stuff
        window.clear();
        renderer.lights[0] = Light(pos, sf::Vector3f(1.0, 0.8, 0.7), 1000);;
        renderer.setupFrame(&testShader);
        renderer.draw(testSprite);
        renderer.draw(testSprite2);
        window.display();
        frame++;
    }
    return 0;
}