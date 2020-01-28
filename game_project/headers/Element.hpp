#ifndef ELEMENT_HPP_
#define ELEMENT_HPP_

#include "../headers/Position.hpp"

class Element {
protected :
	Position pos;
	// int type; // 0 obstacle, 1 ObjRam, 2 guerrier , 3 balle
public :
	Element();
	virtual ~Element(){}

	Element(Position);
	virtual Position getPosition() const;

 	virtual void setPosition( Position p);
 	virtual void setPosition( int x, int y);
};

#endif /* ELEMENT_HPP_ */
