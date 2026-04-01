#include "funciones.h"

Javier::Javier(const std::string &rutaPNG, sf::Vector2f posicion, float escala)
    : velocidad(150.f), listo(false)
{
    if (!textura.loadFromFile(rutaPNG))
        return; // listo queda en false

    textura.setSmooth(false);
    sprite.setTexture(textura);
    sprite.setScale(escala, escala);
    sprite.setOrigin(textura.getSize().x / 2.f, textura.getSize().y / 2.f);
    sprite.setPosition(posicion);
    listo = true;
}

bool Javier::estaListo() const { return listo; }

// Movimiento absoluto
void Javier::setPosicion(sf::Vector2f posicion)
{
    sprite.setPosition(posicion);
}

// Movimiento relativo (llamar cada frame con dt)
void Javier::mover(sf::Vector2f direccion, float dt)
{
    sprite.move(direccion * velocidad * dt);
}

void Javier::setVelocidad(float v) { velocidad = v; }

void Javier::setEscala(float escala)
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

sf::Vector2f Javier::getPosicion() const
{
    return sprite.getPosition();
}

void Javier::dibujar(sf::RenderWindow &ventana) const
{
    ventana.draw(sprite);
}
