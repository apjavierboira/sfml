#include "funciones.h"
#include <cmath>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Juego"); // Crea una ventana window


    // Objeto javier
    Javier javier("assets/javier.png", {40.f, 30.f}, 0.1f);
    Javier javier2("assets/javier.png", {200.f, 30.f}, 0.1f);
    Javier javier3("assets/javier.png", {40.f, 200.f}, 0.1f);
    Javier javier4("assets/javier.png", {100.f, 300.f}, 0.1f);

    // objeto
    Raul raul({20.f, 20.f});
    Beltran beltran({60.f, 60.f});

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

        sf::Vector2f dir2(0.f, 0.f);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            dir2.x -= 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            dir2.x += 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            dir2.y -= 1.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            dir2.y += 1.f;

        // movimiento circular
        sf::Vector2f dirb = beltran.getPosicion();
        dirb.x = 120.f - dirb.x;
        dirb.y = 120.f - dirb.y;
        float temp = dirb.x * (-1);
        dirb.x = dirb.y;
        dirb.y = temp;
        temp = std::sqrt(dirb.x * dirb.x + dirb.y * dirb.y);
        dirb.x /= temp;
        dirb.y /= temp;
        dirb.x *= 2;
        dirb.y *= 2;

        beltran.mover(dirb, dt);


        // Objeto Javier
        // Movimientfloat modulo(sf::Vector2f vector){
    return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

sf::Vector2f rotarVector(sf::Vector2f vector, float grados){
    float radianes = grados * 3.14159265f / 180.f;
    float cosA = std::cos(radianes);
    float sinA = std::sin(radianes);
    return sf::Vector2f(vector.x * cosA - vector.y * sinA, vector.x * sinA + vector.y * cosA);
}o con WASD
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
        raul.dibujar(window);
        // Objeto javier
        javier2.dibujar(window);
        javier3.dibujar(window);
        javier4.dibujar(window);
        window.display();
    }
}