/*

Se consideră o tablă de șah de dimensiune n. Să se plaseze pe tablă n regine astfel încât să nu existe două regine care să se atace.


*/


#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int sol[200], n, l = 0;
char a[20][20];

void afis ()
{
    for (int i = 1; i <= n; ++ i)
        a[i][sol[i]] = '*';
    for (int i = 1; i <= n; ++ i)
    {
        for (int j = 1; j <= n; ++ j)
            cout << a[i][j] << " ";
        cout << "\n";
    }
    n = 1;
}

void initializare (int k)
{
    sol[k] = 0;
}

int succesor (int k)
{
    if (sol[k] < n)
    {
        sol[k] ++;
        return 1;
    }
    return 0;
}

bool solutie (int k)
{
    return k == n + 1;
}

bool valid (int k)
{
    for (int i = 1; i <= k - 1; ++ i)
        if (sol[i] == sol[k] || abs(sol[k] - sol[i]) == k - i)
            return false;
    return true;
}

void backtracking (int k)
{
    if (solutie(k))
    {
        for (int i = 1; i <= n; ++ i)
            for (int j = 1; j <= n; ++ j)
                a[i][j] = '-';
        afis();
    }
    else
    {
        initializare(k);
        while (succesor(k))
            if (valid(k))
                backtracking(k + 1);
    }
}

int main()
{
    cin >> n;
    backtracking(1);
    return 0;
}