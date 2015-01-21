//------------------------------------------------------------------------------
// Filename: Exceptiondividebyzero.h
// Description: Class representing a divide by 0 exception
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors:
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//
#ifndef EXCEPTIONDIVIDEBYZERO_H
#define EXCEPTIONDIVIDEBYZERO_H

#include <exception>

class Exceptiondividebyzero : public std::exception 
{
  public:

  	//--------------------------------------------------------------------------
    // Constructor
	  //
    Exceptiondividebyzero();

    //--------------------------------------------------------------------------
    // Copy Constructor
    //
    Exceptiondividebyzero(Exceptiondividebyzero const &src);

    //--------------------------------------------------------------------------
    // Virtual destructor
    //
    virtual ~Exceptiondividebyzero() throw();

    //--------------------------------------------------------------------------
    // method to print the exception
    //
    virtual const char *what() const throw();
};

#endif
