#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    int liczby[6];
    bool wybrane[50] = { false };
    int ilosc = 0;

    srand(time(NULL));

    while (ilosc < 6) {
        int los = rand() % 49 + 1;
        if (!wybrane[los]) {
            wybrane[los] = true;
            liczby[ilosc] = los;
            ilosc++;
        }
    }

    for (int i = 0; i < 6; ++i) {
        for (int j = i + 1; j < 6; ++j) {
            if (liczby[j] < liczby[i]) {
                int temp = liczby[i];
                liczby[i] = liczby[j];
                liczby[j] = temp;
            }
        }
    }

    cout << "Wylosowane liczby: ";
    for (int i = 0; i < 6; ++i) {
        cout << liczby[i];
        if (i < 5) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}