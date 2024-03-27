/*

Se dă un graf orientat ponderat – în care fiecare arc are asociat un cost, număr natural strict pozitiv, și un nod p. 
Să se determine, folosind algoritmul lui Dijkstra, costul minim al drumului de la p la fiecare nod al grafului.

*/

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

ifstream fin ("dijkstra.in");
ofstream fout ("dijkstra.out");

const int NMax = 105;
const int oo = (1 << 30);

int N, P, x, y, c;
int D[NMax];
bool Coada[NMax];

vector < pair <int, int> > G[NMax];

struct compara
{
    bool operator() (int x, int y)
    {
        return D[x] > D[y];
    }
};

priority_queue <int, vector <int>, compara> Q;

void Citire()
{
    fin >> N >> P;
    while (fin >> x >> y >> c)
    {
        G[x].push_back(make_pair(y, c));
    }
}

void Dijkstra(int nodStart)
{
    for (int i = 1; i <= N; i ++)
        D[i] = oo;

    D[nodStart] = 0;
    Q.push(nodStart);
    Coada[nodStart] = true;
    while (! Q.empty())
    {
        int nodCurent = Q.top();
        Q.pop();
        Coada[nodCurent] = false;

        for (size_t i = 0; i < G[nodCurent].size(); i ++)
        {
            int vecin = G[nodCurent][i].first;
            int cost = G[nodCurent][i].second;
            if (D[nodCurent] + cost < D[vecin])
            {
                D[vecin] = D[nodCurent] + cost;
                if (Coada[vecin] == false)
                {
                    Q.push(vecin);
                    Coada[vecin] = true;
                }
            }
        }
    }
}

void Afisare()
{
    for (int i = 1; i <= N; i ++)
    {
        if (D[i] != oo)
            fout << D[i] << " ";
        else
            fout << "-1 ";
    }
}

int main()
{
    Citire();
    Dijkstra(P);
    Afisare();
    return 0;
}