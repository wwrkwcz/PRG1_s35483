#include <iostream>    // wejście/wyjście
#include <conio.h>     // obsługa klawiatury
#include <windows.h>   // funkcje konsoli Windows

using namespace std;   // użycie standardowej przestrzeni nazw

class FiguraAscii {
private:
    int polozenieX; // pozycja X
    int polozenieY; // pozycja Y
    int szerokosc; // szerokość figury
    int wysokosc; // wysokość figury
    char znak; // znak ASCII figury

public:
    FiguraAscii(int x, int y, int s, int w, char z) : polozenieX(x), polozenieY(y), szerokosc(s), wysokosc(w), znak(z) {} // konstruowanie figury

    int pobierzX() const { return polozenieX; } // pobranie X
    int pobierzY() const { return polozenieY; } // pobranie Y
    int pobierzSzerokosc() const { return szerokosc; } // pobranie szerokości
    int pobierzWysokosc() const { return wysokosc; } // pobranie wysokości
    char pobierzZnak() const { return znak; } // pobranie znaku

    void ustawZnak(char z) { znak = z; } // ustawienie znaku
    void ustawPozycje(int x, int y) { polozenieX = x; polozenieY = y; } // ustawienie pozycji
    void ustawRozmiar(int s, int w) { szerokosc = s; wysokosc = w; } // ustawienie rozmiaru

    void rysuj(int szerKonsoli, int wysKonsoli) const { // rysowanie litery W
        int x = polozenieX; int y = polozenieY; int w = szerokosc; int h = wysokosc; char z = znak; // lokalne zmienne
        if (w < 5) w = 5; if (h < 3) h = 3; // minimalny rozmiar

        for (int wiersz = 0; wiersz < h; wiersz++) { // pętla wierszy
            float t = (float)wiersz / (h - 1); // współczynnik interpolacji
            int lewyZew = 0; int prawyZew = w - 1; // punkty zewnętrzne
            int lewySrodek = (int)((w / 2.0f) * t); int prawySrodek = w - 1 - (int)((w / 2.0f) * t); // punkty środkowe
            int punkty[4] = { lewyZew, lewySrodek, prawySrodek, prawyZew }; // tablica punktów
            int wierszRys = h - 1 - wiersz; int aktualnyY = y + wierszRys; // aktualny wiersz
            if (aktualnyY < 0 || aktualnyY >= wysKonsoli) continue; // granice Y

            for (int i = 0; i < 4; i++) { // pętla po punktach
                int rysX = w - 1 - punkty[i]; int aktualnyX = x + rysX; // obliczenie X
                if (aktualnyX >= 0 && aktualnyX < szerKonsoli) { // granice X
                    COORD pozycja = { (SHORT)aktualnyX, (SHORT)aktualnyY }; // współrzędne kursora
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pozycja); cout << z; // rysowanie
                }
            }
        }
    }

    void obsluzKlawisz(int klawisz, int szerKonsoli, int wysKonsoli) { // obsługa klawiszy
        switch (klawisz) {
            case 75: if (polozenieX > 0) polozenieX--; break; // lewo
            case 77: if (polozenieX + szerokosc < szerKonsoli) polozenieX++; break; // prawo
            case 72: if (polozenieY > 0) polozenieY--; break; // góra
            case 80: if (polozenieY + wysokosc < wysKonsoli - 1) polozenieY++; break; // dół
            case '+': case '=': if (szerokosc < szerKonsoli) szerokosc++; if (wysokosc < wysKonsoli - 1) wysokosc++; break; // powiększenie
            case '-': if (szerokosc > 5) szerokosc--; if (wysokosc > 3) wysokosc--; break; // zmniejszenie
        }
    }
};

void wyczyscEkran() { system("cls"); } // czyszczenie ekranu

void ukryjKursor() { // ukrycie kursora
    HANDLE uchwyt = GetStdHandle(STD_OUTPUT_HANDLE); CONSOLE_CURSOR_INFO info; GetConsoleCursorInfo(uchwyt, &info); info.bVisible = FALSE; SetConsoleCursorInfo(uchwyt, &info);
}

void pobierzWymiaryKonsoli(int& szer, int& wys) { // pobranie wymiarów konsoli
    HANDLE uchwyt = GetStdHandle(STD_OUTPUT_HANDLE); CONSOLE_SCREEN_BUFFER_INFO csbi; GetConsoleScreenBufferInfo(uchwyt, &csbi);
    szer = csbi.srWindow.Right - csbi.srWindow.Left + 1; wys = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

char pobierzZnakOdUzytkownika() { // pobranie znaku ASCII
    wyczyscEkran(); int kod; cout << "Prosze podac kod ASCII znaku, czyli od 0 do 255: "; cin >> kod;
    if (kod < 0 || kod > 255) kod = 35; return (char)kod;
}

void wyswietlPomoc(int szerKonsoli, int wysKonsoli) { // pasek pomocy
    COORD pozycja = { 0, (SHORT)(wysKonsoli - 1) }; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pozycja);
    cout << "STRZALKI: ruch figury, MINUS I PLUS: rozmiar figury, ENTER: zmiana znaku, ESC: koniec programu";
}

int main() {
    ukryjKursor(); int szerKonsoli, wysKonsoli; pobierzWymiaryKonsoli(szerKonsoli, wysKonsoli); // inicjalizacja
    int asciiKod; cout << "Prosze podac kod ASCII znaku, czyli od 0 do 255: "; cin >> asciiKod; if (asciiKod < 0 || asciiKod > 255) asciiKod = 35; // znak
    int szer, wys; cout << "Prosze podac szerokosc figury: "; cin >> szer; cout << "Prosze podac wysokosc figury: "; cin >> wys; // rozmiar

    FiguraAscii figura(szerKonsoli - szer, wysKonsoli - 1 - wys, szer, wys, (char)asciiKod); // utworzenie figury

    while (true) { // główna pętla
        pobierzWymiaryKonsoli(szerKonsoli, wysKonsoli); // aktualizacja rozmiaru
        if (figura.pobierzX() < 0) figura.ustawPozycje(0, figura.pobierzY()); // ograniczenie lewego brzegu
        if (figura.pobierzY() < 0) figura.ustawPozycje(figura.pobierzX(), 0); // ograniczenie górnego brzegu
        if (figura.pobierzX() + figura.pobierzSzerokosc() > szerKonsoli) figura.ustawPozycje(szerKonsoli - figura.pobierzSzerokosc(), figura.pobierzY()); // ograniczenie prawego
        if (figura.pobierzY() + figura.pobierzWysokosc() > wysKonsoli - 1) figura.ustawPozycje(figura.pobierzX(), wysKonsoli - 1 - figura.pobierzWysokosc()); // ograniczenie dolnego

        wyczyscEkran(); figura.rysuj(szerKonsoli, wysKonsoli); wyswietlPomoc(szerKonsoli, wysKonsoli); // rysowanie i pomoc

        if (kbhit()) { // klawisz wciśnięty?
            int klawisz = getch(); if (klawisz == 27) break; // ESC – wyjście
            if (klawisz == 224) { klawisz = getch(); figura.obsluzKlawisz(klawisz, szerKonsoli, wysKonsoli); } // strzałki
            else if (klawisz == '+' || klawisz == '-' || klawisz == '=') figura.obsluzKlawisz(klawisz, szerKonsoli, wysKonsoli); // zmiana rozmiaru
            else if (klawisz == 13) figura.ustawZnak(pobierzZnakOdUzytkownika()); // ENTER – nowy znak
        }

        Sleep(40); // opóźnienie animacji
    }
    return 0; // koniec programu
}