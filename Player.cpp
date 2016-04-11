#include "Player.h"

Player::Player(float center_x, float center_y, float distance)
{
	setOrigin(16, 12);
	m_center_x = center_x;
	m_center_y = center_y;
	m_distance = distance;
	m_speed = 0;
	m_angle = 90;
	m_direction = 0;
	m_prevLeft = false;
	m_prevRight = false;
}

void Player::Update(double tickrate)
{
	double tick60=tickrate*60; //multiplier so physics can be coded to assume 60 ticks per second and not break if the tickrate is changed later in development


	//movement

	//store state of keys
	bool leftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	bool rightPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

	//"Null Cancelling" movement: you move in the direction of the last key pressed
	//moving left (clockwise)
	if (leftPressed && ((m_direction==1 && !(!m_prevRight && rightPressed)) || (!m_prevLeft && m_direction!=1) || !rightPressed) && !(m_direction == 0 && leftPressed && rightPressed))
	{
		m_direction = 1;
		if (m_speed < 1)
		{
			m_speed += 0.12 * tick60;
		}
	}
	//moving right (counter-clockwise)
	else if (rightPressed && !(m_direction == 0 && leftPressed && rightPressed))
	{
		m_direction = -1;
		if (m_speed > -1)
		{
			m_speed -= 0.12 * tick60;
		}
	}
	//decelerating
	else
	{
		m_direction = 0;
		if (std::abs(m_speed) < 0.1 * tick60)
		{
			m_speed = 0;
		}
		if (m_speed < 0)
		{
			m_speed += 0.1 * tick60;
		}
		if (m_speed > 0)
		{
			m_speed -= 0.1 * tick60;
		}
	}

	m_prevLeft = leftPressed;
	m_prevRight = rightPressed;

	m_angle += m_speed * tick60;

	//setting position on circle
	setPosition(m_center_x + m_distance * cos(m_angle * M_PI / 180),
			m_center_y + m_distance * sin(m_angle * M_PI / 180));
	setRotation(m_angle);
}

void Player::setCenter(float x, float y)
{
	m_center_x = x;
	m_center_y = y;
}

Player::~Player()
{

}
