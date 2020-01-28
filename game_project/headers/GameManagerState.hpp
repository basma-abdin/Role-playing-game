/*
 * GameManager.hpp
 *
 *  Created on: Oct 25, 2019
 *      Author: basma
 */

#ifndef GAMEMANAGERSTATE_HPP_
#define GAMEMANAGERSTATE_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <math.h>
#include <typeinfo>
#include "Drawer.hpp"
#include "BaseState.hpp"
#include "StateManager.hpp"

class Carte;
class GameManagerState : public BaseState {
private:
	Carte* carte;
	Drawer * drawer;

	std::map <Position, Element> * current_map;
	GuerrierPrincipal *player1;
	GuerrierPrincipal *player2;
	GuerrierPrincipal *active_player;
	GuerrierPrincipal *enemy_player;

//	window
	sf::RenderWindow* window;
	sf::Event sfmlEvent;
	sf::Clock clock;
	sf::Clock clockWorker;

	sf::RectangleShape pause_button;


	bool re_draw;
	bool endGame;
	bool pick_up;
	int timerWorker;

	int workers_number;
	int objetR_number;

	void initVariables();
	void switching_role();
	void initWindow();
	void initFonts();
	void initText();
	void renderMap(sf::RenderTarget&);
	void go_to_winner_state();

public:

	GameManagerState(StateManager * st);
	virtual ~GameManagerState();

	const bool& getEndGame() const;
	const bool running() const;
	void poll_events();

	void motion();
	void updatePlayer();
	void updateCollision();
	void updateGui();
	void update()override;
	void updateWorker();
	void update_objetR();

	// Balles controlling
	void check_balle_collision();
	bool check_balle_hit_player(Position, Balle&);
	void destroying_balles();

	void renderGui(sf::RenderTarget* target);
	void draw()override;

	bool is_obstacle(Direction,Guerrier* f);
	bool is_objetR(Position );

	void pick_it_up(Position g);
	void init_workers();
	void generate_objetsR(int max =10);
	bool out_of_borders(Position);


	void on_create()override;
	void on_destroy()override;

	void life_player_cntrl();

	bool exist_in_map(const Position & p);

	bool check_button_pressed();
	void pause_game();
};

#endif /* GAMEMANAGERSTATE_HPP_ */
