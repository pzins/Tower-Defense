//------------------------------------------------------------------------------
// Filename: Coordinate.cpp
// Description: Class representing a coordinate
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors:
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#include <cstdlib>
#include <cmath>
#include "Coordinate.h"


//------------------------------------------------------------------------------
Coordinate::Coordinate() 
{

}

//------------------------------------------------------------------------------
Coordinate::Coordinate(unsigned int x_coordinate, unsigned int y_coordinate) : 
                       x_coordinate_(x_coordinate), y_coordinate_(y_coordinate)
{

}

//------------------------------------------------------------------------------
Coordinate::~Coordinate()
{

}

//------------------------------------------------------------------------------
Coordinate::Coordinate(const Coordinate &original) :
                       x_coordinate_(original.x_coordinate_),
                       y_coordinate_(original.y_coordinate_)
{

}

//------------------------------------------------------------------------------
unsigned int Coordinate::mapCoordinateY() const
{
  unsigned int y_coordinate = y_coordinate_;
  return ++y_coordinate;
}

//------------------------------------------------------------------------------
char Coordinate::mapCoordinateX() const
{
  char x_coordinate = static_cast<char>(x_coordinate_ + 97);
  return x_coordinate;
}

//------------------------------------------------------------------------------
double Coordinate::euclidDistance(Coordinate other)
{
  int delta_x = other.getX() - x_coordinate_;
  int delta_y = other.getY() - y_coordinate_;
  double distance = sqrt(delta_y * delta_y + delta_x * delta_x);
  return distance;
}

//------------------------------------------------------------------------------
unsigned int Coordinate::getX() const
{
  return x_coordinate_;
}

//------------------------------------------------------------------------------
unsigned int Coordinate::getY() const
{
  return y_coordinate_;
}

//------------------------------------------------------------------------------
void Coordinate::setX(unsigned int x_coordinate)
{
  x_coordinate_ = x_coordinate;
}

//------------------------------------------------------------------------------
void Coordinate::setY(unsigned int y_coordinate)
{
  y_coordinate_ = y_coordinate;
}
