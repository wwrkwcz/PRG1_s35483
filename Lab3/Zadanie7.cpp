#include <iostream>

using namespace std;

int main() {
    int pierwszaLiczba, drugaLiczba, tymczasowaPierwsza, tymczasowaDruga, nww;

    cout << "Podaj pierwsza liczbe calkowita: ";
    cin >> pierwszaLiczba;
    cout << "Podaj druga liczbe calkowita: ";
    cin >> drugaLiczba;

    if (pierwszaLiczba > 0 && drugaLiczba > 0) {
        tymczasowaPierwsza = pierwszaLiczba;
        tymczasowaDruga = drugaLiczba;

        while (tymczasowaPierwsza != tymczasowaDruga) {
            if (tymczasowaPierwsza > tymczasowaDruga) {
                tymczasowaDruga += drugaLiczba;
            } else {
                tymczasowaPierwsza += pierwszaLiczba;
            }
        }

        nww = tymczasowaPierwsza;
    } else {
        nww = 0;
    }

    cout << "NWW podanych przez ciebie liczb calkowitych wynosi: " << nww << endl;

    return 0;
}