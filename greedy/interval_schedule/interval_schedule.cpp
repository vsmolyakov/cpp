#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

struct workshops
{
    int start_time;
    int duration;
    int end_time;
};

struct available_workshops
{
    int n;
    vector<workshops> w;
};

available_workshops* initialize(int start_time[], int duration[], int n)
{
    available_workshops * paw = new available_workshops;
    
    paw->n = n;
    for (int i=0; i<n; ++i)
    {
        workshops ws;
        ws.start_time = start_time[i];
        ws.duration = duration[i];
        ws.end_time = start_time[i] + duration[i];
        paw->w.push_back(ws);
    }
    return paw;
}

bool compare(workshops w1, workshops w2)
{
    return (w1.end_time < w2.end_time);
}

int max_workshops(available_workshops* ptr)
{
    // sort workshops by end time
    sort(ptr->w.begin(), ptr->w.end(), compare);

    // interval scheduling
    int max_workshops = 0;
    int last_processed_time = -1;
    for (int i=0; i<ptr->n; ++i)
    {
        if (ptr->w[i].start_time >= last_processed_time)
        {
            last_processed_time = ptr->w[i].end_time;
            max_workshops++;
        }
    }
    return max_workshops;
}

int main(int argc, char *argv[])
{
    ifstream fin("./data/interval_schedule.in");
    ofstream fout("./data/interval_schedule.out");

    int n; //number of workshops
    fin >> n;
    int * start_time = new int[n];
    int * duration = new int[n];

    for(int i=0; i<n; ++i) {fin >> start_time[i];}
    for(int i=0; i<n; ++i) {fin >> duration[i];}

    available_workshops * ptr;
    ptr = initialize(start_time, duration, n);
    cout << "max number of workshops: " << max_workshops(ptr) << endl;
    fout << "max number of workshops: " << max_workshops(ptr) << endl;

    return 0;
}
