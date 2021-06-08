#include "Piece.h"

Piece::Piece(unsigned int x, unsigned int y, PieceType type, bool is_black) : current(x, y) // current is x,y in a private
{
     this->is_black = is_black; //the defult is black
     this->type = type;

     //set moves
     switch(this->type) {
         case PieceType::PAWN: this->setPawnMovements(); break;
         case PieceType::KING: this->setKingMovements(); break;
         case PieceType::QUEEN: this->setQueenMovements(); break;
         case PieceType::KNIGHT: this->setKnightMovements(); break;
         case PieceType::ROOK: this->setRookMovements(); break;
         case PieceType::BISHOP: this->setBishopMovements(); break;
    }
}
// movement that define range
void Piece::addMovement(Position from, Position to, MovementType type) {
    this->moves.push_back(MovementArea()); // Add element
    this->moves.back().positions.push_back(from);
    this->moves.back().positions.push_back(to);
    this->moves.back().type = type;
}
//movement that define vector
void Piece::addMovement(Position vector, MovementType type) {
    this->moves.push_back(MovementArea());
    this->moves.back().positions.push_back(vector);
    this->moves.back().type = type;
}

void Piece::setPawnMovements(){
    this->addMovement(Position(0, 1), Position(0, 1), MovementType::REGULAR);
    this->addMovement(Position(-1, 1), Position(-1, 1), MovementType::EATING);
    this->addMovement(Position(1, 1), Position(1, 1), MovementType::EATING);
}

void Piece::setKingMovements(){
    this->addMovement(Position(0, 1), Position(0, 1), MovementType::REGULAR_EATING);
    this->addMovement(Position(-1, 1), Position(-1, 1), MovementType::REGULAR_EATING);
    this->addMovement(Position(1, 1), Position(1, 1), MovementType::REGULAR_EATING);
    this->addMovement(Position(-1, 0), Position(-1, 0), MovementType::REGULAR_EATING);
    this->addMovement(Position(1, 0), Position(1, 0), MovementType::REGULAR_EATING);
    this->addMovement(Position(-1, -1), Position(-1, -1), MovementType::REGULAR_EATING);
    this->addMovement(Position(0, -1), Position(0, -1), MovementType::REGULAR_EATING);
    this->addMovement(Position(1, -1), Position(1, -1), MovementType::REGULAR_EATING);

}

void Piece::setRookMovements(){
    this->addMovement(Position(0, 1), MovementType::REGULAR_EATING);
    this->addMovement(Position(1, 0), MovementType::REGULAR_EATING);
}

void Piece::setBishopMovements(){
    this->addMovement(Position(-1, -1), MovementType::REGULAR_EATING);
    this->addMovement(Position(1, 1), MovementType::REGULAR_EATING);
}

void Piece::setQueenMovements(){
    this->setBishopMovements();
    this->setRookMovements();
}

void Piece::setKnightMovements() {
    this->addMovement(Position(2, 1), Position(2, 1), MovementType::REGULAR_EATING);
    this->addMovement(Position(2, -1), Position(2, -1), MovementType::REGULAR_EATING);
    this->addMovement(Position(-2, 1), Position(-2, 1), MovementType::REGULAR_EATING);
    this->addMovement(Position(-2, -1), Position(-2, -1), MovementType::REGULAR_EATING);
    this->addMovement(Position(1, 2), Position(1, 2), MovementType::REGULAR_EATING);
    this->addMovement(Position(1, -2), Position(1, -2), MovementType::REGULAR_EATING);
    this->addMovement(Position(-1, 2), Position(-1, 2), MovementType::REGULAR_EATING);
    this->addMovement(Position(-1, -2), Position(-1, -2), MovementType::REGULAR_EATING);
}

Position &Piece::getPosition() {
    return this->current;
}

MovementArea* Piece::getMovement(Position to) {
    // Move point to '0' position relative to piece
    to.x -= this->current.x;
    to.y -= this->current.y;

    for(int i = 0; i < this->moves.size(); i++) {
        // In case of vector
        if(this->moves[i].positions.size() == 1) {
            // Get GCD of to
            int g = gcd(to.x, to.y);
            int temp_x = to.x / g;
            int temp_y = to.y / g;

            if(temp_x == this->moves[i].positions[0].x
            && temp_y == this->moves[i].positions[0].y) return &(this->moves[i]);
            continue;
        }

        // In case of range
        // If to position is at the start of the range then return the movement
        if(to.y == this->moves[i].positions[0].y
        && to.x == this->moves[i].positions[0].x) return &(this->moves[i]);

        // Find & compares derivatives
        int m1 = (to.y - this->moves[i].positions[0].y) / (to.x - this->moves[i].positions[0].x); // Y2-Y1 / X2-X1
        int m2 = (this->moves[i].positions[1].y - this->moves[i].positions[0].y) / (this->moves[i].positions[1].x - this->moves[i].positions[0].x);
        if(m1 != m2) continue;

        // Check if position in range
        if(to.x <= this->moves[i].positions[1].x && to.x >= this->moves[i].positions[0].x
        && to.y <= this->moves[i].positions[1].y && to.y >= this->moves[i].positions[0].y) return &(this->moves[i]);
    }
    return nullptr;
}

void Piece::setPosition(unsigned int x, unsigned int y) {
    this->current.x = x;
    this->current.y = y;
}

bool Piece::isBlack() {
    return this->is_black;
}

//Another step
//i need write code to check who win
//and check if the king blocking from all position
//check if the king threatened