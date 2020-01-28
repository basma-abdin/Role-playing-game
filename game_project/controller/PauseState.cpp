
#include "../headers/PauseState.hpp"
using namespace std;
PauseState::PauseState(StateManager* st):BaseState(st){

}

PauseState::~PauseState(){

}

void PauseState::on_create(){

	sf::Vector2u windowSize = m_stateMgr->get_window()->getSize();

	font.loadFromFile("media/Arial.ttf");

	this->background_img.loadFromFile("media/war_back.png");


	init_button(windowSize);
}
void PauseState::on_destroy()
{
	cout << "from Intro::on_destroy" << endl;
}

void PauseState::init_button(sf::Vector2u windowSize){
	m_buttonSize = sf::Vector2f(300.0f,32.0f);
	m_buttonPos = sf::Vector2f(400,200);

	sf::Vector2f buttonPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);

	resume_button.setSize(m_buttonSize);
	resume_button.setFillColor(sf::Color::Red);
	resume_button.setOrigin(m_buttonSize.x / 2.0f, m_buttonSize.y / 2.0f);
	resume_button.setPosition(buttonPosition);
	resume_label.setFont(font);
	resume_label.setString(sf::String("Resume"));
	resume_label.setCharacterSize(12);

	sf::FloatRect rect = resume_label.getLocalBounds();
	resume_label.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
	resume_label.setPosition(buttonPosition);

}

void PauseState::resume_game(){
	m_stateMgr->switch_to(StateType::GOGame);
}

bool PauseState::check_button_pressed( sf::Vector2i mousePos){
	float halfX = m_buttonSize.x / 2.0f;
	float halfY = m_buttonSize.y / 2.0f;
	return (mousePos.x >= resume_button.getPosition().x - halfX && mousePos.x <= resume_button.getPosition().x + halfX &&
			mousePos.y >= resume_button.getPosition().y - halfY && mousePos.y <= resume_button.getPosition().y + halfY);

}


void PauseState::update()
{
	sf::RenderWindow* window = m_stateMgr->get_window();
	while (window->pollEvent(this->sfmlEvent)) {
			switch (this->sfmlEvent.type){
			case sf::Event::Closed:
							window->close();
							break;
				case sf::Event::MouseButtonPressed:

					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	      {
					if (check_button_pressed(sf::Mouse::getPosition( *window )))
							resume_game();
				}
					break;
				case sf::Event::KeyPressed:
								if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
									window->close();
						break;
				default:
					break;
			}
			}
}

void PauseState::draw(){
	sf::Sprite background(background_img);
	m_stateMgr->access_window().clear();
	m_stateMgr->access_window().draw(background);
	m_stateMgr->access_window().draw(resume_button);
	m_stateMgr->access_window().draw(resume_label);
	m_stateMgr->access_window().display();

}
