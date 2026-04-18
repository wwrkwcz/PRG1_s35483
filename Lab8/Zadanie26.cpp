#include <iostream>
#include <ctime>

using namespace std;

int main() {
    int rozmiarTablicy;
    int indeks;
    int tablicaLiczb[10000];
    int* wskaznikTablicy;
    clock_t czasStart;
    clock_t czasStop;

    cout << "Podaj liczbe elementow tablicy, maksymalnie 10000: ";
    cin >> rozmiarTablicy;
    if (rozmiarTablicy > 10000) {
        rozmiarTablicy = 10000;
    }

    czasStart = clock();
    for (indeks = 0; indeks < rozmiarTablicy; ++indeks) {
        tablicaLiczb[indeks] = indeks;
        tablicaLiczb[indeks] = tablicaLiczb[indeks] + 50;
    }
    for (indeks = 0; indeks < rozmiarTablicy; ++indeks) {
        tablicaLiczb[indeks];
    }
    czasStop = clock();
    cout << "Czas bez uzycia wskaznikow: " << (czasStop - czasStart) << endl;

    wskaznikTablicy = tablicaLiczb;
    czasStart = clock();
    for (indeks = 0; indeks < rozmiarTablicy; ++indeks) {
        *(wskaznikTablicy + indeks) = indeks;
        *(wskaznikTablicy + indeks) = *(wskaznikTablicy + indeks) + 50;
    }
    for (indeks = 0; indeks < rozmiarTablicy; ++indeks) {
        *(wskaznikTablicy + indeks);
    }
    czasStop = clock();
    cout << "Czas z uzyciem wskaznikow: " << (czasStop - czasStart) << endl;

    return 0;
}