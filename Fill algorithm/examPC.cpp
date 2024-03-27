/*

Într-un restaurant sunt mese de formă pătrată de dimensiuni diferite.
Mesele sunt poziționate fie cu laturile paralele cu pereții sau înclinate cu 45 grade, precum în exemplul de mai jos:

0 0 0 0 0 0 0 0 0
0 1 1 1 0 0 2 0 0
0 1 1 1 0 2 2 2 0
0 1 1 1 0 0 2 0 0
0 0 0 0 0 0 0 0 0

Restaurantul are forma dreptunghiulară având dimensiunile MxN. 
Suprafața ocupata de mese este marcată cu numere întregi pozitive reprezentând culoarea feței de masă (1=roșu, 5=albastru, 13=violet, etc)

Eticheta 0 reprezintă podeaua (fără importanță în problemă).
Să se scrie un program care citește de la tastatură dimensiunile restaurantului M, N, iar apoi matricea MxN de etichete.

Să se afișeze care este eticheta culorii și aria (numărul de elemente) pentru masa de suprafață maximă.

*/


#include <iostream>
#include <string.h>

using namespace std;

int mat[205][205];
bool ok(int i, int j, int m, int n){
    if (i < 0 || i > m || j < 0 || j > n)
        return false;
    return true;
}

int di[] = {0, -1, 1, 0};
int dj[] = {1, 0, 0, -1};

void Fill(int i, int j, int &nr, int m, int n){
    mat[i][j] = 0;
    nr ++;
    for (int d = 0; d < 4; d ++){
        int ii = i + di[d];
        int jj = j + dj[d];
        if (ok(ii, jj, m, n) && mat[ii][jj])
            Fill(ii, jj, nr, m, n);
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    int nr = 0, max = 0, p = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (mat[i][j]) {
                int x = mat[i][j];
                nr = 0;
                Fill(i, j, nr, m, n);
                if (nr > max)
                    max = nr, p = x;
                    //cout << nr << " " << x << endl;
            }
    cout << p << " " << max;
}