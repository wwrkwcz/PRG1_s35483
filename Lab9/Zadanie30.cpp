#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

void wczytajRozmiar(int &rozmiarTablicy);
void wypiszTablice(int tablica[], int &rozmiarTablicy);
float obliczSrednia(int tablica[], int &rozmiarTablicy);
int policzWystapienia(int tablica[], int &rozmiarTablicy);
int policzNieparzyste(int tablica[], int &rozmiarTablicy);
int znajdzMin(int tablica[], int &rozmiarTablicy);
int znajdzMax(int tablica[], int &rozmiarTablicy);
void znajdzPareSasiednich(int tablica[], int &rozmiarTablicy);
int znajdzNajczestszy(int tablica[], int &rozmiarTablicy);
void odwracanieTablicy(int tablica[], int &rozmiarTablicy);
void kopiujTablice(int tablicaA[], int tablicaB[], int &rozmiarTablicy);

int main() {
    srand(time(NULL));

    int rozmiarTablicy;
    int tablicaA[100];
    int tablicaB[100];
    int zakresPoczatkowy;
    int zakresKoncowy;

    wczytajRozmiar(rozmiarTablicy);

    cout << "Podaj zakres liczb losowych [a, b]:" << endl;
    cout << "a: ";
    cin >> zakresPoczatkowy;
    cout << "b: ";
    cin >> zakresKoncowy;

    if (zakresPoczatkowy > zakresKoncowy) {
        int wartoscTymczasowa = zakresPoczatkowy;
        zakresPoczatkowy = zakresKoncowy;
        zakresKoncowy = wartoscTymczasowa;
    }

    for (int indeks = 0; indeks < rozmiarTablicy; ++indeks) {
        tablicaA[indeks] = rand() % (zakresKoncowy - zakresPoczatkowy + 1) + zakresPoczatkowy;
    }

    cout << endl << "Tablica wygenerowana" << endl;
    wypiszTablice(tablicaA, rozmiarTablicy);

    cout << endl << "1. Srednia arytmetyczna: " << obliczSrednia(tablicaA, rozmiarTablicy) << endl;

    cout << endl << "2. Liczba wystapien elementu." << endl;
    int licznikWystapien = policzWystapienia(tablicaA, rozmiarTablicy);
    cout << "Element wystapil: " << licznikWystapien << " razy." << endl;

    cout << endl << "3. Liczba elementow nieparzystych i ich suma." << endl;
    policzNieparzyste(tablicaA, rozmiarTablicy);

    cout << endl << "4. Element minimalny." << endl;
    znajdzMin(tablicaA, rozmiarTablicy);

    cout << endl << "5. Element maksymalny." << endl;
    znajdzMax(tablicaA, rozmiarTablicy);

    cout << endl << "6. Para sasiednich elementow o najwiekszej sumie." << endl;
    znajdzPareSasiednich(tablicaA, rozmiarTablicy);

    cout << endl << "7. Element najczesciej wystepujacy: " << znajdzNajczestszy(tablicaA, rozmiarTablicy) << endl;

    cout << endl << "8. Przestawienie kolejnosci elementow w tablicy (odwracanie)." << endl;
    odwracanieTablicy(tablicaA, rozmiarTablicy);
    cout << "Tablica po odwroceniu:" << endl;
    wypiszTablice(tablicaA, rozmiarTablicy);

    cout << endl << "9. Kopiowanie tablicy A do B." << endl;
    kopiujTablice(tablicaA, tablicaB, rozmiarTablicy);
    cout << "Tablica B (kopia):" << endl;
    wypiszTablice(tablicaB, rozmiarTablicy);

    return 0;
}
void czyt_dane(int &n) {
    do {
        cout << "Podaj rozmiar tablicy n (0 < n <= 100): ";
        cin >> n;
    } while (n <= 0 || n > 100);
}

void pisz_tab(int A[], int &n) {
    for (int i = 0; i < n; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
}

float srednia(int A[], int &n) {
    if (n == 0) return 0.0f;

    long long suma = 0;
    for (int i = 0; i < n; ++i) {
        suma += A[i];
    }
    return (float)suma / n;
}

int ile(int A[], int &n) {
    int szukana;
    cout << "Podaj element do zliczenia: ";
    cin >> szukana;

    int licznik = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i] == szukana) {
            ++licznik;
        }
    }
    return licznik;
}

int nieparzyste(int A[], int &n) {
    int licznik = 0;
    long long suma = 0;
    for (int i = 0; i < n; ++i) {
        if (A[i] % 2 != 0) {
            ++licznik;
            suma += A[i];
        }
    }
    cout << "Liczba elementow nieparzystych: " << licznik << endl;
    cout << "Suma elementow nieparzystych: " << suma << endl;
    return licznik;
}

int min(int A[], int &n) {
    if (n == 0) return 0;

    int minWartosc = A[0];
    int minIndeks = 0;
    for (int i = 1; i < n; ++i) {
        if (A[i] < minWartosc) {
            minWartosc = A[i];
            minIndeks = i;
        }
    }
    cout << "Element minimalny: " << minWartosc << " na indeksie: " << minIndeks << endl;
    return minWartosc;
}

int max(int A[], int &n) {
    if (n == 0) return 0;

    int maxWartosc = A[0];
    int maxIndeks = 0;
    for (int i = 1; i < n; ++i) {
        if (A[i] > maxWartosc) {
            maxWartosc = A[i];
            maxIndeks = i;
        }
    }
    cout << "Element maksymalny: " << maxWartosc << " na indeksie: " << maxIndeks << endl;
    return maxWartosc;
}

void sasiednie(int A[], int &n) {
    if (n < 2) {
        cout << "Za malo elementow, aby znalezc pare sasiednich." << endl;
        return;
    }

    long long maxSuma = LLONG_MIN;
    int indeks1 = -1;
    int indeks2 = -1;

    for (int i = 0; i < n - 1; ++i) {
        long long aktualnaSuma = (long long)A[i] + A[i + 1];
        if (aktualnaSuma > maxSuma) {
            maxSuma = aktualnaSuma;
            indeks1 = i;
            indeks2 = i + 1;
        }
    }

    cout << "Para sasiednich elementow o najwiekszej sumie (" << maxSuma << "): "
         << A[indeks1] << " (indeks " << indeks1 << ") i "
         << A[indeks2] << " (indeks " << indeks2 << ")" << endl;
}

int najczestszy(int A[], int &n) {
    if (n == 0) return 0;

    int maxCzestosc = 0;
    int najczestszyElement = A[0];

    for (int i = 0; i < n; ++i) {
        int aktualnyLicznik = 0;
        for (int j = 0; j < n; ++j) {
            if (A[j] == A[i]) {
                ++aktualnyLicznik;
            }
        }
        if (aktualnyLicznik > maxCzestosc) {
            maxCzestosc = aktualnyLicznik;
            najczestszyElement = A[i];
        }
    }
    return najczestszyElement;
}

void przestawianie(int A[], int &n) {
    for (int i = 0; i < n / 2; ++i) {
        int tymczasowa = A[i];
        A[i] = A[n - 1 - i];
        A[n - 1 - i] = tymczasowa;
    }
}

void kopiowanie(int A[], int B[], int &n) {
    for (int i = 0; i < n; ++i) {
        B[i] = A[i];
    }
}