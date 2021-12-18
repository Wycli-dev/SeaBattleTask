//
//  SeaBattleGameField.hpp
//  SeaBattleTask
//
//  Created by Alex Denisov on 12.12.2021.
//

#ifndef SeaBattleGameField_hpp
#define SeaBattleGameField_hpp

#include <stdio.h>
#include <iostream>

#include <vector>
#include "Ship.hpp"
#include "PointState.hpp"

class SeaBattleGameField {
private:
    std::vector<Ship> ships;
    bool shots[10][10];
    bool field_type;
    
    bool ship_exists(int x, int y);
    bool ship_available(int length);
    
    PointState state_for_position(int x, int y);
    std::string color_for_state(PointState state);
    std::string with_leading_spaces(std::string source_string, int max_length);
    
    
public:
    SeaBattleGameField(bool field_type);
    void draw();
    bool add_ship(Ship new_ship);
    bool shoot(int x, int y);
};


#endif /* SeaBattleGameField_hpp */
