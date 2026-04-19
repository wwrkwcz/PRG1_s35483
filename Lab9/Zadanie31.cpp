#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void wczytajRozmiar(int &rozmiarTablicy);
void wypiszTablice(int tablica[], int &rozmiarTablicy);
void sortujSzybko(int tablica[], int &rozmiarTablicy);
void sortowanieSzybkie(int tablica[], int indeksPoczatkowy, int indeksKoncowy);
int podzielTablice(int tablica[], int indeksPoczatkowy, int indeksKoncowy);

int main() {
    srand(time(NULL));

    int rozmiarTablicy;
    int tablica[100];
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
        tablica[indeks] = rand() % (zakresKoncowy - zakresPoczatkowy + 1) + zakresPoczatkowy;
    }

    cout << endl << "Tablica wygenerowana." << endl;
    wypiszTablice(tablica, rozmiarTablicy);

    cout << endl << "Sortowanie quicksort." << endl;
    sortujSzybko(tablica, rozmiarTablicy);
    cout << "Tablica po posortowaniu:" << endl;
    wypiszTablice(tablica, rozmiarTablicy);

    return 0;
}

void wczytajRozmiar(int &rozmiarTablicy) {
    do {
        cout << "Podaj rozmiar tablicy n (0 < n <= 100): ";
        cin >> rozmiarTablicy;
    } while (rozmiarTablicy <= 0 || rozmiarTablicy > 100);
}

void wypiszTablice(int tablica[], int &rozmiarTablicy) {
    for (int indeks = 0; indeks < rozmiarTablicy; ++indeks) {
        cout << tablica[indeks] << " ";
    }
    cout << endl;
}

void sortujSzybko(int tablica[], int &rozmiarTablicy) {
    if (rozmiarTablicy > 1) {
        sortowanieSzybkie(tablica, 0, rozmiarTablicy - 1);
    }
}

void sortowanieSzybkie(int tablica[], int indeksPoczatkowy, int indeksKoncowy) {
    if (indeksPoczatkowy < indeksKoncowy) {
        int indeksPodzialu = podzielTablice(tablica, indeksPoczatkowy, indeksKoncowy);
        sortowanieSzybkie(tablica, indeksPoczatkowy, indeksPodzialu - 1);
        sortowanieSzybkie(tablica, indeksPodzialu + 1, indeksKoncowy);
    }
}

int podzielTablice(int tablica[], int indeksPoczatkowy, int indeksKoncowy) {
    int pivot = tablica[indeksKoncowy];
    int indeks = indeksPoczatkowy - 1;

    for (int aktualny = indeksPoczatkowy; aktualny <= indeksKoncowy - 1; ++aktualny) {
        if (tablica[aktualny] <= pivot) {
            ++indeks;
            int wartoscTymczasowa = tablica[indeks];
            tablica[indeks] = tablica[aktualny];
            tablica[aktualny] = wartoscTymczasowa;
        }
    }

    int wartoscTymczasowa = tablica[indeks + 1];
    tablica[indeks + 1] = tablica[indeksKoncowy];
    tablica[indeksKoncowy] = wartoscTymczasowa;

    return indeks + 1;
}