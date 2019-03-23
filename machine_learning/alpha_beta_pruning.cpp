#include <iostream>
using namespace std;

#define MIN -1000 //init alpha
#define MAX +1000 //init beta

int minimax(int depth, int nodeIndex, bool maximizingPlayer,
            int values[], int alpha, int beta)
{
   //base case: leaf node is reached
   if (depth == 3)
       return values[nodeIndex];

   if (maximizingPlayer)
   {
       int best = MIN;

       //recurse for left and right children
       for (int i = 0; i < 2; ++i)
       {
           int val = minimax(depth+1, 2*nodeIndex+i, false,
                             values, alpha, beta);
           best = max(best, val);
           alpha = max(alpha, best);

           //alpha beta pruning
           if (beta <= alpha)
               break;
       }
       return best; 
   }
   else
   {
       int best = MAX;
   
       //recurse for left and right children
       for (int i = 0; i < 2; ++i)
       {
           int val = minimax(depth+1, 2*nodeIndex+i, true,
                             values, alpha, beta);
 
           best = min(best, val);
           beta = min(beta, best);

           //alpha beta pruning
           if (beta <= alpha)
               break;
       }
       return best;
   }
}

int main()
{
    int values[8] = {3, 5, 6, 9, 1, 2, 0, -1};
    cout << "Alpha-Beta Pruning..." << endl;
    cout << "the optimal minimax value is: ";
    cout << minimax(0, 0, true, values, MIN, MAX);
    cout << endl;

    return 0;
}
