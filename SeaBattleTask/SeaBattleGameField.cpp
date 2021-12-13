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
    ships_avaliability = {4, 3, 2, 1};
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
    
    for(int i = 0; i < 11; i++) {
        
        for(int j = 0; j < 11; j++) {
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
    int x_length = new_ship.orientation == Orientation::HORIZONTAL ? new_ship.length : 1;
    int y_length = new_ship.orientation == Orientation::VERTICAL ? new_ship.length : 1;
    int x = new_ship.x;
    int y = new_ship.y;
    
    if(x < 0 || y < 0 || x + x_length >= 10 || y + y_length >= 10) {
        return false;
    }
    
    for(int i = std::max(0, y - 1); i < std::max(9, y + y_length); i++) {
        for(int j = std::max(0, x - 1); j < std::max(9, x + x_length); j++){
            if(ship_exists(j, i)) {
                return false;
            }
        }
    }
    
    if(ships_avaliability[new_ship.length - 1] == 0) {
        return false;
    }

    ships.push_back(new_ship);
    ships_avaliability[new_ship.length - 1]--;
    return true;
}
