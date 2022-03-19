#include <SFML/Graphics.hpp>
#include <random>


#include "Object.h"
#include "Player.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Renderer.h"
#include "testClass.h"
#include "SceneState.h"
#include "Utility.h"
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");  

    const int NUM_OBJECTS = 128;
    float frame = 0;

    Object* objects[NUM_OBJECTS];
    for (int i = 0; i < 128; i++) {
        Filler* filler = new Filler();
        objects[i] = filler;
    }

    sf::Shader testShader;
    testShader.loadFromFile("testFragment.frag", sf::Shader::Fragment);
    sf::Texture texture;
    texture.loadFromFile("letter.png");
    sf::Texture texture2;
    texture2.loadFromFile("table.png");

    sf::Texture testNormal;
    testNormal.loadFromFile("red_bricks_04_nor_gl_1k.jpg");

    sf::Texture testNormal2;
    testNormal2.loadFromFile("metal_plate_nor_gl_1k.jpg");

    Renderer renderer(&window);

    sf::Texture bloobImg;
    bloobImg.loadFromFile("bloob.png");
    Material bloobMat(&testShader, bloobImg, testNormal);
    Sprite playerSprite(bloobMat);
    Player* player = new Player(objects, playerSprite, &renderer);
    player->renderer = &renderer;
    objects[0] = player;

    //sf::Shader shaders[128];

    //sf::Shader testShader2;
    //testShader2.loadFromFile("testFragment.frag", sf::Shader::Fragment);


    Material testMaterial(&testShader,texture,testNormal);
    Material testMaterial2(&testShader,texture2,testNormal2);

    Sprite testSprite(testMaterial);
    testSprite.sprite.setScale(100, 100);
    Sprite testSprite2(testMaterial2);
    testSprite2.sprite.setScale(10, 10);
    testSprite.sprite.setPosition(-400, -1000);
    testSprite2.sprite.setPosition(200, 200);


    for (int i = 2; i < 18; i++) {
        Particle* particle = new Particle(sf::Vector2f(rand()%1000, rand() % 1000));
        particle->renderer = &renderer;
        particle->objects = objects;
        objects[i] = particle;
    }

    //std::cout << getObjectSlot(objects);
    //for (int i = 0; i < 128; i++) {
    //    if (objects[i] == nullptr) {
    //        std::cout << i;
    //    }
    //}

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

        window.clear();
        for (int i = 0; i < NUM_OBJECTS; i++) {
            //std::cout << objects[i] << std::endl;
            if (objects[i] != nullptr) {
                objects[i]->update();
            }
   
        }
        renderer.lights[0] = Light(pos, sf::Vector3f(1.0, 0.8, 0.7), 1000);
        //renderer.debugLightsArray();
        //draw stuff
        renderer.setupFrame(&testShader);
        renderer.draw(testSprite);
        //renderer.draw(testSprite2);
        for (int i = 0; i < NUM_OBJECTS; i++) {
            //std::cout << objects[i] << std::endl;
            if (objects[i] != nullptr) {
                objects[i]->draw();
            }

        }
        window.display();
        frame++;
    }
    return 0;
}