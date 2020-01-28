
#include "../headers/Menu.hpp"
#include "../headers/shared.hpp"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Menu::Menu():gap(30) {
	font.loadFromFile("media/Arial.ttf");
	init_pause_button();
	init_active_button();
	init_timer_button();
	init_player1_buttons();
	init_player2_buttons();

}

Menu::~Menu(){

}

void Menu::init_pause_button(){
	auto size = sf::Vector2f(110.0f,32.0f);

		sf::Vector2f buttonPosition(w - 60, gap);
	//	sf::Vector2f buttonPosition(333, 111);
		pause_button.setSize(size);
		pause_button.setFillColor(sf::Color::Red);
		pause_button.setOrigin(size.x / 2.0f, size.y / 2.0f);
		pause_button.setPosition(buttonPosition);

		button_label.setFont(font);
		button_label.setString(sf::String("PAUSE"));
		button_label.setCharacterSize(12);

		sf::FloatRect rect = button_label.getLocalBounds();
		button_label.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
		button_label.setPosition(buttonPosition);
}

void Menu::init_active_button(){
	auto size = sf::Vector2f(110.0f,32.0f);
	gap += 40;
		sf::Vector2f buttonPosition(w - 60, gap);
	//	sf::Vector2f buttonPosition(333, 111);
		active_button.setSize(size);
		active_button.setFillColor(sf::Color::Green);
		active_button.setOrigin(size.x / 2.0f, size.y / 2.0f);
		active_button.setPosition(buttonPosition);

		active_label.setFont(font);
		active_label.setString(sf::String(""));
		active_label.setCharacterSize(12);
		active_label.setColor(sf::Color::Black);

		sf::FloatRect rect = active_label.getLocalBounds();
		active_label.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
		active_label.setPosition(buttonPosition);
}

void Menu::init_timer_button(){
	auto size = sf::Vector2f(110.0f,32.0f);
	gap += 40;
		sf::Vector2f buttonPosition(w - 60, gap);
		timer.setSize(size);
		timer.setFillColor(sf::Color::Green);
		timer.setOrigin(size.x / 2.0f, size.y / 2.0f);
		timer.setPosition(buttonPosition);

		timer_label.setFont(font);
		timer_label.setString(sf::String(""));
		timer_label.setCharacterSize(12);
		timer_label.setColor(sf::Color::Black);

		sf::FloatRect rect = timer_label.getLocalBounds();
		timer_label.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
		timer_label.setPosition(buttonPosition);
}

void Menu::init_player1_buttons(){
	auto size = sf::Vector2f(110.0f,32.0f);
	int padding = 4; // 4px.
	gap += 50;
	sf::Vector2f position(w - 60, gap);

	std::string str[4];
	str[0] = "Player 1";
	str[1] = "life: ";
	str[2] = "Attack: ";
	str[3] = "Defense: ";
	for(int i = 0; i < 4; ++i){
		sf::Vector2f buttonPosition(position.x,position.y + (i * (size.y + padding)));
		player1[i].setSize(size);
		player1[i].setFillColor(sf::Color::Blue);
		player1[i].setOrigin(size.x / 2.0f,size.y / 2.0f);
		player1[i].setPosition(buttonPosition);
		player1_labels[i].setFont(font);
		player1_labels[i].setString(sf::String(str[i]));
		player1_labels[i].setCharacterSize(12);
		sf::FloatRect rect = player1_labels[i].getLocalBounds();
		player1_labels[i].setOrigin(rect.left + rect.width / 2.0f,
		rect.top + rect.height / 2.0f);
		player1_labels[i].setPosition(buttonPosition);
	}
}

void Menu::init_player2_buttons(){
	auto size = sf::Vector2f(110.0f,32.0f);
	int padding = 4; // 4px.

	gap+= 170;
	sf::Vector2f position(w - 60, gap);

	std::string str[4];
	str[0] = "Player 2";
	str[1] = "life: ";
	str[2] = "Attack: ";
	str[3] = "Defense: ";
	for(int i = 0; i < 4; ++i){
		sf::Vector2f buttonPosition(position.x,position.y + (i * (size.y + padding)));
		player2[i].setSize(size);
		player2[i].setFillColor(sf::Color::Blue);
		player2[i].setOrigin(size.x / 2.0f,size.y / 2.0f);
		player2[i].setPosition(buttonPosition);
		player2_labels[i].setFont(font);
		player2_labels[i].setString(sf::String(str[i]));
		player2_labels[i].setCharacterSize(12);
		sf::FloatRect rect = player2_labels[i].getLocalBounds();
		player2_labels[i].setOrigin(rect.left + rect.width / 2.0f,rect.top + rect.height / 2.0f);
		player2_labels[i].setPosition(buttonPosition);
	}
}

void Menu::set_active_player(std::string s){
	active_label.setString(s);
	sf::FloatRect rect = active_label.getLocalBounds();
			active_label.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
}

void Menu::set_timer(int s){
	stringstream str;
	str << s;
	timer_label.setString(str.str());
	sf::FloatRect rect = timer_label.getLocalBounds();
			timer_label.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
}

void Menu::set_labels_player1(std::vector<int> info){
	set_active_objetR(info[3]);

	stringstream str[3];
		str[0] << "life: " <<info[0];
		str[1]<< "Attack: " <<info[1];
		str[2] << "Defense: " <<info[2];

	for(int i = 1; i < 4; ++i){
		player1_labels[i].setString(sf::String(str[i-1].str()));
		sf::FloatRect rect = player1_labels[i].getLocalBounds();
		player1_labels[i].setOrigin(rect.left + rect.width / 2.0f,rect.top + rect.height / 2.0f);

	}
}

void Menu::set_labels_player2(std::vector<int>info){
	set_active_objetR(info[3]);

	stringstream str[3];
			str[0] << "life: " << info[0];
			str[1] << "Attack: " << info[1];
			str[2] << "Defense: " << info[2];

		for(int i = 1; i < 4; ++i){
			player2_labels[i].setString(sf::String(str[i-1].str()));
			sf::FloatRect rect = player2_labels[i].getLocalBounds();
			player2_labels[i].setOrigin(rect.left + rect.width / 2.0f,rect.top + rect.height / 2.0f);
		}
}

void Menu::set_active_objetR(int active_type){
	for(int i = 0; i< 4 ; i++){
		 player1[i].setFillColor(sf::Color::Blue);
	}
	if(active_type == 0) player1[1].setFillColor(sf::Color::Green);
	else if(active_type == 1 || active_type == 2 )player1[2].setFillColor(sf::Color::Green);
	else if(active_type == 3 || active_type == 4 )player1[3].setFillColor(sf::Color::Green);

}
