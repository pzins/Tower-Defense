//------------------------------------------------------------------------------
// Filename: Echo.cpp
// Description: Class representing command: Echo
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
#include <vector>
#include "Echo.h"
#include "Game.h"


//------------------------------------------------------------------------------
Echo::Echo() : Command("Echo")
{

}

//------------------------------------------------------------------------------
Echo::~Echo()
{

}

//------------------------------------------------------------------------------
int Echo::execute(Game& board, std::vector<std::string>& params)
{
  //If user have entered parameters
  if (params.size() != 0)
  {
    //Prints the different paramters with "|" inbetewen
    bool test(false);
    for (unsigned int it = 0; it < params.size(); ++it)
    {
      if (test)
      {
        std::cout << "|";
      }
      std::cout << params.at(it);
      if (!(test))
      {
        test = true;
      }
    }
    std::cout << std::endl;
    return 0;
  }
  else
  {
    return WRONG_PARAMETER_COUNT;
  }
}

