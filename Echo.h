//------------------------------------------------------------------------------
// Filename: Echo.h
// Description: Class representing command: Echo
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors: 
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#ifndef ECHO_H
#define ECHO_H

#include "Command.h"



class Echo : public Command
{
  public:

    //--------------------------------------------------------------------------
    // Constructor
    //
    Echo();

    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Echo();

    //--------------------------------------------------------------------------
    // Executes the command.
    // @param board The board where action should be performed on
    // @param params Possible parameters neede for the execution
    int execute(Game& board, std::vector<std::string>& params);


};

#endif // ECHO_H