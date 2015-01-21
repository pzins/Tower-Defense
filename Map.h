//------------------------------------------------------------------------------
// Filename: Map.h
// Group: Group 8841, study assistant Michael Schwarz
//
// Authors:
// Carl-Philip Lartén 1330704
// Qendrim Kuleta 0932113
// Zins Pierre 1332023
//------------------------------------------------------------------------------
//

#ifndef MAP_H
#define MAP_H
#include <vector>

class Map
{
  private:

    //--------------------------------------------------------------------------
    // Width of map
    //
    unsigned int width_;

    //--------------------------------------------------------------------------
    // Height of map
    //
    unsigned int height_;

    //--------------------------------------------------------------------------
    // Field
    //
    std::vector<unsigned int> fields_;

public:

    //--------------------------------------------------------------------------
    // Constructor
    // @Param width width of map
    // @Param height height of map
    // @param fields objects on map
    //
    Map(unsigned int width, unsigned int height,
        std::vector<unsigned int> fields);

    //--------------------------------------------------------------------------
    // Constructor
    //
    Map();

    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Map();

    //--------------------------------------------------------------------------
    // Setter methods
    //
    void setWidth(unsigned int width);

    void setHeight(unsigned int height);

    void setFields(std::vector<unsigned int> fields);

    //--------------------------------------------------------------------------
    // Getter methods
    //
    unsigned int getWidth() const;

    unsigned int getHeight() const;

    std::vector<unsigned int> getFields() const;

};
#endif // MAP_H