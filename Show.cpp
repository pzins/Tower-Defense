//------------------------------------------------------------------------------
// Filename: Show.cpp
// Description: Class representing command: Show
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
#include "Show.h"
#include "Spawn.h"
#include "Monster.h"
#include "Tower.h"

//------------------------------------------------------------------------------
Show::Show() : Command("Show")
{

}

//------------------------------------------------------------------------------
Show::~Show()
{
}

//------------------------------------------------------------------------------
int Show::execute(Game &board, std::vector<std::string> &params)
{
	if (params.size() == 0)
	{ 
		//Prints some infromation       
	  std::cout << "Tick: " << board.getCurrentTick() << " | Money: " 
	  << board.getCash() << " $ | Life: " << board.getPlayer_hp() << " HP" 
	  << std::endl;
		//A vector with the all the field "points" in
	  std::vector<unsigned int> fields_vector =
	  board.getVectorMap().at(board.getMap_id() - 1).getFields();
		//Saves whatever should be printed on the screen instead of corresspoing
		//number
	  for (unsigned int it = 0; it < fields_vector.size(); ++it)
	  {
		  switch (fields_vector.at(it))
			{
			  case 0 : fields_vector.at(it) = ' '; break;
			  case 1 : fields_vector.at(it) = 'R'; break;
			  case 2 : fields_vector.at(it) = 'B'; break;
			  case 3 : fields_vector.at(it) = '.'; break;
			  case 4 : fields_vector.at(it) = '.'; break;
			  case 5 : fields_vector.at(it) = '.'; break;
			  case 6 : fields_vector.at(it) = '.'; break;
			  case 7 : fields_vector.at(it) = '.'; break;
		  }
	  }
	  std::cout <<"  ";
		//First field point is the entrance point
	  fields_vector.at(0) = 'E';
		//Gets the vector of monsters and tower from game
	  std::vector<Monster> monster = board.getVectorMonster();
		std::vector<Tower> tower = board.getVectorTower();

	  std::vector<unsigned int> 
						number_monster(board.getVectorMap().at(board.getMap_id() - 1)
	          .getFields().size());
	
	  for (unsigned int ite = 0; ite < number_monster.size(); ++ite)
	  {
	    number_monster.at(ite) = 0;
	  }
	  //Saves the number of monsters that are at one point on the field
	  for (unsigned int it = 0; it < monster.size(); ++it)
	  { 
	  	if (monster.at(it).getLife() > 0)
	  	{
			  int coo_x = monster.at(it).getCoordinate().getX(); 
			  int coo_y = monster.at(it).getCoordinate().getY();
			  unsigned int position =
			  coo_y * board.getVectorMap().at(board.getMap_id() - 1).getWidth()
				+ coo_x;
			  number_monster.at(position)++;
			  fields_vector.at(
				coo_y * board.getVectorMap().at(board.getMap_id() - 1).getWidth() 
				+ coo_x) = static_cast<char>(number_monster.at(position) + 48);
	  	}
		}
		//Saves the number of towers that are at one point on the field
    for (unsigned int it = 0; it < tower.size(); ++it)
    {
        int coo_x = tower.at(it).getCoordinate().getX(); 
        int coo_y = tower.at(it).getCoordinate().getY();
        unsigned int position =
            coo_y * board.getVectorMap().at(board.getMap_id()-1).getWidth()
             + coo_x;
        fields_vector.at(position) = 'T';
    }


		//Printes out the field	
	  for (unsigned int it = 0; 
				 it < board.getVectorMap().at(board.getMap_id() - 1).getWidth();
				 ++it)
	  {
	  	if (it == board.getVectorMap().at(board.getMap_id() - 1).getWidth() - 1) 
	  	{
	  		std::cout << char(it + 97);
	  	}
	  	else std::cout << char(it + 97) << " ";
	  }
	  std::cout << std::endl;
	  for (unsigned int it = 0; it < board.getVectorMap().at(board.getMap_id() 
				 - 1).getHeight(); ++it)
	  {
	    std::cout << " ";
	    for (unsigned int ite = 0; 
					 ite < board.getVectorMap().at(board.getMap_id() - 1).getWidth();
					 ++ite)
	    {
	    	std::cout << "+-";
	    }
		    std::cout << "+" << std::endl;
		    std::cout << it + 1 << "|";
		    for (unsigned int iter = 0; 
						 iter < board.getVectorMap().at(board.getMap_id() - 1).getWidth();
		            ++iter)
	    {
        std::cout << static_cast<char>(fields_vector.at(iter +
        it * board.getVectorMap().at(board.getMap_id() - 1).getWidth())) 
				<< "|";
	    }
	    
	    std::cout << std::endl;
	  }
		std::cout << " +-+-+-+-+-+-+-+-+-+" << std::endl;
	
	  return 0;
	}
	else
	{
	  //If parameter (coordinate) is given, this gives the information on whats 
		//on that coordinate
	  std::string parameter = params.at(0);
	  char ch;
	  unsigned int temp = 0;
	  unsigned int position = 0;
	  unsigned int position_2 = 0;
	  unsigned int y_coord = 0;
	  unsigned int x_coord = 0;
	  bool flag = false;
	  ch = parameter[0];
	  
	  //transforms the coordinate to lower case
		std::transform(parameter.begin(), parameter.end(), parameter.begin(), 
									 ::tolower);
	  //Checks if the first part of coordinate is OK
	  if( ch >= 'a'  && ch <= 'z')
	  { 
	  	position = ( static_cast<unsigned int>(ch) - 96 - 1 );
	  }       
	  else
	  {
	    std::cout << "Error: invalid coordinate!" << std::endl;
	    return 0;
	  }
	  
	  //Converts the number part of coordination from char to unsigned intt
	  for(unsigned int it = 1; it < parameter.size() ; it++)
  	{	
  		temp = static_cast<unsigned int>( parameter[it] ) - 48;
  		temp = temp * pow(10, (parameter.size() - it - 1));
  		y_coord = y_coord + temp - 1;
  		x_coord = position;
  		position = position + y_coord * board.getWidth();
  	}
	  if(x_coord >= board.getWidth() || y_coord >= board.getHeight())
	  { 
      std::cout << "Error: invalid coordinate!" << std::endl;
      return 0;   
	  }
	  //Checks if a monster is on this position, if so it prints it
	  for(unsigned int it = 0; it < board.getVectorMonster().size(); it++)
	  {
	   	position_2 = board.getVectorMonster().at(it).getCoordinate().getX() + 
	      board.getVectorMonster().at(it).getCoordinate().getY()*board.getWidth();
	    if(position == position_2 && board.getVectorMonster().at(it)
	    	.getLife() > 0)
	    { 
        flag = true;
        std::cout << board.getVectorMonster().at(it).getName() <<" (damage: " 
				<< board.getVectorMonster().at(it).getDamage() << ", speed: "
        << board.getVectorMonster().at(it).getMovespeed().getNumerator() <<
				"/" << board.getVectorMonster().at(it).getMovespeed().getDenominator()
				<< ", reward: " << board.getVectorMonster().at(it).getReward() << 
				" $, HP: " << board.getVectorMonster().at(it).getLife() << ")" << 
				std::endl;
	    }       
	  }	  
		//Checks if a tower is on this position, if so it prints it
	  for(unsigned int it = 0; it < board.getVectorTower().size(); it++)
	  {
	   	position_2 = board.getVectorTower().at(it).getCoordinate().getX() + 
	      board.getVectorTower().at(it).getCoordinate().getY()*board.getWidth();
	    if(position == position_2)
	    { 
        flag = true;
        std::cout << board.getVectorTower().at(it).getName() <<" (damage: " 
				<< board.getVectorTower().at(it).getDamage() << ", range: " << board
				.getVectorTower().at(it).getRange() << " , speed: " << board
				.getVectorTower().at(it).getFirespeed().getNumerator() << "/" << board
				.getVectorTower().at(it).getFirespeed().getDenominator() << ")" 
				<< std::endl;
	    }       
	  }

	  
	  std::vector<unsigned int> fields_vector =
	      board.getVectorMap().at(board.getMap_id()-1).getFields();
		if(flag == false)
		{ 
		  flag = true;
	    switch (fields_vector.at(position))
	    {
	      case 0 : std::cout << 
				"This ground is empty. You should build something!" << std::endl; 
				break;
				
	      case 1 : std::cout <<
			  "Rocks are blocking the way. You cannot build here." <<std::endl; 
				break;
	      
				case 2 : std::cout <<
				"This is your stronghold. Protect it!" << std::endl; 
				break;
				
	      case 3 : std::cout << 
				"Here the monsters trample, nothing can be built here." << std::endl; 
				break;
				
	      case 4 : std::cout <<
				"Here the monsters trample, nothing can be built here." << std::endl; 
				break;
				
	      case 5 : std::cout <<
				"Here the monsters trample, nothing can be built here." << std::endl;
				break;
				
	      case 6 : std::cout <<
				"Here the monsters trample, nothing can be built here." << std::endl;
				break;
				
	      case 7 : std::cout <<
				"Here the monsters trample, nothing can be built here." << std::endl; 
				break;
	   	}
	  }
	}
	return 0;   
}
