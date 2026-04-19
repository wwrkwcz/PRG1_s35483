#include <iostream>

using namespace std;

int czyPosortowane(int tablica[], int rozmiar, char kierunek)
{
    if (kierunek != 'r' && kierunek != 'm') {
        return -1;
    }

    if (kierunek == 'r') {
        for (int i = 0; i < rozmiar - 1; ++i) {
            if (tablica[i] > tablica[i + 1]) {
                return 0;
            }
        }
    }

    if (kierunek == 'm') {
        for (int i = 0; i < rozmiar - 1; ++i) {
            if (tablica[i] < tablica[i + 1]) {
                return 0;
            }
        }
    }

    return 1;
}

int main()
{
    int rozmiarTablicy;
    char kierunekSortowania;
    int tablica[100];

    cout << "Prosze podac rozmiar tablicy: ";
    cin >> rozmiarTablicy;

    cout << "Prosze podac elementy tablicy: ";
    for (int i = 0; i < rozmiarTablicy; ++i) {
        cin >> tablica[i];
    }

    cout << "Prosze podac opcje: r - rosnaco, m - malejaco: ";
    cin >> kierunekSortowania;

    cout << czyPosortowane(tablica, rozmiarTablicy, kierunekSortowania) << endl;
    return 0;
}