#include<cmath>
#include<iostream>
using namespace std;

int next(int n)
{
    int sum = 0;

    //compute sum of squared digits
    //e.g. 19 -> 1^2 + 9^2 = 82
    while (n!=0)
    {
        sum += pow(n % 10, 2);
        n = n / 10;
    }

    return sum;
}

bool isHappy(int n)
{
    //a number is happy if sum of
    //square digits converges to 1
    int slow = next(n);
    int fast = next(next(n));

    cout << "slow: " << slow << ", fast : " << fast << endl;

    while (slow != fast)
    {
        slow = next(slow);
        fast = next(next(fast));
        cout << "slow: " << slow << ", fast : " << fast << endl;
    }

    return fast == 1;
}

int main()
{
    int n = 19;
    cout << "Is the number " << n << " happy? ";
    cout << "(i.e. does the sum of digits squared converge to 1)" << endl;
   
    bool result;
    result = isHappy(n);
    if (result) {cout << "Answer: Yes" << endl;} else {cout << "Answer: No";}

    return 0;
}


