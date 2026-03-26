#include <iostream>

using namespace std;

int main() {
    int szerokoscProstokata;
    int wysokoscProstokata;
    char znakWypelnienia;

    cout << "Podaj szerokosc a: ";
    cin >> szerokoscProstokata;

    cout << "Podaj wysokosc b: ";
    cin >> wysokoscProstokata;

    cout << "Podaj znak: ";
    cin >> znakWypelnienia;

    for (int indeksWiersza = 0; indeksWiersza < wysokoscProstokata; indeksWiersza++) {
        for (int indeksKolumny = 0; indeksKolumny < szerokoscProstokata; indeksKolumny++) {
            if (indeksWiersza == 0) {
                cout << znakWypelnienia;
            } else if (indeksWiersza == wysokoscProstokata - 1) {
                cout << znakWypelnienia;
            } else {
                if (indeksKolumny == 0) {
                    cout << znakWypelnienia;
                } else if (indeksKolumny == szerokoscProstokata - 1) {
                    cout << znakWypelnienia;
                } else {
                    cout << " ";
                }
            }
        }
        cout << endl;
    }

    return 0;
}