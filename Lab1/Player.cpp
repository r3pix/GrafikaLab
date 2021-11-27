#include "Player.h"
void Player::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        translate(5,0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        translate(-5, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        translate(0, 5);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        translate(0, -5);
    }
}