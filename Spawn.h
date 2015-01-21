//------------------------------------------------------------------------------
// Filename: Spawn.h
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors: 
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#ifndef SPAWN_H
#define SPAWN_H

#include <algorithm>
#include "Coordinate.h"


class Monster;
class Tower;

class Spawn
{
private:
	unsigned int tick_;
	unsigned int monster_id_;
	Coordinate coordinate_;

public:
  //--------------------------------------------------------------------------
  // Constructor
  // @param tick at what tick the spawn should occur
  // @param monster_id which monster that should be spawned 
  // @param coordinates where the monster should be spawned
	//
  Spawn(unsigned int tick, unsigned int monster_id, Coordinate coordinate);

  Spawn();


	//---------------------------------------------------------------------------
  // Destructor
	//
	virtual ~Spawn();
	
	//---------------------------------------------------------------------------
  // Copy Constructor
  //
	Spawn(const Spawn& original);

	//---------------------------------------------------------------------------
	// Get methods
  unsigned int getTick() const;

  unsigned int getMonsterId() const;
  
  Coordinate getCoordinate() const;

  //---------------------------------------------------------------------------
  //Set methods
  void setTick(unsigned int tick);

  void setMonsterId(unsigned int monster_id);
  
  void setCoordinate(Coordinate coordinate);


	
};
#endif
