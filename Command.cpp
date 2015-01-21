//------------------------------------------------------------------------------
// Filename: Command.cpp
// Description: Class representing a general command
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors: 
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#include "Command.h"

//------------------------------------------------------------------------------
Command::Command(std::string name) : command_name_(name)
{

}

//------------------------------------------------------------------------------
Command::~Command()
{

}

//------------------------------------------------------------------------------
const std::string& Command::getName() const
{
  return command_name_;
}