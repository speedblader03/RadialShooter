#ifndef TESTBOSSGUY_H_
#define TESTBOSSGUY_H_

#include <SFML/Graphics.hpp>

class TestBossGuy: public sf::Sprite
{
public:
	TestBossGuy();

	void Update(double tickrate);

	virtual ~TestBossGuy();
};

#endif
