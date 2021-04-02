#include "Headers/simulation.hpp"
#include "Platform/Platform.hpp"
int main()
{
	std::srand(std::time(nullptr));
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	Simulation simulation;
	// sf::RenderWindow window;
	// // in Windows at least, this must be called before creating the window
	// float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// std::cout << screenScalingFactor << std::endl;
	// // Use the screenScalingFactor
	// window.create(sf::VideoMode(1600.0f * screenScalingFactor, 1600.0f * screenScalingFactor), "Sheep Herder");
	// platform.setIcon(window.getSystemHandle());

	// sf::CircleShape shape(window.getSize().x / 2);
	// shape.setFillColor(sf::Color::White);

	// sf::Texture shapeTexture;
	// shapeTexture.loadFromFile("content/sfml.png");
	// shape.setTexture(&shapeTexture);

	while (simulation.running())
	{
		//Update
		simulation.update();

		//Render
		simulation.render();
	}

	return 0;
}
