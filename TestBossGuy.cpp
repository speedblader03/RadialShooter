#include "TestBossGuy.h"

TestBossGuy::TestBossGuy()
{
	this->setOrigin(this->getPosition().x + 64, this->getPosition().y + 64);
}

void TestBossGuy::Update(double tickrate)
{
	rotate(tickrate * 60);
}

TestBossGuy::~TestBossGuy()
{

}
