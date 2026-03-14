#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

using namespace std;

int main() {

    double promien, katwstopniach, katwradianach, zmienna;

    cout << "Podaj promien: ";
    cin >> promien;

    cout << "Podaj kat w stopniach: ";
    cin >> katwstopniach;

    katwradianach = M_PI * katwstopniach / 180.0;

    zmienna = (promien * promien / 2.0) * (katwradianach - sin(katwradianach));

    cout << "Pole odcinka wynosi: " << zmienna << endl;

    return 0;
}