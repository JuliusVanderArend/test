#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Player.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Renderer.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");  

    const int NUM_OBJECTS = 128;
    Object* objects[NUM_OBJECTS];

    Player* player = new Player();
    objects[1] = player;

    sf::Shader testShader;
    testShader.loadFromFile("testFragment.frag", sf::Shader::Fragment);
    sf::Shader testShader2;
    testShader2.loadFromFile("testFragment.frag", sf::Shader::Fragment);

    sf::Texture texture;
    texture.loadFromFile("letter.png");
    sf::Texture texture2;
    texture2.loadFromFile("table.png");

    sf::Texture testNormal;
    testNormal.loadFromFile("red_bricks_04_nor_gl_1k.jpg");

    sf::Texture testNormal2;
    testNormal2.loadFromFile("rust_coarse_01_nor_gl_1k.jpg");

    //sf::Sprite sprite;
    //sprite.setTexture(texture);
    Renderer renderer(&window);

    Material testMaterial(&testShader);
    Material testMaterial2(&testShader2);

    Sprite testSprite(texture,testNormal, testMaterial);
    Sprite testSprite2(texture2, testNormal, testMaterial);

    testSprite2.sprite.setPosition(50, 50);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        renderer.draw(testSprite);
        renderer.draw(testSprite2);
        window.display();
    }
    return 0;
}