#include <iostream>

using namespace std;

int main() {
    int wyborOperacji;
    double pierwszaLiczba, drugaLiczba;

    while (true) {
        cout << endl << "Wybierz operacje:" << endl;
        cout << "0. Zamknij program" << endl;
        cout << "1. Dodawanie" << endl;
        cout << "2. Odejmowanie" << endl;
        cout << "3. Mnozenie" << endl;
        cout << "4. Dzielenie" << endl;
        cout << "Wybrana operacja: ";
        cin >> wyborOperacji;

        if (wyborOperacji == 0) {
            cout << "Koniec programu" << endl;
            break;
        } else if (wyborOperacji >= 1 && wyborOperacji <= 4) {
            cout << "Podaj pierwsza liczbe: ";
            cin >> pierwszaLiczba;
            cout << "Podaj druga liczbe: ";
            cin >> drugaLiczba;

            if (wyborOperacji == 1) {
                cout << "Wynik: " << pierwszaLiczba + drugaLiczba << endl;
            } else if (wyborOperacji == 2) {
                cout << "Wynik: " << pierwszaLiczba - drugaLiczba << endl;
            } else if (wyborOperacji == 3) {
                cout << "Wynik: " << pierwszaLiczba * drugaLiczba << endl;
            } else if (wyborOperacji == 4) {
                if (drugaLiczba != 0) {
                    cout << "Wynik: " << pierwszaLiczba / drugaLiczba << endl;
                } else {
                    cout << "Nie mozna dzielic przez zero" << endl;
                }
            }
        } else {
            cout << "Nie ma takiej operacji, wybierz cyfre od 0 do 4" << endl;
        }
    }

    return 0;
}