/*
Într-o ţară în care corupţia este în floare şi economia la pământ, pentru a obţine toate aprobările necesare în scopul demarării unei afaceri, 
investitorul trebuie să treacă prin mai multe camere ale unei clădiri în care se află birouri.

Clădirea are un singur nivel în care birourile sunt lipite unele de altele formând un caroiaj pătrat de dimensiune n•n. 
Pentru a facilita accesul în birouri, toate camerele vecine au uşi între ele. 
În fiecare birou se află un funcţionar care pretinde o taxă de trecere prin cameră (taxă ce poate fi, pentru unele camere, egală cu 0). 
Investitorul intră încrezător prin colţul din stânga-sus al clădirii (cum se vede de sus planul clădirii) şi doreşte să ajungă în colţul opus al clădirii, 
unde este ieşirea, plătind o taxă totală cât mai mică.

Ştiind că el are în buzunar S euro şi că fiecare funcţionar îi ia taxa de cum intră în birou, 
se cere să se determine dacă el poate primi aprobările necesare şi, în caz afirmativ, 
care este suma maximă de bani care îi rămâne în buzunar la ieşirea din clădire.

*/


#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

ifstream fin ("taxe2.in");
ofstream fout ("taxe2.out");

int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

int S, N, M[110][110], c[110][110];
queue < pair < int, int > > Q;

void Citire(){
    fin >> S >> N;
    for (int i = 1; i <= N; i ++)
        for (int j = 1; j <= N; j ++)
            fin >> M[i][j], c[i][j] = -1;
}

bool PunctInMatrice(int i, int j){
    if (i < 1 || i > N || j < 1 || j > N)
        return false;
    return true;
}

void LeeAlgorithm(){
    Q.push({1, 1});
    c[1][1] = M[1][1];
    while (! Q.empty()){
        int i = Q.front().first;
        int j = Q.front().second;

        Q.pop();

        for (int directie = 0; directie <= 3; directie ++){
            int i_nou = i + di[directie];
            int j_nou = j + dj[directie];

            if (PunctInMatrice(i_nou, j_nou) && ((c[i_nou][j_nou] == -1) || (c[i_nou][j_nou] > c[i][j] + M[i_nou][j_nou]))){
                c[i_nou][j_nou] = c[i][j] + M[i_nou][j_nou];
                Q.push(make_pair(i_nou, j_nou));
            }
        }
    }
    if (S < c[N][N])
        fout << -1;
    else
        fout << S - c[N][N];
}

int main()
{
    Citire();
    LeeAlgorithm();
    return 0;
}

