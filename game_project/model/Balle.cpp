/*
 * Balle.cpp
 *
 *  Created on: Nov 23, 2019
 *      Author: basma
 */

#include "../headers/Balle.hpp"


Balle::Balle(Direction d, Position p) : direction(d), Element(p), speed(3), destroy(false) {
	rect.setSize(sf::Vector2f(13,14));
	rect.setFillColor(sf::Color::Green);
}

Balle::~Balle() {
}
Direction Balle::getDirection() const{
	return direction;
}

void Balle::update(){
	switch (direction) {
		case Direction::Right:
			pos.plusX(speed);
			rect.move(speed,0);
			break;
		case Direction::Left:
			pos.minusX(speed);
			rect.move(-speed,0);
			break;
		case Direction::Up:
			pos.minusY(speed);
			rect.move(0,-speed);
			break;
		case Direction::Down:
			pos.plusY(speed);
			rect.move(0,speed);
			break;
		default:
			break;
	}

	rect.setPosition(pos.getX(),pos.getY());
}


bool Balle::is_destroy() const{
	return destroy;
}
void Balle::set_destroy(bool b) {
	destroy = b;
}
