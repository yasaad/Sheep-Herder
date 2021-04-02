#pragma once

#define _USE_MATH_DEFINES

#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
class Sheep
{
private:
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	sf::Color color;
	// float maxForce = 0.2f;
	float magnitude;

	void initVariables(sf::Vector2f position, sf::Texture* texture);

public:
	sf::RectangleShape shape = sf::RectangleShape(sf::Vector2f(20.0f, 12.0f));
	Sheep(sf::Vector2f position, sf::Texture* texture);
	virtual ~Sheep();

	void update(sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};