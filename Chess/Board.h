#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"
#include <vector>

//the board will be respons on limits and options
using std::vector;

class Board
{
public:
    // create board
    Board();
    void movePiece(Position from, Position to);

private:
    bool white_turn = true;
    Piece* findPiece(Position in);
    bool isPieceBlocking(MovementArea &movement, Position from, Position to);
    vector<Piece> pieces;
    const unsigned int SIZE_X = 8;
    const unsigned int SIZE_Y = 8;

};

#endif // BOARD_H
