#include <iostream>
#include <ctime>

using namespace std;

int obliczWygrana(int rzutPierwszy, int rzutDrugi) {
    int wygrana;
    if (rzutPierwszy % 2 == 0) {
        if (rzutDrugi == 2 || rzutDrugi == 4 || rzutDrugi == 5) {
            wygrana = rzutPierwszy + 3 * rzutDrugi;
        } else {
            wygrana = 2 * rzutDrugi;
        }
    } else {
        if (rzutDrugi == 2 || rzutDrugi == 4 || rzutDrugi == 5) {
            if (rzutPierwszy == rzutDrugi) {
                wygrana = 5 * rzutPierwszy + 3;
            } else {
                wygrana = 2 * rzutDrugi + rzutPierwszy;
            }
        } else {
            if (rzutPierwszy < rzutDrugi) {
                wygrana = rzutPierwszy + 4;
            } else {
                wygrana = rzutDrugi + 4;
            }
        }
    }
    if (rzutPierwszy == 5 && rzutDrugi == 5) {
        wygrana += 5;
    }
    return wygrana;
}

int main() {
    srand(time(NULL));
    int rzutPierwszy, rzutDrugi, wygranaGracza, sposobGry, czyKontynuowac = 1;
    
    while (czyKontynuowac == 1) {
        cout << "Wybierz sposob gry:" << endl;
        cout << "1 - Wczytanie wynikow z klawiatury" << endl;
        cout << "2 - Wylosowanie wynikow" << endl;
        cout << "Wybrany sposob gry: ";
        cin >> sposobGry;
        
        if (sposobGry == 1) {
            cout << "Podaj wynik pierwszego rzutu: ";
            cin >> rzutPierwszy;
            cout << "Podaj wynik drugiego rzutu: ";
            cin >> rzutDrugi;
        } else if (sposobGry == 2) {
            rzutPierwszy = rand() % 6 + 1;
            rzutDrugi = rand() % 6 + 1;
            cout << "Wylosowany wynik pierwszego rzutu: " << rzutPierwszy << ", Wylosowany wynik drugiego rzutu: " << rzutDrugi << endl;
        } else {
            cout << "Nie istnieje taki sposob gry" << endl;
            continue;
        }
        
        wygranaGracza = obliczWygrana(rzutPierwszy, rzutDrugi);
        cout << "Wygrana: " << wygranaGracza << endl;
        
        cout << "Chcesz uzyc programu jeszcze raz?:" << endl;
        cout << "1 - Tak" << endl;
        cout << "2 - Nie" << endl;
        cout << "Decyzja: ";
        cin >> czyKontynuowac;
        
        system("cls");
    }
    
    cout << "Koniec programu" << endl;
    return 0;
}