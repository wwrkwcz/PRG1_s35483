#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand((int)time(NULL));
    int wylosowanaLiczba = rand() % 100 + 1;
    int podanaLiczba = 0;

    cout << "Sprobuj odgadnac liczbe w przediale od 1 do 100" << endl;

    while (true) {
        cout << "Podaj liczbe: ";
        cin >> podanaLiczba;

        if (podanaLiczba > wylosowanaLiczba) {
            cout << "Liczba ktora probujesz odgadnac jest mniejsza" << endl;
        } else if (podanaLiczba < wylosowanaLiczba) {
            cout << "Liczba ktora probujesz odgadnac jest wieksza" << endl;
        } else {
            cout << "Odgadles te liczbe, gratulacje" << endl;
            break;
        }
    }

    return 0;
}