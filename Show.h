//------------------------------------------------------------------------------
// Filename: Show.h
// Description: Class representing command: Show
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors: 
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#ifndef SHOW_H
#define SHOW_H

#include "Command.h"
#include "Game.h"


class Show : public Command
{
  public:

  	//--------------------------------------------------------------------------
    // Constructor
  	//
    Show();

    //--------------------------------------------------------------------------
    // Virtual Destructor
    //
    virtual ~Show();

    //--------------------------------------------------------------------------
    // Executes the command.
    // Shows the game field.
    // @param board The board where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action
    int execute(Game& board, std::vector<std::string>& params);
};

#endif
