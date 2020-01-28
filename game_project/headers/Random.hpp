/*
 * random.hpp
 *
 *  Created on: Nov 28, 2019
 *      Author: basma
 */

#ifndef RANDOM_HPP_
#define RANDOM_HPP_
#include <random>
#include <ctime>
#include "../headers/Position.hpp"
#include "../headers/Direction.hpp"



class Random {
public:
	Random() {}
	virtual ~Random();

	int generateRandom(int);
	Position generateRandom();
	Direction generateRandomDir();
};

#endif /* RANDOM_HPP_ */
