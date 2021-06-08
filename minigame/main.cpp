#include <iostream>

using namespace std;

struct player {
    int score;
    char* name;
    int health;
    int power;
};

void InitializePlayer(struct player* Player) {
    Player->score = 0; // (*Player).score = 0;
    Player->health = 100;
    Player->power = 1;
    Player->name = new char[100];
    cin.getline(Player->name, 100);
}

int main()
{
    int num_players;

    cout << "Enter number of players: ";
    cin >> num_players;
    cin.ignore();

    struct player Players[num_players];

    for(int i = 0; i < num_players; i++){
        cout << "Enter player name: ";
        InitializePlayer(&Players[i]);
    }
    cout << "hello ";
    for(int i = 0; i < num_players; i++ ){
        cout << Players[i].name;
        if(i == num_players - 1) cout << "." << endl;
        else cout << ", ";
    }

    return 0;
}
