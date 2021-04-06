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
	for (int i = 0; i < herdSize; i++)
	{
		Sheep* temp = new Sheep(sf::Vector2f(
			std::rand() % this->window->getSize().x,
			std::rand() % this->window->getSize().y));
		herd.push_back(temp);
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
	for (Sheep* sheep : herd)
	{
		sheep->update(this->window);
	}
}

void print(sf::Vector2f point)
{
	std::cout << point.x << " " << point.y << ", ";
}

void Simulation::render(sf::Texture* sheepTexture)
{
	this->window->clear(sf::Color(80, 180, 130, 255));
	//Draw game objects
	// sf::Vector2f point0 = sf::Vector2f(1059.09f, 571.493f);
	// sf::Vector2f point1 = sf::Vector2f(1119.3f, 549.795f);
	// sf::Vector2f point2 = sf::Vector2f(1128.8, 576.137f);
	// sf::Vector2f point3 = sf::Vector2f(1068.59f, 597.834f);
	sf::VertexArray sheepArray(sf::Triangles, 6 * this->herdSize);
	int currentSheep = 0;

	for (Sheep* sheep : herd)
	{
		sf::Transform matrix = sheep->shape.getTransform();
		sf::Vertex* bottom = &sheepArray[currentSheep * 3];
		sf::Vertex* top = &sheepArray[(currentSheep + 1) * 3];
		std::cout << std::endl;
		bottom[0].position = matrix.transformPoint(sheep->shape.getPoint(0));
		bottom[1].position = matrix.transformPoint(sheep->shape.getPoint(3));
		bottom[2].position = matrix.transformPoint(sheep->shape.getPoint(2));
		bottom[0].texCoords = sf::Vector2f(0.0f, 0.0f);
		bottom[1].texCoords = sf::Vector2f(0.0f, 14.0f);
		bottom[2].texCoords = sf::Vector2f(32.0f, 14.0f);

		top[0].position = matrix.transformPoint(sheep->shape.getPoint(0));
		top[1].position = matrix.transformPoint(sheep->shape.getPoint(1));
		top[2].position = matrix.transformPoint(sheep->shape.getPoint(2));
		top[0].texCoords = sf::Vector2f(0.0f, 0.0f);
		top[1].texCoords = sf::Vector2f(32.0f, 0.0f);
		top[2].texCoords = sf::Vector2f(32.0f, 14.0f);

		// top[0].texCoords = sf::Vector2f(0.0f, 0.0f);
		// top[1].texCoords = sf::Vector2f(32.0f, 0.0f);
		// top[2].texCoords = sf::Vector2f(32.0f, 14.0f);
		currentSheep += 2;
	}

	// for (int i = 0; i < numberOfShapes; i++)
	// {
	// 	for (int j = 0; j < 2; j++)
	// 	{

	// 		sf::Vertex* triangleStrip = &sheepArray[j + i * numberOfShapes];
	// 		triangleStrip[0].position = sf::Vector2f(0.0f, 0.0f);
	// 		triangleStrip[1].position = sf::Vector2f(0.0f + (j * 64), 28.0f);
	// 		triangleStrip[2].position = sf::Vector2f(64.0f - (j * 64), 28.0f);

	// 		triangleStrip[0].color = sf::Color::Red;
	// 		triangleStrip[1].color = sf::Color::Blue;
	// 		triangleStrip[2].color = sf::Color::Green;
	// 	}
	// }
	// define the position of the triangle's points

	// define the color of the triangle's points
	// for (Sheep* sheep : herd)
	// {
	// 	sf::VertexArray
	// 	sheep->render(this->window);
	// }
	window->draw(sheepArray, sheepTexture);
	this->window->display();
}