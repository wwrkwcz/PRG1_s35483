#include <iostream>

using namespace std;

bool czyPierwsza(int sprawdzanaLiczba) {
    if (sprawdzanaLiczba <= 1) return false;

    for (int dzielnikPetli = 2; dzielnikPetli * dzielnikPetli <= sprawdzanaLiczba; dzielnikPetli++) {
        if (sprawdzanaLiczba % dzielnikPetli == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int wyborUzytkownika = 1;

    while (wyborUzytkownika == 1) {
        cout << "Podaj liczbe n: ";
        int gornaGranica;
        cin >> gornaGranica;

        cout << "Liczby pierwsze z przedzialu <2," << gornaGranica << "> to: ";

        for (int liczbaPetli = 2; liczbaPetli <= gornaGranica; liczbaPetli++) {
            if (czyPierwsza(liczbaPetli)) {
                cout << liczbaPetli << " ";
            }
        }

        cout << endl;
        cout << "Chcesz uzyc programu jeszcze raz?" << endl;
        cout << "1 - Tak" << endl;
        cout << "2 - Nie" << endl;
        cout << "Decyzja: ";

        cin >> wyborUzytkownika;
        system("cls");
    }

    return 0;
}
