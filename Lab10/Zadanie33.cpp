#include <iostream>

using namespace std;

void wypelnijTablice(int tablica[], int rozmiarTablicy, int wartoscStartowa)
{
    for (int i = 0; i < rozmiarTablicy; ++i) {
        tablica[i] = wartoscStartowa + i;
    }
}

int main()
{
    int rozmiarTablicy;
    int wartoscStartowa;
    int tablica[100];

    cout << "Prosze podac rozmiar tablicy: ";
    cin >> rozmiarTablicy;

    cout << "Prosze podac wartosc startowa: ";
    cin >> wartoscStartowa;

    wypelnijTablice(tablica, rozmiarTablicy, wartoscStartowa);

    cout << "Oto zawartosc tablicy:" << endl;
    for (int i = 0; i < rozmiarTablicy; ++i) {
        cout << tablica[i] << " ";
    }

    cout << endl;
    return 0;
}