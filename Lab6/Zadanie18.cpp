#include <iostream>

using namespace std;

int main() {
    int liczbaZetonowGraczaA;
    int liczbaZetonowGraczaB;

    cout << "Podaj liczbe zetonow gracza A: ";
    cin >> liczbaZetonowGraczaA;

    cout << "Podaj liczbe zetonow gracza B: ";
    cin >> liczbaZetonowGraczaB;

    while (liczbaZetonowGraczaA != 0 && liczbaZetonowGraczaB != 0 && liczbaZetonowGraczaA != liczbaZetonowGraczaB) {
        if (liczbaZetonowGraczaA > liczbaZetonowGraczaB) {
            liczbaZetonowGraczaA = liczbaZetonowGraczaA - liczbaZetonowGraczaB;
        } else {
            liczbaZetonowGraczaB = liczbaZetonowGraczaB - liczbaZetonowGraczaA;
        }
    }

    cout << "Liczba pozostalych zetonow wynosi: " << liczbaZetonowGraczaA + liczbaZetonowGraczaB << endl;

    return 0;
}