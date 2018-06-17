#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Item
{
    float weight;
    int value;
};

struct Node
{
    int level; //level of node in decision tree (also index in arr[])
    int profit; //total value of nodes from root to this node (including this node)
    int bound; //upper bound on maximum profit
    float weight;
};

bool cmp(Item a, Item b)
{
    double r1 = (double) a.value / a.weight;
    double r2 = (double) b.value / b.weight;
    return r1 > r2;
}

int bound(Node u, int n, int W, Item arr[])
{
    //returns upper bound on profit in subtree rooted at u
    //using greedy solution

    if (u.weight >= W) {return 0;}

    //init
    int profit_bound = u.profit;

    int j = u.level + 1;
    int tot_weight = u.weight;

    while ((j < n) && (tot_weight + arr[j].weight <= W))
    {
        tot_weight += arr[j].weight;
        profit_bound += arr[j].value;
        j++;
    }
    //include last item fractionally
    if (j < n)
    {
        profit_bound += (W - tot_weight) * arr[j].value / arr[j].weight;
    }
    
    return profit_bound;
}

int knapsack_bb(int W, Item arr[], int n)
{
    //sort Items based on greedy heuristics (value / weight)
    sort(arr, arr + n, cmp);

    //create a queue for traversing decision tree (include / not include each item)
    queue<Node> Q;
    Node u, v;

    //dummy node
    u.level = -1;
    u.profit = u.weight = 0;
    Q.push(u);

    int max_profit = 0;
    while (!Q.empty())
    {
        u = Q.front(); Q.pop();

        //if starting node, assign level = 0
        if (u.level == -1) {v.level = 0;}

        //if last level continue
        if (u.level == n-1 ) {continue;}
        
        //examine first branch (i.e. adding item to knapsack)
        //increment level and compute profit
        v.level = u.level + 1;
        v.weight = u.weight + arr[v.level].weight;
        v.profit = u.profit + arr[v.level].value;

        if (v.weight <= W && v.profit > max_profit) {max_profit = v.profit;}

        //get the upper bound on profit to decide
        //whether to add v to Q or not
        v.bound = bound(v, n, W, arr);
     
        if (v.bound > max_profit)
            Q.push(v);

        //examine second branch (i.e. not adding item to knapsack)
        v.weight = u.weight;
        v.profit = u.profit;
        v.bound = bound(v, n, W, arr);
        
        if (v.bound > max_profit)
            Q.push(v);
    
    }
    return max_profit;
}

int main()
{
    int W = 10; //knapsack capacity
    Item arr[] = {{2.0, 40}, {3.14, 50}, {1.98, 100},
                  {5.0, 95}, {3.0, 30}}; //{weight, value}
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Branch and Bound knapsack\n";
    cout << "maximum value: " << knapsack_bb(W, arr, n); 
    cout << endl;

    return 0;
}



