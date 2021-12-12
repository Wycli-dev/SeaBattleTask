//
//  SeaBattleGameField.cpp
//  SeaBattleTask
//
//  Created by Alex Denisov on 12.12.2021.
//

#include "SeaBattleGameField.hpp"

namespace {
    std::string with_leading_spaces(std::string source_string, int max_length) {
        std::string result = source_string;
        while(result.size() < max_length) result = " " + result;
        return result;
    }
}

SeaBattleGameField::SeaBattleGameField() {
    ships = {};
}

bool SeaBattleGameField::ship_exists(int x, int y) {
    bool result = false;
    for (Ship ship : ships) {
        result = result || ship.contains_point(x, y);
    }
    return result;
}

void SeaBattleGameField::draw() {
    int max_length = 2;
    char start_letter = 'A';
    
    for(int i = 0; i < 10; i++) {
        
        for(int j = 0; j < 10; j++) {
            if(i == 0) {
                if(j == 0) {
                    std::cout << with_leading_spaces(" ", max_length);
                } else {
                    std::cout << with_leading_spaces(std::string(1, start_letter++), max_length);
                }
            } else {
                if(j == 0) {
                    std::cout << with_leading_spaces(std::to_string(i), max_length);
                } else {
                    int x = j - 1;
                    int y = i - 1;
                    
                    auto symbol = ship_exists(x, y) ? "*" : "";
                    std::cout << with_leading_spaces(symbol, max_length);
                }
            }
        }
        std::cout << std::endl;
    }
}

bool SeaBattleGameField::add_ship(Ship new_ship) {
    bool exists = false;
    
    for(int i = 0; i < new_ship.length; i++) {
        if(new_ship.orientation == Orientation::HORIZONTAL) {
            exists = exists || ship_exists(new_ship.x + i, new_ship.y);
        } else {
            exists = exists || ship_exists(new_ship.x, new_ship.y + i);
        }
    }
    
    int used_ship_count = 0;
    for(Ship ship : ships) {
        if(ship.length == new_ship.length) used_ship_count++;
    }
    
    if(exists || used_ship_count >= 5 - new_ship.length) return false;

    ships.push_back(new_ship);
    return true;
}
