//------------------------------------------------------------------------------
// Filename: Quit.cpp
// Description: Class representing command: Quit
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
#include "Quit.h"
#include "Game.h"

//------------------------------------------------------------------------------
Quit::Quit() : Command("Quit")
{

}

//------------------------------------------------------------------------------
Quit::~Quit()
{

}

//------------------------------------------------------------------------------
int Quit::execute(Game& board, std::vector<std::string>& params)
{
  if (params.size() == 0)
  {
    std::cout << "Thanks for playing, bye!" << std::endl;
    return QUIT;  // to quit the program
  }

  // if quit is entered with one or more parameters
  // there is the error : Wrong paramter
  else
  {
    return WRONG_PARAMETER_COUNT;
  }
}

