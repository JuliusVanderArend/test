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
    testShader.loadFromFile("testFragment.frag", sf::Shader::Fragment);//testShader.loadFromFile("testVertex.vert", "testFragment.frag");

    sf::Texture texture;
    texture.loadFromFile("letter.png");

    //sf::Sprite sprite;
    //sprite.setTexture(texture);
    Renderer renderer(&window);

    Material testMaterial(&testShader);

    Sprite testSprite(texture,texture,testMaterial);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        /*window.draw(sprite, &testShader);*/
        renderer.draw(testSprite);

        window.display();
    }
    return 0;
}