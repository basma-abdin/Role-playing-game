#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Drawer;
class Menu {
private:
	int gap;
	sf::Font font;

	sf::RectangleShape pause_button;
	sf::Text button_label;

	sf::RectangleShape timer;
	sf::Text timer_label;

	sf::RectangleShape active_button;
	sf::Text active_label;


	sf::RectangleShape player1[4];
	sf::Text player1_labels[4];

	sf::RectangleShape player2[4];
	sf::Text player2_labels[4];

	void set_active_objetR(int);
public:
	Menu();
	~Menu();

	void init_pause_button();
	void init_active_button();
	void init_timer_button();
	void init_player1_buttons();
	void init_player2_buttons();

	void set_active_player(std::string s);
	void set_timer(int s);
	void set_labels_player1(std::vector<int>);
	void set_labels_player2(std::vector<int>);

	friend class Drawer;
};
