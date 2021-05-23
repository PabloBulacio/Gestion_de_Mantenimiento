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


///FUNCIONES GLOBALES DE CLASE REPUESTOS
int buscarPosicionNp(int np){
    Repuestos aux;
    int i=0;

    while (aux.leerDisco(i++)){
    if(aux.getNroParte()==np ){
    return i;
    }
  }
}

int validarNroParte(int np){
Repuestos aux;
int i = 0;

if (aux.leerDisco()==false){return -1;}else{

    while (aux.leerDisco(i++)){
    if(aux.getNroParte() == np){
    return 1;
    }
  }
}
return 0;
}

void listarRepuestos(){
    Repuestos aux;
    int i=0, x=6, y=5;

        setlocale(LC_ALL,"spanish");
        title("LISTADO DE REPUESTOS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        recuadro(2,2,127,27);
        recuadro(4,3,123,25);
        cout << left;
        setColor(YELLOW);
        gotoxy(x,y);
        cout << setw(10) << "N° PARTE" << setw(12) << "MARCA" << setw(12) << "MODELO"<< setw(46) <<"DESCRIPCION" << setw(16) <<"CORRESPONDE A " << setw(12) << "VALOR ($)" << setw(12) << "ESTADO";
        setColor(LIGHTCYAN);
        gotoxy(x,++y);
        cout<< "------------------------------------------------------------------------------------------------------------------------";

            while (aux.leerDisco(i++)){
            setColor(WHITE);
            gotoxy(x,++y);
            cout << setw(10) << aux.getNroParte();
            cout << setw(12) << aux.getMarca();
            cout << setw(12) << aux.getModelo();
            cout << setw(46) << aux.getDescripcion();
            cout << setw(16) << aux.getTipo();
            cout << setw(12) << aux.getPrecio();
            if(aux.getEstado()==true){cout << setw(12) << "En Uso";}else{cout << setw(12) <<"En Desuso";}

            }


}

bool modificar_repuestos(){

    Repuestos aux;
    char sigue, continuar, confirma, eleccion;
    int x=6, y=5, np, opcion, pos, npvalidado;
    float precio;
    bool ok=true;


system ("cls");
setlocale(LC_ALL,"spanish");
title("MODIFICACION DE REPUESTOS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);

gotoxy(x,y);
cout<<"NRO. DE PARTE: ";
cin>>np;

npvalidado=validarNroParte(np);

///SE VALIDA EL NRO PARTE
while(npvalidado!=1){
setColor(LIGHTRED);
gotoxy(x,++y);
cout<<"***NO EXISTE ESE NUMERO EN NUESTROS REGISTROS***";
setColor(WHITE);
gotoxy(x,++y);
cout<<"DESEA CONTINUAR S/N ? : ";
cin>>sigue;
continuar=towupper(sigue);
if (continuar == 'S'){
gotoxy(x,++y);
cout<<"INGRESE NUEVAMENTE EL NRO. DE PARTE: ";
cin>>np;
npvalidado=validarNroParte(np);
}else {return false;}

}
///FIN DE LA VALIDACION


pos=buscarPosicionNp(np);
aux.leerDisco(pos-1);
aux.mostrar();

x=6;
y=10;

gotoxy(x,y);
setColor(LIGHTGREEN);
cout<<"CAMPOS QUE SE PUEDEN  MODIFICAR: ";
gotoxy(x,++y);
setColor(LIGHTCYAN);
cout<< "------------------------------------------------------------------------------------------------------------------------";
gotoxy(x,++y);
setColor(YELLOW);
cout << setw(15) << "1. PRECIO" << setw(15) << "2. ESTADO";
gotoxy(x,++y);
setColor(LIGHTCYAN);
cout<< "------------------------------------------------------------------------------------------------------------------------";


setlocale(LC_ALL,"spanish");
gotoxy(x,++y);
setColor(WHITE);
cout<<"ELIJA UNA OPCION: ";
cin>>opcion;

do{

switch(opcion){


case (1):

gotoxy(x,++y);
cout<<"PRECIO: ";
cin>>precio;
gotoxy(x,++y);
cout<<"CONFIRMA EL CAMBIO REALIZADO S/N?: ";
cin>>eleccion;
confirma=towupper(eleccion);
if(confirma=='S'){
aux.setPrecio(precio);
aux.escribirDisco(pos-1);
return ok;
}
opcion=0;
break;



case (2):

gotoxy(x,++y);
setColor(LIGHTRED);
cout<<"NOTA: ";
setColor(YELLOW);
cout<<"CAMBIANDO EL ESTADO SOLO QUEDARA EL REPUESTO EN DESUSO";

setColor(WHITE);
gotoxy(x,++y);
cout<<"CONFIRMA EL CAMBIO REALIZADO S/N?: ";
cin>>eleccion;
confirma=towupper(eleccion);
if(confirma=='S'){
aux.setEstado(false);
aux.escribirDisco(pos-1);
return ok;
}
opcion=0;
break;

default:
        do{
        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***NO CORRESPONDE A UNA OPCION VALIDA***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR S/N ? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        cout<<"ELIJA UNA OPCION: ";
        cin>>opcion;
        }else {opcion=0;}
        }while (!(opcion>=0 && opcion<=2));


    break;

}


}while(opcion>0 && opcion<=2);

}

bool mostrarDetallesRepuestos(){
Repuestos reg;

int x=6, y=5, pos=0;
int np, npvalidado;
char sigue, continuar;

setlocale(LC_ALL,"spanish");
title("DATOS DETALLADOS DEL REPUESTO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
cout<<"NÚMERO DE PARTE: ";
cin>>np;

npvalidado=validarNroParte(np);

///SE VALIDA LA ELECCION

while(!(npvalidado==1)){
setColor(LIGHTRED);
gotoxy(x,++y);
cout<<"***NO EXISTE ESE NÚMERO DE PARTE EN NUESTROS REGISTROS***";
setColor(WHITE);
gotoxy(x,++y);
cout<<"DESEA CONTINUAR S/N ? : ";
cin>>sigue;
continuar=towupper(sigue);
if (continuar == 'S'){
gotoxy(x,++y);
cout<<"INGRESE NUEVAMENTE EL NÚMERO DE PARTE: ";
cin>>np;

npvalidado=validarNroParte(np);

}else {return false;}

}

///FIN DE LA VALIDACION

while (reg.leerDisco(pos++)==true){
if(reg.getNroParte()==np){

cout << left;
gotoxy(x,++y);
setColor(YELLOW);
cout << "NÚMERO DE PARTE: ";
setColor(LIGHTCYAN);
cout<< reg.getNroParte()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "MARCA: ";
setColor(LIGHTCYAN);
cout<< reg.getMarca()<<endl;
setColor(YELLOW);
gotoxy(x,++y);
cout << "MODELO: ";
setColor(LIGHTCYAN);
cout<< reg.getModelo()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "DESCRIPCIÓN: ";
setColor(LIGHTCYAN);
cout<< reg.getDescripcion()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "REPUESTO UTILIZADO EN : ";
setColor(LIGHTCYAN);
cout<< reg.getTipo()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "PRECIO: ";
setColor(LIGHTCYAN);
cout<<"$ "<< reg.getPrecio()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "ESTADO ACTUAL: ";
setColor(LIGHTCYAN);
if(reg.getEstado()==true){cout<< "EN USO";}else{cout<<"EN DESUSO";}

}
}
}

int cantidadRepuestos(){
int bytes, cant;

FILE *f=fopen("Repuestos.dat","rb");
if (f==NULL){
setColor(LIGHTRED);
return 0;
    }
fseek(f, 0, SEEK_END); ///SEEK_SET --> 0 , SEEK_CUR --> 1 , SEEK_END --> 2
bytes=ftell(f);
fclose(f);
cant=bytes/sizeof(Repuestos);

return cant;
}

///METODOS DE LA CLASE REPUESTOS

int   Repuestos::getNroParte(){
    return NroParte;
}

char* Repuestos::getMarca(){
    return Marca;
}

char* Repuestos::getModelo(){
    return Modelo;
}

char* Repuestos::getDescripcion(){
    return Descripcion;
}

char* Repuestos::getTipo(){
    return Tipo;
}

float Repuestos::getPrecio(){
    return Precio;
}

bool  Repuestos::getEstado(){
    return Estado;
}

void  Repuestos::setNroParte(int n){
    NroParte=n;
}

void  Repuestos::setMarca(char *m){
    strcpy(Marca, m);
}

void  Repuestos::setModelo(char *m){
    strcpy(Modelo, m);
}

void  Repuestos::setDescripcion(char *d){
    strcpy(Descripcion, d);
}

void  Repuestos::setTipo(char *t){
    strcpy(Tipo, t);
}

void  Repuestos::setPrecio(float p){
    Precio=p;
}

void  Repuestos::setEstado(bool e){
    Estado=e;
}

void Repuestos::obtenerTipo(int np){
    Maquinas aux;
    int i=0;

char mc[20]="Mesa de Corte";
char pr[20]="Prensa";
char iny[20]="Inyectora";


if(np>=100000 && np<102000){
    while(aux.leerDisco(i++)){
      if(strcmp(mc,aux.getTipo())==0){
        strcpy(Tipo, aux.getTipo());
      }
    }
}

if(np>=102000 && np<104000){
    while(aux.leerDisco(i++)){
      if(strcmp(pr,aux.getTipo())==0){
        strcpy(Tipo, aux.getTipo());
      }
    }
}

if(np>=104000 && np<108000){
    while(aux.leerDisco(i++)){
      if(strcmp(iny,aux.getTipo())==0){
        strcpy(Tipo, aux.getTipo());
      }
    }
}


}

bool Repuestos::cargar(){

    bool cargo, escribio;
    int np, npvalidado, opcion;
    char sigue, continuar;



do{
int x=6, y=5;

system ("cls");
setlocale(LC_ALL,"spanish");
title("NUEVO REPUESTO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);

gotoxy(x,y);
cout<<"NUMERO DE PARTE: ";
cin>>np;

npvalidado=validarNroParte(np);

///SE VALIDA LA ELECCION
if(npvalidado==-1 || npvalidado==0){
obtenerTipo(np);
this->setNroParte(np);
}
else{
        while(npvalidado==1){
        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***YA EXISTE ESE NUMERO DE PARTE EN NUESTROS REGISTROS***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR S/N ? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        cout<<"INGRESE NUEVAMENTE EL NÚMERO DE PARTE: ";
        cin>>np;

        npvalidado=validarNroParte(np);

        }else {return false;}

        }
        obtenerTipo(np);
        this->setNroParte(np);
    }
///FIN DE LA VALIDACION

gotoxy(x,++y);
setColor(YELLOW);
cout<<"EL NUMERO DE PARTE INGRESADO CORRESPONDE A: ";
setColor(LIGHTGREEN);
cout<<this->Tipo;

this->setTipo(Tipo);

gotoxy(x,++y);
setColor(WHITE);
cout<<"MARCA: ";
cin.ignore();
cin.getline(Marca, 20);

this->setMarca(Marca);

gotoxy(x,++y);
cout<<"MODELO: ";
cin.getline(Modelo, 20);

this->setModelo(Modelo);

gotoxy(x,++y);
cout<<"DESCRIPCION: ";
cin.getline(Descripcion, 50);

this->setDescripcion(Descripcion);

gotoxy(x,++y);
cout<<"INGRESE EL PRECIO ACTUAL EN PESOS ($): ";
cin>>Precio;

this->setPrecio(Precio);

this->mostrar();

x=6;
y=10;

gotoxy(x,y);
setColor(LIGHTRED);
cout<<"NOTA: ";
setColor(LIGHTCYAN);
cout<<"ANTES DE CONTINUAR PUEDE ELEGIR UNA DE LAS SIGUIENTES OPCIONES: ";
gotoxy(x,12);
setColor(LIGHTGREEN);
cout << setw(40) << "1.INGRESAR NUEVAMENTE LOS DATOS"<< setw(30) << "2.FINALIZAR SIN GUARDAR" << setw(30) << "3.FINALIZAR Y GUARDAR";
setColor(WHITE);
gotoxy(x,14);
cout<<"ELIJA UNA OPCIÓN (1-3): ";
cin>>opcion;

x=6;
y=14;

///SE VALIDA LA ELECCION
while (!(opcion>0 && opcion<=3)){
    msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);
    setColor(WHITE);
    gotoxy(x,++y);
    cout<<"ELIJA UNA OPCIÓN (1-3): ";
    cin>>opcion;
}
///FIN DE LA VALIDACION

}while(opcion==1);

if (opcion==2){return false;}
else{
this->setEstado(true);
return true;}

}

void  Repuestos::mostrar(){
 int x=6, y=5;

        setlocale(LC_ALL,"spanish");
        title("INFORMACION DEL REPUESTO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        recuadro(2,2,127,27);
        recuadro(4,3,123,25);
        cout << left;
        setColor(YELLOW);
        gotoxy(x,y);
        cout << setw(10) << "N° PARTE" << setw(12) << "MARCA" << setw(12) << "MODELO"<< setw(46) <<"DESCRIPCION" << setw(16) <<"CORRESPONDE A " << setw(12) << "VALOR ($)" << setw(12) << "ESTADO";
        setColor(LIGHTCYAN);
        gotoxy(x,++y);
        cout<< "------------------------------------------------------------------------------------------------------------------------";
            setColor(WHITE);
            gotoxy(x,++y);
            cout << setw(10) << getNroParte();
            cout << setw(12) << getMarca();
            cout << setw(12) << getModelo();
            cout << setw(46) << getDescripcion();
            cout << setw(16) << getTipo();
            cout << setw(12) << getPrecio();
            if(getEstado()==true){cout << setw(12) << "En Uso";}else{cout << setw(12) <<"En Desuso";}




}

bool  Repuestos::escribirDisco(int pos){
 bool grabo=false;
        FILE *f;
        if (pos == -1){
            f = fopen("Repuestos.dat", "ab");
            if (f == NULL){
                msj("***NO SE PUEDO ABRIR EL ARCHIVO***", rlutil::WHITE, rlutil::RED);
                return grabo;
            }
        }
        else{
            f = fopen("Repuestos.dat", "rb+");
            if (f == NULL){
                msj("***NO SE PUEDO ABRIR EL ARCHIVO***", rlutil::WHITE, rlutil::RED);
                return grabo;
            }
            fseek(f, pos * sizeof(Repuestos), 0);
        }
        grabo = fwrite(this, sizeof(Repuestos), 1, f);
        fclose(f);
        return grabo;
}

bool Repuestos::leerDisco(){
 bool leyo;

FILE *f;
f = fopen("Repuestos.dat", "rb");
if (f == NULL){
return false;
}

leyo = fread(this, sizeof(Repuestos), 1, f);
fclose(f);

return leyo;

}

bool Repuestos::leerDisco(int pos){
 bool leyo=false;

FILE *f;
f = fopen("Repuestos.dat", "rb");
if (f == NULL){
return leyo;
}

fseek(f, pos * sizeof(Repuestos), 0);
leyo = fread(this, sizeof(Repuestos), 1, f);
fclose(f);


return leyo;

}







