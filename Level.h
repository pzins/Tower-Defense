//------------------------------------------------------------------------------
// Filename: Level.h
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors:
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#ifndef LEVEL_H
#define LEVEL_H

class Level
{
  private:
  
    //--------------------------------------------------------------------------
    // Level ID
    //  
    unsigned int id_;
    
    //--------------------------------------------------------------------------
    // Health Points
    //
    unsigned int hp_;
  
    //--------------------------------------------------------------------------
    // Money
    //
    unsigned int money_;

  public:
  
    //--------------------------------------------------------------------------
    // Constructor
    // @param ID Level ID
    // @param hp Health points
    // @param money  money
    //
    Level(unsigned int id, unsigned int hp, unsigned int money);
     
    //--------------------------------------------------------------------------
    // Constructor
    //
    Level();
    
    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Level();

    //--------------------------------------------------------------------------
    // Getter Methods
    //
    unsigned int getId() const;
  
    unsigned int getHp() const;
  
    unsigned int getMoney() const;

    //--------------------------------------------------------------------------
    // Setter Methods
    //
    void setId(unsigned int id);
  
    void setHp(unsigned int hp);
    
    void setMoney(unsigned int money);
};
#endif  // LEVEL_H
