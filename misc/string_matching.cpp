#include <iostream>
#include <cstring>
#include <time.h>
using namespace std;

#define MAX_LEN 100000

char T[MAX_LEN], P[MAX_LEN]; //T = text, P = pattern
int b[MAX_LEN], n, m; //b = back table, n = len(T), m = len(P)

void naive_matching()
{
    for (int i = 0; i < n; ++i) //try all possible starting indices
    {
        bool found = true;
        for (int j = 0; j < m && found; ++j)
        {
            if (P[j] != T[i+j] || i+j >= n) {found = false;}
        }
        if (found) {printf("string P is found at index %d in T\n", i);}
    }
}

void kmp_preprocess()
{
    int i = 0, j = -1; b[0] = -1;
    while (i < m) // pre-process pattern string P
    {
        while (j >= 0 && P[i] != P[j]) j = b[j]; //if different, reset j using b
        i++; j++; // if same, advance both pointers
        b[i] = j;
    }
}

void kmp_search()
{
    //Knuth-Morris-Pratt (KMP)
    int i = 0, j = 0;
    while (i < n) //similar to kmp_preprocess but on string T
    {
        while (j >= 0 && T[i] != P[j]) j = b[j]; //if different, reset j using b
        i++; j++; //if same advance both pointers
        if (j == m) // a match is found when j == m
        {
            printf("string P is found at index %d in T\n", i-j);
            j = b[j]; //prepare j for the next possible match
        }
    }
}

int main()
{
    strcpy(T, "THIS IS A SAMPLE INPUT STRING");
    strcpy(P, "IN");
    n = (int)strlen(T);
    m = (int)strlen(P);

    printf("T = %s\n", T);
    printf("P = %s\n", P);
    printf("\n");

    clock_t t0 = clock();
    printf("Naive Matching\n");
    naive_matching();
    clock_t t1 = clock();
    printf("runtime = %.10lf s\n\n", (t1 - t0) / (double) CLOCKS_PER_SEC);

    printf("Knuth-Morris-Pratt (KMP)\n");
    kmp_preprocess();
    kmp_search();
    clock_t t2 = clock();
    printf("runtime = %.10lf s\n\n", (t2 - t1) / (double) CLOCKS_PER_SEC);

    printf("String Library search\n");
    char *pos = strstr(T, P);
    while (pos != NULL)
    {
        printf("string P is found at index %ld in T\n", pos - T);
        pos = strstr(pos+1, P);
    }
    clock_t t3 = clock();
    printf("runtime = %.10lf s\n\n", (t3 - t2) / (double) CLOCKS_PER_SEC);


    return 0;
}
