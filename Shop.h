//------------------------------------------------------------------------------
// Filename: Shop.h
// Description: Class representing command: Shop
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors: 
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#ifndef SHOP_H
#define SHOP_H

#include "Command.h"
#include "Game.h"



class Shop : public Command
{
  public:
  	
    //--------------------------------------------------------------------------
    // Constructor
  	//	
    Shop();
    
		//--------------------------------------------------------------------------
    // Virtual Destructor
    //
		virtual ~Shop();

		//--------------------------------------------------------------------------
    // Executes the command.
    // Shows the different types of Towers, and if parameter is used (Tower-ID)
    // it shows the towers information.
    // @param board The board where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action
    int execute(Game& board, std::vector<std::string>& params);


};

#endif
