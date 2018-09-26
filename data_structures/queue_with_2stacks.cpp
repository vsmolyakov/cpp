#include <stack>
#include <iostream>
using namespace std;

class Queue
{
public:

    void enQueue(int x)
    {
        //push item onto the first stack
        s1.push(x);
    }

    int deQueue()
    {
        if (s1.empty() && s2.empty())
        {
            cout << "queue is empty" << endl;
            return -1;
        }

        //if s2 is empty, move all items from s1
        if (s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        //return top item from s2
        int x = s2.top();
        s2.pop();

        return x;
    }

private:
    stack<int> s1, s2;
};

int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);

    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;

    return 0;
}
