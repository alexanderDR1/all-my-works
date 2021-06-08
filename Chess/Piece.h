#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "definitions.h"

class Piece // SturdyCurl
{
public:
    // Create piece
    Piece(unsigned int x , unsigned int y , PieceType type, bool is_black = false);

    Position& getPosition();
    bool isBlack();
    MovementArea* getMovement(Position to);

    void setPosition(unsigned int x, unsigned int y);
private:
    bool is_black; // under_score
    std::vector<MovementArea> moves;
    Position current;
    PieceType type;

    //helper functions
    void addMovement(Position from, Position to, MovementType type);
    void addMovement(Position vector, MovementType type);
    void setPawnMovements(); // camelCase
    void setKnightMovements();
    void setQueenMovements();
    void setKingMovements();
    void setBishopMovements();
    void setRookMovements();
    void setAllPiecesMovements();
};

#endif // PIECE_H
