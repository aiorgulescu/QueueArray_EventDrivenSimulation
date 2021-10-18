#ifndef CUSTOMER_H
#define CUSTOMER_H
class Customer
{
    private:
    int arrivalTime;
    int transactionTime;
    int departureTime;
    int totalWatiTime;

    public:
    Customer();
    void setArrivalTime(int &myArrivalTime);
    void setTransactionTime(int &myTransactionTime);
    void setDepartureTime(int &myDepartureTime);

    int getArrivalTime() const;
    int getTransactionTime() const;
    int getDepartureTime() const;


};



#endif