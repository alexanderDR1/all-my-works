#include <iostream>

struct BankUser {
    std::string name;
    int money;
};

int main() {
    BankUser users[5];
    int total_money = 0;

    // Range based loop - C++17
    for(auto & user : users){
        std::cout << "enter your name: ";
        std::cin >> user.name;
        std::cout << "enter your amount of money: ";
        std::cin >> user.money;
    }

    for(auto & user : users){
        total_money += user.money;
    }
    std::cout << "Here yo money bitch: " << total_money << std::endl;

    return 0;
}