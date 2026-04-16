#include "funciones.h"

Adrian::Adrian(sf::Vector2f posicion)
    : velocidad(150.f), listo(false)
{
   if (!textura.loadFromFile("assets/sprite4-1.png"))
        return; // listo queda en false

    textura.setSmooth(false);
    sprite.setTexture(textura);
    sprite.setScale(1.f, 1.f);
    sprite.setOrigin(textura.getSize().x / 2.f, textura.getSize().y / 2.f);
    sprite.setPosition(posicion);
    listo = true;
}

bool Adrian::estaListo() const { return listo; }

// Movimiento absoluto
void Adrian::setPosicion(sf::Vector2f posicion)
{
    sprite.setPosition(posicion);
}

// Movimiento relativo (llamar cada frame con dt)
void Adrian::mover(sf::Vector2f direccion, float dt)
{
    sprite.move(direccion * velocidad * dt);
}
void Adrian::dibujar(sf::RenderWindow &ventana) const
{
    ventana.draw(sprite);
}
