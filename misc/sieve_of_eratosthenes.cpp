#include <iostream>
#include <cstring>
using namespace std;

void seive_of_eratosthenes(int n)
{
    bool prime[n+1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; ++p)
    {
        if (prime[p] == true)
        {
            //update all multiples of p
            for (int i = p * 2; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; ++p)
    {
        if (prime[p]) {cout << p << " ";}
    }
}

int main()
{
    int n = 30;
    cout << "Seive of Eratosthenes:" << endl;
    cout << "prime numbers less than or equal to " << n << endl;
    seive_of_eratosthenes(n);
    cout << endl;

    return 0;
}
