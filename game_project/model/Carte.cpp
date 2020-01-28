
#include "../headers/Carte.hpp"

using namespace std;


Carte::Carte() : game_map(), largeur(0), hauteur(0)
{
}


Carte::Carte(string file_name):largeur(0), hauteur(0)
{
	game_map = map<Position, Element*>() ;

	readFile(file_name);
}



Carte::~Carte() {
	delete guerrier1;
	delete guerrier2;
}


void Carte::createElement(char type, int x, int y){
 switch(type)
 {
  case '*':
    {
      Position p = Position(x,y);
      Obstacle *o = new Obstacle(p);

      addObstacle(o, p);
      break;
    }
  case 'G':
    {
      Position p1 =  Position(x,y);
      string n1 = "Player 1";
      this->guerrier1 = new GuerrierPrincipal("team 1",p1, n1, 5,3 );
      break;
    }
  case 'g':
    {
      Position p2 =  Position(x,y);
      string n2 = "Player 2";
      this->guerrier2 = new GuerrierPrincipal("team 2",p2, n2, 5,3 );
      break;
    }
  case '1'...'9':
	{
  	Position p2 =  Position(x,y);
  	int nbr_vie = type - 48;
  	ObjetRamassable *obj_r = new ObjetRamassable(0,nbr_vie,p2);
  	addObjetRamassable(obj_r, p2);
  	break;
	}
  default:{
  	break;}
 }
}

void Carte::addObstacle(Obstacle *o, Position key){
 game_map[key] = o;
}


void Carte::addObjetRamassable(ObjetRamassable *o,Position key){
	game_map[key] = o;
}

void Carte::create_objetR(int type, int power, Position p){
	ObjetRamassable *obj_r = new ObjetRamassable(type,power,p);
	addObjetRamassable(obj_r, p);
}


void Carte::readFile(string filename){
 int cmp_line = 0;
 int cmp_column = 0;

	ifstream file(filename, ios::in);
	if(file){

		file >> largeur >> hauteur;

		string str;
		std::getline(file, str);
		 while (std::getline(file, str))
		 {
			 if(cmp_line >= hauteur ){
				 cerr << "depassment de hauteur" << endl;
				 throw "error";
			 }
			 for (int i=0; i< str.length(); i++){
				 if(cmp_column >= largeur ){
					 cerr << "depassment de largeur" << endl;
					 throw "error";
				 }
				 createElement(str[i], cmp_column, cmp_line);
				 cmp_column++;
			 }

			 cmp_line++;
			 cmp_column = 0;
		 }

		 file.close();

	}else cerr << "can't open file !" << endl;

}

map<Position, Element*> const & Carte::get_map() const{
	return game_map;
}

int Carte::getLargeur() const{
	return largeur;
}
int Carte::getHauteur() const{
	return hauteur;
}

GuerrierPrincipal* Carte::getGuerrier1(){
	return guerrier1;
}
GuerrierPrincipal* Carte::getGuerrier2(){
	return guerrier2;
}

void Carte::delete_objetR(Position key){
	auto ob = game_map[key];
	game_map.erase(key);

 delete ob;
}

