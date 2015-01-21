//------------------------------------------------------------------------------
// Filename: main.cpp
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors:
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//
#include <iostream>
#include "Game.h"
#include "Monster.h"
#include "Tower.h"
#include "Command.h"

//------------------------------------------------------------------------------



int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "Error: Wrong Argument Count: \"./towerdefense <Levelfile>"
   << "<DB-File> [-b]\"" << std::endl;
        return 1;
    }

    Game game( 0, 0, 0, 0, 0 );
		
		
		game.run(argv[1], argv[2]);
    
		return 0;
}
