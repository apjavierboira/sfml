#include "funciones.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Juego"); // Crea una ventana window

    sf::RectangleShape enemy({40.f, 40.f}); // Crea objeto enemy

    enemy.setFillColor(sf::Color::Red);
    enemy.setPosition(200.f, 0.f);

    // Objeto javier
    Javier javier("assets/javier.png", {40.f, 30.f}, 0.1f);
    Javier javier2("assets/javier.png", {200.f, 30.f}, 0.1f);
    Javier javier3("assets/javier.png", {40.f, 200.f}, 0.1f);
    Javier javier4("assets/javier.png", {100.f, 300.f}, 0.1f);

    // objeto
    Raul raul({20.f, 20.f});
    Beltran beltran({20.f, 20.f});

    if (!javier.estaListo())
        return -1;

    float speed = 400.f;

    sf::Clock clock; // Inicializamos clock

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();

        sf::Event event; // Objeto event
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        sf::Vector2f dir2(0.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            dir2.x -= 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            dir2.x += 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            dir2.y -= 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            dir2.y += 1.f;

        beltran.mover(dir2, dt);

        mEnemigo(enemy, dt);

        // Objeto Javier
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
        window.draw(enemy);
        javier.dibujar(window);
        raul.dibujar(window);
        // Objeto javier
        javier2.dibujar(window);
        javier3.dibujar(window);
        javier4.dibujar(window);
        window.display();
    }
}