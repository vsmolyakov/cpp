#include <iostream>
#include <climits>
using namespace std;

void swap(int *x, int *y);

class min_heap
{
public:

    min_heap(int capacity);

    void minHeapify(int i);

    int parent(int i) {return (i-1)/2;}
    int left(int i) {return (2*i + 1);}
    int right(int i) {return (2*i + 2);}

    int extractMin();
    void decreaseKey(int i, int new_val);
    int getMin() {return harr[0];}
    void deleteKey(int i);
    void insertKey(int k);
    void print_heap();

private:
    int *harr; //pointer to array of elements in heap
    int capacity; //maximum heap size
    int heap_size; //current number of elements
};

min_heap::min_heap(int cap)
{
    heap_size = 0;
    capacity = cap;
    harr = new int[cap];
}

void min_heap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\nmax capacity: could not insert key\n";
        return;
    }

    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    while (i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

void min_heap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i!=0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

int min_heap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
    
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    minHeapify(0);

    return root;
}

void min_heap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

void min_heap::minHeapify(int i)
{
    //recursive method to heapify a subtree rooted at i
    //assumes subtrees are already heapified
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;

    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        minHeapify(smallest);
    }
}

void min_heap::print_heap()
{
    for (int i = 0; i < heap_size; ++i)
    {
        cout << harr[i] << " ";
    }
    cout << endl;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    min_heap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.insertKey(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.insertKey(45);

    cout << "binary heap: " << endl;
    h.print_heap();

    cout << "extract min: " << h.extractMin() << endl;
    cout << "get min: " << h.getMin() << endl;
    cout << "decrease key: 2->1 and get min: ";
    h.decreaseKey(2, 1);
    cout << h.getMin() << endl;

    return 0;
}



