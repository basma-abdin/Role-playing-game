/*
 * Drawer.hpp
 *
 *  Created on: Oct 30, 2019
 *      Author: basma
 */

#ifndef DRAWER_HPP_
#define DRAWER_HPP_


#include <map>
#include <SFML/Graphics.hpp>
#include <typeinfo>
#include "../headers/Element.hpp"
#include "../headers/GuerrierPrincipal.hpp"
#include "../headers/Obstacle.hpp"

#include "../headers/Menu.hpp"

class Drawer {
private:
	sf::Texture obstacle_img;
	sf::Texture lifeAndBullet;

	sf::Texture player1_img;
	sf::Texture player2_img;

	sf::Texture worker1_img;
	sf::Texture worker2_img;

	sf::RectangleShape background_sh;

	sf::Sprite obstacle_sprite;
	sf::Sprite guerrier_sprite;
	sf::Sprite objetR_sprite;
	sf::Sprite balle_sprite;
	sf::Sprite worker_sprite;

	Menu menu;

	void initImages();
	void BackGround(sf::RenderTarget& target);

public:
	Drawer();
	virtual ~Drawer();
	void drawObstacle(int, int,sf::RenderTarget& target);
	void drawObjR(int x, int y,sf::RenderTarget& target);
	void drawMap(sf::RenderTarget& target, std::map <Position, Element*>);
	void drawGuerrier(GuerrierPrincipal * guerrier,sf::RenderTarget& target,int);
	void drawGuerrierDead(GuerrierPrincipal * guerrier,sf::RenderTarget& target,int);
	void drawBalle(GuerrierPrincipal * guerrier,sf::RenderTarget& target);
	void drawWorker(GuerrierPrincipal * guerrier,sf::RenderTarget& target, int);
	void drawMenu(sf::RenderTarget& target, std::string, std::vector<int>, std::vector<int>,int t);
};

#endif /* DRAWER_HPP_ */
