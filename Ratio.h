//------------------------------------------------------------------------------
// Filename: Ratio.h
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors: 
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#ifndef RATIO_H
#define RATIO_H

class Ratio
{
  private:
    unsigned int numerator_;
    unsigned int denominator_;

  public:

    //--------------------------------------------------------------------------
    // Constructor
    // @param numerator
    // @param denominator
    //
    Ratio(unsigned int numerator, unsigned int denominator);

		//--------------------------------------------------------------------------
    // Constructor
    //
    Ratio();
		
    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Ratio();

   	//--------------------------------------------------------------------------
    // Overloading operator
    //
    Ratio operator+(const Ratio& other) const;
    Ratio operator-(const Ratio& other) const;
    bool operator>=(const Ratio& other) const;

  	//--------------------------------------------------------------------------
    // Euclide method to simplify the fraction
    //
    int euclid(int a, int b);


    //--------------------------------------------------------------------------
    // Copy Constructor
    // Makes a copy of another Ratio Object.
    // @param original Original to copy.
    //
    Ratio(const Ratio& original);

		//------------------------------------------------------------------------------
		// Get methods
		
    unsigned int getNumerator() const;
    
		unsigned int getDenominator() const;
		
		//------------------------------------------------------------------------------
		// Set methods
		
    void setNumerator(unsigned int numerator);
    
		void setDenominator(unsigned int denominator);


};


#endif // RATIO_H
