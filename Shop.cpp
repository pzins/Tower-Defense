//------------------------------------------------------------------------------
// Filename: Shop.cpp
// Description: Class representing command: Shop
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
#include <cmath>
#include "Shop.h"
#include "Game.h"


//------------------------------------------------------------------------------
Shop::Shop() : Command("Shop")
{

}

//------------------------------------------------------------------------------
Shop::~Shop()
{

}

//------------------------------------------------------------------------------
int Shop::execute(Game& board, std::vector<std::string>& params)
{ 
  //If user have entered parameters
  if (params.size() != 0)
  {
    //saves string from parameter
    std::string parameter_string = params[0];
    unsigned int temp = 0;
    //initializes a unsgined int parameter which saves the ID of the tower
    unsigned int parameter = 0;
    
    //Makes the characters into unsigned int and saves it in parameter
    for(unsigned int it = 0; it < parameter_string.size() ; it++)
    {
    temp = static_cast<unsigned int>( parameter_string[it] ) - 48;
      temp = temp * pow(10, (parameter_string.size() - it - 1));
      parameter = parameter + temp;
    }
    //Checks if valid Tower-ID
    if(parameter > board.getVectorTowerType().size())
    {
      std::cout << "Error: invalid ID!" << std::endl;
    }
    else if(parameter > 0)
    {
    //when parameter is OK prints out the Towers information
      std::cout << "id:       " << parameter << std::endl;
      std::cout << "name:     " << 
      board.getVectorTowerType().at(parameter-1).getName() << std::endl;
      std::cout << "price:    " <<
      board.getVectorTowerType().at(parameter-1).getPrice() << 
      " $" << std::endl;
      std::cout << "damage:   " <<
      board.getVectorTowerType().at(parameter-1).getDamage() << std::endl;
      std::cout << "range:    " <<
      board.getVectorTowerType().at(parameter-1).getRange() << std::endl;
      std::cout << "speed:    " <<
      board.getVectorTowerType().at(parameter-1).getFirespeed().getNumerator()
      << "/" << 
      board.getVectorTowerType().at(parameter-1).getFirespeed().getDenominator()
      << std::endl;
      std::cout << "range:    " <<
      board.getVectorTowerType().at(parameter-1).getRange() << std::endl;
      std::cout << "requires: nothing" << std::endl;
      std::cout << "upgrades: none" << std::endl;
    }
    else
    {
      std::cout << "Error: invalid ID!" << std::endl;
    }
  }
  else
  {
    //If no paramater, prints out Towers name and ID
    for(unsigned int it = 0; it < board.getVectorTowerType().size(); it++)
    {
      std::cout << it + 1 << ": " << board.getVectorTowerType().at(it).getName()
      << std::endl;
    }
  }
  return 0;
}

