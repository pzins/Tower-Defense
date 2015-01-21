//------------------------------------------------------------------------------
// Filename: Buy.cpp
// Description: Class representing command: Buy
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors:
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Buy.h"
#include "Coordinate.h"
#include "Game.h"
#include "Next.h"


//------------------------------------------------------------------------------
Buy::Buy() : Command("Buy")
{

}

//------------------------------------------------------------------------------
Buy::~Buy()
{

}


//------------------------------------------------------------------------------
int Buy::execute(Game& board, std::vector<std::string>& params)
{
  //If user have entered parameters
  if (params.size() == 2)
  {
    std::istringstream iss(params[0]);
    int parametre;
    iss >> parametre;

    // Test to verify that the parameter is a number and not letters or symbols
    bool test_param_number = true;
    if (params[0] > "9" || params[0] < "0")
    {
      test_param_number = false;
    }

    unsigned int type_of_tower = parametre;
    std::string  coordinate = params.at(1);

    //test if the coordianates entered are correct
    bool test_coordinate_correct = true;
    if (coordinate.size() != 2 || !(coordinate[0] < 'z' && coordinate[0] > 'a')
     || !(coordinate[1] < '9' && coordinate[1] > '0'))
    {
      test_coordinate_correct = false;
    }

    unsigned int x_coordinate = static_cast<unsigned int>(coordinate[0]) - 97;
    unsigned int y_coordinate = static_cast<unsigned int>(coordinate[1]) - 49;

    //error if the first parameter is not a number.
    if (!test_param_number && test_coordinate_correct)
    {
      return WRONG_PARAMETER_TYPE;
    }

    // if the Id given does not exist
    if (type_of_tower > board.getVectorTowerType().size() || type_of_tower < 1)
    {
      return INVALID_ID;
    }

    //test if the coordinate are not out of the map
    bool is_out_of_map = false;
    if (x_coordinate >= board.getVectorMap().at(board.getMap_id() - 1)
      .getWidth() || y_coordinate >= board.getVectorMap()
      .at(board.getMap_id() - 1).getHeight()) is_out_of_map = true;
    if (is_out_of_map)
    {
      return INVALID_COORDINATES;
    }

    std::vector<unsigned int> fields_vector = board.getVectorMap()
                                              .at(board.getMap_id() - 1)
                                              .getFields();

    unsigned int position = fields_vector.at(y_coordinate * board.getVectorMap()
                            .at(board.getMap_id() - 1).getWidth() 
                            + x_coordinate);


    //test if there is not other monster or tower in these coordinates
    bool is_monster_here = false;
    bool is_tower_here = false;

    for (unsigned int it = 0; it < board.getVectorMonster().size(); ++it)
    {
      unsigned int x_coo = board.getVectorMonster().at(it).getCoordinate()
                           .getX();
      unsigned int y_coo = board.getVectorMonster().at(it).getCoordinate()
                           .getY();

      if ((y_coo * board.getVectorMap().at(board.getMap_id() - 1).getWidth() 
        + x_coo) == y_coordinate * board.getVectorMap().at(board.getMap_id()
        - 1).getWidth() + x_coordinate) is_monster_here = true;
    }
    for (unsigned int it = 0; it < board.getVectorTower().size(); ++it)
    {
      
      unsigned int x_coo = board.getVectorTower().at(it).getCoordinate().getX();
      unsigned int y_coo = board.getVectorTower().at(it).getCoordinate().getY();
      
      if ((y_coo * board.getVectorMap().at(board.getMap_id() - 1).getWidth() 
        + x_coo) == y_coordinate * board.getVectorMap().at(board.getMap_id() 
        - 1).getWidth() + x_coordinate) is_tower_here = true;
    }

    if ((position >= 1 && position <= 7) || is_tower_here || is_monster_here)
    {
      return INVALID_COORDINATES;
    }
    //construction of the new tower

    else 
    {
      Tower* tower = new Tower();
      tower->setName(board.getVectorTowerType().at(type_of_tower - 1 )
        .getName());
      tower->setPrice(board.getVectorTowerType().at(type_of_tower - 1)
        .getPrice());
      tower->setDamage(board.getVectorTowerType().at(type_of_tower - 1)
        .getDamage());
      tower->setRange(board.getVectorTowerType().at(type_of_tower - 1)
        .getRange());
      tower->setFirespeed(board.getVectorTowerType().at(type_of_tower - 1)
        .getFirespeed());
      Ratio ratio(0,0);
      tower->setFirepoint(ratio);
      tower->setUpgradefromid(board.getVectorTowerType().at(type_of_tower - 1)
        .getUpgradefromid());
      tower->setAttributes(board.getVectorTowerType().at(type_of_tower - 1)
        .getAttribute());
      tower->setGame(&board);
      Coordinate coord;
      coord.setX(x_coordinate);
      coord.setY(y_coordinate);
      tower->setCoordinate(coord);

      if (board.getCash() >= tower->getPrice())
      {
        //test if the game is already won or lost
        if (Next::is_dead_) return ALREADY_DEAD;
        if (Next::is_won_) return ALREADY_WON;
        board.setCash(board.getCash() - tower->getPrice());
        board.addTower(tower);
        std::cout << "Building new " << tower->getName() << " at " 
        << tower->getCoordinate().mapCoordinateX() 
        << tower->getCoordinate().mapCoordinateY() << " for " 
        << tower->getPrice() << " $." << std::endl;
      }
      else 
      {
        return NOT_ENOUGH_MONEY;
      }
      return 0; 
    }
  }
  else
  {
    return WRONG_PARAMETER_COUNT;
  }
}

