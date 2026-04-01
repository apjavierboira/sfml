#include "funciones.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Juego"); // Crea una ventana window

    sf::RectangleShape player({50.f, 50.f}); // Crea objeto player
    sf::RectangleShape enemy({40.f, 40.f});  // Crea objeto enemy

    player.setFillColor(sf::Color::Green);
    player.setPosition(375.f, 500.f);

    enemy.setFillColor(sf::Color::Red);
    enemy.setPosition(200.f, 0.f);

    // Objeto javier
    Javier javier("assets/javier.png", {40.f, 30.f}, 0.1f);
    Javier javier2("assets/javier.png", {200.f, 30.f}, 0.1f);
    Javier javier3("assets/javier.png", {40.f, 200.f}, 0.1f);
    Javier javier4("assets/javier.png", {100.f, 300.f}, 0.1f);

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player.move(-speed * dt, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            player.move(speed * dt, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            player.move(0, -speed * dt);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            player.move(0, speed * dt);

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
        javier.mover(dir, dt);

        window.clear();
        window.draw(player);
        window.draw(enemy);
        javier.dibujar(window); // Objeto javier
        javier2.dibujar(window);
        javier3.dibujar(window);
        javier4.dibujar(window);
        window.display();
    }
}