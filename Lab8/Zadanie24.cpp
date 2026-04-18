#include <iostream>

using namespace std;

int main() {
    char wyraz[30];

    cout << "Podaj wyraz: ";
    cin >> wyraz;

    int dlugoscWyrazu = 0;
    while (wyraz[dlugoscWyrazu] != '\0') {
        ++dlugoscWyrazu;
    }

    int indeksLewy = 0;
    int indeksPrawy = dlugoscWyrazu - 1;
    bool czyPalindrom = true;

    while (indeksLewy < indeksPrawy) {
        if (wyraz[indeksLewy] != wyraz[indeksPrawy]) {
            czyPalindrom = false;
            break;
        }
        ++indeksLewy;
        --indeksPrawy;
    }

    if (czyPalindrom) {
        cout << "Podany wyraz jest palindromem";
    } else {
        cout << "Podany wyraz nie jest palindromem";
    }

    return 0;
}