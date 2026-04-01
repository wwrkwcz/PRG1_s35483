#include <iostream>
using namespace std;

int main()
{
    int liczbaElementow;
    int buforowaLiczba;
    int licznikZewnetrzny;
    int licznikWewnetrzny;
    int tablicaLiczb[100];

    cout << "Prosze podac liczbe elementow: ";
    cin >> liczbaElementow;

    cout << "Prosze podac " << liczbaElementow << " elementow: ";
    for (licznikZewnetrzny = 0; licznikZewnetrzny < liczbaElementow; licznikZewnetrzny = licznikZewnetrzny + 1)
    {
        cin >> tablicaLiczb[licznikZewnetrzny];
    }

    for (licznikZewnetrzny = 0; licznikZewnetrzny < liczbaElementow - 1; licznikZewnetrzny = licznikZewnetrzny + 1)
    {
        for (licznikWewnetrzny = 0; licznikWewnetrzny < liczbaElementow - 1 - licznikZewnetrzny; licznikWewnetrzny = licznikWewnetrzny + 1)
        {
            if (tablicaLiczb[licznikWewnetrzny] > tablicaLiczb[licznikWewnetrzny + 1])
            {
                buforowaLiczba = tablicaLiczb[licznikWewnetrzny];
                tablicaLiczb[licznikWewnetrzny] = tablicaLiczb[licznikWewnetrzny + 1];
                tablicaLiczb[licznikWewnetrzny + 1] = buforowaLiczba;
            }
        }
    }

    cout << "Posortowane elementy: ";
    for (licznikZewnetrzny = 0; licznikZewnetrzny < liczbaElementow; licznikZewnetrzny = licznikZewnetrzny + 1)
    {
        cout << tablicaLiczb[licznikZewnetrzny] << " ";
    }

    cout << endl;
    return 0;
}