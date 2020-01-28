#pragma once

#include "../headers/BaseState.hpp"
#include "../headers/StateManager.hpp"
class PauseState : public BaseState{
private:
	sf::RectangleShape resume_button;
	sf::Text resume_label;
	sf::Event sfmlEvent;
	sf::Font font;

	sf::Vector2f m_buttonSize;
	sf::Vector2f m_buttonPos;

	sf::Texture background_img;

	void resume_game();
	void init_button(sf::Vector2u windowSize);
	bool check_button_pressed(sf::Vector2i);

public:
	PauseState(StateManager* st);
	 ~PauseState();

		void on_create()override;
		void on_destroy()override;

		void update()override;
		void draw() override;

};
