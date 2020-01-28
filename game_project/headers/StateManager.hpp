/*
 * StateManager.hpp
 *
 *  Created on: Dec 26, 2019
 *      Author: basma
 */

#ifndef STATEMANAGER_HPP_
#define STATEMANAGER_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <unordered_map>
#include <vector>
#include <iostream>
#include <functional>

#include "../headers/BaseState.hpp"
#include "StateType.hpp"

class StateManager {
private:
	bool re_draw = false;

	sf::RenderWindow* w_shared;
	std::string winner = "";

	std::vector<std::pair<StateType,BaseState*>> m_states;
	std::vector<StateType> m_toRemove;

	BaseState * currentState;

	std::unordered_map<StateType, std::function<BaseState*(void)>> m_stateFactory;

	void create_state(const StateType& l_type);
	void remove_state(const StateType& l_type);

	template<class T>
		void register_state(const StateType &stateType) {
			m_stateFactory[stateType] = [this]() -> BaseState*
			{
				return new T(this);
			};
		}



public:
	explicit StateManager();
	~StateManager();
	void update();
	void draw();
	void process_requests();
	sf::RenderWindow* get_window();
	sf::RenderWindow& access_window();
	void set_window(sf::RenderWindow* l_shared);
	bool has_state(const StateType& l_type);
	void switch_to(const StateType& l_type, std::string winner = "");
	void remove(const StateType& l_type);

	bool endGame = false;
	std::string get_winner();
};

#endif /* STATEMANAGER_HPP_ */
