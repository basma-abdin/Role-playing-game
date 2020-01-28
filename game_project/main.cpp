
#include "headers/GameManagerState.hpp"
int main()
{
		srand(static_cast<unsigned>(time(NULL)));


		//window init
		sf::RenderWindow* window;
		sf::VideoMode videoMode;
		videoMode = sf::VideoMode(sf::VideoMode::getDesktopMode().width , sf::VideoMode::getDesktopMode().height);
		window = new sf::RenderWindow(videoMode, "Jeu de role", sf::Style::Close | sf::Style::Titlebar);
		window->setFramerateLimit(60);
		///

		StateManager state_manager;
		state_manager.set_window(window);
		state_manager.switch_to(StateType::Introduction);
		//Game loop
		while (window->isOpen() && !state_manager.endGame)
		{
			state_manager.update();
			state_manager.draw();
		}
		return 0;
}
