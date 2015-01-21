//------------------------------------------------------------------------------
// Filename: Buy.h
// Description: Class representing command: Buy
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors: 
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#ifndef BUY_H
#define BUY_H

#include "Command.h"



class Buy : public Command
{
  public:
    Buy();
    virtual ~Buy();

    int execute(Game& board, std::vector<std::string>& params);


};

#endif