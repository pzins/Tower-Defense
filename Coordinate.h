//------------------------------------------------------------------------------
// Filename: Coordinate.h
// Description: Class representing a coordinate
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors:
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate
{
  private:

    //--------------------------------------------------------------------------
    // Coordinate for width
    //
    unsigned int x_coordinate_;
    
    //--------------------------------------------------------------------------
    // Coordinate for height
    //
    unsigned int y_coordinate_;

  public:
  
    //--------------------------------------------------------------------------
    // Constructor
    //
    Coordinate();

    //--------------------------------------------------------------------------
    // Constructor
    //
    Coordinate(unsigned int x_coordinate_, unsigned int y_coordinate_);
    
    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Coordinate();

    //--------------------------------------------------------------------------
    // Copy Constructor
    // Makes a copy of another Coordinate Object.
    // @param original Original to copy.
    Coordinate(const Coordinate &original);

    //--------------------------------------------------------------------------
    // Coordinate for Y
    // @return Returns the Y Coordinate
    //
    unsigned int mapCoordinateY() const;
    
    //--------------------------------------------------------------------------
    // Coordinate for X
    // @return Returns the X Coordinate
    //
    char mapCoordinateX() const;

    //--------------------------------------------------------------------------
    // Calculate the distace between tower and monster
    // @return Returns the distace
    //
    double euclidDistance(Coordinate other);
    
    //--------------------------------------------------------------------------
    // Getter Methods
    //
    unsigned int getX() const;

    unsigned int getY() const;
    
    //--------------------------------------------------------------------------
    // Setter Methods
    //   
    void setX(unsigned int x_coordinate);

    void setY(unsigned int y_coordinate);

};

#endif // COORDINATE_H