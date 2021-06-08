#include <iostream>
//select from minimum to maximim
int  MinToMax(int* arr, int arr_size)
{
    for(int j = 0; j < arr_size; j++)
    {
        for(int i = 0; i < arr_size -1; i++)
        {
            if(arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}
//its not so neccery if you want increase difficult  remove this function
void print(int* arr, int arr_size)
{
    for(int i = 0; i < arr_size ; i++)
    {
        std::cout << arr[i] << " ";
    }
}
//  using namespace  becuase i so cool
using namespace std;

int main()
{
    //data set
    int player_1 = 0, player_2 = 0, points = 0;
    int arr_size,  num_turn, arr_num[50], MinToMax_arr[50];
    bool turn;

    //
    std::cout << "Enter the number of turn: ";
    std::cin >> num_turn;

    turn = true;//first player start
    //number of turn games
    for(int i = 0; i <  2 * num_turn; i++)
    {
        if(turn)
            cout << "player 1: " << endl;
        else
            cout << "player 2:  " << endl;
        //put data to know size of array
        std::cout << "enter size of array: ";
        cin >> arr_size ;
        int  arr[arr_size];

        //puting numbers in array
        for(int i = 0;  i < arr_size ;  i++ )
        {
            std::cout << "Enter number " << i + 1 << ": ";
            std::cin >> arr[i];

        }   //print numbers array
        for(int i = 0; i < arr_size; i++)
        {
            cout <<  arr[i]  ;
            if(i == arr_size - 1){
                cout << "." ;
            }
            else cout << ",  ";
}
        //function
        cout << endl;
        MinToMax(arr, arr_size);
        //function to print new array (min to max) . its not neccery function
        print(arr, arr_size);
        //switch turn
        turn = !turn;

        if(turn)
            cout << "player 1: " << endl;
        else
            cout << "player 2:  " << endl;
        //second player Arranges the numbers in the array
        cout << "enter numbers from Min to Max";
        for(int i = 0; i < arr_size; i++)
        {
            std::cout << "Enter number " << i + 1 << ": ";
            cin >> MinToMax_arr[i];
        }
        //
        for(int i = 0;  i < arr_size;  i++)
        {
            cout <<  MinToMax_arr[i]  ;
            if( i == arr_size - 1){
                cout << "." ;
            }
            else
                cout << ",  ";
        }

        //check if array from player_1 compatible to player_2
        if(arr[i] == MinToMax_arr [i])
        {
            cout << endl << "wondeful its right:  "<< endl;
            points =+ 5;//giving points

        }  //check if array from player  not compatible to  another player
        else if(arr[i] != MinToMax_arr[i])
        {
            cout << endl <<"worng:   " << endl;
            points =+ 0;//giving points
        }
        //Checking where the points will go
        if(turn)
            player_1 = player_1 + points;
        else
            player_2 = player_2 + points;


        //Testing and declaring the winner
    }
    if(player_1 > player_2)
    {
        cout << "player 1 win " << endl;
    }
    else if (player_1 < player_2)
    {
        cout << "player 2 win" << endl;
    }
    else if (player_1 == player_2)
    {
        cout << "its a draw" << endl;
    }
    // print scores
    cout << "the score of player 1: " << player_1 << endl;
    cout << "the score of player 2: " << player_2 << endl;

    //its my symbol
    int rows;
      cout << "Enter number of rows: ";
    cin >> rows;
    for(int i = rows; i >= 1; --i)
    {
        for(int space = 0; space < rows-i; ++space)
            cout << "  ";
        for(int j = i; j <= 2*i-1; ++j)
            cout << "* ";
        for(int j = 0; j < i-1; ++j)
            cout << "* ";
        cout << endl;

    }
    cout << "its my symbol";
    return 0;


}

