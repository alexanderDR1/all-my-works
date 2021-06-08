#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
    Board board = Board();
    int fx, fy, tx, ty;
    while(true) {
        cout << "Your move on from (x): ";
        cin >> fx;
        cout << "Your move on from (y): ";
        cin >> fy;
        cout << "Your move on to (x): ";
        cin >> tx;
        cout << "Your move on to (y): ";
        cin >> ty;

        board.movePiece(Position(fx, fy), Position(tx, ty));
    }

    return 0;
}
