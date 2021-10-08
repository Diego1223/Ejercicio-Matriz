/*
 * @autor -> Diego Narvaez
 * @date -> 08/10/2021
 * @instagram -> @diego_narvaez_21 (https://www.instagram.com/diego_narvaez_21/?hl=es)
 */

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
int i, j, contador = 1;
string trabajadores[3][2]; 

// ---- Prototipo de funciones -----
void MostrarDatos();
void gotoxy(int x, int y);
void CentrarTexto(const char* texto, int y);

int main(void) {
    system("cls");
    CentrarTexto("Ingresa los datos que se te piden", 1);
    cout << '\n';

    /*Pedir datos al usuario*/
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            //Este if, se asegura que este pidiendo los datos correctos
            //Cuando este pidiendo el campo de trabajador, va a decir trabajador y cuando no, va a poner ayudante 
            if ((i == 0 && j == 0) || (i == 1 && j == 0) || (i == 2 && j == 0)) {
                cout << contador << ". Trabajador => ";
                cin >> trabajadores[i][j];
            } else {
                cout << "Ayudante => ";
                cin >> trabajadores[i][j];
            }
        }
        contador++;
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
