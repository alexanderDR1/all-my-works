
#include "Client.h"
#include "BankSystem.h"

using namespace std;

void Client::showInfo(ClientData& client) {

}

void Client::clientConsole(ClientData& client) {
    int deposit;
    int withdrawl;

    while(true){
        // get command
        int command;
        cout << "enter command( 0 - actions with account, 1 - cash deposit, 2 - cash withdrawl ,  3- exit )" ;
        cin >> command;

        if(command == 3) break;
        if(command > 3) {
            std::cout << "Illegal Command" << std::endl;
            continue;
        }
        switch(command){
            case 0:
                Client::additionalActions(client);
                break;
            case 1:
                cout << "enter your deposit : ";
                cin >> deposit ;
                deposit += deposit;
                break;
            case 2:
                cout << "enter your withdrawl: ";
                cin >> withdrawl;
                withdrawl += withdrawl;
                break;
        }
        client.total_money = deposit - withdrawl ;
    }
    cout << "you have " << client.total_money << "$" << endl;
}

void Client::additionalActions(ClientData& client) {
    while(true){
        int commando;
        cout << "enter command(0 - calculate security deposit  , 1 - information about you,  2 - exit)";
        cin >> commando;
        if(commando == 2) break;
        if(commando > 2) {
            std::cout << "Illegal Command" << std::endl;
            continue;
        }
        switch(commando){
            case 0:
                Client::ribit(client);
                break;
            case 1:
                Client::showInfo(client);
                break;
        }
    }
}

void Client::ribit(ClientData& client) {
    int secure_deposit;
    int years;
    int total_money;

    cout << " calculate your profit from security deposit " << endl << "you will receive 3% in year  " << endl;
    cout << "how long you want put your money in the bank?  ";
    cin >> years;
    cout << "how much money you want put in the bank? ";
    cin >> secure_deposit;
    // secure_deposit *= pow(1.03, years);
    for(int i = 0; i < years; i++){
        secure_deposit = 1.03 * secure_deposit;
    }
    cout << "your will have " << secure_deposit <<"$  after " << years << " years" << endl;
}
