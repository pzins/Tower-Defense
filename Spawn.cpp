//------------------------------------------------------------------------------
// Filename: Spawn.cpp
// Description: Level, tells the start level
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors:
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#include <string>
#include <vector>
#include "Spawn.h"


//------------------------------------------------------------------------------
Spawn::Spawn() : tick_(0), monster_id_(0), coordinate_(0,0)
{

}

//------------------------------------------------------------------------------
Spawn::Spawn(unsigned int tick, unsigned int monster_id, Coordinate coordinate)
	: tick_(tick), monster_id_(monster_id), coordinate_(coordinate)
{

}

//---------------------------------------------------------------------------
Spawn::Spawn(const Spawn& original) 
	: tick_(original.tick_), monster_id_(original.monster_id_), 
		coordinate_(original.coordinate_)
{
	
}		

//---------------------------------------------------------------------------
Spawn::~Spawn()
{
	
}

//---------------------------------------------------------------------------
unsigned int Spawn::getTick() const
{
  return tick_;
}

//---------------------------------------------------------------------------
unsigned int Spawn::getMonsterId() const
{
  return monster_id_;
}

//---------------------------------------------------------------------------
Coordinate Spawn::getCoordinate() const
{
  return coordinate_;
}

void Spawn::setTick(unsigned int tick)
{
  tick_ = tick;
}

void Spawn::setMonsterId(unsigned int monster_id)
{
  monster_id_ = monster_id;
}

void Spawn::setCoordinate(Coordinate coordinate)
{
  coordinate_ = coordinate;
}
