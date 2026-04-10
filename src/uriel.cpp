#include "funciones.h"

  Uriel::Uriel(sf::Vector2f posicion, float escala)
    : velocidad(150.f), listo(false)
{
    if (!textura.loadFromFile(rutaPNG))
        return; // listo queda en false

    textura.setSmooth(false);
    sprite.setTexture(sprite3.png);
    sprite.setScale(1.f,1f);
    sprite.setOrigin(textura.getSize().x / 2.f, textura.getSize().y / 2.f);
    sprite.setPosition(posicion);
    listo = true;
}
bool Uriel::estaListo() const { return listo; }

// Movimiento absoluto
void Uriel::setPosicion(sf::Vector2f posicion)
{
    sprite.setPosition(posicion);
}

// Movimiento relativo (llamar cada frame con dt)
void Uriel::mover(sf::Vector2f direccion, float dt)
{
    sprite.move(direccion * velocidad * dt);
}

void Uriel::setVelocidad(float v) { velocidad = v; }

void Uriel::setEscala(float escala)
{
    sprite.setScale(escala, escala);
}

void Javier::setRotacion(float angulo)
{
    sprite.setRotation(angulo);
}

void Javier::rotar(float grados)
{
    sprite.rotate(grados);
}

