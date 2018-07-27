#include <vector>
#include <iostream>
using namespace std;

class circular_queue
{
public:
    circular_queue(int k)
    {
        data.resize(k);
        head = 0;
        tail = 0;
        reset = true;
    }

    bool enQueue(int value)
    {
        if (isFull()) return false;
        //update reset on first enQueue
        if (head == tail && reset) reset = false;
        data[tail] = value;
        tail = (tail + 1) % data.size();
        return true;
    }

    bool deQueue()
    {
        if (isEmpty()) return false;
        head = (head + 1) % data.size();
        //update reset on last deQueue
        if (head == tail && !reset) reset = true;
        return true;
    }

    int Front()
    {
        if (isEmpty()) return -1;
        return data[head];
    }

    int Rear()
    {
        if (isEmpty()) return -1;
        return data[(tail + data.size() - 1) % data.size()];
    }

    bool isEmpty()
    {
        if (tail == head && reset) return true;
        return false;
    }

    bool isFull()
    {
        if (tail == head && !reset) return true;
        return false;
    }

    void display_queue()
    {
        if (isEmpty()) {printf("Queue is empty.\n");}
        if (tail > head)
        {
            for (int i = head; i < tail; ++i) {cout << data[i] << " ";}
            cout << endl;
        }
        else
        {
            for (int i = head; i < (int) data.size(); ++i) {cout << data[i] << " ";}
            for (int i = 0; i <= tail; ++i) {cout << data[i] << " ";}
            cout << endl;
        }
    }

private:
    vector<int> data;
    int head;
    int tail;
    bool reset; //to distinguish between full and empty
};

int main()
{
    circular_queue cq(5);

    cout << "Inserting elements into circular queue: " << endl;
    cq.enQueue(14);
    cq.enQueue(22);
    cq.enQueue(13);
    cq.enQueue(-6);
    cq.display_queue();

    cout << "Deleting elements from circular queue: " << endl;
    cq.deQueue();
    cq.deQueue();
    cq.display_queue();

    cout << "Inserting elements into circular queue: " << endl;
    cq.enQueue(9);
    cq.enQueue(20);
    cq.enQueue(15);
    cq.display_queue();
    
    return 0;
}

