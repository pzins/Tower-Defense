//------------------------------------------------------------------------------
// Filename: Monster.cpp
// Description: Class representing a monster
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors:
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#include <iostream>
#include <string>
#include <algorithm>
#include "Monster.h"
#include "Game.h"

//------------------------------------------------------------------------------
Monster::Monster(std::string name, unsigned int damage, unsigned int life,
                 unsigned int reward, Ratio move_point, Ratio move_speed,
								 Game* game, Coordinate coordinate)
  :  name_(name),
     damage_(damage),
     life_(life),
     reward_(reward),
     move_point_(move_point),
     move_speed_(move_speed), 
     game_(game), 
     coordinate_(coordinate),
     last_move_(1)
{

}

//------------------------------------------------------------------------------
Monster::Monster()
{

}

//------------------------------------------------------------------------------
Monster::~Monster()
{

}

//------------------------------------------------------------------------------
Monster::Monster(Monster const& original)
  : name_(original.name_),
    damage_(original.damage_),
    life_(original.life_),
    reward_(original.reward_),
    move_point_(original.move_point_),
    move_speed_(original.move_speed_),
    game_(original.game_), 
    coordinate_(original.coordinate_), 
    last_move_(original.last_move_)
{

}

//------------------------------------------------------------------------------
std::string Monster::getName() const
{
  return name_;
}

//------------------------------------------------------------------------------
unsigned int Monster::getDamage() const
{
  return damage_;
}

//------------------------------------------------------------------------------
unsigned int Monster::getLife() const
{
  return life_;
}

//------------------------------------------------------------------------------
unsigned int Monster::getReward() const
{
  return reward_;
}

//------------------------------------------------------------------------------
Ratio Monster::getMovespeed() const
{
  return move_speed_;
}

//------------------------------------------------------------------------------
Ratio Monster::getMovepoint() const
{
  return move_point_;
}

//------------------------------------------------------------------------------
Game* Monster::getGame() const
{
  return game_;
}

//------------------------------------------------------------------------------
Coordinate Monster::getCoordinate() const
{
  return coordinate_;
}

//------------------------------------------------------------------------------
unsigned int Monster::getLastMove() const
{
  return last_move_;
}

//------------------------------------------------------------------------------
void Monster::setName(std::string name)
{
  name_ = name;
}

//------------------------------------------------------------------------------
void Monster::setDamage(unsigned int damage)
{
  damage_ = damage;
}

//------------------------------------------------------------------------------
void Monster::setLife(unsigned int life)
{
  life_ = life;
}

//------------------------------------------------------------------------------
void Monster::setReward(unsigned int reward)
{
  reward_ = reward;
}

//------------------------------------------------------------------------------
void Monster::setMovespeed(Ratio move_speed)
{
  move_speed_ = move_speed;
}

//------------------------------------------------------------------------------
void Monster::setMovepoint(Ratio move_point)
{
  move_point_ = move_point;
}

//------------------------------------------------------------------------------
void Monster::setGame(Game* game)
{
  game_ = game;
}

//------------------------------------------------------------------------------
void Monster::setCoordinate(Coordinate coordinate)
{
  coordinate_ = coordinate;
}

//------------------------------------------------------------------------------
void Monster::setLastMove(unsigned int last_move)
{
  last_move_ = last_move;
}





//------------------------------------------------------------------------------
unsigned int Monster::move(Game& board)
{
 	std::vector<unsigned int> fields_vector = 
	 													board.getVectorMap().at(0).getFields();
	unsigned int coordinate_x_monster = coordinate_.getX();
	unsigned int coordinate_y_monster = coordinate_.getY();
	unsigned int position = coordinate_x_monster + coordinate_y_monster *
	 												board.getVectorMap().at(0).getWidth();
	unsigned int  move_monster = fields_vector.at(position);
	// if the monster is in the base
	if (move_monster == 2) return 1;
	//if the monster is in a field without direction he moves like before
	if (move_monster > 6 || move_monster < 3)
	{
	  position = last_move_;
	}
	switch (move_monster)
	{
	  case 3 : coordinate_.setY(coordinate_.getY() - 1); 
	  break;
	  case 4 : coordinate_.setX(coordinate_.getX() + 1);
	  break;
	  case 5 : coordinate_.setY(coordinate_.getY() + 1); 
	  break;
	  case 6 : coordinate_.setX(coordinate_.getX() - 1);
	  break;
	}
	
	//calculate new coordinates
	coordinate_x_monster = coordinate_.getX();
	coordinate_y_monster = coordinate_.getY();
	position = coordinate_x_monster + coordinate_y_monster *
						 board.getVectorMap().at(0).getWidth();
	
	//if the monster is in a wrong field or out the map or in a blocked way
	if ((fields_vector.at(position) == 1) || 
	  	(coordinate_.getX() > board.getVectorMap().at(0).getWidth()) ||
	  	(coordinate_.getY() > board.getVectorMap().at(0).getHeight()))
	{
	  return 0;
	}
return 2;

}
