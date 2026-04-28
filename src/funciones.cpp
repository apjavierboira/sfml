#include "funciones.h"

float modulo(sf::Vector2f vector){
    return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

sf::Vector2f rotarVector(sf::Vector2f vector, float grados){
    float radianes = grados * 3.14159265f / 180.f;
    float cosA = std::cos(radianes);
    float sinA = std::sin(radianes);
    return sf::Vector2f(vector.x * cosA - vector.y * sinA, vector.x * sinA + vector.y * cosA);
}

void mEnemigo(sf::RectangleShape &enemigo, float dt)
{
    enemigo.move(10 * dt, 0.f);
}
