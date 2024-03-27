/*


Gigel a învățat la școală despre următoarele forme geometrice: cub, sferă, paralelipiped
dreptunghic și cilindru. Gigel a găsit în casă mai multe obiecte ce sunt forme geometrice de
bază și vrea să le sorteze după raportul volum / suprafață. Gigel știe să spună despre un
obiect ce formă este respectiv ce dimensiuni are, dar nu știe să calculeze volumul și
suprafața astfel încât vă cere ajutorul.



*/



#include <bits/stdc++.h>

using namespace std;

class Figura {
public:
    virtual double volum() = 0;

    virtual double arie() = 0;

};

class Cub : public Figura {
protected:
    double latura;
public:
    void init(double x) {
        latura = x;
    }

    double volum() {
        return latura * latura * latura;
    }

    double arie() {
        return 6 * latura * latura;
    }
};

class Sfera : public Figura {
protected:
    double raza;
public:
    void init(double x) {
        raza = x;
    }

    double volum() {
        double pi = 3.1415926535;
        double r3 = raza * raza * raza;
        double v = 4 * pi * r3;
        return v / 3;
    }

    double arie() {
        double r2 = raza * raza;
        double pi = 3.1415926535;
        return 4 * pi * r2;
    }
};

class Paralelipiped : public Figura {
protected:
    double lungime;
    double latime;
    double inaltime;

public:

    void init(double x, double y, double z) {
        lungime = x;
        latime = y;
        inaltime = z;
    }

    double volum() {
        return lungime * latime * inaltime;
    }

    double arie() {
        return 2 * ((lungime * latime) + (lungime * inaltime) + (latime * inaltime));
    }
};

class Cilindru : public Figura {
protected:
    double raza;
    double inaltime;

public:
    void init(double x, double y) {
        raza = x;
        inaltime = y;
    }

    double volum() {
        double pi = 3.1415926535;
        double r2 = raza * raza;
        return pi * r2 * inaltime;
    }

    double arie() {
        double pi = 3.1415926535;
        double pir = pi * raza;
        return 2 * pir * (raza + inaltime);
    }
};

struct forme {
    double volum;
    double suprafata;
};

int main() {
    //Cilindru c;
    cout << fixed << setprecision(3);
    //c.init(4, 4);
    //cout << c.volum();
    string s;
    forme a[1005];
    int l = 0;
    while (cin >> s) {
        if (s == "CUB") {
            Cub cub;
            double x;
            cin >> x;
            cub.init(x);
            a[++l].volum = cub.volum();
            a[l].suprafata = cub.arie();
        }
        if (s == "SFERA") {
            Sfera sfera;
            double x;
            cin >> x;
            sfera.init(x);
            sfera.init(x);
            a[++l].volum = sfera.volum();
            a[l].suprafata = sfera.arie();
        }
        if (s == "PARALELIPIPED") {
            Paralelipiped paral;
            double x, y, z;
            cin >> x >> y >> z;
            paral.init(x, y, z);
            a[++l].volum = paral.volum();
            a[l].suprafata = paral.arie();
        }
        if (s == "CILINDRU") {
            Cilindru cil;
            double x, y;
            cin >> x >> y;
            cil.init(x, y);
            a[++l].volum = cil.volum();
            a[l].suprafata = cil.arie();
        }
    }
    double rap[1005];
    for (int i = 1; i <= l; i++)
        rap[i] = a[i].volum / a[i].suprafata;

    for (int i = 1; i < l; i++)
        for (int j = i + 1; j <= l; j++)
            if (rap[i] > rap[j])
                swap(rap[i], rap[j]), swap(a[i], a[j]);

    for (int i = 1; i < l; i++)
        for (int j = i + 1; j <= l; j++)
            if (rap[i] == rap[j] && a[i].volum < a[j].volum)
                swap(a[i], a[j]);

    for (int i = 1; i <= l; i++)
        cout << a[i].volum << " " << a[i].suprafata << endl;
}