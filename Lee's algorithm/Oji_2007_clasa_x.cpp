/*


Parcul oraşului a fost neglijat mult timp, astfel că acum toate aleile sunt distruse. 
Prin urmare, anul acesta Primăria şi-a propus să facă reamenajări. 
Parcul are forma unui pătrat cu latura de n metri și este înconjurat de un gard care are exact două porți. 
Proiectanții de la Primărie au realizat o hartă a parcului și au trasat pe hartă un caroiaj care împarte parcul în nxn zone pătrate cu latura de 1 metru. 
Astfel harta parcului are aspectul unei matrice pătratice cu n linii și n coloane. Liniile și respectiv coloanele sunt numerotate de la 1 la n. 
Elementele matricei corespund zonelor pătrate de latură 1 metru. O astfel de zonă poate să conțină un copac sau este liberă. 
Edilii orașului doresc să paveze cu un număr minim de dale pătrate cu latura de 1 metru zonele libere (fără copaci) ale parcului, 
astfel încât să se obțină o alee continuă de la o poartă la alta.

Cerința

Scrieți un program care să determine numărul minim de dale necesare pentru construirea unei alei continue de la o poartă la cealaltă.


*/


#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

ifstream fin ("alee.in");
ofstream fout ("alee.out");

int di[] = {-1, 1, 0, 0};
int dj[] = {0, 0, 1, -1};

queue < pair <int, int> > Q;

int N, Mat[200][200], M, Lin, Col, i_start, j_start, i_stop, j_stop;

void Read(){
    fin >> N >> M;
    for (int i = 1; i <= N; i ++)
        for (int j = 1; j <= N; j ++)
            Mat[i][j] = 0;
    while (M --){
        fin >> Lin >> Col;
        Mat[Lin][Col] = -1;
    }
    fin >> i_start >> j_start >> i_stop >> j_stop;
}

bool Ok(int i, int j){
    if (i < 1 || i > N || j < 1 || j > N)
        return false;
    if (Mat[i][j] == -1)
        return false;
    return true;
}

void LeeAlgorithm(){
    Q.push(make_pair(i_start, j_start));
    Mat[i_start][j_start] = 1;

    while (! Q.empty()){
        int i = Q.front().first;
        int j = Q.front().second;

        Q.pop();

        for (int directie = 0; directie < 4; directie ++){
            int i_nou = i + di[directie];
            int j_nou = j + dj[directie];

            if (Ok(i_nou, j_nou) && Mat[i_nou][j_nou] < 1){
                Mat[i_nou][j_nou] = Mat[i][j] + 1;
                Q.push(make_pair(i_nou, j_nou));
            }
        }
    }
    fout << Mat[i_stop][j_stop];
}

int main()
{
    Read();
    LeeAlgorithm();
    return 0;
}