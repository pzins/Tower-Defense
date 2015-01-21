//------------------------------------------------------------------------------
// Filename: Map.cpp
// Description: Class representing the map
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors:
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#include <iostream>
#include <string>
#include "Game.h"
#include "Map.h"


//------------------------------------------------------------------------------
Map::Map(unsigned int width, unsigned int height,
         std::vector<unsigned int> fields)
         : width_(width), height_(height), fields_(fields)
{

}

//------------------------------------------------------------------------------
Map::Map()
{

}

//------------------------------------------------------------------------------
Map::~Map()
{

}

//------------------------------------------------------------------------------
void Map::setWidth(unsigned int width)
{
  width_ = width;
}

//------------------------------------------------------------------------------
void Map::setHeight(unsigned int height)
{
  height_ = height;
}

//------------------------------------------------------------------------------
void Map::setFields(std::vector<unsigned int> fields)
{
  fields_ = fields;
}

//------------------------------------------------------------------------------
unsigned int Map::getWidth() const
{
  return width_;
}

//------------------------------------------------------------------------------
unsigned int Map::getHeight() const
{
  return height_;
}

//------------------------------------------------------------------------------
std::vector<unsigned int> Map::getFields() const
{
  return fields_;
}

