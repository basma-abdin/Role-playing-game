
#include "../headers/Position.hpp"

Position::Position() : x(0), y(0){
}

Position::~Position() {
}

Position::Position(int _x, int _y) : x(_x) , y(_y) { }

int Position::getX() const {
	return x;
}
int Position::getY() const{
	return y;
}
void Position::setX( int x1 ){
	if(x1 >= 0){
		x = x1;
	}
}

void Position::setY( int y1 ){
	if(y1 >= 0){
		 y = y1;
	}
}
void Position::minusX(int _x){
	if(x -1 >= 0){
		 x = x -_x;
	}
}
void Position::minusY(int _y){
	if(y -1 >= 0){
		 y = y - _y;
	}
}
void Position::plusX(int _x){
		 x = x + _x;
}
void Position::plusY(int _y){
		 y = y + _y;
}


