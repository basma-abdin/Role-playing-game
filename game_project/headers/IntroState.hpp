#pragma once

#include "BaseState.hpp"
#include "StateManager.hpp"

class IntroState :public BaseState{
private:

	sf::Text m_text;
	sf::Font m_font;

	sf::Vector2f m_buttonSize;
	sf::Vector2f m_buttonPos;

	sf::RectangleShape m_rect;
	sf::Text m_label;
	sf::Event sfmlEvent;

	sf::Texture background_img;

	void go_to_game();
	void init_buttons(sf::Vector2u windowSize);
	bool check_button_pressed(sf::Vector2i);
public:
	explicit IntroState(StateManager* st);
	~IntroState();


	void on_create()override;
	void on_destroy()override;

	void update()override;
	void draw() override;


};
