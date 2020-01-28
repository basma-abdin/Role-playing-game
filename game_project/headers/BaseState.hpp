/*
 * BaseState.hpp
 *
 *  Created on: Dec 26, 2019
 *      Author: basma
 */

#ifndef BASESTATE_HPP_
#define BASESTATE_HPP_
class StateManager;
class BaseState {

protected:
	StateManager* m_stateMgr;
	bool m_transparent;
	bool m_transcendent;

public:
	 BaseState(StateManager* const l_stateManager) :m_stateMgr(l_stateManager),m_transparent(false), m_transcendent(false){}
	virtual ~BaseState(){}

	virtual void on_create() = 0;
	virtual void on_destroy() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

	void set_transparent(const bool& l_transparent){
		m_transparent = l_transparent;
	}

	bool is_transparent()const{
		return m_transparent;
	}

	void set_transcendent(const bool& l_transcendence){
		m_transcendent = l_transcendence;
	}

	bool is_transcendent()const{
		return m_transcendent;
	}

	StateManager* GetStateManager(){
		return m_stateMgr;
	}

	friend class StateManager;
};

#endif /* BASESTATE_HPP_ */
