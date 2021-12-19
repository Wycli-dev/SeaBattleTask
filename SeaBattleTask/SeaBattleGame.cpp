//
//  SeaBattleGame.cpp
//  SeaBattleTask
//
//  Created by Alex Denisov on 18.12.2021.
//

#include "SeaBattleGame.hpp"

SeaBattleGame::SeaBattleGame() {
    playerGameField = SeaBattleGameField(true);
    enemyGameField = SeaBattleGameField(false);
    state = GameState::NEED_SET_SHIP;
}

bool SeaBattleGame::make_shot(std::string position) {
    return false;
}
