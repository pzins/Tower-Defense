//------------------------------------------------------------------------------
// Filename: Tower.h
// Description: Class representing a tower
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors: 
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#ifndef TOWER_H
#define TOWER_H
#include <string>
#include "Ratio.h"
#include "Coordinate.h"
#include "Monster.h"

class Game;


class Tower
{
  private:
    std::string name_;
    unsigned int price_;
    unsigned int damage_;
    unsigned int range_;
    unsigned int speed_;
    Ratio fire_point_;
    Ratio fire_speed_;
    unsigned int upgrade_from_id_;
    unsigned int attributes_;
    Game* game_;
    Coordinate coordinate_;


  public:

    //--------------------------------------------------------------------------
    // Constructor
    // @param name Name of the tower
    // @param price Price of tower
    // @param damage Damage of the tower
    // @param range  Range of the tower
    // @param fire_point the towers fire points
    // @param fire_speed the towers fire speed
    // @param upgrade_from_id
    // @param attributes
    // @param game Pointer on object from class game
    // @param coordinate coordinates of where the tower build
    Tower(std::string name, unsigned int price, unsigned int damage,
          unsigned int range, Ratio fire_point, Ratio fire_speed, 
          unsigned int upgrade_from_id, unsigned int attributes, 
          Game* game, Coordinate coordinate);    

		//--------------------------------------------------------------------------
    // Constructor
    //
    Tower();

    //--------------------------------------------------------------------------
    // Virtual Destructor
    //
    virtual ~Tower();


    //--------------------------------------------------------------------------
    // Copy Constructor
    //
    Tower(Tower const& original);



    //--------------------------------------------------------------------------
    // Getter Methods
    //
    std::string getName() const;

    unsigned int getDamage() const;

    unsigned int getRange() const;
    
    unsigned int getPrice() const;
    
    Ratio getFirepoint() const;
    
    Ratio getFirespeed() const;
    
    unsigned int getUpgradefromid() const;
    
    unsigned int getAttribute() const;

    Game* getGame() const;

    Coordinate getCoordinate() const;

    //--------------------------------------------------------------------------
    // Setter Methods
    //
    void setName(std::string name);

    void setDamage(unsigned int damage);

    void setRange(unsigned int range);
    
    void setPrice(unsigned int price);

    void setFirepoint(Ratio ratio);
    
    void setFirespeed(Ratio ratio);

    void setUpgradefromid(unsigned int upgrade_from_id);

    void setAttributes(unsigned int attributes);

    void setGame(Game* game);

    void setCoordinate(Coordinate coordinate);

    //--------------------------------------------------------------------------
    // fire Method
    // @param monster pointer to monster that is fired on
    // @return 1 if monster is dead, 0 if not
    //
    unsigned int fire(Monster& monster);
};


#endif // TOWER_H
