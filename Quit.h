//------------------------------------------------------------------------------
// Filename: Quit.h
// Description: Class representing command: Quit
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors: 
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#ifndef QUIT_H
#define QUIT_H

#include "Command.h"



class Quit : public Command
{
  public:

    //--------------------------------------------------------------------------
    // Constructor
    //
    Quit();

    //--------------------------------------------------------------------------
    // Virtual Destructor
    //
    virtual ~Quit();

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param board The board where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action
    int execute(Game& board, std::vector<std::string>& params);
};

#endif