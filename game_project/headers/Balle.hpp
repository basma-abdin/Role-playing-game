/*
 * Balle.hpp
 *
 *  Created on: Nov 23, 2019
 *      Author: basma
 */

#ifndef BALLE_HPP_
#define BALLE_HPP_

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../headers/Element.hpp"
#include "../headers/Direction.hpp"




class Balle : public Element{
private:
	Direction direction;
	int speed;
	bool destroy;
public:
	Balle(Direction , Position);
	virtual ~Balle();
	void update();
	Direction getDirection() const;
	bool is_destroy() const;
	void set_destroy(bool);


	sf::RectangleShape rect;
};

#endif /* BALLE_HPP_ */
