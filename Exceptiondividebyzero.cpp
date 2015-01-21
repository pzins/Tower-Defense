//------------------------------------------------------------------------------
// Filename: Exceptiondividebyzero.cpp
// Description: Class representing a divide by 0 exception
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors:
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//----------------------------------------------------------------------------
#include "Exceptiondividebyzero.h"
#include <iostream>

//------------------------------------------------------------------------------
Exceptiondividebyzero::Exceptiondividebyzero() : exception()
{
}

//------------------------------------------------------------------------------
Exceptiondividebyzero::Exceptiondividebyzero(Exceptiondividebyzero const &src)
  : exception(src)
{
}

//------------------------------------------------------------------------------
Exceptiondividebyzero::~Exceptiondividebyzero() throw()
{
}

//------------------------------------------------------------------------------
const char *Exceptiondividebyzero::what() const throw()
{
  return "Division By Zero Error";
}
