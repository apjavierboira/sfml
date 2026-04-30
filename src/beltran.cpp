#include "funciones.h"

Beltran::Beltran(sf::Vector2f posicion)
    : velocidad(150.f), listo(false)
{
    if (!textura.loadFromFile("assets/sprite2-1.png"))
        return; // listo queda en false

    textura.setSmooth(false);
    sprite.setTexture(textura);
    sprite.setScale(1.f, 1.f);
    sprite.setOrigin(textura.getSize().x / 2.f, textura.getSize().y / 2.f);
    sprite.setPosition(posicion);
    listo = true;
}

bool Beltran::estaListo() const { return listo; }

// Movimiento absoluto
void Beltran::setPosicion(sf::Vector2f posicion)
{
    sprite.setPosition(posicion);
}

// Movimiento relativo (llamar cada frame con dt)
void Beltran::mover(sf::Vector2f direccion, float dt)
{
    sprite.move(direccion * velocidad * dt);
}

void Beltran::dibujar(sf::RenderWindow &ventana) const
{
    ventana.draw(sprite);
}

void Beltran::actualizar(sf::Vector2f destino, float dt){
    sf::Vector2f miposicion, direccion;
    miposicion = sprite.getPosition();
    
    direccion.x = (destino.x - miposicion.x); direccion.y = (destino.y - miposicion.y);
    direccion.x /= modulo(direccion); direccion.y /= modulo(direccion);

    float velocidad = 1.5;

    sprite.move(direccion*velocidad*dt);
}
