/*
Lot national, Râmnicu Vâlcea, 2015 


Roberto are suflet de artist. El visează să ajungă într-o bună zi un pictor celebru, dar pentru moment își câştigă existența ca zugrav.

Roberto a primit sarcina de a zugrăvi un zid având lungimea n metri şi înălţimea un metru. 
Pentru aceasta are la dispoziţie m zile. În fiecare zi i, el acoperă cu un singur strat de vopsea o porţiune compactă de înălțime un metru și de lungime l[i] metri, 
începând de la distanţa d[i] metri faţă de capătul din stânga al zidului.

Roberto ştie din experienţă că fiecare porţiune de zid trebuie acoperită cu cel puţin K straturi de vopsea pentru ca stratul final de vopsea să aibă consistenţa dorită. 
Din nefericire, firea lui de artist nu i-a permis să-şi poată planifica munca în mod optim, astfel că la capătul celor m zile de efort, 
Roberto a constatat că zidul are porţiuni pe care le-a acoperit de mai mult de k ori şi alte porţiuni pe care le-a acoperit de mai puţin de k ori.

Pentru a recupera în proprii săi ochi dar mai ales în ochii şefului de echipă, 
el trebuie să afle mai întâi suprafaţa totală a tuturor porţiunilor de zid care mai trebuie zugrăvite.

Cerinţă
Cunoscând lungimea zidului n, numărul de zile m şi porţiunile compacte pe care le zugrăveşte în fiecare zi, 
determinaţi suprafaţa totală a zidului care mai trebuie zugrăvită.


*/


#include <iostream>
#include <fstream>
using namespace std;

#define DIM 250001
int f[DIM], a[DIM];

int main()
{
    ifstream cin ("paint.in");
    ofstream cout ("paint.out");
    int N, M, K, st, dr, nr = 0, s = 0;
    cin >> N >> K >> M;
    while (M --){
        cin >> st >> dr;
        a[st+1] ++;
        a[st+dr+1] --;
    }
    for (int i=1; i<=N; i++){
        s += a[i];
        if (s < K)
            nr ++;
    }
    cout << nr;
    return 0;
}