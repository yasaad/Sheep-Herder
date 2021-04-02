#pragma once

#include "sheep.hpp"
#include <iostream>
/*
	Class for sheep herding
*/
class Simulation
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::VideoMode videoMode;
	sf::Event event;
	sf::RectangleShape shape;

	//Mouse Position
	sf::Vector2i mousePosition;

	//Game objects
	std::list<Sheep*> herd;

	//Private Functions
	void initVariables();
	void initWindow();
	void initHerd(sf::Texture* sheepTexture);

public:
	//Constructors / Distructors
	Simulation(sf::Texture* sheepTexture);
	virtual ~Simulation();

	//Accessors
	bool running() const;

	//Functions
	void pollEvents();
	void updateMousePosition();
	void update();
	void render();
};