#ifndef GUERRIER_HPP_
#define GUERRIER_HPP_
#include <iostream>
#include <list>
#include <vector>

#include "../headers/Element.hpp"
#include "../headers/Direction.hpp"
#include "../headers/ObjetRamassable.hpp"
#include "../headers/Balle.hpp"
#include "../headers/shared.hpp"


class Guerrier : public Element {
protected:
	std::string team;
	bool is_alive;
	Direction direction;

public:
	Guerrier();
	Guerrier(std::string team, Position p, Direction, int, int);
	virtual ~Guerrier();

	virtual std::string getTeam() const;
	virtual Direction getDirection() const;

	virtual void setTeam(std::string t);
	virtual void setDirection(Direction);

//	Rect shape
	sf::RectangleShape rect;
	int shapeHeight;
	int shapeWidth;

	virtual void init_rect();
	virtual void update_rect_pos();
	virtual bool canMove(Direction d) const;
};

#endif /* GUERRIER_HPP_ */
