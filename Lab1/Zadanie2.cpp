#include <iostream>

using namespace std;

int main() {

    double a, b, c, d, e, f;

    cout << "Podaj wspolczynniki a, b, c, d, e, f:" << endl;
    cin >> a >> b >> c >> d >> e >> f;

    double W = a * d - b * c;

    if (W == 0) {
        cout << "Uklad nie ma rozwiazania lub ma nieskonczenie wiele rozwiazan." << endl;
    } else {
        double Wx = e * d - b * f;
        double Wy = a * f - e * c;
        double x = Wx / W;
        double y = Wy / W;

        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }

    return 0;
}