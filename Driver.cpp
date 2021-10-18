#include <iostream>
#include <vector>

#include "Queue/QueueArray.h"
#include "Simulation/BankCalculator.h"


int main()
{
    BankCalculator a("customers.txt");
    a.simulate();

    double averageTime = a.getWaitTime();
    int numCustomers = a.getCustomers();

    std::cout << "\nStatistiscs: " << std::endl;
    std::cout << "Total wait time (minutes): " << averageTime << std::endl;
    std::cout << "Total Customers Processed: " << numCustomers << std::endl;

    return 0;
}