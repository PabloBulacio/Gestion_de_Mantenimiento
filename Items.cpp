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
using namespace rlutil;


///METODOS DE LA CLASE ITEMS

int Items::getNroVale(){
    return NroVale;
}

int Items::getItem(){
    return Item;
}

int Items::getNroParte(){
    return NroParte;
}

int Items::getCant(){
    return Cant;
}

float Items::getPU(){
    return PU;
}

void Items::setNroVale(int nv){
    NroVale=nv;
}

void Items::setItem(int item){
    Item=item;
}

void Items::setNroParte(int nro){
   NroParte=nro;
}

void Items::setCant(int cant){
    Cant=cant;

}

void Items::setPU(float pu){
    PU=pu;
}

bool Items::cargar(int NroVale, int item, bool es){
    int cant,cantR, np, npvalidado;
    Stock auxS;
    Repuestos auxR;
    bool cantValidada, ok=false;
    char sigue, continuar;


if (es==false){///SE CARGA ITEMS DE VALE DE SALIDA

int x=6, y=5;

system ("cls");
setlocale(LC_ALL,"spanish");
title("CARGAR ITEMS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);

gotoxy(x,y);
setColor(LIGHTBLUE);
cout<<"ÍTEM NÚMERO: ";

setColor(WHITE);
cout<<item;

this->setItem(item);

gotoxy(x,y=y+2);
cout<<"NUMERO DE PARTE: ";
cin>>np;

npvalidado=validarNroParteStock(np);

///SE VALIDA LA ELECCION

do{
switch(npvalidado){
case -1:
        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***NO SE PUEDE ABRIR EL ARCHIVO DE REPUESTOS***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR S/N ? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        cout<<"INGRESE NUEVAMENTE EL NRO. DE PARTE: ";
        cin>>np;
        npvalidado=validarNroParteStock(np);
        }else {return false;}

    break;
case 0:
        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***NO EXISTE EL NRO PARTE EN LOS REGISTROS***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR S/N ? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        cout<<"INGRESE NUEVAMENTE EL NRO. DE PARTE: ";
        cin>>np;
        npvalidado=validarNroParteStock(np);
        }else {return false;}
    break;

}

}while(!(npvalidado==1));

///FIN DE LA VALIDACION

this->setNroParte(np);

///SE MUESTRA EL ITEM SELECCIONADO DESDE EL ARCHIVO DE STOCK
auxS.mostrar(np, x, y);



///SE VALIDA LA CANTIDAD ELEGIDA
do{
setColor(WHITE);
gotoxy(x,y=y+4);
cout<<"CANTIDAD DE REPUESTOS A UTILIZAR: ";
cin>>cantR;

while (cantR <= 0){
setColor(LIGHTRED);
gotoxy(x,++y);
cout<<"***EL VALOR INGRESADO ES INCORRECTO***";
setColor(WHITE);
gotoxy(x,++y);
cout<<"CANTIDAD DE REPUESTOS A UTILIZAR: ";
cin>>cantR;

}

cantValidada=validarCantActualStock(np, cantR);

if (cantValidada==false){
setColor(LIGHTRED);
gotoxy(x,++y);
cout<<"***LA CANTIDAD SOLICITADA NO PUEDE SUPERAR EL STOCK ACTUAL***";
}
y=y-3;
}while (cantValidada==false);

///FIN DE LA VALIDACION

this->setCant(cantR);

///SE ASIGNA EL PRECIO UNITARIO
int i=0;

while (auxR.leerDisco(i++)){
   if(auxR.getNroParte()==np){
    this->setPU(auxR.getPrecio());
   }
}
///FIN DE LA ASIGNACION


setColor(LIGHTGREEN);
gotoxy(x,y=y+6);
cout<<"DESEA SOLICITAR MÁS REPUESTOS S/N ? : ";
setColor(WHITE);
cin>>sigue;
continuar=towupper(sigue);

if(continuar=='S'){ok=true;} else{ok=false;}

}
else{///SE CARGAN ITEMS DE VALE DE ENTRADA

int x=6, y=5;

system ("cls");
setlocale(LC_ALL,"spanish");
title("CARGAR ITEMS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);

gotoxy(x,y);
setColor(LIGHTBLUE);
cout<<"ÍTEM NÚMERO: ";

setColor(WHITE);
cout<<item;

this->setItem(item);

gotoxy(x,y=y+2);
cout<<"NUMERO DE PARTE: ";
cin>>np;

npvalidado=validarNroParteStock(np);

///SE VALIDA LA ELECCION

do{
switch(npvalidado){
case -1:
        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***NO SE PUEDE ABRIR EL ARCHIVO DE REPUESTOS***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR S/N ? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        cout<<"INGRESE NUEVAMENTE EL NRO. DE PARTE: ";
        cin>>np;
        npvalidado=validarNroParteStock(np);
        }else {return false;}

    break;
case 0:
        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***NO EXISTE EL NRO PARTE EN LOS REGISTROS***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR S/N ? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        cout<<"INGRESE NUEVAMENTE EL NRO. DE PARTE: ";
        cin>>np;
        npvalidado=validarNroParteStock(np);
        }else {return false;}
    break;

}

}while(!(npvalidado==1));

///FIN DE LA VALIDACION

this->setNroParte(np);

///SE MUESTRA EL ITEM SELECCIONADO DESDE EL ARCHIVO DE STOCK
auxS.mostrar(np, x, ++y);


setColor(WHITE);
gotoxy(x,y=y+4);
cout<<"CANTIDAD DE REPUESTOS A INCORPORAR AL STOCK: ";
cin>>cantR;

while (cantR < 0){
setColor(LIGHTRED);
gotoxy(x,++y);
cout<<"***EL VALOR INGRESADO ES INCORRECTO***";
setColor(WHITE);
gotoxy(x,++y);
cout<<"CANTIDAD DE REPUESTOS A INCORPORAR AL STOCK: ";
cin>>cantR;

}

this->setCant(cantR);

///SE ASIGNA EL PRECIO UNITARIO
int i=0;

while (auxR.leerDisco(i++)){
   if(auxR.getNroParte()==np){
    this->setPU(auxR.getPrecio());
   }
}
///FIN DE LA ASIGNACION

setColor(LIGHTGREEN);
gotoxy(x,y=y+6);
cout<<"DESEA SOLICITAR MÁS REPUESTOS S/N ? : ";
setColor(WHITE);
cin>>sigue;
continuar=towupper(sigue);

if(continuar=='S'){ok=true;} else{ok=false;}


}///FIN DEL IF

this->setNroVale(NroVale);

return ok;

}

void Items::mostrar(){
}

bool Items::escribirDisco(int pos){
 bool grabo=false;
        FILE *f;
        if (pos == -1){
            f = fopen("Items.dat", "ab");
            if (f == NULL){
                msj("***NO SE PUEDO ABRIR EL ARCHIVO***", rlutil::WHITE, rlutil::RED);
                return grabo;
            }
        }
        else{
            f = fopen("Items.dat", "rb+");
            if (f == NULL){
                msj("***NO SE PUEDO ABRIR EL ARCHIVO***", rlutil::WHITE, rlutil::RED);
                return grabo;
            }
            fseek(f, pos * sizeof(Items), 0);
        }
        grabo = fwrite(this, sizeof(Items), 1, f);
        fclose(f);
        return grabo;
}

bool Items::leerDisco(){
 bool leyo;

FILE *f;
f = fopen("Items.dat", "rb");
if (f == NULL){
return false;
}

leyo = fread(this, sizeof(Items), 1, f);
fclose(f);

return leyo;
}

bool Items::leerDisco(int pos){
 bool leyo=false;

FILE *f;
f = fopen("Items.dat", "rb");
if (f == NULL){
return leyo;
}

fseek(f, pos * sizeof(Items), 0);
leyo = fread(this, sizeof(Items), 1, f);
fclose(f);


return leyo;
}





///FUNCIONES GLOBALES DE CLASE ITEMS
int cantidadItems(int nv){
int cant=0, i=0;
Items reg;

while (reg.leerDisco(i++)){
if (reg.getNroVale()==nv){
    cant++;
}

}
return cant;
}
