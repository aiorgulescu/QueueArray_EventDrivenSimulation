#ifndef BANK_CALCULATOR_H
#define BANK_CALCULATOR_H

#include "/Users/aiorgulescu/Desktop/GitHubProjects/Event_Driven_Simulation_QueueImplementation/Queue/QueueArray.h"
#include "Customer.h"
#include <vector>
#include <fstream>
class BankCalculator
{
    QueueArray<Customer> bankQueue;
    int currentTime;
    int departureTime;
    int waitTime;
    int totalWaitTime;
    int arrivalTime;
    int transactionTime;
    int totalCustomers;
    double averageWaitTime;

    std::ifstream file;

    void processArrival(const Customer &newCustomer);
    void processDeparture(const Customer &oldCustomer);
    bool customerDeparting(int currentTime, Customer &leadCustomer);
    
    public:
    BankCalculator(std::string fileName);

    void simulate();
    void calculateWaitTime();
    double getWaitTime() const;
    int getCustomers() const;
};





#endif