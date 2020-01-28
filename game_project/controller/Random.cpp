#include "../headers/Random.hpp"
#include "../headers/shared.hpp"

Random::~Random() {}

int Random::generateRandom(int max){
	int randomNumber = rand();
	float rand = (randomNumber % max) + 1;
	int r = rand;
	return r;
}




Position Random::generateRandom(){
	int xNumber = rand();
	int yNumber = rand();

	float randx = (xNumber % 95) + 1;
	float randy = (yNumber % 55) + 1;

	int rx = randx;
	int ry = randy;
	return Position(rx,ry);
}




Direction Random::generateRandomDir(){
	int number = rand();
	float r = (number %4);

	int rand = r;

	switch (rand) {
		case 1:
			return Direction::Right;
		case 2:
			return Direction::Left;
		case 3:
			return Direction::Up;
		case 4:
			return Direction::Down;
	}

	return Direction::Left;
}

