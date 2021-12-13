//
//  main.cpp
//  SeaBattleTask
//
//  Created by Alex Denisov on 12.12.2021.
//

#include <iostream>
#include "Ship.hpp"
#include "SeaBattleGameField.hpp"

int main(int argc, const char * argv[]) {
    SeaBattleGameField* game_field = new SeaBattleGameField();
    game_field->draw();

    std::cout << game_field->add_ship(Ship(5, 5, 3, Orientation::HORIZONTAL)) << std::endl;
    std::cout << game_field->add_ship(Ship(7, 2, 2, Orientation::VERTICAL)) << std::endl;
//    game_field->add_ship(Ship(0, 0, 3, Orientation::VERTICAL));

    game_field->draw();
    
}
