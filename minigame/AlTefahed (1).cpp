#include <iostream>

using namespace std;

struct Player {
    int health;
    int attack;
    int position;
    char name[20];
};

void InitializePlayer(struct Player* player) {
    player->health = 100;
    player->attack = 10;
    player->position = 0;
    cin.getline(player->name, 20);
}

void AttackTheseBitches(struct Player* players, int attackerIndex, int amountOfPlayers) {
    int positionForAttack = players[attackerIndex].position;

    for(int i = 0; i < amountOfPlayers; i++) {
        // Skip dead or the attacker himself
        if(players[i].health <= 0 || i == attackerIndex) continue;
        // Measure distance from attacker
        int distanceFromAttacker = players[i].position - positionForAttack;
        if(distanceFromAttacker == 1 || distanceFromAttacker == -1) players[i].health -= players[attackerIndex].attack;
    }
}

// Return if move was legal
bool MoveTheFucker(struct Player* players, int moverIndex, int amountOfPlayers) {
    int amountToMove = 0;

    cout << "How much you want to move u lazy fuck (-2 <> 2): ";
    cin >> amountToMove;
    // Indicate illegal move
    if(amountToMove > 2 || amountToMove < -2) return false;
    // Move
    players[moverIndex].position += amountToMove;

    // Allah Wakhbar
    for(int i = 0;i < amountOfPlayers;i++){
        // Skip dead or the mover himself
        if(players[i].health <= 0 || i == moverIndex) continue;
        if(players[i].position == players[moverIndex].position){
            players[i].health = 0;
            players[moverIndex].health = 0;
            cout << players[moverIndex].name << " allah wakhbar'ed dis other nigga " << players[i].name << "." << endl;
        }
    }

    return true;
}

bool WinnerExists(struct Player* players, int amountOfPlayers) {
    bool OnlyOneLeft = false;
    int survivorIndex;

    // Check for last survivor, exit if more than 1
    for(int i = 0;i < amountOfPlayers;i++){
        if(players[i].health > 0 && !OnlyOneLeft){
            OnlyOneLeft = true;
            survivorIndex = i;
        }
        else if(players[i].health > 0 && OnlyOneLeft) return false;
    }

    // Draw!
    if(!OnlyOneLeft) cout << "You all died you fuckerts!!! stupid ass bitches" << endl;
    // Show winner
    else cout << players[survivorIndex].name << " beat the shit outta all you losers, suck a cock" << endl;

    return true;
}

int main()
{
    int NumberOfPlayers;
    int universeBorder = 0;
    int playerTurn = 0;
    int command = 0;
    cout << "enter number of players: ";
    cin >> NumberOfPlayers;
    cin.ignore();

    struct Player players[NumberOfPlayers];
    universeBorder = NumberOfPlayers * 5 + 5;

    for(int i = 0; i < NumberOfPlayers; i++){
        cout << "Enter name of player " << i << ": ";
        InitializePlayer(&players[i]);
        players[i].position = (i + 1) * 5;
    }

    while(true){
        // Skip dead players
        if(players[playerTurn].health <= 0) {
            playerTurn = (playerTurn + 1) % NumberOfPlayers;
            continue;
        }

        // Show map!
        for(int i = 0; i < universeBorder; i++){
            int currentPosition = i + 1;
            bool Found = false;

            for(int j = 0; j < NumberOfPlayers; j++){
                if(players[j].health <= 0) continue;
                if(players[j].position == currentPosition){
                    cout << players[j].name[0];
                    Found = true;
                    break;
                }
            }
            if(!Found) cout << ".";
        }
        cout << endl;

        cout << "Current turn: " << players[playerTurn].name << endl;
        // Step 1: Get command
        cout << "Enter a command bitch (0 - Attack, 1 - Move, 2 - Skip): ";
        cin >> command;

        // Skip
        if(command == 2) {
            playerTurn = (playerTurn + 1) % NumberOfPlayers;
            continue;
        }

        // Step 2: Follow command (Move left/right or attack the bastards)
        switch(command) {
        case 0:
            AttackTheseBitches(players, playerTurn, NumberOfPlayers);
            break;
        case 1:
            bool isLegal = MoveTheFucker(players, playerTurn, NumberOfPlayers);
            while(!isLegal) isLegal = MoveTheFucker(players, playerTurn, NumberOfPlayers);
            break;
        }

        // Step 3: Indicate winner if present
        if(WinnerExists(players, NumberOfPlayers)) break;

        // Step 4: Calculate next turn
        playerTurn = (playerTurn + 1) % NumberOfPlayers;
    }
    cout << "Game over";
    return 0;
}
