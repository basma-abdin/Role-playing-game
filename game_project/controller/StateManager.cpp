/*
 * StateManager.cpp
 *
 *  Created on: Dec 26, 2019
 *      Author: basma
 */

#include "../headers/StateManager.hpp"

#include "../headers/GameManagerState.hpp"
#include "../headers/IntroState.hpp"
#include "../headers/PauseState.hpp"
#include "../headers/WinState.hpp"

using namespace std;

StateManager::StateManager(){

	register_state<IntroState>(StateType::Introduction);
	register_state<GameManagerState>(StateType::GOGame);
	register_state<PauseState>(StateType::Pause);
	register_state<WinState>(StateType::Winner);
}

StateManager::~StateManager() {
	for(auto &it : m_states){
		it.second->on_destroy();
		delete it.second;
	}
	delete w_shared;
	delete currentState;
}

void StateManager::set_window(sf::RenderWindow* l_shared){
	w_shared= l_shared;
}

void StateManager::draw(){
  if (m_states.empty()){ return; }
	m_states.back().second->draw();
	re_draw = false;
}

void StateManager::update(){
	if (m_states.empty()){ return; }
		m_states.back().second->update();
}

sf::RenderWindow* StateManager::get_window(){
	return w_shared;
}

sf::RenderWindow& StateManager::access_window(){
	return *w_shared;
}

bool StateManager::has_state(const StateType& l_type){

	for (auto itr = m_states.begin(); itr != m_states.end(); ++itr) {
		if (itr->first == l_type){
			auto removed = std::find(m_toRemove.begin(), m_toRemove.end(), l_type);
			if (removed == m_toRemove.end()) { return true; }
			return false;
			}
		}
		return false;
}

void StateManager::remove(const StateType& l_type){
	m_toRemove.push_back(l_type);
}

void StateManager::process_requests(){
	while (m_toRemove.begin() != m_toRemove.end()){
		remove_state(*m_toRemove.begin());
		m_toRemove.erase(m_toRemove.begin());
	}
}

void StateManager::remove_state(const StateType& l_type){
	for (auto itr = m_states.begin();itr != m_states.end(); ++itr) {
		if (itr->first == l_type){
			itr->second->on_destroy();
			delete itr->second;
			m_states.erase(itr);
			return;
		}
	}
}

void StateManager::switch_to(const StateType& l_type, std::string winner ){
	if(l_type == StateType::Winner & winner != "") {
		this->winner = winner;
	}
	re_draw = true;

	for (auto itr = m_states.begin(); itr != m_states.end(); ++itr) {
		if (itr->first == l_type){
			StateType tmp_type = itr->first;
			BaseState* tmp_state = itr->second;
			m_states.erase(itr);
			m_states.emplace_back(tmp_type, tmp_state);
			return;
		}
	}
	// State with l_type wasn't found.
		create_state(l_type);
		currentState = m_states.back().second;
}

void StateManager::create_state(const StateType& l_type){
	auto newState = m_stateFactory.find(l_type);
	if (newState == m_stateFactory.end()){ return; /* state not found!*/ }
	BaseState* state = newState->second();
	m_states.emplace_back(l_type, state);
	state->on_create();
}

std::string StateManager::get_winner(){
	return this->winner;
}
