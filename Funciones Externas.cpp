#include <iostream>
using namespace std;
#include <iomanip>
#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "Clases.h"
#include "Estructuras.h"
#include "Funciones Externas.h"
#include "Menues.h"
#include "ui.h"
#include "rlutil.h"
#include "Informes.h"
#include "Configuracion.h"
using namespace rlutil;;




enum Ubicado{
    SeccionA,
    SeccionB,
    SeccionC,
    Armario1,
    Armario2,
    Armario3,
    Estante1,
    Estante2,
    Estante3,


};

enum Clasificado{
    Preventivo,
    Correctivo,
    Predictivo,
    Otros
};

enum Especialidad{
    Electrico,
    Mecanico,
    Electromecanico,
    Electronico,
    Herrero
};

enum Categoria{
    Ayudante,
    MedioOficial,
    Oficial,
    OficialMultiple,
    AdministrativoTecnico,
    Supervisor,
    JefeMantenimiento

};

enum Estado{
    Trabaja,
    No_Trabaja

};


void recuadro(int x, int y, int ancho, int alto){
    /// Reemplazar éstos códigos por los de Windows para correr en Windows.
    const char *UI_BOTTOM_RIGHT = "\e(0\x6a\e(B"; // 188 - ┘
    const char *UI_BOTTOM_LEFT = "\e(0\x6d\e(B"; // 200 - └
    const char *UI_TOP_LEFT = "\e(0\x6c\e(B"; // 201 - ┌
    const char *UI_TOP_RIGHT = "\e(0\x6b\e(B"; // 187 - ┐
    const char *UI_CROSS = "\e(0\x6e\e(B"; // 206 - ┼
    const char *UI_HORIZONTAL_LINE = "\e(0\x71\e(B"; // 205 - ─
    const char *UI_HORIZONTAL_LINE_TOP =  "\e(0\x76\e(B"; // 202 - ┴
    const char *UI_HORIZONTAL_LINE_BOTTOM =  "\e(0\x77\e(B"; // 203 - ┬";
    const char *UI_VERTICAL_LINE = "\e(0\x78\e(B"; // 186 - │
    const char *UI_VERTICAL_LINE_LEFT =  "\e(0\x74\e(B"; // 204 - ├
    const char *UI_VERTICAL_LINE_RIGHT =  "\e(0\x75\e(B"; // 185 - ┤


    /// Borramos el espacio del recuadro
    int i, j;
    for(i=x; i<=x+ancho; i++){
        for(j=y; j<=y+alto; j++){

            locate(i, j);
            cout << " ";

        }
    }
    setColor(WHITE);
    /// Líneas horizontales
    for(i=x; i<=x+ancho; i++){

        locate(i, y);
        cout << UI_HORIZONTAL_LINE;
        locate(i, y+alto);
        cout << UI_HORIZONTAL_LINE;
    }
    /// Líneas verticales
    for(i=y; i<=y+alto; i++){
        locate(x, i);
        cout << UI_VERTICAL_LINE;
        locate(x+ancho, i);
        cout << UI_VERTICAL_LINE;
    }
    /// Vértices
    locate(x, y);
    cout << UI_TOP_LEFT;
    locate(x, y+alto);
    cout << UI_BOTTOM_LEFT;
    locate(x+ancho, y);
    cout << UI_TOP_RIGHT;
    locate(x+ancho, y+alto);
    cout << UI_BOTTOM_RIGHT;
}

void mostrar_pin(int pin[], int tam){
    int i;
    for(i=0;i<tam;i++){

        setColor(LIGHTGREEN);
        cout<<pin[i];

    }
    cout<<endl;
 }

void pin_numerico(int pin[],int cant){
    int i;

    srand(time(NULL));
    for(i=0;i<cant;i++){
       pin[i]=(rand()%9)+1;

    }
    mostrar_pin(pin, cant);
}

bool validarPin(int vec[], int pin[], const int cantPin){
int i, cont=0;


for(i=0; i<cantPin; i++){
if (vec[i]==pin[i]){
    cont++;
}
}
if(cont==cantPin){return true;}else{return false;}

}


