#pragma once
#include <SFML/Graphics.hpp>
#include "Hitbox.hpp"

class Entity : public sf::Sprite{
public:
	sf::Vector2f velocity;
	sf:: Vector2f size;
	Hitbox hitbox;
};