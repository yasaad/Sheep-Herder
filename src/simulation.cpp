#include "Headers/simulation.hpp"
//Private Functions
void Simulation::initVariables()
{
	this->window = nullptr;
}
void Simulation::initWindow()
{
	this->videoMode.height = 2000;
	this->videoMode.width = 2000;

	this->window = new sf::RenderWindow(this->videoMode, "Sheep Herder", sf::Style::Titlebar | sf::Style::Close /*|
		sf::Style::Resize*/
	);

	this->window->setFramerateLimit(60);
}

void Simulation::initHerd()
{
	std::cout << (int)sizeof(this->sheep) / sizeof(*this->sheep) << std::endl;
	for (int i = 0; i < (int)(sizeof(this->sheep) / sizeof(*this->sheep)); i++)
	{
		this->sheep[i] = new Sheep(sf::Vector2f(
			std::rand() % this->window->getSize().x,
			std::rand() % this->window->getSize().y));
	}
}

//Constructors / Destructors
Simulation::Simulation()
{
	this->initVariables();
	this->initWindow();
	this->initHerd();
}

Simulation::~Simulation()
{
	delete this->window;
}

//Accessors
bool Simulation::running() const
{
	return this->window->isOpen();
}

//Functions
void Simulation::pollEvents()
{
	while (this->window->pollEvent(this->event))
	{
		switch (this->event.type)
		{
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::KeyPressed:
				if (this->event.key.code == sf::Keyboard::Escape)
					this->window->close();
			default:
				break;
		}
	}
}

void Simulation::updateMousePosition()
{
	/*
	Updates the mouse position:
	- Mouse position relative to window (Vector2i)
	*/

	this->mousePosition = sf::Mouse::getPosition(*this->window);
	// std::cout << this->mousePosition.x << " : " << this->mousePosition.y << std::endl;
}

void Simulation::update()
{
	this->pollEvents();
	this->updateMousePosition();
	for (int i = 0; i < (int)(sizeof(this->sheep) / sizeof(*this->sheep)); i++)
	{
		this->sheep[i]->update(this->window);
	}
}

void Simulation::render()
{
	this->window->clear(sf::Color(80, 180, 130, 255));
	//Draw game objects
	for (int i = 0; i < (int)(sizeof(this->sheep) / sizeof(*this->sheep)); i++)
	{
		this->sheep[i]->render(this->window);
	}

	this->window->display();
}