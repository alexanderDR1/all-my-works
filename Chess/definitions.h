//
// Created by lesscomplex on 09/03/2020.
//

#ifndef CHESS_DEFINITIONS_H
#define CHESS_DEFINITIONS_H

#include <iostream>

inline int gcd(int x, int y) {
    while(y != 0) {
        int temp = y;
        y = y % x;
        x = y;
    }

    return x;
}

enum class PieceType {
    KING,
    QUEEN,
    ROOK,
    KNIGHT,
    BISHOP,
    PAWN
};

class Position {
public:
    unsigned int x;
    unsigned int y;

    Position(unsigned int x, unsigned int y) {
        this->x = x;
        this->y = y;
    }
};

enum class MovementType {
    REGULAR,
    REGULAR_EATING,
    EATING
};

struct MovementArea {
    // positions.size() == 1 -> vector
    // positions.size() == 2 -> area
    std::vector<Position> positions;
    MovementType type;
};

#endif //CHESS_DEFINITIONS_H
