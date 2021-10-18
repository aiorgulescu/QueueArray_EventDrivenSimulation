#ifndef QUEUE_ARRAY
#define QUEUE_ARRAY

#include "QueueInterface.h"

template<class ItemType>
class QueueArray:public QueueInterface<ItemType>
{
    private:
        static const int DEFAULT_CAPACITY=50;
        ItemType items[DEFAULT_CAPACITY];
        int front;
        int back;
        int count;

    public:
        QueueArray();
        bool isEmpty() const;
        bool enqueue(const ItemType& newEntry);
        bool dequeue();

        ItemType peekFront() const;
};
#include "QueueArray.cpp"
#endif