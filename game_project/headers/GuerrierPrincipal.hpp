
#ifndef GUERRIERPRINCIPAL_HPP_
#define GUERRIERPRINCIPAL_HPP_
#include <iostream>
#include <list>
#include <vector>

#include "../headers/Guerrier.hpp"
#include "../headers/Worker.hpp"
#include "../headers/Random.hpp"

class GuerrierPrincipal : public Guerrier{
private:
	std::string name;
	int attack_capacity;
	int defense_capacity;
	int life;
	int balle_recu;
	int type_objetR_picked = -1;
	bool is_shooting;
	std::vector<Worker*> workerArray;

public:
	GuerrierPrincipal();
	GuerrierPrincipal(std::string team, Position p, std::string name, int _ac, int _dc);
	~GuerrierPrincipal();

//	GETTERS
	std::string getName() const;
	int getAttackCapacity() const;
	int getLife() const;
	int getDefenseCapacity() const;
	bool IsShooting() const;
	int getX() const;
	int getY() const;
	bool IsAlive() const;
	int get_type_objetR_picked() const;
	std::vector<Worker*>& getWorkerArray();

//	SETTER
	void setName(std::string n);
	void lostAttackCapacity();
	void lostDefenseCapacity(int d_c = 1);
	void lostLife(int d_c = 1);
	void IsShooting(bool);
	void dead();
	void reset_type_objetR_picked();


//	MOTIONS
	void moveRight();
	void moveLeft();
	void moveUp();
	void moveDown();

//	LOGICS
	bool isAdversaire( Guerrier  & g) const;
	bool canMove( Direction d) const;
	bool canPickUp(ObjetRamassable o) const;
	void pick_up(ObjetRamassable * ob);

	//	Balles
	std::vector<Balle> balleArray;
	void generateBall();

//	workers
	void init_workerArray(Position);
};

#endif /* GUERRIERPRINCIPAL_HPP_ */
