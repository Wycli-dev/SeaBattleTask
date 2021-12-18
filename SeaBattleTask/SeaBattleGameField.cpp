//
//  SeaBattleGameField.cpp
//  SeaBattleTask
//
//  Created by Alex Denisov on 12.12.2021.
//

#include "SeaBattleGameField.hpp"

#define STANDARD_FONT_COLOR "\033[37m"

bool SeaBattleGameField::ship_exists(int x, int y) {
    bool result = false;
    for (Ship ship : ships) {
        result = result || ship.contains_point(x, y);
    }
    return result;
}

bool SeaBattleGameField::ship_available(int length) {
    int counter = 1;
    for(Ship ship : ships) {
        if (ship.length == length) counter++;
    }
    if (5 - counter == 0) return false;
    return true;
}

PointState SeaBattleGameField::state_for_position(int x, int y) {
    if (ship_exists(x, y)) {
        if(shots[y][x]) return PointState::HIT;
        else return PointState::SHIP;
    } else {
        if(shots[y][x]) return PointState::MISS;
        else return PointState::EMPTY;
    }
}

std::string SeaBattleGameField::color_for_state(PointState state) {
    switch(state){
        case PointState::EMPTY:
            return "\033[30m";
        case PointState::SHIP:
            if(!field_type) return "\033[37m";
            else return "\033[30m";
        case PointState::HIT:
            return "\033[31m";
        case PointState::MISS:
            return "\033[34m";
    }
}

std::string SeaBattleGameField::with_leading_spaces(std::string source_string, int max_length) {
        std::string result = source_string;
        while(result.size() < max_length) result = " " + result;
        return result;
}

SeaBattleGameField::SeaBattleGameField(bool field_type) {
    ships = {};
    
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            shots[i][j] = false;
        }
    }
    
    this->field_type = field_type;
}

void SeaBattleGameField::draw() {
    std::cout << STANDARD_FONT_COLOR << "    A B C D E F G H I G " << std::endl;
    
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(j == 0) std::cout << STANDARD_FONT_COLOR << with_leading_spaces(std::to_string(i + 1), 3);
            
            PointState current_point_state = state_for_position(j, i);
            std::string current_font_color = color_for_state(current_point_state);
            std::cout << current_font_color << with_leading_spaces("*", 2) << STANDARD_FONT_COLOR;
        }
        std::cout << std::endl;
    }
}

bool SeaBattleGameField::add_ship(Ship new_ship) {
    int x = new_ship.x;
    int y = new_ship.y;
    int x_len = new_ship.orientation == Orientation::HORIZONTAL ? new_ship.length : 1;
    int y_len = new_ship.orientation == Orientation::VERTICAL ? new_ship.length : 1;
    
    if(x < 0 || x + x_len - 1 > 9 || y < 0 || y + y_len - 1 > 9) return false;
    
    if(!ship_available(new_ship.length)) return false;
    
    ships.push_back(new_ship);
    return true;
}

bool SeaBattleGameField::shoot(int x, int y) {
    if (x < 0 || x > 9 || y < 0 || y > 9) return false;
    
    if (shots[y][x]) return false;
    
    shots[y][x] = true;
    return true;
}


