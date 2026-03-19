#include <iostream>

using namespace std;

int obliczNWD(int a, int b) {
    int tymczasowaA = a;
    int tymczasowaB = b;
    while (tymczasowaA != tymczasowaB) {
        if (tymczasowaA > tymczasowaB) {
            tymczasowaA -= tymczasowaB;
        } else {
            tymczasowaB -= tymczasowaA;
        }
    }
    return tymczasowaA;
}

int main() {
    int pierwszaLiczba, drugaLiczba;
    
    cout << "Podaj pierwsza liczbe calkowita: ";
    cin >> pierwszaLiczba;
    
    cout << "Podaj druga liczbe calkowita: ";
    cin >> drugaLiczba;
    
    if (pierwszaLiczba > 0 && drugaLiczba > 0) {
        int nwd = obliczNWD(pierwszaLiczba, drugaLiczba);
        cout << "NWD podanych przez ciebie liczb calkowitych wynosi: " << nwd << endl;
    } else {
        cout << "Liczby musza byc dodatnie" << endl;
    }
    
    return 0;
}