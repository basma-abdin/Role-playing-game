
#ifndef OBSTACLE_HPP_
#define OBSTACLE_HPP_
#include "Element.hpp"

class Obstacle :public Element{
public:
	Obstacle();
	Obstacle(Position);
	virtual ~Obstacle();
};

#endif /* OBSTACLE_HPP_ */
