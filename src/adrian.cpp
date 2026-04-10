#include "funciones.h"
    Adrian::Adrian(sf::Vector2f posicion,)
    : velocidad(150.f), listo(false)

    if (!textura.loadFromFile("sprite5.png"))
        return; // listo queda en false

    textura.setSmooth(false);
    sprite.setTexture(textura);
    sprite.setScale(1.f, 1.f);
    sprite.setOrigin(textura.getSize().x / 2.f, textura.getSize().x;
    sprite.setPosition(posición);
    listo=false;

    bool Adrian::estaListo() const { return listo;}
    //Movimiento absoluto
    void Adrian::setPosicion(sf::Vector2f posicion)
    {
        sprite.setPosicion(posicion);
    }

    //Movimiento relativo (llamar cada frame con dt)
    void Adrian::mover(sf::Vector2f direccion, float dt)
    {
        sprite.move(direccion * velocidad * dt);
    }