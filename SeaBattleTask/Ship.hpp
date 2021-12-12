//
//  Ship.hpp
//  SeaBattleTask
//
//  Created by Alex Denisov on 12.12.2021.
//

#ifndef Ship_hpp
#define Ship_hpp

#include <stdio.h>

enum Orientation {
    HORIZONTAL,
    VERTICAL
};

class Ship {
public:
    int x;
    int y;
    int length;
    Orientation orientation;
    
    Ship(int x, int y, int length, Orientation orientation);
    
    bool contains_point(int x, int y);
};

#endif /* Ship_hpp */
