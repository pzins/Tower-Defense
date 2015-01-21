//------------------------------------------------------------------------------
// Filename: Next.h
// Description: Class representing command: Next
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors: 
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#ifndef NEXT_H
#define NEXT_H

#include "Command.h"



class Next : public Command
{

  public:
    Next();
    static bool is_dead_;
    static bool is_won_;

    virtual ~Next();



    int execute(Game& board, std::vector<std::string>& params);
};

#endif
