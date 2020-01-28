/*
 * Win.cpp
 *
 *  Created on: Jan 5, 2020
 *      Author: basma
 */

#include "../headers/WinState.hpp"
using namespace std;

WinState::WinState(StateManager* st):BaseState(st) {

}

WinState::~WinState() {
	// TODO Auto-generated destructor stub
}

void WinState::draw(){
	m_stateMgr->access_window().clear();
	m_stateMgr->access_window().draw(m_text);
	m_stateMgr->access_window().draw(trophy_sprite);
	m_stateMgr->access_window().display();
}


void WinState::on_create(){

	sf::Vector2u windowSize = m_stateMgr->get_window()->getSize();

	m_font.loadFromFile("media/Pacifico.ttf");
	m_text.setFont(m_font);
	m_text.setOutlineColor(sf::Color::Red);
	m_text.setString({ "WINNER"});
	sf::FloatRect textRect = m_text.getLocalBounds();
	m_text.setOrigin(textRect.left + textRect.width / 2.0f,textRect.top + textRect.height / 2.0f);
	m_text.setPosition(windowSize.x / 2.0f, windowSize.y / 4.0f);

	trophy.loadFromFile("media/trophy.png");
	trophy_sprite.setTexture(trophy);
	trophy_sprite.setPosition(( windowSize.x -100) / 2, (windowSize.y - 50)  / 2);
}

void WinState::on_destroy()
{
}

void WinState::update()
{
	m_text.setString({ "WINNER : " + m_stateMgr->get_winner()});
	sf::RenderWindow* window = m_stateMgr->get_window();
		while (window->pollEvent(this->sfmlEvent)) {
				switch (this->sfmlEvent.type){
				case sf::Event::Closed:
								window->close();
								break;
					case sf::Event::KeyPressed:
									if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
										window->close();
							break;
					default:
						break;
				}
				}
}


