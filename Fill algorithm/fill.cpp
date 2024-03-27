/*

Se dă o matrice cu n linii și m coloane și elemente 0 sau 1, care reprezintă harta unei planete, în care 1 înseamnă uscat, iar 0 înseamnă apă. 
Două elemente 1 care se învecinează pe linie sau pe coloană (nu și pe diagonală) fac parte din același continent.

Să se determine câte continente sunt pe hartă.

*/

#include <iostream>
#include <fstream>
using namespace std;

int a[110][110];

void fill (int i, int j, int c){
    a[i][j] = c;
    if (a[i-1][j] == 1)
        fill(i-1, j, c);
    if (a[i][j+1] == 1)
        fill(i, j+1, c);
    if (a[i+1][j] == 1)
        fill(i+1, j, c);
    if (a[i][j-1] == 1)
        fill(i, j-1, c);
}

int main()
{
    ifstream cin ("fill.in");
    ofstream cout ("fill.out");
    int n, m, nr = 0;

    cin >> n >> m;

    for (int i = 1; i <= n ; i++)
        for (int j = 1; j <= m ; j ++)
            cin >> a[i][j];

    for (int i = 1; i <= n ; i++)
        for (int j = 1; j <= m ; j ++)
            if (a[i][j] == 1){
                nr ++;
                fill(i, j, nr+1);
            }
            
    cout << nr;
    return 0;
}