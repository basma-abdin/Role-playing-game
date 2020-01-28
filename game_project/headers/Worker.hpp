

#ifndef WORKER_HPP_
#define WORKER_HPP_

#include "../headers/Guerrier.hpp"
#include "../headers/Random.hpp"


class Worker: public Guerrier {
private:
	int speed;

public:
	Worker();
	Worker(std::string team, Position);
	virtual ~Worker();

	void move();
};

#endif
