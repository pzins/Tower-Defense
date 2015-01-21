//------------------------------------------------------------------------------
// Filename: Tower.cpp
// Description: Class representing a tower
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors:
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//
#include <string>
#include <iostream>
#include "Tower.h"
#include "Game.h"


//------------------------------------------------------------------------------
Tower::Tower(std::string name, unsigned int price, unsigned int damage,
             unsigned int range, Ratio fire_point, Ratio fire_speed,
             unsigned int upgrade_from_id, unsigned int attributes, Game* game, 
             Coordinate coordinate)
    : name_(name),
      price_(price),
      damage_(damage),
      range_(range),
      fire_point_(fire_point),
      fire_speed_(fire_speed),
      upgrade_from_id_(upgrade_from_id),
      attributes_(attributes),
      game_(game),
      coordinate_(coordinate)
{

}

//------------------------------------------------------------------------------
Tower::Tower(Tower const &original)
    : name_(original.name_),
      price_(original.price_),
      damage_(original.damage_),
      range_(original.range_),
      fire_point_(original.fire_point_),
      fire_speed_(original.fire_speed_),
      upgrade_from_id_(original.upgrade_from_id_),
      attributes_(original.attributes_),
      game_(original.game_),
      coordinate_(original.coordinate_)
{

}

//------------------------------------------------------------------------------
Tower::Tower()
{

}

//------------------------------------------------------------------------------
Tower::~Tower()
{

}


//------------------------------------------------------------------------------
Game *Tower::getGame() const
{
  return game_;
}

//------------------------------------------------------------------------------
Coordinate Tower::getCoordinate() const
{
  return coordinate_;
}



//------------------------------------------------------------------------------
std::string Tower::getName() const
{
  return name_;
}

//------------------------------------------------------------------------------
unsigned int Tower::getDamage() const
{
  return damage_;
}

//------------------------------------------------------------------------------
unsigned int Tower::getPrice() const
{
  return price_;
}

//------------------------------------------------------------------------------
unsigned int Tower::getRange() const
{
  return range_;
}

//------------------------------------------------------------------------------
Ratio Tower::getFirepoint() const
{
  return fire_point_;
}

//------------------------------------------------------------------------------
Ratio Tower::getFirespeed() const
{
  return fire_speed_;
}

//------------------------------------------------------------------------------
unsigned int Tower::getUpgradefromid() const
{
  return upgrade_from_id_;
}

//------------------------------------------------------------------------------
unsigned int Tower::getAttribute() const
{
  return attributes_;
}

//------------------------------------------------------------------------------
void Tower::setName(std::string name)
{
  name_ = name;
}

//------------------------------------------------------------------------------
void  Tower::setPrice(unsigned int price)
{
  price_ = price;
}

//------------------------------------------------------------------------------
void  Tower::setDamage(unsigned int damage)
{
  damage_ = damage;
}

//------------------------------------------------------------------------------
void  Tower::setRange(unsigned int range)
{ 
  range_ = range;
}

//------------------------------------------------------------------------------
void Tower::setFirepoint(Ratio fire_point)
{
  fire_point_ = fire_point;
}

//------------------------------------------------------------------------------
void Tower::setFirespeed(Ratio fire_speed)
{
  fire_speed_ = fire_speed;
}

void Tower::setUpgradefromid(unsigned int upgrade_from_id)
{
  upgrade_from_id_ = upgrade_from_id;
}

//------------------------------------------------------------------------------
void Tower::setAttributes(unsigned int attributes)
{
  attributes_ = attributes;
}

//------------------------------------------------------------------------------
void Tower::setGame(Game *game)
{
  game_ = game;
}


//------------------------------------------------------------------------------
void Tower::setCoordinate(Coordinate coordinate)
{
  coordinate_ = coordinate;
}

//------------------------------------------------------------------------------
unsigned int Tower::fire(Monster& monster)
{
  int points = monster.getLife() - damage_;
  if (points <= 0)
  {
    monster.setLife(0);
    
    return 1;
  }
  else
  {
    monster.setLife(points);
    return 0;
  }
}
