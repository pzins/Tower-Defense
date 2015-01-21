//------------------------------------------------------------------------------
// Filename: Stats.cpp
// Description: Class representing command: Stats
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
#include <vector>
#include "Stats.h"
#include "Game.h"
#include "Tower.h"
#include "Monster.h"
#include "Spawn.h"
#include "Coordinate.h"


//------------------------------------------------------------------------------
Stats::Stats() : Command("Stats")
{

}

//------------------------------------------------------------------------------
Stats::~Stats()
{

}

//------------------------------------------------------------------------------
int Stats::execute(Game& board, std::vector<std::string>& params)
{
  //If user have entered parameters
  if (board.getCurrentTick() != 0)
  {
    std::cout << "current tick:    ";
    std::cout << board.getCurrentTick();
    std::cout << std::endl;
    std::cout << "monsters killed: ";
    unsigned int monster_dead = 0;
    unsigned int monster_attack = 0;
    unsigned int money_earned = 0;
    for (unsigned int it = 0; it < (board.getVectorMonster()).size(); ++it)
    {
      if (!board.getVectorMonster2().at(it)->getLife())
      {
        monster_dead++;
  			money_earned += board.getVectorMonster().at(it).getReward();    
			}
      if ((board.getVectorMonster().at(it).getCoordinate().getX() == 8 ) && 
          (board.getVectorMonster().at(it).getCoordinate().getY() == 0))
      {
        monster_attack++;   
      }    
    }
    std::cout << monster_dead;
    std::cout << std::endl;	
    std::cout << "reached base:    ";
    std::cout << monster_attack;
    std::cout << std::endl;
    std:: cout << "money spent:     ";
    std::cout << board.getVectorTower().size() * 
                 board.getVectorTowerType().at(0).getPrice();
    std::cout << std::endl;
    std::cout << "money earned:    ";
    std::cout << money_earned << std::endl;
    std::cout << "towers built:    ";
    std::cout << board.getVectorTower().size();
    std::cout<<std::endl;
    std::cout << "towers upgraded: 0" << std::endl;
    std::cout << "health:          ";
    std::cout << board.getPlayer_hp();
    std::cout << "/30";
    std::cout << std::endl;
    return 0;
  }
  else
  {
    return NOTHING_HAPPENED_SO_FAR;
  }

}

