#ifndef BANK_CALCULATOR_CPP
#define BANK_CALCULATOR_CPP

#include "BankCalculator.h"
#include <iostream>


BankCalculator::BankCalculator(std::string fileName)
{
    currentTime = 0;
    waitTime = 0;
    totalWaitTime = 0;
    departureTime = 0;
    arrivalTime = 0;
    transactionTime = 0;
    totalCustomers = 0;
    averageWaitTime = 0;

    file.open(fileName);

    if (!file)
    {
        std::cout << "Error: could not open file" << std::endl;
        exit(0);
    }
}

void BankCalculator::simulate()
{
    while (file >> arrivalTime >> transactionTime )
    {
        //create newCustomer with their arrival and transaction times
        Customer newCustomer;
        newCustomer.setArrivalTime(arrivalTime);
        newCustomer.setTransactionTime(transactionTime);

        //set currentTime equal to arrivalTime (event driven simulation)
        currentTime = arrivalTime;

        //if the queue is empty, first customer doesn't have to wait in line, so their departure time isn't affected by waiting in line
        if (bankQueue.isEmpty())
        {
            processArrival(newCustomer);
            waitTime = 0;
            departureTime = arrivalTime + transactionTime;
            newCustomer.setDepartureTime(departureTime);
            bankQueue.enqueue(newCustomer);
        }
        else
        {
            Customer leadCustomer = bankQueue.peekFront();
            
            if (customerDeparting(currentTime, leadCustomer)) //see customerDeparting method
            {
                //check to see if empty after updating line
                if (bankQueue.isEmpty())
                {
                    departureTime = arrivalTime + transactionTime;
                }
                else
                {
                    departureTime += transactionTime;
                }
            }
            else
            {
                departureTime += transactionTime;
            }
        }
        newCustomer.setDepartureTime(departureTime);
        processArrival(newCustomer);
        waitTime = newCustomer.getDepartureTime() - arrivalTime - transactionTime;
        bankQueue.enqueue(newCustomer); 
        totalCustomers++;
        totalWaitTime += waitTime;
    }
    processDeparture(bankQueue.peekFront()); // process departure of last cutomer in the day
    bankQueue.dequeue(); // remove last customer from line
    file.close();
    calculateWaitTime();
}




void BankCalculator::processArrival(const Customer &newCustomer)
{
    std::cout << "Processing an arrival event at time: " << newCustomer.getArrivalTime() << std::endl;
}
void BankCalculator::processDeparture(const Customer &oldCustomer)
{
    std::cout << "Processing a departure event at time: " << oldCustomer.getDepartureTime() << std::endl;
}

bool BankCalculator::customerDeparting(int currentTime, Customer &leadCustomer)
{
   
    bool isLeaving = false;

    // if the currentTime is greater than the customer in front of the line's departure time, then that means they've been serviced. So we can remove the customer at the front of the line from the queue
    if (currentTime > leadCustomer.getDepartureTime())
    {
        isLeaving = true;

        //we keep iterating to see how many customers we've serviced already
        while (currentTime > leadCustomer.getDepartureTime() && !bankQueue.isEmpty())
        {
            processDeparture(leadCustomer);
            bankQueue.dequeue();
            leadCustomer = bankQueue.peekFront();
        }
    }

    return isLeaving;
 }



void BankCalculator::calculateWaitTime()
{
    averageWaitTime = (double)totalWaitTime/totalCustomers;
}

double BankCalculator::getWaitTime() const
{
    return averageWaitTime;
}

int BankCalculator::getCustomers() const
{
    return totalCustomers;
}

#endif