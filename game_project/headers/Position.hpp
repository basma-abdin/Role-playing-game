#ifndef POSITION_HPP_
#define POSITION_HPP_
#include <iostream>

class Position {
private:
	int x;
	int y;
public:
	Position();
	virtual ~Position();
	Position(int, int);
	void setX(int);
	void setY(int);
	int getX() const;
	int getY() const;

	void minusX(int _x = 1);
	void minusY(int _y = 1);
	void plusX(int _x = 1);
	void plusY(int y = 1);

//	void plusX()

	bool operator==(const Position & other) const
	 {
		return (this->x == other.x && this->y == other.y);
	 }

	bool operator<(const Position& other) const
	{
		return x < other.x || (x == other.x && y < other.y);
	}
};

#endif /* POSITION_HPP_ */
