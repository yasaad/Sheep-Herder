#include "Headers/simulation.hpp"
#include "Platform/Platform.hpp"
int main()
{
	std::srand(std::time(nullptr));
	util::Platform platform;

#if defined(_DEBUG)
	std::cout << "Hello World!" << std::endl;
#endif

	sf::Texture sheepTexture;
	if (!sheepTexture.loadFromFile("content/Sheep_outline.png"))
	{
		std::cout << "Faild to load sheep texture!" << std::endl;
		return EXIT_FAILURE;
	}
	// sf::Clock clock;
	Simulation simulation;

	// sf::RenderWindow window;
	// // in Windows at least, this must be called before creating the window
	// float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// std::cout << screenScalingFactor << std::endl;
	// // Use the screenScalingFactor
	// window.create(sf::VideoMode(1600.0f * screenScalingFactor, 1600.0f * screenScalingFactor), "Sheep Herder");
	// platform.setIcon(window.getSystemHandle());

	// sf::RectangleShape shape(sf::Vector2f(100.0f, 100.0f));
	// shape.setFillColor(sf::Color::White);

	while (simulation.running())
	{
		// sf::Time time = clock.getElapsedTime();
		// std::cout << 1.0f / time.asSeconds() << std::endl;
		// clock.restart().asSeconds();
		//Update
		simulation.update();

		//Render
		simulation.render(&sheepTexture);
	}

	return 0;
}
