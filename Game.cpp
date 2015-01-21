//------------------------------------------------------------------------------
// Filename: Game.cpp
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors:
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <string>
#include "Game.h"
#include "Map.h"
#include "Tower.h"
#include "Monster.h"
#include "Quit.h"
#include "Show.h"
#include "Echo.h"
#include "Next.h"
#include "Spawn.h"
#include "Ratio.h"
#include "Coordinate.h"
#include "Buy.h"
#include "Shop.h"
#include "Stats.h"
//------------------------------------------------------------------------------
Game::Game (unsigned int cash, unsigned int player_hp, unsigned int map_id,
            unsigned int width, unsigned int height)
  : cash_(cash),
    player_hp_(player_hp),
    map_id_(map_id),
    width_(width),
    height_(height),
    current_tick_(0)
{

}

//------------------------------------------------------------------------------
Game::Game()
{
  
}

//------------------------------------------------------------------------------
Game::~Game()
{
  
}

//------------------------------------------------------------------------------
void Game::addTower( Tower* tower)
{
  if(tower != NULL)
  {
    list_tower.push_back(tower);
  }
  else
  {
    ERROR_CODE = 8;
  }
}

//------------------------------------------------------------------------------
void Game::addTower_type(Tower* tower)
{
  if(tower != NULL)
  {
    list_tower_types.push_back(tower);
  }
  else
  {
    ERROR_CODE = 8;
  }
}

//------------------------------------------------------------------------------
void Game::addMonster( Monster* monster)
{
  if(monster != NULL)
  {
    list_monster.push_back(monster);
  }
  else
  {
    ERROR_CODE = 8;
  }
}

//------------------------------------------------------------------------------
void Game::addMonster_type( Monster* monster)
{
  if(monster != NULL)
  {
    list_monster_types.push_back(monster);
  }
  else
  {
    ERROR_CODE = 8;
  }
}

//------------------------------------------------------------------------------
void Game::addSpawn( Spawn* spawn)
{
  if(spawn != NULL)
  {
    list_spawn.push_back(spawn);
  }
  else
  {
    ERROR_CODE = 8;
  }
}

//------------------------------------------------------------------------------
void Game::addMap(Map* map)
{
  if(map != NULL)
  {
    list_map.push_back(map);
  }
  else
  {
    ERROR_CODE = 8;
  }
}

//------------------------------------------------------------------------------
void Game::delete_tower_monster()
{
  for (unsigned int it = 0; it < list_monster.size(); ++it)
  {
    delete list_monster.at(it);
  }

  for (unsigned int it = 0; it < list_tower.size(); ++it)
  {
    delete list_tower.at(it);
  }
  
  for (unsigned int it = 0; it < list_monster_types.size(); ++it)
  {
    delete list_monster_types.at(it);
  }

  for (unsigned int it = 0; it < list_tower_types.size(); ++it)
  {
    delete list_tower_types.at(it);
  }
  
  for (unsigned int it = 0; it < list_spawn.size(); ++it)
  {
    delete list_spawn.at(it);
  }
  
  for (unsigned int it = 0; it < list_map.size(); ++it)
  {
    delete list_map.at(it);
  }
  
}

//------------------------------------------------------------------------------
unsigned int Game::getCash() const
{
  return cash_;
}

//------------------------------------------------------------------------------
unsigned int Game::getPlayer_hp() const
{
  return player_hp_;
}

//------------------------------------------------------------------------------
unsigned int Game::getMap_id() const
{
  return map_id_;
}

//------------------------------------------------------------------------------
unsigned int Game::getWidth() const
{
  return width_;
}

//------------------------------------------------------------------------------
unsigned int Game::getHeight() const
{
  return height_;
}

//------------------------------------------------------------------------------
unsigned int Game::getCurrentTick() const
{
  return current_tick_;
}

//------------------------------------------------------------------------------
std::vector<Monster> Game::getVectorMonster() const
{
  std::vector<Monster> return_value;
  for (unsigned int it = 0; it < list_monster.size(); ++it)
  {
    Monster monster = *(list_monster.at(it));
    return_value.push_back(monster);
  }
  return return_value;
}

//------------------------------------------------------------------------------
std::vector<Monster*> Game::getVectorMonster2() const
{
  return list_monster;
}

//------------------------------------------------------------------------------
std::vector<Tower> Game::getVectorTower() const
{
  std::vector<Tower> return_value;
  for (unsigned int it = 0; it < list_tower.size(); ++it)
  {
    return_value.push_back(*(list_tower.at(it)));
  }
  return return_value;
}

//------------------------------------------------------------------------------
std::vector<Tower*> Game::getVectorTower2() const
{
  return list_tower;
}

//------------------------------------------------------------------------------
std::vector<Map> Game::getVectorMap() const
{
  std::vector<Map> return_value;
  for (unsigned int it = 0; it < list_map.size(); ++it)
  {
    return_value.push_back(*(list_map.at(it)));
  }
  return return_value;
}

//------------------------------------------------------------------------------
std::vector<Spawn> Game::getVectorSpawn() const
{
  std::vector<Spawn> return_value;
  for (unsigned int it = 0; it < list_spawn.size(); ++it)
  {
    return_value.push_back(*(list_spawn.at(it)));
  }
  return return_value;
}

//------------------------------------------------------------------------------
std::vector<Monster> Game::getVectorMonsterType() const
{
  std::vector<Monster> return_value;
  for (unsigned int it = 0; it < list_monster_types.size(); ++it)
  {
    return_value.push_back(*(list_monster_types.at(it)));
  }
  return return_value;
}

//------------------------------------------------------------------------------
std::vector<Tower> Game::getVectorTowerType() const
{
  std::vector<Tower> return_value;
  for (unsigned int it = 0; it < list_tower_types.size(); ++it)
  {
    return_value.push_back(*(list_tower_types.at(it)));
  }
  return return_value;
}

//------------------------------------------------------------------------------
void Game::setCash(unsigned int cash)
{
  cash_ = cash;
}

//------------------------------------------------------------------------------
void Game::setPlayer_hp(unsigned int player_hp)
{
  player_hp_ = player_hp;
}

//------------------------------------------------------------------------------
void Game::setMap_id(unsigned int map_id)
{
  map_id_ = map_id;
}

//------------------------------------------------------------------------------
void Game::setWidth(unsigned int width)
{
  width_ = width;
}

//------------------------------------------------------------------------------
void Game::setHeight(unsigned int height)
{
  height_ = height;
}

//------------------------------------------------------------------------------
void Game::setCurrentTick(int current_tick)
{
  current_tick_ = current_tick;
}

unsigned int Game::loadLevelSpawn(char* lvlfile)
{
  //----------------------------------------------------------------------------
  // load LVL file
  //

  char str_1[256];
  unsigned int uns_int = 0;
  unsigned int uns_int_2 = 0;
  ERROR_CODE = 0;
  const std::string str_2 = "PROG2014";
  const std::string level = "LEVEL";
  const std::string spawn = "SPAWN";
  bool flag = false;
  
  std::ifstream input (lvlfile, std::ios::in | std::ios::binary);
  
  if (!input.is_open()) 
    {
      ERROR_CODE = 3;
      return ERROR_CODE;
    } 
  
  input.read(str_1 , 8);
  str_1[8] = 0;
  
  if (str_1 != str_2)
    { 
      ERROR_CODE = 5;
      return ERROR_CODE;
    }
  
  while (input.is_open() && !input.eof())
  {
    uns_int = 0;
    uns_int_2 = 0;	
    input.read(str_1 , 8);	
    str_1[8] = 0;
    
    if( str_1 == level)
    {
      // checks if another level 
      if (flag)
      {
        ERROR_CODE = 5;
        return ERROR_CODE;
      }
      
      //reads Map ID
      input.read(str_1 , 4);
      uns_int = static_cast<unsigned int>(str_1[1]) + 
                static_cast<unsigned int>(str_1[0]);
      setMap_id(uns_int);
      setHeight(list_map.at(uns_int-1)->getHeight());
      setWidth(list_map.at(uns_int-1)->getWidth());
      if (uns_int == 0)
      {
        ERROR_CODE = 6;
        return ERROR_CODE;
      }
      //reads HP
      input.read(str_1 , 4);
      uns_int = static_cast<unsigned int>(str_1[1]) + 
                static_cast<unsigned int>(str_1[0]);
      setPlayer_hp(uns_int);
      //reads Money
      input.read(str_1 , 4);
      uns_int = static_cast<unsigned int>(str_1[1]) + 
                static_cast<unsigned int>(str_1[0]);
      setCash(uns_int);
      
      flag = true;
    }
    else if( str_1 == spawn)
    {
      Spawn* spawn = new Spawn;	
     
      //reads Tick
      input.read(str_1 , 4);
      uns_int = static_cast<unsigned int>(str_1[1]) + 
                static_cast<unsigned int>(str_1[0]);
      if(uns_int < 1)
      {
        ERROR_CODE = 5;
        return ERROR_CODE;
      }
      spawn->setTick(uns_int);
      //reads Monster ID
      input.read(str_1 , 4);
      uns_int = static_cast<unsigned int>(str_1[1]) + 
                static_cast<unsigned int>(str_1[0]);
      spawn->setMonsterId(uns_int);
      if (uns_int == 0)
      {
        ERROR_CODE = 6;
        return ERROR_CODE;
      }

      // Here we first need to fix a Coordinate class!
      
      //reads Coordinate 1
      input.read(str_1 , 4);
      uns_int = static_cast<unsigned int>(str_1[1]) + 
                static_cast<unsigned int>(str_1[0]);
      Coordinate coordinate;
      coordinate.setX(uns_int);

      //reads Coordinate 2
      input.read(str_1 , 4);
      uns_int_2 = static_cast<unsigned int>(str_1[1]) + 
                  static_cast<unsigned int>(str_1[0]);
      coordinate.setY(uns_int_2);
      spawn->setCoordinate(coordinate);

      if (coordinate.getX() >= width_ || coordinate.getY() >= height_)
      {
        ERROR_CODE = 7;
        return ERROR_CODE;
      }

      addSpawn(spawn);
      }
    else 
    {
      ERROR_CODE = 5;
      return ERROR_CODE;
    }
    input.peek();
  }
 
  input.close();
  return ERROR_CODE;
}


unsigned int Game::loadMonsterTowerMap(char* dbfile)
{
//------------------------------------------------------------------------------
// Load .db file!

  char str_1[256];
  const std::string str_2 = "PROG2014";
  unsigned int name_length = 0;
  unsigned int uns_int = 0;
  unsigned int uns_int_2 = 0;
  const std::string monster_1 = "MONSTER";
  const std::string tower_1 = "TOWER";
  const std::string map_1 = "MAP";
  
  ERROR_CODE = 0;
  std::ifstream input (dbfile, std::ios::in | std::ios::binary);
  
  if (!input.is_open()) 
  {
    ERROR_CODE = 2;
    return ERROR_CODE;
  }

  input.read(str_1 , 8);
  str_1[8] = 0;

  if( str_1 != str_2)
  { 
    ERROR_CODE = 4;
    return ERROR_CODE;
  }

  while (input.is_open() && !input.eof())
  {
    uns_int = 0;
    uns_int_2 = 0;	
    input.read(str_1 , 8);	
    str_1[8] = 0;
    
    
    if( str_1 == monster_1)
    {
      Monster* monster = new Monster;
      
      //reads name_length
      input.read(str_1,4);
      name_length = static_cast<unsigned int>(str_1[1]) + 
                    static_cast<unsigned int>(str_1[0]);
      //reads name
      input.read(str_1 , name_length);
      str_1[name_length] = 0;
      monster->setName(str_1); 
      
      
      Ratio move_speed;
      //reads Speed nomminator
      input.read(str_1 , 4);
      uns_int = static_cast<unsigned int>(str_1[1]) + 
                static_cast<unsigned int>(str_1[0]);
      move_speed.setNumerator(uns_int);
      //reads Speed denominator
      input.read(str_1 , 4);
      uns_int_2 = static_cast<unsigned int>(str_1[1]) + 
                  static_cast<unsigned int>(str_1[0]);
      move_speed.setDenominator(uns_int_2);
      monster->setMovespeed(move_speed);					
      
      //reads damage
      input.read(str_1 , 4);
      uns_int = static_cast<unsigned int>(str_1[1]) + 
                static_cast<unsigned int>(str_1[0]);
      monster->setDamage(uns_int);
      //reads HP
      input.read(str_1 , 4);
      uns_int = static_cast<unsigned int>(str_1[1]) + 
                static_cast<unsigned int>(str_1[0]);
      monster->setLife(uns_int);
      //reads Reward
      input.read(str_1 , 4);
      uns_int = static_cast<unsigned int>(str_1[1]) + 
                static_cast<unsigned int>(str_1[0]);
      monster->setReward(uns_int);
      
      Ratio move_point;
      move_point.setNumerator(0);
      move_point.setDenominator(0);
      monster->setMovepoint(move_point);

      addMonster_type(monster);
      
    }
    else if( str_1 == tower_1)
    {
      Tower* tower = new Tower;
      Ratio ratio;
      Ratio ratio_2;
      tower->setFirepoint(ratio_2);
      //tower->setGame(this);
      
      //reads name_length
      input.read(str_1,4);
      name_length = static_cast<unsigned int>(str_1[1]) + 
                    static_cast<unsigned int>(str_1[0]);
      
      //reads name
      input.read(str_1 , name_length);
      str_1[name_length] = 0;
      tower->setName(str_1);
      
      //reads cost
      input.read(str_1 , 4);
      uns_int = static_cast<unsigned int>(str_1[1]) + 
                static_cast<unsigned int>(str_1[0]);
      tower->setPrice(uns_int);
      
      //reads damage
      input.read(str_1 , 4);
      uns_int = static_cast<unsigned int>(str_1[1]) + 
                static_cast<unsigned int>(str_1[0]);
      tower->setDamage(uns_int);
      
      //reads range
      input.read(str_1 , 4);
      uns_int = static_cast<unsigned int>(str_1[1]) + 
                static_cast<unsigned int>(str_1[0]);
      tower->setRange(uns_int);
      
      //reads Firespeed nominator
      input.read(str_1 , 4);
      uns_int = static_cast<unsigned int>(str_1[1]) + 
                static_cast<unsigned int>(str_1[0]);
      ratio.setNumerator(uns_int);
      //reads Firespeed denominator
      input.read(str_1 , 4);
      uns_int_2 = static_cast<unsigned int>(str_1[1]) + 
                  static_cast<unsigned int>(str_1[0]);
      ratio.setDenominator(uns_int_2);
      tower->setFirespeed(ratio);
      
      //reads Upgrade from ID
      input.read(str_1 , 4);
      uns_int = static_cast<unsigned int>(str_1[1]) + 
                static_cast<unsigned int>(str_1[0]);
      tower->setUpgradefromid(uns_int);
 
      //reads Attributes
      input.read(str_1 , 4);
      uns_int = static_cast<unsigned int>(str_1[1]) + 
                static_cast<unsigned int>(str_1[0]);
      tower->setAttributes(uns_int);
      
      addTower_type(tower);
    }
    else if( str_1 == map_1)
    {
      Map* map = new Map;
      
      //reads Width
      input.read(str_1 , 4);
      uns_int = static_cast<unsigned int>(str_1[1]) + 
                static_cast<unsigned int>(str_1[0]);
      map->setWidth(uns_int);
      
      //reads Height
      input.read(str_1 , 4);
      uns_int_2 = static_cast<unsigned int>(str_1[1]) + 
                  static_cast<unsigned int>(str_1[0]);
      map->setHeight(uns_int_2);
      
      //read fields
      input.read(str_1 , (uns_int*uns_int_2));
      
      std::vector<unsigned int> vector;
      str_1[uns_int*uns_int_2] = 0;
      for (unsigned int it = 0; it < (uns_int * uns_int_2); it++)
      {
        vector.push_back(static_cast<unsigned int>(str_1[it])); 
      }
      
      map->setFields(vector);
      
      addMap(map);
      
    }
    else
    {
      ERROR_CODE = 4;
      return ERROR_CODE;
    }
    input.peek();  
  }

  input.close();
  return ERROR_CODE;
}

//------------------------------------------------------------------------------
void Game::run(char* lvlfile, char* dbfile)
{
  unsigned int return_value1 = loadMonsterTowerMap(dbfile);

  unsigned int return_value2 = loadLevelSpawn(lvlfile);




  Quit* quit = new Quit;
  Show* show = new Show;
  Echo* echo = new Echo;
  Next* next = new Next;
  Shop* shop = new Shop;
  Buy* buy = new Buy;
  Stats* stats = new Stats;


  const std::string ECHO_COMMAND = "echo";
  const std::string SHOW_COMMAND = "show";
  const std::string QUIT_COMMAD = "quit";
  const std::string NEXT_COMMAND = "next";
  const std::string SHOP_COMMAND = "shop";
  const std::string BUY_COMMAND = "buy";
  const std::string STATS_COMMAND = "stats";

  if (quit == NULL || show == NULL || echo == NULL || next == NULL || 
      shop == NULL || buy == NULL || stats == NULL)
  {
    std::cout << "Out of mana!" << std::endl;
  }

  // save every command in the map list_command
  list_command[ECHO_COMMAND] = echo;
  list_command[SHOW_COMMAND] = show;
  list_command[QUIT_COMMAD] = quit;
  list_command[NEXT_COMMAND] = next;
	list_command[SHOP_COMMAND] = shop;
  list_command[BUY_COMMAND] = buy;
  list_command[STATS_COMMAND] = stats;


  // reset the current_tick
  setCurrentTick(0);

  
  while (true)
  {
  	// test errors in tower.db	
    if (return_value1 == 2)
    {
      std::cout << "Error: Database file cannot be opened!" << std::endl;
    }
    else if (return_value1 == 4)
    {
      std::cout << "Error: Database file corrupt!" << std::endl;
    }
    else if (return_value1 == 8)
    {
      std::cout << "Error: Out of Mana!" << std::endl; 
    }
		
    // test errors in tower.lvl
    if (return_value2 == 3)
    {
      std::cout << "Error: Level file cannot be opened!" << std::endl;
      break;
    }
    else if (return_value2 == 5)
    {
      std::cout << "Error: Level file corrupt!" << std::endl;
      break;
    }
    else if (return_value2 == 6)
    {
      std::cout << "Error: Level file corrupt! ID does not exist!" << std::endl;
      break;
    }
    else if (return_value2 == 7)
    {
      std::cout << "Error: Level file corrupt! Coordinate invalid!" 
        << std::endl;
      break; 
    }
    // clear the vectors of parameters of every command
    parameters[ECHO_COMMAND].clear();
    parameters[NEXT_COMMAND].clear();
    parameters[SHOW_COMMAND].clear();
    parameters[QUIT_COMMAD].clear();
		parameters[SHOP_COMMAND].clear();
    parameters[BUY_COMMAND].clear();
    parameters[STATS_COMMAND].clear();

    int return_value = 0;
    std::string name_command;
    std::string name_command_ln;
    std::cout << "sep> ";
    getline(std::cin, name_command_ln);  //to get the command and parameters

    // detect if no command is entered
    if (name_command_ln.size() == 0)
    {
      continue;
    }

    bool detect_command = true;  //detect if it is command or parameters

    // a temporal string to save the name of the command or the parameters
    // extract from the getline()
    std::string temporal_string = "";

    unsigned int it = 0;  // iterator
    // loop while to extract the command and parameters from the getline
    // name_command : the name of the command entered
    // parameters["name_command"] : parameters entered
    while (it < name_command_ln.size())
    {
      // Loop to get the name of the command or the parameters
      while ((name_command_ln[it] != ' ') && (it < name_command_ln.size()))
      {
        temporal_string += name_command_ln[it];
        ++it;
      }
      ++it;  // to jump the space

      // detect if temporal_string contains a command or a parameters
      // the first time it is a command
      // and then it is a parameter
      if (detect_command)
      {
      // to transform the command to lower case
      transform(temporal_string.begin(), temporal_string.end(),
                temporal_string.begin(), ::tolower);
        name_command = temporal_string;
      }
      else
      {
        parameters[name_command].push_back(temporal_string);
      }
      temporal_string = "";  // to reset temporal_string
      // detect_command become false at the end of the first loop
      // to know that after we save parameters
      detect_command = false;
    }

    // next without parameter is equivalent to : next 1
    // so there is always a defaut parameter 1 in this vector
    parameters[NEXT_COMMAND].push_back("1");

    // Loop and bool test_command to know if the command entered exists
    bool test_command = false;
    for (std::map<std::string, Command*>::iterator it = list_command.begin();
         it != list_command.end(); it++)
    {
      if (name_command == it->first)
      {
        test_command = true;
      }
    }

    if (test_command)
    {
      return_value = list_command[name_command]->execute(*this,
                     parameters[name_command]);

      // case when there is a problem with the number of parameters
      if (return_value == WRONG_PARAMETER_COUNT)
      {
        std::cout << "Error: Wrong parameter count!" << std::endl;
      }

      else if (return_value == WRONG_PARAMETER_TYPE)
      {
        std::cout << "Error: Wrong parameter type!" << std::endl;
      }
      else if (return_value == INVALID_NUMBER)
      {
        std::cout << "Error: invalid number!" << std::endl;
      }
      else if (return_value == QUIT)
      {
      	return_value1 = 0;
        break;
      }
      else if (return_value == DEAD)
      {
        std::cout << "You die." << std::endl;
      }
      else if (return_value == ALREADY_DEAD)
      {
        std::cout << "Error: You are already dead!" << std::endl;
      }
      else if (return_value == GAME_WON)
      {
        std::cout << "You survive and beat the challenge!" << std::endl;
      }
      else if (return_value == ALREADY_WON)
      {
        std::cout << "Error: You already won!" << std::endl;
      }
      else if (return_value == INVALID_ID)
      {
        std::cout << "Error: invalid ID!" << std::endl;
      }
      else if (return_value == INVALID_COORDINATES)
      {
        std::cout << "Error: invalid coordinate!" << std::endl;
      }
      else if (return_value == NOT_ENOUGH_MONEY)
      {
        std::cout << "Error: You don\'t have enough money!" << std::endl;
      }
      else if (return_value == NOTHING_HAPPENED_SO_FAR)
      {
        std::cout << "Error: Nothing happend so far!" << std::endl;
      }
    }

    else
    {
      std::cout << "Error: Unknown command!" << std::endl;
    }
  }

  delete next;
  delete echo;
  delete show;
  delete quit;
  delete shop;
  delete buy;
  delete stats;

  delete_tower_monster();
  
}

