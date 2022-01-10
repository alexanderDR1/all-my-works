#ifndef BANKSYSTEM_WORKER_H
#define BANKSYSTEM_WORKER_H

#include <string>
#include "Worker.h"
#include "Client.h"
#include <iostream>
#include <vector>

struct WorkerData {
    // What data does a worker hold?
    std::vector  <ClientData>clients = {};
    std::string name;
    std::string family_name;
    std::string email;
    int id;
    int age;
    int password;
    int branch;

};

class Worker {
public:
     static void workerConsole(WorkerData & worker);
     void createClient();
     void infoClient();
     void  remove();

};


#endif //BANKSYSTEM_WORKER_H
