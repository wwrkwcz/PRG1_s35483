#include <iostream>
#include <string>

using namespace std;

int main() {

    string haslo;
    bool silne = false;

    while (!silne) {
        cout << "Podaj haslo: ";
        cin >> haslo;

        bool duzaLitera = false;
        bool cyfra = false;
        bool znakSpecjalny = false;

        for (int i = 0; i < haslo.length(); i++) {
            char znak = haslo[i];
            if (znak >= 'A' && znak <= 'Z') duzaLitera = true;
            if (znak >= '0' && znak <= '9') cyfra = true;
            if (!((znak >= 'a' && znak <= 'z') || (znak >= 'A' && znak <= 'Z') || (znak >= '0' && znak <= '9'))) {
                znakSpecjalny = true;
            }
        }

        if (haslo.length() >= 8 && duzaLitera && cyfra && znakSpecjalny) {
            cout << "Haslo jest wystarczajaco silne." << endl;
            silne = true;
        } else {
            cout << "Haslo nie jest wystarczajaco silne. Podaj silniejsze haslo." << endl;
        }
    }

    return 0;
}