//------------------------------------------------------------------------------
// Filename: Next.cpp
// Description: Class representing command: Next
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
#include "Next.h"
#include "Game.h"
#include "Tower.h"
#include "Monster.h"
#include "Spawn.h"
#include "Coordinate.h"

//------------------------------------------------------------------------------
Next::Next() : Command("Next")
{

}

//------------------------------------------------------------------------------
Next::~Next()
{

}

// initialization of static members
  bool Next::is_dead_ = false;
  bool Next::is_won_ = false;

//------------------------------------------------------------------------------
int Next::execute(Game& board, std::vector<std::string>& params)
{

  // test if the player has already won or lost the game
  if (is_dead_) return ALREADY_DEAD;
  if (is_won_) return ALREADY_WON;

  //Save the parameter as an INT
  std::istringstream iss(params[0]);
  int parametre;
  iss >> parametre;

  // Test to verify that the parameter is a number and not letters or symbols
  bool test_param_number = true;
  if (params[0] > "9" || params[0] < "0")
  {
    test_param_number = false;
  }

  //error if more than 2 parameters or if the parameters are NOT numbers.
  if (params.size() > 2 || (!test_param_number))
  {
    parametre = -1;
  }
  //If everything OK, we go through the amount of rounds 
  //that the parameter value says we should
  if (parametre > 0)
  {
    //Loop as many times as the parameters says
    for (int iterator = 1; iterator <= parametre; ++iterator)
    {
      //Add one to current tick
      int current_tick = board.getCurrentTick() + 1;
      board.setCurrentTick(current_tick);


      //Fire every tower and give on screen
      for (unsigned int it = 0; it < (board.getVectorTower()).size(); ++it)
      {
        if (board.getCurrentTick() > 0)
        {
          //increase fire points by fire speed
          board.getVectorTower2().at(it)->setFirepoint(board
            .getVectorTower().at(it).getFirepoint() + board.getVectorTower()
            .at(it).getFirespeed());
          Ratio temp_ratio(1,1);
          //bool test to know if one or more tower can be shooted by the tower
          bool test_in_range = false;
          for (unsigned int iter = 0; iter < board.getVectorMonster().size();
           ++iter)
          {
            if (board.getVectorMonster().at(iter).getLife() != 0)
            {
              test_in_range = (static_cast<double>(board.getVectorTower()
                              .at(it).getRange()) >= board.getVectorTower()
                              .at(it).getCoordinate().euclidDistance(board
                              .getVectorMonster().at(iter).getCoordinate()));
              if (test_in_range) break;
            }
          }


          while (board.getVectorTower().at(it).getFirepoint()  >= 
              temp_ratio && test_in_range) 
          {
            // position of the monster which will be shooted
            unsigned int monster_shooted(0);

            //to get the closer monster from a tower
            double distance_eucli_1;
            double distance_eucli_2;
            distance_eucli_1 = 1000000;

            for (unsigned int ite = 0; ite < board.getVectorMonster().size();
              ++ite)
            {
              if (board.getVectorMonster().at(ite).getLife() != 0)
              {
                distance_eucli_2 = board.getVectorTower().at(it).getCoordinate()
                                   .euclidDistance(board.getVectorMonster()
                                   .at(ite).getCoordinate());
                if (distance_eucli_2 < distance_eucli_1)
                {
                  monster_shooted = ite;              
                  distance_eucli_1 = distance_eucli_2;
                } 
              }
            }
            //tower fires
            unsigned int dead = board.getVectorTower2().at(it)->fire(*(board
                                .getVectorMonster2().at(monster_shooted)));

            Tower tower = board.getVectorTower().at(it);
            Monster monster = board.getVectorMonster().at(monster_shooted);

            std::cout << tower.getName() << "(" << tower.getCoordinate()
              .mapCoordinateX() << tower.getCoordinate().mapCoordinateY() 
              << ") fires at " << monster.getName() << "(" << monster
              .getCoordinate().mapCoordinateX()  << monster.getCoordinate()
              .mapCoordinateY() << ")." << std::endl;

            //if the monster is dead
            if (dead == 1)
            {
            	board.setCash(board.getCash() + monster.getReward());
              std::cout << "The monster takes " << tower.getDamage() 
              << " damage" << " and dies." << std::endl;
            }
            else
            {
              std::cout << "The monster takes " << tower.getDamage() 
              << " damage" <<  " and survives with " << monster.getLife() 
              << " HP." << std::endl;
            }
            std::cout << std::endl;

            // the fire points are decreased by 1/1
            board.getVectorTower2().at(it)->setFirepoint(board.getVectorTower()
              .at(it).getFirepoint() - temp_ratio);

            

          }
          
        }

      }

      //Move every monster and show on screen
      for (unsigned int it = 0; it < board.getVectorMonster().size() 
        ; ++it)
      {
        // increase the movepoints by movespeed
        Ratio movepoints = board.getVectorMonster()
                           .at(it).getMovepoint() + board.getVectorMonster()
                           .at(it).getMovespeed();
        board.getVectorMonster2().at(it)->setMovepoint(movepoints);

        Ratio temp_ratio(1,1);
        while ((board.getVectorMonster().at(it).getMovepoint() >= temp_ratio) 
          && board.getVectorMonster2().at(it)->getLife() != 0)
        {
          // decrease the movepoints by 1/1
          board.getVectorMonster2().at(it)->setMovepoint(board
            .getVectorMonster().at(it).getMovepoint() - temp_ratio);

          unsigned int result = board.getVectorMonster2().at(it)->move(board);

          if (result == 1)
          {
            Monster temp_monster = board.getVectorMonster().at(it);
            board.setPlayer_hp(board.getPlayer_hp() - board.getVectorMonster()
              .at(it).getDamage());
            std::cout << "Arr! " << temp_monster.getName() <<
            " attacks your base and deals " << temp_monster.getDamage() << 
            " damage (" << board.getPlayer_hp() << " HP remaining)." 
            << std::endl;
            // if the player is dead
            if (board.getPlayer_hp() <= 0)
            {
              is_dead_ = true;
              return DEAD;
            }
          }
          else if (result == 0)
          {
            // the monster dies
            board.getVectorMonster().at(it).setLife(0);
          }
        }
      }



            // creation of new monster
     // unsigned int number_of_monster_entered(0);
      for (unsigned int it = 0; it < board.getVectorSpawn().size(); ++it)
      {
        //test if the monster can be added
        if (board.getVectorSpawn().at(it).getTick() == board.getCurrentTick())
        {
          unsigned int id = board.getVectorSpawn().at(it).getMonsterId();
            Monster monstertype = board.getVectorMonsterType().at(id - 1);
            Monster* monster = new Monster(monstertype.getName(), 
                               monstertype.getDamage(), monstertype.getLife(), 
                                monstertype.getReward(), monstertype
                                .getMovepoint(), monstertype.getMovespeed(),
                                &board, board.getVectorSpawn().at(it)
                                .getCoordinate());
            board.addMonster(monster);
            
            std::cout << "Be careful! " << monster->getName() 
            << " enters the dungeon at " 
            << monster->getCoordinate().mapCoordinateX() 
            << monster->getCoordinate().mapCoordinateY() << "." 
            << std::endl;

           // ++number_of_monster_entered;
          }
      }  
      // test to know if all monsters are dead
      bool all_monster_dead = true;
      for (unsigned int it = 0; it < board.getVectorMonster().size(); ++it)
      {
        if (board.getVectorMonster().at(it).getLife() != 0)
        {
          all_monster_dead = false;
        }
      }
      if (all_monster_dead) 
      {
        Next::is_won_ = true;
        return GAME_WON;
      }
    }
  }
  //If parameter put in is = 0 give back 0 and just show prompt on screen
  else if (parametre == 0)
  {
    return 0;
  }
  //If more than 2 parameters, give error message.
  else if (params.size() > 2)
  {
    return WRONG_PARAMETER_COUNT;
  }
  //If wrong parameter type (not and number), give error message.
  else
  { 
    return INVALID_NUMBER;
  }
  return 0;
}
