//------------------------------------------------------------------------------
// Filename: Game.h
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors:
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#ifndef GAME_H
#define GAME_H
#include <vector>
#include <string>
#include <map>
#include "Map.h"
#include "Tower.h"
#include "Monster.h"


class Tower;
class Monster;
class Command;
class Spawn;
class Base;
class Coordinate;

const int WRONG_PARAMETER_TYPE = 1;
const int WRONG_PARAMETER_COUNT = 2;
const int QUIT = 3;
const int INVALID_NUMBER = 4;
const int DEAD = 5;
const int ALREADY_DEAD = 6;
const int GAME_WON = 7;
const int ALREADY_WON = 8;
const int INVALID_ID = 9;
const int INVALID_COORDINATES = 10;
const int NOT_ENOUGH_MONEY = 11;
const int NOTHING_HAPPENED_SO_FAR = 12;
class Game
{
  private:
	
	  //--------------------------------------------------------------------------
    // Cash of player
    //  
    unsigned int cash_;
		
    //--------------------------------------------------------------------------
    // Player health
    //  		
    unsigned int player_hp_;
		
    //--------------------------------------------------------------------------
    // The ID of map
    //  		
    unsigned int map_id_;
		
    //--------------------------------------------------------------------------
    // Coordinate for width
    //  
    unsigned int width_;
	
    //--------------------------------------------------------------------------
    // Coordinate for height
    //  
    unsigned int height_;
		
    //--------------------------------------------------------------------------
    // The Current tick
    //  
    unsigned int current_tick_;

    //--------------------------------------------------------------------------
    // two vector to save the Monsters (types), 
		// the Towers (types) and the different spawns
		//
    std::vector<Monster*> list_monster;
    std::vector<Monster*> list_monster_types;
    std::vector<Tower*> list_tower;
    std::vector<Tower*> list_tower_types;
    std::vector<Spawn*> list_spawn;
    std::vector<Map*> list_map;

		//--------------------------------------------------------------------------
    // a map to save the commands
		//
    std::map<std::string, Command*> list_command;

		//--------------------------------------------------------------------------
    // a map to save the paramters entered by the user
		//
    std::map<std::string, std::vector<std::string> > parameters;

    unsigned int ERROR_CODE;


  public:

    //--------------------------------------------------------------------------
    // Constructor
    // @param cash current cash
    // @param player_hp life of the player
    // @param map_id The id of the map that should be played
    // @param width width of the field
    // @param height height of the field
	//
    Game (unsigned int cash, unsigned int player_hp, unsigned int map_id,  
	      	unsigned int width, unsigned int height);
          
  	//--------------------------------------------------------------------------
    // Constructor
    // 
    Game ();
    
    //--------------------------------------------------------------------------
    // Deconstructor
    // 
    virtual ~Game ();
		
    unsigned int loadLevelSpawn(char* lvlfile);
    unsigned int loadMonsterTowerMap(char* dbfile);

    //--------------------------------------------------------------------------
    // Add a tower in the game
    // @param tower a pointer on a new tower
		//
    void addTower(Tower* tower);
    
    //--------------------------------------------------------------------------
    // Add a tower type in the game
    // @param tower a pointer on a new tower type
		//
    void addTower_type(Tower* tower);

    //--------------------------------------------------------------------------
    // Add a monster in the game
    // @param monster a pointer on a new monster
		//
    void addMonster(Monster* monster);
    
    //--------------------------------------------------------------------------
    // Add a monster type in the game
    // @param monster a pointer on a new monster type
		//
    void addMonster_type(Monster* monster);

    //--------------------------------------------------------------------------
    // Delete the monsters, the towers and the spawns
		//
    void delete_tower_monster();
    
    //--------------------------------------------------------------------------
    // Add a spawn to a list
    // @param spawn a pointer on a new spawn
		//
    void addSpawn( Spawn* spawn);

    //--------------------------------------------------------------------------
    // Add a Map to a list
    // @param map a pointer on a new map
		//
    void addMap( Map* map);

    //--------------------------------------------------------------------------
    // Start the game
    //
    void run(char* lvlfile, char* dbfile);

    //--------------------------------------------------------------------------
    // Getter Methods
    //
    unsigned int getCash() const;

    unsigned int getPlayer_hp() const;
    
    unsigned int getMap_id() const;

    unsigned int getWidth() const;

    unsigned int getHeight() const;

    unsigned int getCurrentTick() const;

    std::vector<Monster> getVectorMonster() const;

    std::vector<Monster*> getVectorMonster2() const;

    std::vector<Tower> getVectorTower() const;

    std::vector<Tower*> getVectorTower2() const;

    std::vector<Map> getVectorMap() const;

    std::vector<Spawn> getVectorSpawn() const;

    std::vector<Monster> getVectorMonsterType() const;

    std::vector<Tower> getVectorTowerType() const;

    //--------------------------------------------------------------------------
    // Setter Methods
    //
    void setCash(unsigned int cash);

    void setPlayer_hp(unsigned int player_hp);

    void setWidth(unsigned int width);
    
    void setMap_id(unsigned int map_id);

    void setHeight(unsigned int height);

    void setCurrentTick(int current_tick);
};

#endif
