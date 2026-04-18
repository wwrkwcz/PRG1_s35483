#include <iostream>

using namespace std;

int main() {
    short liczbaPoczatkowa = 213;
    short* wskaznikLiczby = &liczbaPoczatkowa;

    cout << "&liczbaPoczatkowa = " << &liczbaPoczatkowa << endl;
    cout << "wskaznikLiczby = " << wskaznikLiczby << endl;

    cout << "liczbaPoczatkowa = " << liczbaPoczatkowa << endl;
    cout << "*wskaznikLiczby = " << *wskaznikLiczby << endl;

    *wskaznikLiczby = 50;
    cout << "liczbaPoczatkowa po zmianie = " << liczbaPoczatkowa << endl;

    return 0;
}