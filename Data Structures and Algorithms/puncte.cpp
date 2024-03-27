/*


Containerul stochează coordonate (X, Y) ale unor puncte din plan ce reprezintă un
contur închis (ultimul punct este conectat cu primul punct). X si Y sunt valori întregi
pozitive nenule pe 32 biti, citite de la tastatura până se întâlnește valoarea 0.
Se citesc de la tastatura două valori reale pozitive (de tip double) D1 si D2. Se garantează
D2 > 2 * D1.

Dacă două puncte consecutive se află la distanța mai mica strict decât D1, atunci al
doilea punct se elimina. Dacă două puncte consecutive se afla la distanță mai mare strict
decât D2, atunci între cele 2 puncte se inserează un punct nou care se afla la mijlocul
segmentul determinat de cele 2 puncte inițiale. Se repetă aceasta procedură până când
cele 2 condiții (D1 și D2) sunt respectate. În final se va afișa perimetrul conturului
obținut / numărul de puncte.

Ajustarea coordonatelor se face pe tip întreg de 32 biti (prin trunchiere) . Calculul
distanțelor și a perimetrului se face pe tip double. Prelucrarea începe de la prima
pereche (X, Y) citită și se termină atunci când toate punctele respectă cele 2 condiții.


*/


#include <bits/stdc++.h>

using namespace std;

template<class T>
class nod {
public:
    T x;
    T y;
    nod<T> *next{nullptr};

    nod() = default;

    nod(T x, T y, nod<T> *next) : x(x), y(y), next(next) {}

    ~nod() = default;
};

template<class T>
class Lista {
    nod<T> *head{nullptr};
public:
    Lista() = default;

    ~Lista() {
        nod<T> *curr = head;

        while (curr != nullptr) {
            auto next = curr->next;

            curr->next = nullptr;
            delete curr;

            curr = next;
        }

        head = nullptr;
    }

    void pushfront(T const &data1, T const &data2) {
        head = new nod<T>(data1, data2, head);
    }

    void pushback(T const &data1, T const &data2) {
        if (head == nullptr) {
            pushfront(data1, data2);
        }

        nod<T> *curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = new nod<T>(data1, data2, curr->next);
    }

    void afisareCirculara() {
        auto curr = head;
        float perim = 0;
        int nr = 0;
        //curr = curr->next;
        while (curr->next != head) {

            float a = pow((curr->x - curr->next->x), 2);
            float b = pow((curr->y - curr->next->y), 2);
            float DIS = sqrt(a + b);
            perim += DIS;
            nr++;
            //cout << curr->x << " " << curr->y << endl;
            //cout << DIS << " ";

            curr = curr->next;
        }
        float a = pow((curr->x - curr->next->x), 2);
        float b = pow((curr->y - curr->next->y), 2);
        float DIS = sqrt(a + b);
        perim += DIS;
        nr++;

        cout << fixed << setprecision(3) << perim / nr;
        //cout << perim << " " << nr;
    }

    void reverse() {
        nod<T> *curr = head;
        nod<T> *prev{nullptr};
        nod<T> *next{nullptr};

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }


    void incircle() {
        auto aux = head;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = head;
    }

    void permutari(float P1, float P2) {
        bool ok;
        do {
            nod<T> *curr = head;
            ok = 1;
            while (curr->next != head) {

                float a = pow((curr->x - curr->next->x), 2);
                float b = pow((curr->y - curr->next->y), 2);
                float DIS = sqrt(a + b);

                if (DIS > P2) {
                    ok = 0;

                    int xx = curr->x + curr->next->x;
                    xx /= 2;
                    int yy = curr->y + curr->next->y;
                    yy /= 2;
                    curr->next = new nod<T>(xx, yy, curr->next);

                    curr = curr->next;
                }

                if (DIS < P1) {
                    ok = 0;

                    auto aux = curr->next;
                    curr->next = curr->next->next;
                    aux->next = nullptr;
                    delete aux;

                } else {
                    curr = curr->next;
                }
            }
        } while (ok != 1);
    }
};

int main() {
    Lista<float> myList;

    float x, y;

    while (cin >> x) {
        if (x == 0) {
            break;
        }
        cin >> y;
        myList.pushback(x, y);
    }
    //myList.reverse();
    double d1, d2;
    cin >> d1 >> d2;

     myList.incircle();
     myList.permutari(d1, d2);
     myList.afisareCirculara();

}