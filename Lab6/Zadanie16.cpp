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
            cout << znakWypelnienia;
        }
        cout << endl;
    }

    return 0;
}