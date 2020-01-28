
#include "../headers/ObjetRamassable.hpp"

ObjetRamassable::ObjetRamassable() : type(0), power(1), Element(){
}

ObjetRamassable::ObjetRamassable(int _type, int _power, Position p) : type(_type), power(_power), Element(p)
{ }


ObjetRamassable::~ObjetRamassable() {

}

int ObjetRamassable::get_type() const{
	return this->type;
}

int ObjetRamassable::get_power() const{
	return this->power;
}


