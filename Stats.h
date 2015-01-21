//------------------------------------------------------------------------------
// Filename: Stats.h
// Description: Class representing command: Stats
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors: 
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#ifndef STATS_H
#define STATS_H

#include "Command.h"



class Stats : public Command
{
  public:
  
    //--------------------------------------------------------------------------
    // Constructor
    //
    Stats();
    
    //--------------------------------------------------------------------------
    // Virtual Destructor
    //
    virtual ~Stats();

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param board The board where action should be performed on
    // @param params Possible parameters neede for the execution
    int execute(Game& board, std::vector<std::string>& params);

};

#endif // STATS_H