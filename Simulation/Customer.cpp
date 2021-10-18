#ifndef CUSTOMER_CPP
#define CUSTOMER_CPP

#include "Customer.h"


Customer::Customer(): arrivalTime(0), departureTime(0), transactionTime(0) {}

void Customer::setArrivalTime(int &myArrivalTime)
{
    arrivalTime = myArrivalTime;
}

void Customer::setTransactionTime(int &myTransactionTime)
{
    transactionTime = myTransactionTime;
}

void Customer::setDepartureTime(int &myDepartureTime)
{
    departureTime = myDepartureTime;
}

int Customer::getArrivalTime() const
{
    return arrivalTime;
}

int Customer::getTransactionTime() const
{
    return transactionTime;
}

int Customer::getDepartureTime() const
{
    return departureTime;
}



#endif