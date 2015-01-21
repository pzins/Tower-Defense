//------------------------------------------------------------------------------
// Filename: Monster.h
// Description: Class representing a monster
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors:
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#ifndef MONSTER_H
#define MONSTER_H
#include "Ratio.h"
#include "Coordinate.h"

class Game;


class Monster
{
  private:
    std::string name_;
    unsigned int damage_;
    unsigned int life_;
    unsigned int reward_;
    Ratio move_point_;
    Ratio move_speed_;
    Game* game_;
    Coordinate coordinate_;
    unsigned int last_move_;

  public:

    //--------------------------------------------------------------------------
    // Constructor
    // @param name Name of the monster
    // @param damage Damage that monster causes
    // @param life Health points that monster has
    // @param game Pointer on object from class game
    // @param reward Amount of money earned when killing monster
    // @param move_point move points of monster
    // @param move_speed speed that monster moves in
    // @param Coordinate coordinate of the monster in the map
    //    
    Monster(std::string name, unsigned int damage, unsigned int life,
                 unsigned int reward, Ratio move_point, Ratio move_speed,Game* game, Coordinate coordinate);    


	  //--------------------------------------------------------------------------
    // Constructor
    //
    Monster();


    //--------------------------------------------------------------------------
    // Virtual Destructor
    //
    virtual ~Monster();

    //--------------------------------------------------------------------------
    // Copy Constructor
    //
    Monster(Monster const& original);

    //--------------------------------------------------------------------------
    // Getter Methods
    //

    std::string getName() const;

    unsigned int getDamage() const;

    unsigned int getLife() const;

    unsigned int getReward() const;

    Ratio getMovespeed() const;
    
    Ratio getMovepoint() const;

    Game* getGame() const;

    Coordinate getCoordinate() const;

    unsigned int getLastMove() const;

    //--------------------------------------------------------------------------
    // Setter Methods
    //

    void setName(std::string name);

    void setDamage(unsigned int damage);

    void setLife(unsigned int life);

    void setReward(unsigned int reward);

    void setMovespeed(Ratio move_speed);

    void setMovepoint(Ratio move_point);

    void setGame(Game* game);

    void setCoordinate(Coordinate coordinate);

    void setLastMove(unsigned int last_move);




    //--------------------------------------------------------------------------
    // move Method
    // @param board Pointer to the Game that is played	
    // @return the quantity of move
    //
    unsigned int move(Game& board);

};

#endif // MONSTER_H
