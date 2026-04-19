#include <iostream>

using namespace std;

void konwertujLiczbe(int liczba, int podstawa)
{
    if (liczba < 0 || podstawa < 2) {
        cout << "BLAD" << endl;
        return;
    }

    if (liczba == 0) {
        cout << 0 << endl;
        return;
    }

    int cyfry[32];
    int iloscCyfr = 0;

    while (liczba > 0) {
        cyfry[iloscCyfr] = liczba % podstawa;
        liczba = liczba / podstawa;
        iloscCyfr = iloscCyfr + 1;
    }

    for (int indeks = iloscCyfr - 1; indeks >= 0; --indeks) {
        cout << cyfry[indeks];
    }

    cout << endl;
}

int main()
{
    int liczba;
    int podstawa;

    cout << "Prosze podac liczbe naturalna: ";
    cin >> liczba;

    cout << "Prosze podac podstawe systemu: ";
    cin >> podstawa;

    konwertujLiczbe(liczba, podstawa);
    return 0;
}