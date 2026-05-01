#include <iostream>
#include <cstdio>

using namespace std;

bool pobierzParametry(const char* nazwaPliku, char& znak, int& ilosc)
{
    FILE* plik = fopen(nazwaPliku, "r");
    if (plik == NULL) {
        return false;
    }

    bool ok = fscanf(plik, "znak=%c\nilosc=%d", &znak, &ilosc) == 2;
    fclose(plik);
    return ok;
}

int main()
{
    char znak = '*';
    int ilosc = 0;

    if (!pobierzParametry("konfiguracja.txt", znak, ilosc) || ilosc < 0) {
        cout << "Niepoprawny plik konfiguracja.txt" << endl;
        return 1;
    }

    for (int i = 0; i < ilosc; ++i) {
        cout << znak;
    }
    cout << endl;

    return 0;
}
