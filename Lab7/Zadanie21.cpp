#include <iostream>

using namespace std;

int main()
{
    int granicaWyliczenia;
    int poprzedniaLiczba = 0;
    int aktualnaLiczba = 1;
    int nastepnaLiczba;

    cout << "Prosze podac liczbe bedaca granica wyliczenia ciagu: ";
    cin >> granicaWyliczenia;

    cout << poprzedniaLiczba;
    if (granicaWyliczenia >= 1)
    {
        cout << " " << aktualnaLiczba;
    }

    while (true)
    {
        nastepnaLiczba = poprzedniaLiczba + aktualnaLiczba;
        if (nastepnaLiczba > granicaWyliczenia)
        {
            break;
        }

        cout << " " << nastepnaLiczba;
        poprzedniaLiczba = aktualnaLiczba;
        aktualnaLiczba = nastepnaLiczba;
    }

    cout << endl;
    return 0;
}
