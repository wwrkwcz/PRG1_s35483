#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    int iloscRzutow;

    cout << "Podaj liczbe rzutow: ";
    cin >> iloscRzutow;

    srand(time(NULL));

    cout << "Wylosowano: ";
    for (int i = 0; i < iloscRzutow; ++i) {
        int wynik = rand() % 6 + 1;
        cout << wynik;
        if (i < iloscRzutow - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}