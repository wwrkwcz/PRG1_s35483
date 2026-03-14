#include <iostream>

using namespace std;

int main() {

    int uczniowie, cukierki;

    cout << "Ilu uczniow jest w klasie Jasia? ";
    cin >> uczniowie;

    cout << "Ile cukierkow kupila mama? ";
    cin >> cukierki;

    int dlaucznia = cukierki / uczniowie;
    int zostalo = cukierki % uczniowie;

    cout << "Kazdy uczen dostanie " << dlaucznia << " cukierkow." << endl;
    cout << "Jasiowi zostanie " << zostalo << " cukierkow na wieczor." << endl;

    return 0;
}