#include <SFML/Graphics.hpp>
#include "Object.h"
#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");  

    const int NUM_OBJECTS = 128;
    Object* objects[NUM_OBJECTS];

    Player* player = new Player();
    objects[1] = player;

    sf::Shader testShader;
    testShader.loadFromFile("testFragment.frag", sf::Shader::Fragment);//testShader.loadFromFile("testVertex.vert", "testFragment.frag");


    sf::CircleShape shape(100.f);
    sf::RectangleShape rect(sf::Vector2f(30,30));
    rect.setPosition(30, 30);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        for()
        window.draw(shape, &testShader);
        window.draw(rect);
        window.display();
    }
    return 0;
}