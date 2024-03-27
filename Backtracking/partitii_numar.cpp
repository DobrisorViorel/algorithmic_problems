/*

Se dă un număr natural n. Determinaţi, în ordine lexicografică, toate modalităţile de a-l scrie pe n ca sumă de numere naturale.

*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("partitiinumar.in");
ofstream fout ("partitiinumar.out");

int sol[45], n, sum;

int afis(int k)
{
    for (int i = 1; i <= k; ++ i)
        fout << sol[i] << " ";
    fout << "\n";
}

int valid(int k)
{
    if (sol[k-1] > sol[k])
        return false;
    sum = 0;
    for (int i = 1; i <= k; ++ i)
        sum += sol[i];
    if (sum <= n)
        return true;
    return false;
}

int initializare(int k)
{
    sol[k] = 0;
}

int succsor(int k)
{
    if (sol[k] < n)
    {
        sol[k] ++;
        return true;
    }
    return false;
}

bool solutie(int k)
{
    return sum == n;
}

void backtracking(int k)
{
    if (solutie(k))
        afis(k - 1);
    else
    {
        initializare(k);
        while (succsor(k))
            if (valid(k))
                backtracking(k+1);
    }
}

int main()
{
    fin >> n;
    backtracking(1);
    return 0;
}