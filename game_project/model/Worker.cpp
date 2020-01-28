#include "../headers/Worker.hpp"

Worker::Worker(): speed(1) {
}
Worker::Worker(std::string team,Position p): Guerrier(team, p, Direction::Left,23,32),speed(1) {
	init_rect();
}

Worker::~Worker() {
}

void Worker::move(){
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
}
