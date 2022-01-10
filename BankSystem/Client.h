#ifndef BANKSYSTEM_CLIENT_H
#define BANKSYSTEM_CLIENT_H

#include <iostream>
#include <string>

struct ClientData {
    std::string name;
    std::string family_name;
    std::string email;
    int id;
    int age;
    int password;
    int branch;
    int total_money;
};


class Client {
public:
    // Client functions
    static void showInfo(ClientData& client);
    static void clientConsole(ClientData& client);
    static void additionalActions(ClientData& client);
    static void ribit(ClientData& client);
};


#endif //BANKSYSTEM_CLIENT_H
