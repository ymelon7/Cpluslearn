#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <vector>
#include <stdexcept>
#include <deque>

template <typename T, typename CONT = std::deque<T> >
class Queue
{
    private:
        CONT elems_;
    public:
        void push(const T &t);
        T front() const; // return the first elem of queue
        void pop(); // remove the heap of queue elem

        bool empty() const
        {return elems_.empty();}
};

template <typename T, typename CONT>
void Queue<T, CONT>::push(const T &t)
{
    elems_.push_back(t);
}

template <typename T, typename CONT>
T Queue<T, CONT>::front() const
{
    if(elems_.empty())
        throw std::out_of_range("is empty");
    return elems_.front();
}

template <typename T, typename CONT>
void Queue<T, CONT>::pop()
{
    if(elems_.empty())
        throw std::out_of_range("is empty");
    elems_.pop_front();
}

#endif /* _QUEUE_H_ */



