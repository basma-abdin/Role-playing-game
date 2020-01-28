
#include "../headers/Guerrier.hpp"

using namespace std;

Guerrier::Guerrier() : Element(), team(""), is_alive(true),direction(Direction::Left){
	init_rect();
}

Guerrier::Guerrier(string t, Position p, Direction d, int sh, int sw) : Element(p), team(t), is_alive(true), direction(d),  shapeHeight(sh), shapeWidth(sw){
	init_rect();
}

Guerrier::~Guerrier() {}




std::string Guerrier::getTeam() const{
  return team;
}

void Guerrier::setTeam(string t){
	team = t;
}

Direction Guerrier::getDirection() const{
	return this->direction;
}
void Guerrier::setDirection(Direction d){
	direction = d;
}


void Guerrier::init_rect(){
	rect.setSize(sf::Vector2f(shapeWidth,shapeHeight));
	rect.setPosition(this->pos.getX(),this->pos.getY());

	rect.setFillColor(sf::Color::Blue);
}

void Guerrier::update_rect_pos(){
	rect.setPosition(this->pos.getX(),this->pos.getY());
}

bool Guerrier::canMove( Direction d) const{
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



