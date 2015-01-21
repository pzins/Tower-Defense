//------------------------------------------------------------------------------
// Filename: Level.cpp
// Description: Level, tells the start level
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors:
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#include <iostream>
#include "Level.h"

//------------------------------------------------------------------------------
Level::Level(unsigned int id, unsigned int hp, unsigned int money) : id_(id),
    hp_(hp), money_(money)
{

}

//------------------------------------------------------------------------------
Level::Level()
{
  
}

//------------------------------------------------------------------------------
Level::~Level()
{

}

//------------------------------------------------------------------------------
unsigned int Level::getId() const
{
  return id_;
}

//------------------------------------------------------------------------------
unsigned int Level::getHp() const
{
  return hp_;
}

//------------------------------------------------------------------------------
unsigned int Level::getMoney() const
{
  return money_;
}

//------------------------------------------------------------------------------
void Level::setId(unsigned int id)
{
  id_ = id;
}

//------------------------------------------------------------------------------
void Level::setHp(unsigned int hp)
{
  hp_ = hp;
}

//------------------------------------------------------------------------------
void Level::setMoney(unsigned int money)
{
  money_ = money;
}
