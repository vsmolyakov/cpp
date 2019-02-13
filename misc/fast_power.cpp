#include<iostream>
using namespace std;


double fastPow(double x, long long n)
{
    if (n == 0) {return 1.0;} 

    double half = fastPow(x, n / 2);

    // x^n = x^{n/2} * x^{n/2}
    if (n % 2 == 0)
        return half * half; 
    else
        return half * half * x;
}


double fastPow_iter(double x, long long n)
{
    double ans = 1.0;
    double current_product = x;

    for (long long i = n; i; i /= 2)
    {
        if (i % 2 == 1){ans = ans * current_product;}
        current_product = current_product * current_product;
    }
    return ans;
}


double myPow(double x, int n, bool is_recursive)
{
    long long N = n;
    if (N < 0)
    {
        x = 1 / x;
        N = -N;
    }

    return is_recursive ? fastPow(x, N) : fastPow_iter(x, N);
}

int main()
{
    int n = 10;    //power
    double x = 2;  //base

    cout << "Computing x^n recursively: ";
    cout << myPow(x, n, true); //O(log n) time, O(log n) space

    cout << "\nComputing x^n iteratively: ";
    cout << myPow(x, n, false); //O(log n) time, O(1) space
    cout << endl;

    return 0;
}
