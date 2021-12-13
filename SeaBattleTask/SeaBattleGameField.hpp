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
#include <string>
#include <vector>
#include "Ship.hpp"

class SeaBattleGameField {
private:
    std::vector<Ship> ships;
    std::vector<int> ships_avaliability;
    
public:

    SeaBattleGameField();
    void draw();
    bool add_ship(Ship new_ship);
    bool ship_exists(int x, int y);
};


#endif /* SeaBattleGameField_hpp */
