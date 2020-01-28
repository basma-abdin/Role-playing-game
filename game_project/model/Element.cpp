#include "../headers/Element.hpp"
#include <string>

using namespace std;

Element::Element(Position p) : pos(p) { }

Element::Element():pos(Position())  { }

Position Element::getPosition() const {
	return pos;
}

void Element::setPosition( Position p1 )  {
 	pos = p1;
}

void Element::setPosition( int x, int y )  {
 	this->pos.setX(x);
 	this->pos.setY(y);
}
