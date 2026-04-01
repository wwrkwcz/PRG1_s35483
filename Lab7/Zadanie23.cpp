#include <iostream>
using namespace std;

int main()
{
    int liczbaWierszyA;
    int liczbaKolumnA;
    int liczbaWierszyB;
    int liczbaKolumnB;
    int macierzA[100][100];
    int macierzB[100][100];
    int macierzC[100][100];

    cout << "Podaj liczbe wierszy i kolumn pierwszej macierzy: " << endl;
    cin >> liczbaWierszyA >> liczbaKolumnA;

    cout << "Podaj liczbe wierszy i kolumn drugiej macierzy:" << endl;
    cin >> liczbaWierszyB >> liczbaKolumnB;

    if (liczbaWierszyA <= 0 || liczbaKolumnA <= 0 || liczbaWierszyB <= 0 || liczbaKolumnB <= 0 || liczbaWierszyA != liczbaWierszyB || liczbaKolumnA != liczbaKolumnB)
    {
        cout << "BLAD";
        return 0;
    }

    cout << "Podaj elementy pierwszej macierzy:" << endl;
    for (int licznikWierszy = 0; licznikWierszy < liczbaWierszyA; licznikWierszy = licznikWierszy + 1)
    {
        for (int licznikKolumny = 0; licznikKolumny < liczbaKolumnA; licznikKolumny = licznikKolumny + 1)
        {
            cin >> macierzA[licznikWierszy][licznikKolumny];
        }
    }

    cout << "Podaj elementy drugiej macierzy:" << endl;
    for (int licznikWierszy = 0; licznikWierszy < liczbaWierszyB; licznikWierszy = licznikWierszy + 1)
    {
        for (int licznikKolumny = 0; licznikKolumny < liczbaKolumnB; licznikKolumny = licznikKolumny + 1)
        {
            cin >> macierzB[licznikWierszy][licznikKolumny];
        }
    }

    cout << "Wynik dodawania macierzy to:" << endl;
    for (int licznikWierszy = 0; licznikWierszy < liczbaWierszyA; licznikWierszy = licznikWierszy + 1)
    {
        for (int licznikKolumny = 0; licznikKolumny < liczbaKolumnA; licznikKolumny = licznikKolumny + 1)
        {
            macierzC[licznikWierszy][licznikKolumny] = macierzA[licznikWierszy][licznikKolumny] + macierzB[licznikWierszy][licznikKolumny];
            cout << macierzC[licznikWierszy][licznikKolumny] << " ";
        }
        cout << endl;
    }

    return 0;
}