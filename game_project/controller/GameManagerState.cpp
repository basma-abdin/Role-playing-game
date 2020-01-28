
#include "../headers/GameManagerState.hpp"

#include "../headers/Carte.hpp"

void GameManagerState::initVariables()
{
	this->carte = new Carte("./map.txt");
	this->drawer = new Drawer();

	this->endGame = false;
	this->re_draw = true;
	this->pick_up = false;
	this->workers_number = 5;
	this->objetR_number = 0;

	this->player1 = carte->getGuerrier1();
	this->player2 = carte->getGuerrier2();

	pause_button.setPosition(sf::Vector2f (w -60, 30));
	pause_button.setSize(sf::Vector2f(110.0f,32.0f));

	generate_objetsR(15);
	init_workers();

	this->active_player = player1;
	this->enemy_player = player2;
}

void GameManagerState::init_workers(){
		Position p ;
	//int player_1
	for (int var = 0; var < workers_number; var++) {
		 p = Random().generateRandom();
		while( exist_in_map(p)|| out_of_borders(p)){
			// qd la position est occupé je regenre un autre position jsqua trouver le un vide
			p = Random().generateRandom();
		}
		player1->init_workerArray(p);
	}

//	int player_2
	for (int var = 0; var < workers_number; var++) {
		p = Random().generateRandom();
		while( exist_in_map(p) || out_of_borders(p)){
			// qd la position est occupé je regenre un autre position jsqua trouver le un vide
			p = Random().generateRandom();
		}
		player2->init_workerArray(p);
	}
}

void GameManagerState::generate_objetsR(int max){
		Position p ;
	//int player_1
	for (int var = 0; var < max; var++) {
		 p = Random().generateRandom();
		while( exist_in_map(p)|| out_of_borders(p)){
			// qd la position est occupé je regenre un autre position jsqua trouver le un vide
			p = Random().generateRandom();
		}
		int type = Random().generateRandom(4);
		this->carte->create_objetR(type,1,p);

		this->objetR_number ++;
	}
}


void GameManagerState::initWindow()
{
	this->window = m_stateMgr->get_window();
}



void GameManagerState::on_create(){
	this->initVariables();
	this->initWindow();
}

GameManagerState::GameManagerState(StateManager* st):BaseState(st){
}

void GameManagerState::on_destroy()
{
	cout << "from Intro::on_destroy" << endl;
}

GameManagerState::~GameManagerState() {
	delete this->window;
}

bool GameManagerState::exist_in_map(const Position & p){
	return this->carte->game_map.find(p) != this->carte->game_map.end();
}


const bool GameManagerState::running() const
{
	return this->window->isOpen() && !this->endGame;
}

bool GameManagerState::out_of_borders(Position p){
	if(p.getX() < 0 || p.getX() > w - 100 || p.getY() < 0 || p.getY() > h)
		return true;
	else return false;
}

const bool & GameManagerState::getEndGame() const
{
	return this->endGame;
}

bool GameManagerState::check_button_pressed(){
	auto mousePos = sf::Mouse::getPosition( *(this->window) );
	float halfX = pause_button.getSize().x / 2.0f;
		float halfY = pause_button.getSize().y / 2.0f;
		return (mousePos.x >= pause_button.getPosition().x - halfX && mousePos.x <= pause_button.getPosition().x + halfX &&
				mousePos.y >= pause_button.getPosition().y - halfY && mousePos.y <= pause_button.getPosition().y + halfY);

}

void GameManagerState::pause_game(){
	cerr << "pause_game" << endl;
	re_draw = true;
	m_stateMgr->switch_to(StateType::Pause);
}

void GameManagerState::poll_events()
{
	while (this->window->pollEvent(this->sfmlEvent)) {
		switch (this->sfmlEvent.type){
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::MouseButtonPressed:
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						if (check_button_pressed())
							pause_game();
								break;
			case sf::Event::KeyPressed:
				// CONTROLLING PLAYER MOTION
				if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
					this->window->close();
				if (this->sfmlEvent.key.code == sf::Keyboard::Space){
						active_player->generateBall();
						re_draw = true;
					}
				if (this->sfmlEvent.key.code == sf::Keyboard::Left && active_player->canMove(Direction::Left) && !is_obstacle(Direction::Left,active_player)){
						active_player->moveLeft();
						re_draw = true;
					}
				if (this->sfmlEvent.key.code == sf::Keyboard::Right && active_player->canMove(Direction::Right) && !is_obstacle(Direction::Right,active_player)){
							active_player->moveRight();
							re_draw = true;

						}
				if (this->sfmlEvent.key.code == sf::Keyboard::Up && active_player->canMove(Direction::Up) && !is_obstacle(Direction::Up,active_player)){
						active_player->moveUp();
						re_draw = true;
					}
				if (this->sfmlEvent.key.code == sf::Keyboard::Down && active_player->canMove(Direction::Down) && !is_obstacle(Direction::Down,active_player)){
						active_player->moveDown();
						re_draw = true;
					}
				break;
			default:
				break;
		}
	}
}

bool GameManagerState::is_obstacle(Direction d,Guerrier* g)
{
	Position p = g->getPosition();
	int range_y = ceil(g->shapeHeight/heightScale);
	int range_x = ceil(g->shapeWidth/widthScale);
		int count(1);

	switch (d) {
		case Direction::Left:
			p.minusX();
			break;
		case Direction::Right:
			p.plusX((g->shapeWidth/widthScale));
			break;
		case Direction::Up:
			p.minusY();
			break;
		case Direction::Down:
			p.plusY((g->shapeHeight/heightScale) + 1);
			break;
		default:
			break;
	}

	while(count <= range_y  && (d == Direction::Right || d == Direction::Left) ){
		if(!exist_in_map(p)){//not found
			p.plusY();
			count++;
		}
		else {// existe in map
			if(is_objetR(p)){ pick_it_up(p); return false;}
			return true;
		}
	}

	while(count <= range_x && ( d == Direction::Down || d == Direction::Up) ){
		if(!exist_in_map(p)){//not found
			p.plusX();
			count++;
		}
		else {// existe in map
		if(is_objetR(p)){ pick_it_up(p);  return false;}
			return true;
		}
	}
	return false;
}

bool GameManagerState::is_objetR(Position p){
	return typeid(*this->carte->game_map[p]) == typeid(ObjetRamassable);
}

void GameManagerState::switching_role(){
	if(this->clock.getElapsedTime().asSeconds() > 30) {

		if(active_player == player1) {
			active_player = player2;
			enemy_player = player1;
		}
		else {
			active_player = player1;
			enemy_player = player2;
		}
		cout << "PLAYER :" << active_player->getName() << endl;
		clock.restart();
	}
}

void GameManagerState::check_balle_collision(){
	bool found(false);
	bool hit(false);

	for(auto& balle : active_player->balleArray){
		re_draw = true;
		Position p(balle.getPosition().getX()/widthScale,balle.getPosition().getY()/heightScale);

		if(p.getX() < 0 || p.getX() > w || p.getY() <0 || p.getY() > h) {
			balle.set_destroy(true);
			break;
		}
		switch (balle.getDirection()){
			case Direction::Left:
				p.minusX();
				found = exist_in_map(p);
				break;
			case Direction::Right:
				p.plusX();
				found = exist_in_map(p);
				break;
			case Direction::Up:
				p.minusY();
				found = exist_in_map(p);
				break;
			case Direction::Down:
				p.plusY();
				found = exist_in_map(p);
				break;
			default:
				break;
		}

		hit = check_balle_hit_player(p,balle);

		if(found || hit) {
			balle.set_destroy(true);
		}
	}
}

void GameManagerState::destroying_balles(){
	int counter(0);
	for(auto iter = active_player->balleArray.begin(); iter != active_player->balleArray.end(); iter++ ){
		if(active_player->balleArray[counter].is_destroy()){
			active_player->balleArray.erase(iter);
			break;
		}
		counter++;
	}
}

bool GameManagerState::check_balle_hit_player(Position p, Balle& balle){

	int range_x = (ceil(enemy_player->shapeWidth/widthScale)) -1;
	int range_y = (ceil(enemy_player->shapeHeight/heightScale)) - 1;

	int current_x = enemy_player->getPosition().getX();
	int current_y = enemy_player->getPosition().getY();

	if( (p.getX() >= current_x &&  p.getX() <= current_x + range_x) &&  (p.getY() >= current_y &&  p.getY() <= current_y + range_y)              )
	{
		this->enemy_player->lostDefenseCapacity(1);
		return true;
	}
	return false;
}

void GameManagerState::updateWorker(){
	if(this->clockWorker.getElapsedTime().asSeconds() > 0.3){
		for(auto worker : active_player->getWorkerArray()){
			Direction d = Random().generateRandomDir();
			if(worker->canMove(d) && !is_obstacle(d,worker)){
				worker->setDirection(d);
				worker->move();
				re_draw = true;
			}
		}
	clockWorker.restart();
	}
}

void GameManagerState::update_objetR(){
	if(objetR_number<6){
		generate_objetsR(5);}
}

void GameManagerState::pick_it_up(Position p){

	if (typeid(*this->carte->game_map[p])== typeid(ObjetRamassable)){
		active_player->pick_up(dynamic_cast<ObjetRamassable*>(this->carte->game_map[p]));
	}
	this->carte->delete_objetR(p);
	objetR_number--;
}

void GameManagerState::life_player_cntrl(){
	if(player1->getLife()< 1) player1->dead();
	if(player2->getLife()< 1) player2->dead();
}

void GameManagerState::go_to_winner_state(){
	this->clock.restart();

		m_stateMgr->switch_to(StateType::Winner, active_player->getName());
}

void GameManagerState::update(){
	switching_role();
	this->poll_events();
	if (this->endGame == false){
		active_player->reset_type_objetR_picked();
		check_balle_collision();
		destroying_balles();
		updateWorker();
		life_player_cntrl();
		update_objetR();
	}
}

void GameManagerState::draw(){
	vector<int> info= {player1->getLife(),player1->getAttackCapacity(),player1->getDefenseCapacity(),player1->get_type_objetR_picked()};
	vector<int> info2 = {player2->getLife(),player2->getAttackCapacity(),player2->getDefenseCapacity(),player2->get_type_objetR_picked()};

	if(re_draw){
		this->window->clear();

		this->drawer->drawMap(*this->window, this->carte->get_map());
		this->drawer->drawMenu(*this->window, active_player->getName() ,info,info2, this->clock.getElapsedTime().asSeconds());

		if(player1->IsAlive())
			this->drawer->drawGuerrier(player1,*this->window,1);
		else {
			this->drawer->drawGuerrierDead(player1,*this->window,1);
			go_to_winner_state();
		}

		if(player2->IsAlive())
			this->drawer->drawGuerrier(player2,*this->window,2);
		else {
			this->drawer->drawGuerrierDead(player2,*this->window,2);
			go_to_winner_state();
		}
		re_draw = false;
	}
	this->window->display();
}
