
#ifndef CARTE_HPP_
#define CARTE_HPP_

#include <iostream>
#include <fstream>
#include <list>
#include <iterator>
#include <map>
#include "../headers/Element.hpp"
#include "../headers/Obstacle.hpp"
#include "../headers/ObjetRamassable.hpp"
#include "../headers/GuerrierPrincipal.hpp"
#include "../headers/GameManagerState.hpp"


using namespace std;
class Carte {
private :
	map <Position, Element*> game_map;
	int largeur;
	int hauteur;

	GuerrierPrincipal *guerrier1;
	GuerrierPrincipal *guerrier2;
	void createElement(char , int , int);
public:
	Carte();
	Carte(string);
	virtual ~Carte();
	void readFile(std::string);// lire , creer les elements, hashage de cle
	void addObstacle(Obstacle *, Position);
	void addGuerrier(Guerrier *, Position);
	void addObjetRamassable(ObjetRamassable *,Position);

	void deleteElement(Element &);
	void updateGeruierPos(Guerrier &);

//	Accessors
//	MyType const & MyClass::getMyType() const
	map <Position, Element*> const & get_map() const;// lire ,  hashage de cle
	GuerrierPrincipal* getGuerrier1();
	GuerrierPrincipal* getGuerrier2();
	int getLargeur() const;
	int getHauteur() const;

	//objet
	void create_objetR(int type , int power,Position);
	void delete_objetR(Position);

	friend bool GameManagerState::exist_in_map(const Position & p);
	friend bool GameManagerState::is_objetR(Position p);
	friend void GameManagerState::pick_it_up(Position);
};

#endif /* CARTE_HPP_ */
