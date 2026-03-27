#include <iostream>
#include <cmath>

using namespace std;

bool czyDoskonala(int sprawdzanaLiczba) {
    int sumaDzielnikow = 0;
    int dzielnikPetli = sqrt(sprawdzanaLiczba);

    while (dzielnikPetli > 1) {
        if (sprawdzanaLiczba % dzielnikPetli == 0) {
            sumaDzielnikow += dzielnikPetli;

            int drugiDzielnik = sprawdzanaLiczba / dzielnikPetli;
            if (drugiDzielnik != dzielnikPetli) {
                sumaDzielnikow += drugiDzielnik;
            }
        }

        dzielnikPetli--;
    }

    sumaDzielnikow += 1;

    return sumaDzielnikow == sprawdzanaLiczba;
}

int main() {
    int wyborUzytkownika = 1;

    while (wyborUzytkownika == 1) {
        cout << "Podaj liczbe: ";
        int sprawdzanaLiczba;
        cin >> sprawdzanaLiczba;

        if (czyDoskonala(sprawdzanaLiczba)) {
            cout << "Jest to liczba doskonala" << endl;
        } else {
            cout << "Nie jest to liczba doskonala" << endl;
        }

        cout << "Chcesz uzyc programu jeszcze raz?" << endl;
        cout << "1 - Tak" << endl;
        cout << "2 - Nie" << endl;
        cout << "Decyzja: ";

        cin >> wyborUzytkownika;
        system("cls");
    }

    return 0;
}
