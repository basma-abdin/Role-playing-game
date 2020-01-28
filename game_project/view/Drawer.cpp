
#include "../headers/Drawer.hpp"

using namespace std;

void Drawer::initImages(){
	this->obstacle_img.loadFromFile("media/wall.png");
	this->lifeAndBullet.loadFromFile("media/bulletAndLife.png");

	this->player1_img.loadFromFile("media/player4.png");
	this->player2_img.loadFromFile("media/player3.png");

	this->worker1_img.loadFromFile("media/worker1.png");
	this->worker2_img.loadFromFile("media/worker2.png");

	this->obstacle_sprite.setTexture(obstacle_img);
	this->objetR_sprite.setTexture(lifeAndBullet);
	this->balle_sprite.setTexture(lifeAndBullet);
}


Drawer::Drawer( ){
	initImages();
}

Drawer::~Drawer() {
}

void Drawer::drawObstacle(int x, int y,sf::RenderTarget& target){
	obstacle_sprite.setPosition(x * widthScale, y*  heightScale);
	obstacle_sprite.setTextureRect(sf::IntRect(1, 41, 17, 17));

	target.draw(obstacle_sprite);
}

void Drawer::BackGround(sf::RenderTarget& target){
	background_sh.setSize(sf::Vector2f(w-130,h));
	background_sh.setPosition(0,0);
	background_sh.setFillColor(sf::Color(60,179,113));

	target.draw(background_sh);
}

void Drawer::drawGuerrier(GuerrierPrincipal * guerrier,sf::RenderTarget& target, int type){

	if(type==1) guerrier_sprite.setTexture(player1_img);
	else  guerrier_sprite.setTexture(player2_img);
	guerrier_sprite.setPosition(guerrier->rect.getPosition().x * widthScale, guerrier->rect.getPosition().y * heightScale);

	 switch (guerrier->getDirection()) {
		case Direction::Right:
			if(guerrier->IsShooting()) guerrier_sprite.setTextureRect(sf::IntRect(120,493,71,66));
			else  guerrier_sprite.setTextureRect(sf::IntRect(33,18,40,67));
			break;
		case Direction::Left:
			if(guerrier->IsShooting()) guerrier_sprite.setTextureRect(sf::IntRect(97,400,68,64));
			else guerrier_sprite.setTextureRect(sf::IntRect(19 ,115,49,64));
			break;
		case Direction::Up:
			if(guerrier->IsShooting()) guerrier_sprite.setTextureRect(sf::IntRect(120,493,71,66));
			else guerrier_sprite.setTextureRect(sf::IntRect(19 ,209,49,64));
			break;
		default:
			guerrier_sprite.setTextureRect(sf::IntRect(33 ,302,40,64));
			break;
	}
		target.draw(guerrier_sprite);
		drawBalle(guerrier,target);
		drawWorker(guerrier,target,type);
}


void Drawer::drawGuerrierDead(GuerrierPrincipal * guerrier,sf::RenderTarget& target,int type){

	if(type==1) guerrier_sprite.setTexture(player1_img);
	else  guerrier_sprite.setTexture(player2_img);

	guerrier_sprite.setPosition(guerrier->rect.getPosition().x * widthScale, guerrier->rect.getPosition().y * heightScale);

	guerrier_sprite.setTextureRect(sf::IntRect(697 ,698,40,64));
	target.draw(guerrier_sprite);
}

void Drawer::drawObjR(int x, int y,sf::RenderTarget& target){
	objetR_sprite.setPosition(x * widthScale, y * heightScale);

	objetR_sprite.setTextureRect(sf::IntRect(258 ,267,16,16	));
	target.draw(objetR_sprite);
}

void Drawer::drawMap(sf::RenderTarget& target,map <Position, Element*> game_map ){
	BackGround(target);
	for (auto it : game_map)
	{
		if (typeid(*it.second) == typeid(Obstacle)){
			drawObstacle(it.first.getX(), it.first.getY(), target);
		}
		else if (typeid(*it.second) == typeid(ObjetRamassable)){
			;
			drawObjR(it.first.getX(), it.first.getY(), target);
		}
	}
}

void Drawer::drawBalle(GuerrierPrincipal * guerrier,sf::RenderTarget& target){
	balle_sprite.setTextureRect(sf::IntRect(242 ,214,15,12));

	for(auto& balle : guerrier->balleArray)
		{
			balle.update();

			balle_sprite.setPosition(balle.rect.getPosition());

			switch (balle.getDirection()) {
				case Direction::Left:
					balle_sprite.setTextureRect(sf::IntRect(242 ,214,15,12));
					break;
				case Direction::Right:
					balle_sprite.setTextureRect(sf::IntRect(279 ,215,15,12));
					break;
				case Direction::Up:
					balle_sprite.setTextureRect(sf::IntRect(263 ,197,15,12));
					break;
				case Direction::Down:
					balle_sprite.setTextureRect(sf::IntRect(263 ,230,15,12));
					break;
				default:
					break;
			}
			target.draw(balle_sprite);
		}
}



void Drawer::drawWorker(GuerrierPrincipal* g,sf::RenderTarget& target, int type){
	if(type==1) worker_sprite.setTexture(worker1_img);
	else  worker_sprite.setTexture(worker2_img);

	for(auto& worker : g->getWorkerArray()){
		worker_sprite.setPosition(worker->rect.getPosition().x * widthScale, worker->rect.getPosition().y * heightScale);
		switch (worker->getDirection()) {
			case Direction::Left:
				worker_sprite.setTextureRect(sf::IntRect(15 ,8,23,32));
				break;
			case Direction::Right:
				worker_sprite.setTextureRect(sf::IntRect(11 ,58,23,32));
				break;
			case Direction::Up:
				worker_sprite.setTextureRect(sf::IntRect(11 ,58,23,32));
				break;
			case Direction::Down:
				worker_sprite.setTextureRect(sf::IntRect(15 ,8,23,32));
				break;
			default:
				break;
		}
		target.draw(worker_sprite);
	}
}

void Drawer::drawMenu(sf::RenderTarget& target,string s,vector<int> info1, vector<int> info2,int t){
	menu.set_active_player(s);
	menu.set_timer(t);
	menu.set_labels_player1(info1);
	menu.set_labels_player2(info2);

	target.draw(menu.pause_button);
	target.draw(menu.button_label);

	target.draw(menu.active_button);
	target.draw(menu.active_label);

	target.draw(menu.timer);
	target.draw(menu.timer_label);

	for(int i = 0; i < 4; ++i){
		target.draw(menu.player1[i]);
		target.draw(menu.player1_labels[i]);
	}

	for(int i = 0; i < 4; ++i){
		target.draw(menu.player2[i]);
		target.draw(menu.player2_labels[i]);
	}
}

