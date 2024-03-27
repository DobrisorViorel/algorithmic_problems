/*

Folosind derivare, moșteniri, virtualizare și polimorfism să se implementeze un program care gestionează serviciile oferite de companie de telefonie mobilă.

Serviciile oferite sunt:

A – Abonament Standard. Costul abonamentului este de 50 lei. Abonamentul include 100 minute, 100 SMS și 10GB internet. 
Dacă sunt depășite cele 100 minute utilizatorul plătește 0.1 lei pe minut în plus consumat. Dacă sunt depășite mesajele, 
clientul plătește 0.5 lei pe SMS în plus. Dacă este depășită limita de internet, utilizatorul plătește 1 leu pentru fiecare GB în plus.

B – Abonament Standard Plus. Costul abonamnetului este de 75 lei. Abonamentul include 200 minute, 200 SMS și 15GB. 
Dacă sunt depășite cele 200 minute utilizatorul plătește 0.15 lei pe minut în plus consumat. Dacă sunt depășite mesajele, 
clientul plătește 0.75 lei pe SMS în plus. Dacă este depășită limita de internet, utilizatorul plătește 1.5 leu pentru fiecare GB în plus.

Clienții își achiziționează un abonament pe baza ID-ului propriu care este un număr pe 64 biți.

Din N înregistrări din gestiune, determinați ID-ul clientului care plătește cel mai mult pentru serviciile oferite. 
Un client poate avea unul sau mai multe abonamente de același fel sau diferite.

*/


#include <bits/stdc++.h>

using namespace std;

class Servicii {
protected:
    int ID;
public:
    Servicii(int id) : ID(id) {}

    virtual float cost() = 0;
};

class AbonamentStandard : public Servicii {
    int minute_folosite;
    int sms_folosite;
    int gb_folositi;
public:
    AbonamentStandard(int id, int minuteFolosite, int smsFolosite, int gbFolositi) : Servicii(id),
                                                                                     minute_folosite(minuteFolosite),
                                                                                     sms_folosite(smsFolosite),
                                                                                     gb_folositi(gbFolositi) {}

    float cost() override {
        double sum = 50;
        if (minute_folosite > 100) {
            sum += (minute_folosite - 100) * 0.1;
        }
        if (sms_folosite > 100) {
            sum += (sms_folosite - 100) * 0.5;
        }
        if (gb_folositi > 10) {
            sum += (gb_folositi - 10) * 1;
        }
        return sum;
    }
};

class AbonamentStandardPlus : public Servicii {
    int minute_folosite;
    int sms_folosite;
    int gb_folositi;
public:
    AbonamentStandardPlus(int id, int minuteFolosite, int smsFolosite, int gbFolositi) : Servicii(id), minute_folosite(
            minuteFolosite), sms_folosite(smsFolosite), gb_folositi(gbFolositi) {}

    float cost() override {
        double sum = 75;
        if (minute_folosite > 200) {
            sum += (minute_folosite - 200) * 0.15;
        }
        if (sms_folosite > 200) {
            sum += (sms_folosite - 200) * 0.75;
        }
        if (gb_folositi > 15) {
            sum += (gb_folositi - 15) * 1.5;
        }
        return sum;
    }
};

class Client {
    vector<Servicii *> servicii;
public:
    Client(const vector<Servicii *> &servicii) : servicii(servicii) {}

    int ClientMax() {
        double pret_maxim = 0;
        int p = 1, i = 1;
        for (auto serviciu: servicii) {
            if (serviciu->cost() >= pret_maxim) {
                pret_maxim = serviciu->cost();
                p = i;
            }
            i ++;
        }
        return p;
    }
};

int main() {
    int N, ID_client, Minute_folosite_total, SMS_folosite_total, GB_folosit;
    string Tip_Abonament;
    vector<Servicii *> servicii;
    int v[10000], l = 0;
    cin >> N;
    while (N --) {
        cin >> ID_client >> Tip_Abonament >> Minute_folosite_total >> SMS_folosite_total >> GB_folosit;
        v[++l] = ID_client;
        if (Tip_Abonament == "A") {
            servicii.push_back(new AbonamentStandard{ID_client, Minute_folosite_total, SMS_folosite_total, GB_folosit});
        } else if (Tip_Abonament == "B") {
            servicii.push_back(new AbonamentStandardPlus{ID_client, Minute_folosite_total, SMS_folosite_total, GB_folosit});
        }
    }
    auto client = new Client{servicii};
    int a[1000], l2 = 0;
    int p = 1, lg = 1, mx = 0;
    int f[10000] = {0};

    for(auto serviciu : servicii) {
        f[v[lg]] += serviciu->cost();
        lg ++;
    }
    
    for (int i = 1; i <= 10000; i ++)
        if (f[i] >= mx) {
            mx = f[i];
            p = i;
        }
    cout << p;
}