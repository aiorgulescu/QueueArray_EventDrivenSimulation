#ifndef QUEUE_ARRAY_CPP
#define QUEUE_ARRAY_CPP

#include "QueueArray.h"


template<class ItemType>
QueueArray<ItemType>::QueueArray():front(),back(DEFAULT_CAPACITY-1),count()
{}
template<class ItemType>
bool QueueArray<ItemType>::isEmpty() const
{
    return count ==0;
}
template<class ItemType>
bool QueueArray<ItemType>::enqueue(const ItemType& newEntry)
{
    bool result = false;
    if(count < DEFAULT_CAPACITY)
    {
        back = (back+1)%DEFAULT_CAPACITY;
        items[back]=newEntry;
        count++;
        result=true;
    }
    return result;
}
template<class ItemType>
bool QueueArray<ItemType>::dequeue()
{
    bool result = false;
    if(!isEmpty())
    {
        front=(front+1)%DEFAULT_CAPACITY;
        count--;
        result=true;
    }
    return result;
}
template<class ItemType>
ItemType QueueArray<ItemType>::peekFront() const
{
    if(!isEmpty())
    {
        return items[front];
    }
}

#endif