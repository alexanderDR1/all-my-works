#include "Board.h"
#include "Piece.h"

Board::Board()
{
    for(int i = 0; i < SIZE_X; i++) this->pieces.emplace_back(Piece(i, 1, PieceType::PAWN, false));
    for(int i = 0; i < SIZE_X; i++) this->pieces.emplace_back(Piece(i, 6, PieceType::PAWN, true));

    this->pieces.emplace_back(Piece(4,0, PieceType::KING, true));
    this->pieces.emplace_back(Piece(4,7, PieceType::KING, false));

    this->pieces.emplace_back(Piece(1,0, PieceType::KNIGHT, true));
    this->pieces.emplace_back(Piece(6,0, PieceType::KNIGHT, true));
    this->pieces.emplace_back(Piece(1,7, PieceType::KNIGHT, false));
    this->pieces.emplace_back(Piece(6,7, PieceType::KNIGHT, false));

    this->pieces.emplace_back(Piece(2,0, PieceType::BISHOP, true));
    this->pieces.emplace_back(Piece(5,0, PieceType::BISHOP, true));
    this->pieces.emplace_back(Piece(2,6, PieceType::BISHOP, false));
    this->pieces.emplace_back(Piece(5,6, PieceType::BISHOP, false));

    this->pieces.emplace_back(Piece(0,0, PieceType::ROOK, true));
    this->pieces.emplace_back(Piece(7,0, PieceType::ROOK, true));
    this->pieces.emplace_back(Piece(0,7, PieceType::ROOK, false));
    this->pieces.emplace_back(Piece(7,7, PieceType::ROOK, false));

    this->pieces.emplace_back(Piece(3,0, PieceType::QUEEN, true));
    this->pieces.emplace_back(Piece(3,7, PieceType::QUEEN, false));
}

Piece* Board::findPiece(Position in) {
    for(int i = 0; i < this->pieces.size(); i++) {
        if(in.x == this->pieces[i].getPosition().x
        && in.y == this->pieces[i].getPosition().y)
            return &(this->pieces[i]);
    }
    return nullptr;
}

bool Board::isPieceBlocking(MovementArea &movement, Position from, Position to) {
    // Check if blocking using vector steps
    if(movement.positions.size() == 1) {
        Position toCheck = from;
        while(toCheck.x != to.x - movement.positions[0].x && toCheck.y != to.y - movement.positions[0].y) {
            toCheck.x += movement.positions[0].x;
            toCheck.y += movement.positions[0].y;
            if(this->findPiece(toCheck) != nullptr) return false;
        }
        return true;
    }
    else {
        // Check if blocking in area
        // Hint: need to use GCD
    }

    return false;
}

void Board::movePiece(Position from, Position to) {
    // Find piece at from
    Piece * piece = this->findPiece(from);
    if(piece == nullptr) {
        std::cout << "No piece at given position!" << std::endl;
        return;
    }

    // Get legal movement to to
    MovementArea * movement = piece->getMovement(to);
    if(movement == nullptr) {
        std::cout << "Movement is illegal!" << std::endl;
        return;
    }

    // No piece is blocking the way
    if(this->isPieceBlocking(*movement, from, to)) {
        std::cout << "Road is blocked!" << std::endl;
        return;
    }

    // Consider movement type & Eat if can!
    switch(movement->type) {
        case MovementType::REGULAR:
            // Has no piece at `to`
            break;
        case MovementType::REGULAR_EATING:
            // Can move!
            break;
        case MovementType::EATING:
            // Has to have a piece at `to`
            break;
    }

    // Move piece to new position
    piece->setPosition(to.x, to.y);
}