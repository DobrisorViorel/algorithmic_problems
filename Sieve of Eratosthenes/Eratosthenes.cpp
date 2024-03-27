/*

Se dau n numere naturale mai mici decât 1.000.000. Determinaţi câte dintre ele sunt prime.

*/

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

#define DIM 1000000
int ciur[DIM+1];
int main()
{
    ifstream cin ("eratostene.in");
    ofstream cout ("eratostene.out");
    int i, j;
    for (i=2; i*i<DIM; i++)
        if (ciur[i] == 0)
        {
            for (j=2; i*j<DIM; j++)
                ciur[i*j] = 1;
        }
    int n, x;
    int nr = 0;
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> x;
        if (ciur[x] == 0)
            nr ++;
    }
    cout << nr;
    return 0;
}