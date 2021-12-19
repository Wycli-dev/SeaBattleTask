//
//  SeaBattleGame.hpp
//  SeaBattleTask
//
//  Created by Alex Denisov on 18.12.2021.
//

#ifndef SeaBattleGame_hpp
#define SeaBattleGame_hpp

#include <stdio.h>
#include "SeaBattleGame.hpp"
#include "SeaBattleGameField.hpp"
#include "GameState.hpp"

class SeaBattleGame {
private:
    GameState state;
    SeaBattleGameField playerGameField;
    SeaBattleGameField enemyGameField;
    
public:
    SeaBattleGame();
    bool make_shot(std::string position);
    bool place_ship(Ship ship);
    
    GameState current_state();
    
};

#endif /* SeaBattleGame_hpp */
