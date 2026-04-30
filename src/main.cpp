#include "funciones.h"
#include <cmath>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Juego"); // Crea una ventana window

    //INCIALIZACIÓN DE OBJETOS
    Javier javier("assets/javier.png", {40.f, 30.f}, 0.1f);
    Raul raul({20.f, 20.f});
    Beltran beltran({60.f, 60.f});
    Fran fran({30.f, 30.f});
    Uriel uriel({120.f, 120.f});
    Adrian adrian({140.f, 140.f});

    if (!javier.estaListo())
        return -1;

    sf::Clock clock; // Inicializamos clock

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();

        sf::Event event; // Objeto event
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
        

        // Player mover
        // Movimiento con WASD
        sf::Vector2f dir(0.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            dir.y -= 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            dir.y += 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            dir.x -= 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            dir.x += 1.f;
        raul.mover(dir, dt);

        window.clear();
        
        beltran.dibujar(window);
        javier.dibujar(window);
        fran.dibujar(window);
        raul.dibujar(window);
        uriel.dibujar(window);
        adrian.dibujar(window);
        
        window.display();
    }
}