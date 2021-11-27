#include "Player.h"


void Player::translate(int x, int y)
{
    position = sf::Vector2f(position.x + x, position.y + y);
}

void Player::rotate(float k)
{
}

void Player::scale(float rotation)
{
}

void Player::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        translate(5,0);
        kierunek = Kierunek::right;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        translate(-5,0);
        kierunek = Kierunek::left;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        translate(0,5);
        kierunek = Kierunek::down;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        translate(0,-5);
        kierunek =Kierunek::up;
    }
}

void Player::animate(float dt)
{
    fps++;
    if (fps >= 5) {
        index++;
        fps = 0;
    }
    switch (kierunek)
    {
    case Kierunek::left:
        if (index >= left.size() - 1)
            index = 0;
        txture = sf::Texture();
        txture.loadFromImage(left[index]);
        sprite = sf::Sprite(txture);

        break;
    case Kierunek::right:
        if (index >= right.size() - 1)
            index = 0;
        txture = sf::Texture();
        txture.loadFromImage(right[index]);
        sprite = sf::Sprite(txture);
        break;
    case Kierunek::up:
        if (index >= front.size() - 1)
            index = 0;
        txture = sf::Texture();
        txture.loadFromImage(front[index]);
        sprite = sf::Sprite(txture);
        break;
    case Kierunek::down:
        if (index >= back.size() - 1)
            index = 0;
        txture = sf::Texture();
        txture.loadFromImage(back[index]);
        sprite = sf::Sprite(txture);
        break;
    default:
        break;
    }
}

void Player::draw(sf::RenderWindow* target)
{
    sprite.setPosition(position);
    target->draw(sprite);
}
