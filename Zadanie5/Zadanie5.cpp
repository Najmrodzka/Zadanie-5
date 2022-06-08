#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <limits>

using namespace std;

struct BMP_header
{
    char name[2];
    unsigned int size;
    unsigned short int reserved_1;
    unsigned short int reserved_2;
    unsigned int offset;
}header_bmp;

struct DIB_header{
    unsigned int headerSize;
    unsigned int width;
    unsigned int height;
    unsigned short int planes;
    unsigned short int bitPerPixel;
    unsigned int compresion;
    unsigned int imageSize;
    unsigned int xPelsPerMeter;
    unsigned int yPelsPerMeter;
    unsigned int colorUsed;
    unsigned int colorImportant;

}header_dib;

void info(const char *plik) {

    FILE* fp = fopen(plik, "rb");

    if (fp == nullptr) {
        cout << "Nie mozna bylo otworzyc pliku";
    }
    else {
        cout << "Udało sie otworzyc plik\n" << plik << "\n";

        cout << "INFORMACJE O PLIKU" << "\n\n";

        // Header BMP

        fread(&header_bmp.name, 2, 1, fp);
        fread(&header_bmp.size, sizeof(header_bmp.size), 1, fp);
        fread(&header_bmp.reserved_1, sizeof(header_bmp.reserved_1), 1, fp);
        fread(&header_bmp.reserved_2, sizeof(header_bmp.reserved_2), 1, fp);
        fread(&header_bmp.offset, sizeof(header_bmp.offset), 1, fp);

        cout << "Pierwsze dwa znaki :" << (char)header_bmp.name[0] << header_bmp.name[1] << "\n";
        cout << "Rozmiar pkiku: " << header_bmp.size << " bajtow\n";
        cout << "Zarezerwowane 1: " << header_bmp.reserved_1 << "\n";
        cout << "Zarezerwowane 2: " << header_bmp.reserved_1 << "\n";
        cout << "Offset (poczatkowy adres bitow w tablicy pikseli): " << header_bmp.offset << "\n"; 

        // Header DIB

        fread(&header_dib, sizeof(struct DIB_header), 1, fp);

        cout << "Wielkosc naglowka informacyjnego: " << header_dib.headerSize << "\n";
        cout << "Szerokosc obrazu: " << header_dib.width << " pikseli\n";
        cout << "Wysokosc obrazu: " << header_dib.height << " pikseli\n";
        cout << "Liczba warstw kolorow: " << header_dib.planes << "\n";
        cout << "Liczba bitow na piksel: " << header_dib.bitPerPixel << "\n";
        cout << "Algorytm kompresji: " << header_dib.compresion << "\n";
        cout << "Rozmiar samego rysunku: " << header_dib.imageSize << "\n";
        cout << "Rozdzielczosc pozioma: " << header_dib.xPelsPerMeter << "\n";
        cout << "Rozdzielczosc pionowa: " << header_dib.yPelsPerMeter << "\n";
        cout << "Liczba kolorow w palecie: " << header_dib.colorUsed << "\n";
        cout << "Liczba waznych kolorow w palecie: " << header_dib.colorImportant << "\n";

        fclose(fp);
    }
}

int main(int argc, char* argv[])
{

    return 0;
}


