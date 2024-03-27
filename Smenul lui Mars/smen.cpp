/*
Urmează o perioadă aglomerată și trebuie să ajutați un magazin să își gestioneze stocul. Magazinul are N obiecte indexate de la 1 la N, iar fiecare obiect are un stoc. Trebuie să procesați T operații de tipul:

1) x y p: stocul obiectelor cu ale caror indice se afla intre [x, y] creste cu p
2) x y p: stocul obiectelor cu ale caror indice se afla intre [x, y] scade cu p

In urma unei operatii de tip 2 se poate ca stocul sa fie negativ, caz in care proprietarii raman cu datorie

Restricții și precizări
1 ≤ N ≤ 10^5
1 ≤ T ≤ 10^5
0 ≤ vi ≤ 10^9
0 ≤ p ≤ 10^9

*/

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("easyquery.in");
ofstream fout ("easyquery.out");

int main()
{
    long long S[100010], N, Q, st, dr, p, op, s[100010] = {0};
    fin >> N;
    for (int i = 1; i <= N; i ++)
        fin >> S[i];
    fin >> Q;
    while (Q --){
        fin >> op >> st >> dr >> p;
        if (op == 1){
            s[st] += p;
            s[dr+1] -= p;
        }
        else{
            if (p > 0)
                p *= -1;
            s[st] += p;
            s[dr+1] -= p;
        }
    }
    for (int i = 1; i <= N; i ++)
        s[i] += s[i-1];
    for (int i = 1; i <= N; i ++)
        s[i] = s[i] + S[i];
    for (int i = 1; i <= N; i ++)
        fout << s[i] << " ";
    return 0;
}