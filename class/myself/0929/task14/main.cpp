#include "Queue.hpp"
#include <iostream>
#include <deque>
#include <list>

using namespace std;

int main(int argc, char *argv[])
{
    try
    {
        Queue<int, deque<int> > q;
        q.push(12);
        q.push(19);
        q.push(42);
        q.push(89);
        q.push(30);
        q.push(98);

        while(!q.empty())
        {
            cout << q.front() << endl;
            q.pop();
        }

        Queue<int> q2;
        q2.push(39);
        cout << q2.front() << endl;
        q2.pop();

        Queue<string, list<string> > q3;
        q3.push("hello");
        q3.push("world");
        q3.push("foo");
        q3.push("bar");
        while(!q3.empty())
        {
            cout << q3.front() << endl;
            q3.pop();
        }

    }
    catch(exception &e)
    {
        cout << e.what() << endl; 
    }

}
