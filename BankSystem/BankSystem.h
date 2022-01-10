
#ifndef BANKSYSTEM_BANKSYSTEM_H
#define BANKSYSTEM_BANKSYSTEM_H

#include "Client.h"
#include "Worker.h"
#include <vector>

// Data-oriented design
struct BankData { // Struct type called BankData
    std::vector<ClientData> clients = {};
    std::vector<WorkerData> workers = {};
};

inline struct BankData bankData = {};

class BankSystem {
public:
    BankSystem();

    void clientRegister();
    void workerRegister();
    void clientLogin();
    void workerLogin();
    void create();
    void remove();

    bool console(); // Main system console
private:
    ClientData* logged_client = nullptr;
    WorkerData* logged_worker = nullptr;
};
#endif //BANKSYSTEM_BANKSYSTEM_H
