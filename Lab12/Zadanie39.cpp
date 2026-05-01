#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    FILE* plik = fopen("konfiguracja.txt", "r");
    if (plik == NULL) {
        cout << "Nie mozna otworzyc pliku konfiguracja.txt" << endl;
        return 1;
    }

    char znak = '*';
    int ilosc = 0;

    if (fscanf(plik, "znak=%c\nilosc=%d", &znak, &ilosc) != 2) {
        cout << "Niepoprawny plik konfiguracja.txt" << endl;
        fclose(plik);
        return 1;
    }

    fclose(plik);

    for (int i = 0; i < ilosc; ++i) {
        cout << znak;
    }
    cout << endl;

    return 0;
}