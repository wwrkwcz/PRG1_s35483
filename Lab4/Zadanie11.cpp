#include <iostream>

using namespace std;

const double stawkaA = 15.0;
const double stawkaB = 25.0;
const double stawkaC = 30.0;
const double stawkaD = 35.0;

const double progPodatkowy1 = 700.0;
const double progPodatkowy2 = 1200.0;
const double stawkaPodatkowa1 = 0.15;
const double stawkaPodatkowa2 = 0.20;
const double stawkaPodatkowa3 = 0.25;

double obliczBrutto(double stawka, double godziny) {
    if (godziny <= 40) {
        return godziny * stawka;
    } else {
        return 40 * stawka + (godziny - 40) * (stawka * 2);
    }
}

double obliczPodatek(double brutto) {
    if (brutto <= progPodatkowy1) {
        return stawkaPodatkowa1 * brutto;
    } else if (brutto <= progPodatkowy2) {
        return stawkaPodatkowa2 * brutto;
    } else {
        return stawkaPodatkowa3 * brutto;
    }
}

int main() {
    int wybranaKategoria, decyzjaUzytkownika = 1;
    double liczbaGodzin, stawkaGodzinowa, zarobekBrutto, podatek, zarobekNetto;
    
    while (decyzjaUzytkownika == 1) {
        cout << "Wybierz kategorie zaszeregowania:" << endl;
        cout << "1 - Kategoria A, czyli " << stawkaA << " zl/godz." << endl;
        cout << "2 - Kategoria B, czyli " << stawkaB << " zl/godz." << endl;
        cout << "3 - Kategoria C, czyli " << stawkaC << " zl/godz." << endl;
        cout << "4 - Kategoria D, czyli " << stawkaD << " zl/godz." << endl;
        cout << "Wybrana kategoria: ";
        cin >> wybranaKategoria;
        
        if (wybranaKategoria == 1) {
            stawkaGodzinowa = stawkaA;
        } else if (wybranaKategoria == 2) {
            stawkaGodzinowa = stawkaB;
        } else if (wybranaKategoria == 3) {
            stawkaGodzinowa = stawkaC;
        } else if (wybranaKategoria == 4) {
            stawkaGodzinowa = stawkaD;
        } else {
            cout << "Nie istnieje taka kategoria" << endl;
            continue;
        }
        
        cout << "Podac liczbe przepracowanych godzin w tygodniu: ";
        cin >> liczbaGodzin;
        
        zarobekBrutto = obliczBrutto(stawkaGodzinowa, liczbaGodzin);
        podatek = obliczPodatek(zarobekBrutto);
        zarobekNetto = zarobekBrutto - podatek;
        
        cout << "Zarobek brutto: " << zarobekBrutto << " zl" << endl;
        cout << "Zarobek netto: " << zarobekNetto << " zl" << endl;
        
        cout << "Chcesz uzyc programu jeszcze raz?:" << endl;
        cout << "1 - Tak" << endl;
        cout << "2 - Nie" << endl;
        cout << "Decyzja: ";
        cin >> decyzjaUzytkownika;
    }
    
    cout << "Koniec programu" << endl;
    return 0;
}