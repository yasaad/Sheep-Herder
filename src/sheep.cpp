#include "Headers/sheep.hpp"

//private
void Sheep::initVariables(sf::Vector2f position)
{
	//Number between 3 and 7
	this->magnitude = std::rand() % 4 + 3;
	this->velocity = sf::Vector2f((float)std::rand() / RAND_MAX * 2.0f - 1, (float)std::rand() / RAND_MAX * 2.0f - 1);
	this->shape.setOrigin(this->shape.getSize() / 2.0f);
	this->shape.setPosition(position);
}

//public
Sheep::Sheep(sf::Vector2f position)
{
	this->initVariables(position);
}

Sheep::~Sheep()
{
	std::cout << "HERE" << std::endl;
}

void Sheep::update(sf::RenderTarget* target)
{
	this->shape.setRotation(-std::atan2f(this->velocity.x, this->velocity.y) * 180.0f / M_PI + 90.0f);
	sf::Vector2f currentPosition = this->shape.getPosition();
	this->shape.setPosition(
		std::fmod((currentPosition.x + this->velocity.x), (float)target->getSize().x),
		std::fmod((currentPosition.y + this->velocity.y), (float)target->getSize().y));
}

void Sheep::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}