
#include "../headers/GuerrierPrincipal.hpp"

using namespace std;

GuerrierPrincipal::GuerrierPrincipal(string team, Position p, string name, int _ac, int _dc):
Guerrier(team, p, Direction::Left,63,49), name(name) , attack_capacity(_ac), defense_capacity(_dc), is_shooting(false),life(3)
{
	init_rect();
}

GuerrierPrincipal::GuerrierPrincipal():
Guerrier(), name("") , attack_capacity(5), defense_capacity(5), life(5),is_shooting(false)
{
	init_rect();
}

GuerrierPrincipal::~GuerrierPrincipal() {}

void GuerrierPrincipal::moveRight(){
	this->pos.setX(pos.getX()+1);
	this->direction = Direction::Right;
	this->is_shooting = false;
	update_rect_pos();
}

void GuerrierPrincipal::moveLeft(){
	this->pos.setX(pos.getX()-1);
	this->direction = Direction::Left;
	this->is_shooting = false;
	update_rect_pos();
}

void GuerrierPrincipal::moveUp(){
	this->pos.setY(pos.getY()-1);
	this->direction = Direction::Up;
	this->is_shooting = false;
	update_rect_pos();
}

void GuerrierPrincipal::moveDown(){
	this->pos.setY(pos.getY()+1);
	this->direction = Direction::Down;
	this->is_shooting = false;
	update_rect_pos();
}

int GuerrierPrincipal::getX() const{
	return this->pos.getX();
}

int GuerrierPrincipal::getY() const{
	return this->pos.getY();
}

std::string GuerrierPrincipal::getName() const{
  return name;
}

int GuerrierPrincipal::getAttackCapacity() const{
  return attack_capacity;
}

int GuerrierPrincipal::getLife() const{
  return life;
}

int GuerrierPrincipal::getDefenseCapacity() const{
  return defense_capacity;
}

bool GuerrierPrincipal::IsAlive() const{
  return is_alive;
}

void GuerrierPrincipal::setName(std::string n){
  name= n;
}

void GuerrierPrincipal::dead(){
	is_alive = false;
}

int GuerrierPrincipal::get_type_objetR_picked() const{
	return 	type_objetR_picked;
}

void GuerrierPrincipal::reset_type_objetR_picked() {
	type_objetR_picked = -1;
}

void GuerrierPrincipal::lostAttackCapacity(){
  attack_capacity --;
}

void GuerrierPrincipal::lostDefenseCapacity(int d_a){
	if(defense_capacity == 0) lostLife(1);
	else defense_capacity -=d_a;

}

void GuerrierPrincipal::lostLife(int d_a){
  life -=d_a;
}

bool GuerrierPrincipal::isAdversaire( Guerrier  & g) const{
	return true;
}

bool GuerrierPrincipal::canMove( Direction d) const{
	switch (d) {
		case Direction::Right:
			if(pos.getX()*widthScale + widthScale < w - 100 ) return true;
			else return false;
			break;
		case Direction::Left:
			if(pos.getX()*widthScale > 0) return true;
			else return false;
			break;
		case Direction::Up:
			if(pos.getY()*heightScale >  0) return true;
			else return false;
			break;
		case Direction::Down:
			if(pos.getY()*heightScale + 5*heightScale  < h) return true;
			else return false;
			break;
		default:
			break;
	}
	return true;
}

bool GuerrierPrincipal::canPickUp(ObjetRamassable o) const{
	return true;
}

void GuerrierPrincipal::pick_up(ObjetRamassable * ob){
	int power = ob->get_power();
	int type = ob->get_type();

	switch (ob->get_type()) {
	case 0: //life
		life += power;
		break;
	case 1:
		attack_capacity += power;
		break;
	case 2:
		if(attack_capacity !=0)
		attack_capacity -= power;
		break;
	case 3:
		if(defense_capacity < 4)
		defense_capacity += power;
		break;
	case 4:
		if(defense_capacity !=0)

		defense_capacity -= power;
		break;
	default:
		break;
	}
	type_objetR_picked = ob->get_type();
}

void GuerrierPrincipal::generateBall(){
 if(this->attack_capacity>0){
	Position p(this->rect.getPosition().x,this->rect.getPosition().y);
	Balle balle(this->direction, p);
	this->is_shooting = true;

	int x = balle.getPosition().getX() * widthScale + this->rect.getSize().x/2 - balle.rect.getSize().x/2;
	int y = balle.getPosition().getY() *heightScale + this->rect.getSize().y/2 - balle.rect.getSize().y/2;

	balle.rect.setPosition(x,y);

	balle.setPosition(x,y);

	balleArray.push_back(balle);
	this->attack_capacity--;
 }
}

bool GuerrierPrincipal::IsShooting() const{
	return is_shooting;
}

void GuerrierPrincipal::IsShooting(bool b){
	is_shooting = b;
}

vector<Worker*>& GuerrierPrincipal::getWorkerArray(){
	return workerArray;
}

void GuerrierPrincipal::init_workerArray(Position p){
		Worker* w1 = new Worker(team,p);
		workerArray.push_back(w1);
}




