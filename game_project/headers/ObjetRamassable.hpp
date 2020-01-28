
#ifndef OBJETRAMASSABLE_HPP_
#define OBJETRAMASSABLE_HPP_
#include "../headers/Element.hpp"

class ObjetRamassable: public Element
{
private:
		int type; // 0 + nbrvie, 1 + capAttack , 2 - capAttack, 3 + capDef , 4 - capDef
		int power = 1;

public:
	ObjetRamassable();
	ObjetRamassable(int,int, Position);
	~ObjetRamassable();
	int get_type() const;
	int get_power() const;
};

#endif /* OBJETRAMASSABLE_HPP_ */
