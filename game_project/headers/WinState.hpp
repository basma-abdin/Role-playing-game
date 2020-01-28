/*
 * Win.hpp
 *
 *  Created on: Jan 5, 2020
 *      Author: basma
 */

#ifndef WINSTATE_HPP_
#define WINSTATE_HPP_


#include "../headers/BaseState.hpp"
#include "../headers/StateManager.hpp"

class WinState : public BaseState {
private:
	sf::Text m_text;
	sf::Font m_font;

	sf::Texture trophy;
	sf::Sprite trophy_sprite;
	sf::Event sfmlEvent;


	void update_winner();
public:
	WinState(StateManager* st);
	~WinState();

	void on_create()override;
	void on_destroy()override;

	void update()override;
	void draw() override;
};

#endif /* WINSTATE_HPP_ */
