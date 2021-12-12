//
//  Ship.cpp
//  SeaBattleTask
//
//  Created by Alex Denisov on 12.12.2021.
//

#include "Ship.hpp"

Ship::Ship(int x, int y, int length, Orientation orientation) {
    this->x = x;
    this->y = y;
    this->length = length;
    this->orientation = orientation;
}

bool Ship::contains_point(int x, int y) {
    switch(orientation) {
        case Orientation::HORIZONTAL:
            return (x - this->x) >= 0 && (x - this->x) < length && y == this->y;
        case Orientation::VERTICAL:
            return (y - this->y) >= 0 && (y - this->y) < length && x == this->x;
    }
}
