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
    
    SeaBattleGameField gameField(false);
    gameField.add_ship(Ship(0,0,3, Orientation::HORIZONTAL));
    gameField.shoot(0,0);
    gameField.shoot(0, 1);
    gameField.draw();
}
