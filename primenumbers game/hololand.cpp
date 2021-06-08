#include <iostream>

bool Prime_number(int num){
    // Loop through all number from 2 until the selected number
    for(int index = 2; index < num -1; index++){
        // If the number is divisible by index, then it is not prime
        if(num % index == 0) return false;
    }
    return true;
}
  using namespace std;


int main()
{
    //data for application
    int first_number, second_number, result, num_turn;
    int points = 0;
    int player_1 = 0, player_2 = 0, rows , space;
    bool turn;
    //first turn for player
    turn = true;
    //data for numbers of turn
    std::cout << "enter numbers of turns: ";
    std::cin >> num_turn;
    for(int i = 1; i <= 2 * num_turn; i++){
        if(turn) std::cout << "player_1- " << std::endl;
        else std::cout << "player_2- " << std::endl;
        //set data
        std::cout << "enter first number: ";
        std::cin >> first_number;
        std::cout << "enter second number: "  ;
        std::cin >> second_number;

        //calculate result
        result = first_number + second_number;


            //Check if this is a prime number
          if(Prime_number(result)){
            std::cout <<  result << " " <<"its a prime number" << std::endl;
                points =+ result; //giving points
          }

            //check if this a not prime number
            else if (Prime_number(!result)){
                std::cout << result << "  " << "its not a prime number" << std::endl;
                    points =+ 0; // giving points
            }
            //Distribute points to players
            if(turn) player_1 = player_1 + points;
            else player_2 =player_2 + points;

                //switch turn
                turn = !turn;

    }
            //Check who won and declared him
            if(player_1 > player_2){
                std::cout << "Player 1 Win";
            }
            else if(player_1 < player_2){
                std::cout << "Player 2 Win";
            }
            else std::cout << "You're in the draw";

            cout << endl;

            cout << "the all points of player 1: " << player_1 << endl;
            cout << "the all points of player 2: " << player_2<< endl;


            cout << "its my symbol" << endl;
             cout <<"Enter number of rows: ";
    cin >> rows;
    for(int i = 1, k = 0; i <= rows; ++i, k = 0)
    {
        for(space = 1; space <= rows-i; ++space)
        {
            cout <<"  ";
        }
        while(k != 2*i-1)
        {
            cout << "* ";
            ++k;
        }
        cout << endl;
    }
    return 0;



}



