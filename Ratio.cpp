//------------------------------------------------------------------------------
// Filename: Ratio.cpp
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors:
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#include "Ratio.h"


//------------------------------------------------------------------------------
Ratio::Ratio(unsigned int numerator, unsigned int denominator)
	:	numerator_(numerator),
    denominator_(denominator)
{

}

//------------------------------------------------------------------------------
Ratio::Ratio()
{
	numerator_ = 0;
  denominator_ = 1;
}

//------------------------------------------------------------------------------
Ratio::~Ratio()
{

}

//------------------------------------------------------------------------------
Ratio::Ratio(const Ratio &original) : numerator_(original.numerator_),
 																			denominator_(original.denominator_)
{

}

//------------------------------------------------------------------------------
Ratio Ratio::operator+(const Ratio &other) const
{
	if (other.getNumerator() == 0) return *this;
	else if (numerator_ == 0) return other;
	else
	{
	  Ratio result;
	  Ratio other2;
	  result.setNumerator(numerator_ * other.getDenominator());
	  result.setDenominator(denominator_ * other.getDenominator());
	  other2.setNumerator(other.getNumerator() * denominator_);
	  other2.setDenominator(other.getDenominator() * denominator_);
	  result.setNumerator(other2.getNumerator() + result.getNumerator());
	
	  int divisor = result.euclid(result.getNumerator(),
	                              result.getDenominator());
	  result.setNumerator(result.getNumerator() / divisor);
	  result.setDenominator(result.getDenominator() / divisor);
	  return result;
	}
}

//------------------------------------------------------------------------------
Ratio Ratio::operator-(const Ratio &other) const
	{
	Ratio result;
	Ratio other2;
	result.setNumerator(numerator_ * other.getDenominator());
	result.setDenominator(denominator_ * other.getDenominator());
	other2.setNumerator(other.getNumerator() * denominator_);
	other2.setDenominator(other.getDenominator() * denominator_);
	result.setNumerator(result.getNumerator() - other2.getNumerator());
	
	int divisor = result.euclid(result.getNumerator(),
	                            result.getDenominator());
	result.setNumerator(result.getNumerator() / divisor);
	result.setDenominator(result.getDenominator() / divisor);
	return result;
}
bool Ratio::operator>=(const Ratio& other) const
	{
	double first_result = static_cast<double>(numerator_) / 
												 static_cast<double>(denominator_);
	double second_result = static_cast<double>(other.getNumerator()) / 
												 static_cast<double>(other.getDenominator());
	if (first_result >= second_result) return true;
	else return false;
}

int Ratio::euclid(int a, int b)
{
  if (b == 0)
  {
		return a;
  }
  else
  {
  	return euclid(b, a % b);
  }
}

//------------------------------------------------------------------------------
unsigned int Ratio::getNumerator() const
{
	return numerator_;
}

//------------------------------------------------------------------------------
unsigned int Ratio::getDenominator() const
{
  return denominator_;
}

//------------------------------------------------------------------------------
void Ratio::setNumerator(unsigned int numerator)
{
	numerator_ = numerator;
}

//------------------------------------------------------------------------------
void Ratio::setDenominator(unsigned int denominator)
{
	denominator_ = denominator;
}

