/*
 * Crear una matriz que guarde nombre y companero
 *
 * Representacion
 *                                  Datos
 * Trabajador      Ayudante
 * Diego           Mario
 */

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
using namespace std;

// ----- Variables globales -----
int i, j;
string trabajadores[3][2]; 

// ---- Prototipo de funciones -----
void MostrarDatos();
void gotoxy(int x, int y);
void CentrarTexto(const char* texto, int y);

int main(void) {
    system("cls");
    CentrarTexto("Ingresa los datos que se te piden", 1);
    cout << '\n';

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            cout << "Trabajador " << i << " | " << j << " => ";
            cin >> trabajadores[i][j];

        }
    }   
    MostrarDatos();
    cin.get();
    return 0;
}

void MostrarDatos() {
    system("cls");
    CentrarTexto("Datos", 1); 
    cout << '\n';

    cout << "Nombre\t\t\tAyudante" << "\n\n";

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            cout << trabajadores[i][j] << "\t\t\t";        
        }
        cout << '\n';
    }
}


void gotoxy(int x, int y) {
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);
}


void CentrarTexto(const char* texto, int y) {
    float size;
    size = strlen(texto);
    gotoxy(59.5 - (size / 2), y); printf("%s", texto);
}
