#pragma once
#include <SFML/Graphics.hpp>
#include <stdexcept>
#include <string>

class Javier
{
public:
    Javier(const std::string &rutaPNG, sf::Vector2f posicion, float escala = 1.f);
    bool estaListo() const;
    void setPosicion(sf::Vector2f posicion);
    void mover(sf::Vector2f direccion, float dt);
    void setVelocidad(float v);
    void setEscala(float escala);
    void setRotacion(float angulo);
    void rotar(float grados);
    sf::Vector2f getPosicion() const;
    void dibujar(sf::RenderWindow &ventana) const;

private:
    sf::Texture textura;
    sf::Sprite sprite;
    float velocidad;
    bool listo;
};

void mEnemigo(sf::RectangleShape &enemigo, float dt);