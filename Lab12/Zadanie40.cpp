#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

int sumaCyfr(int liczba)
{
    int suma = 0;
    while (liczba > 0) {
        suma += liczba % 10;
        liczba /= 10;
    }
    return suma;
}

bool zapiszDane(const char* nazwaPliku, int ilosc)
{
    FILE* dane = fopen(nazwaPliku, "w");
    if (dane == NULL) {
        return false;
    }

    for (int i = 0; i < ilosc; ++i) {
        int liczba = rand() % 999999 + 1;
        fprintf(dane, "%d\n", liczba);
    }

    fclose(dane);
    return true;
}

bool przetworzDane(const char* danePliku, const char* wynikPliku)
{
    FILE* dane = fopen(danePliku, "r");
    if (dane == NULL) {
        return false;
    }

    FILE* wynik = fopen(wynikPliku, "w");
    if (wynik == NULL) {
        fclose(dane);
        return false;
    }

    int liczba;
    while (fscanf(dane, "%d", &liczba) == 1) {
        fprintf(wynik, "%d\n", sumaCyfr(liczba));
    }

    fclose(dane);
    fclose(wynik);
    return true;
}

int main()
{
    srand(time(NULL));

    int ilosc = rand() % 1000 + 1;

    if (!zapiszDane("dane.txt", ilosc)) {
        cout << "Nie mozna utworzyc pliku dane.txt" << endl;
        return 1;
    }

    if (!przetworzDane("dane.txt", "wynik.txt")) {
        cout << "Nie mozna przetworzyc pliku dane.txt" << endl;
        return 1;
    }

    return 0;
}