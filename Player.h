#ifndef PLAYER_H_
#define PLAYER_H_

#include <SFML/Graphics.hpp>
#include <cmath>
#include <SFML/Window/Keyboard.hpp>

class Player: public sf::Sprite
{
public:
	Player(float x, float y, float distance);

	void Update(double tickrate);

	void setCenter(float x, float y);

	virtual ~Player();
private:
	float m_angle;
	float m_center_x;
	float m_center_y;
	float m_distance;
	float m_speed;
	int m_direction;
	bool m_prevLeft;
	bool m_prevRight;
};

#endif
