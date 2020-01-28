
#include "../headers/IntroState.hpp"
using namespace std;


IntroState::IntroState(StateManager* st):BaseState(st){

}

IntroState::~IntroState(){

}

void IntroState::draw(){
		sf::Sprite background(background_img);
		m_stateMgr->access_window().draw(background);

		m_stateMgr->access_window().draw(m_text);
		m_stateMgr->access_window().draw(m_rect);
		m_stateMgr->access_window().draw(m_label);

		m_stateMgr->access_window().display();
}


void IntroState::on_create(){

	sf::Vector2u windowSize = m_stateMgr->get_window()->getSize();

	m_font.loadFromFile("media/Pacifico.ttf");
	m_text.setFont(m_font);
	m_text.setOutlineColor(sf::Color::Red);
	m_text.setString({
	"Notes:\n\tChaque joueur a 30 sec pour son role\n\tCapacite de defense: une protection, le joueur ne perd pas de vie quand c'est >0\n\tCapacite d\'attaque: le nombre de balle que le joueur en a.\n\tPetits gurriers: ramassent les objet ramassable pour le grand guerrier.\n\nBut de jeu:\n\tTuer l'adversaire"
	});
	sf::FloatRect textRect = m_text.getLocalBounds();
	m_text.setOrigin(textRect.left + textRect.width / 2.0f,textRect.top + textRect.height / 2.0f);
	m_text.setPosition(windowSize.x / 2.0f, windowSize.y / 4.0f);

	this->background_img.loadFromFile("media/war_back.png");

	init_buttons(windowSize);
}


void IntroState::init_buttons(sf::Vector2u windowSize){
	m_buttonSize = sf::Vector2f(300.0f,32.0f);
	m_buttonPos = sf::Vector2f(400,200);

	sf::Vector2f buttonPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);
	m_rect.setSize(m_buttonSize);
	m_rect.setFillColor(sf::Color::Red);
	m_rect.setOrigin(m_buttonSize.x / 2.0f, m_buttonSize.y / 2.0f);
	m_rect.setPosition(buttonPosition);
	m_label.setFont(m_font);
	m_label.setString(sf::String("Start"));
	m_label.setCharacterSize(12);

	sf::FloatRect rect = m_label.getLocalBounds();
	m_label.setOrigin(rect.left + rect.width / 2.0f, rect.top + rect.height / 2.0f);
	m_label.setPosition(buttonPosition);

}

void IntroState::on_destroy()
{
}

void IntroState::update()
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
							go_to_game();
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

bool IntroState::check_button_pressed( sf::Vector2i mousePos){
	float halfX = m_buttonSize.x / 2.0f;
	float halfY = m_buttonSize.y / 2.0f;
	return (mousePos.x >= m_rect.getPosition().x - halfX && mousePos.x <= m_rect.getPosition().x + halfX &&
			mousePos.y >= m_rect.getPosition().y - halfY && mousePos.y <= m_rect.getPosition().y + halfY);

}

void IntroState::go_to_game(){
	m_stateMgr->switch_to(StateType::GOGame);
}

