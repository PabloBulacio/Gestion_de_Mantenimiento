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

///METODOS DE LA CLASE MAQUINAS

char* Maquinas::getCodificacionMaquina(){
    return CodificacionMaquina;
}

char* Maquinas::getTipo(){
    return Tipo;
}

char* Maquinas::getDescripcion(){
    return Descripcion;
}

char* Maquinas::getNumeroSerie(){
    return NumeroSerie;
}

bool Maquinas::getEstado(){
    return Estado;
}

void  Maquinas::setCodificacionMaquina(char *cm){
    strcpy(CodificacionMaquina, cm);
}

void  Maquinas::setTipo(char *t){
    strcpy(Tipo, t);
}

void  Maquinas::setDescripcion(char *d){
    strcpy(Descripcion, d);
}

void  Maquinas::setNumeroSerie(char *ns){
    strcpy(NumeroSerie, ns);
}

void Maquinas::setEstado(bool e){
    Estado=e;
}

bool Maquinas::cargar(){

    char cod[15], descripcion[50], nroSerie[25];
    bool cargo, escribio;
    int  opcion , codigoValidado;


do{
int x=6, y=5;

system ("cls");
setlocale(LC_ALL,"spanish");
title("CARGA DE NUEVO EQUIPO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);

gotoxy(x,y);
cout<<"CODIFICACION DEL EQUIPO: ";
cin.ignore();
cin.getline(cod, 15);

codigoValidado=validarCodigo(cod);

///SE VALIDA LA ELECCION
if(codigoValidado==-1 || codigoValidado==0){
this->setCodificacionMaquina(cod);}
else{
        while(codigoValidado==1){
        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***YA EXISTE ESA CODIFICACION EN NUESTROS REGISTROS***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"INGRESE NUEVAMENTE LA CODIFICACION DEL EQUIPO: ";
        cin.getline(cod, 15);

        codigoValidado=validarCodigo(cod);
        }
        this->setCodificacionMaquina(cod);
    }
///FIN DE LA VALIDACION

gotoxy(x,++y);
cout<<"TIPO DE MAQUINA: ";
gotoxy(x,++y);
setColor(YELLOW);
cout << setw(20) << "1.Inyectora" << setw(20) << "2.Prensa" << setw(20) << "3.Mesa de Corte";
setColor(WHITE);
gotoxy(x,++y);
cout<<"ELIJA UNA OPCIÓN (1-3): ";
cin>>opcion;

///SE VALIDA LA ELECCION DEL TIPO
while (!(opcion>0 && opcion<=3)){
    msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);
    setColor(WHITE);
    gotoxy(x,++y);
    cout<<"ELIJA UNA OPCIÓN (1-3): ";
    cin>>opcion;
}
///FIN DE LA VALIDACION

char vec[3][25]={"Inyectora", "Prensa", "Mesa de Corte"};

this->setTipo(vec[opcion-1]);

gotoxy(x,++y);
cout<<"DESCRIPCION DEL EQUIPO: ";
cin.ignore();
cin.getline(descripcion, 50);

this->setDescripcion(descripcion);

gotoxy(x,++y);
cout<<"NUMERO DE SERIE DEL EQUIPO: ";
cin.getline(nroSerie, 25);

this->setNumeroSerie(nroSerie);

this->mostrar();

x=6;
y=10;

gotoxy(x,y);
setColor(LIGHTRED);
cout<<"NOTA: ";
setColor(LIGHTCYAN);
cout<<"ANTES DE CONTINUAR PUEDE ELEGIR LAS SIGUIENTES OPCIONES: ";
gotoxy(x,12);
setColor(LIGHTGREEN);
cout << setw(50) << "1.EMPEZAR DE NUEVO Y CARGAR  LOS DATOS"<< setw(35) << "2.FINALIZAR SIN GUARDAR" << setw(35) << "3.FINALIZAR Y GUARDAR";
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

void Maquinas::mostrar(){
    int x=6, y=5;

        setlocale(LC_ALL,"spanish");
        title("DATOS DEL EQUIPO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        recuadro(2,2,127,27);
        recuadro(4,3,123,25);
        cout << left;
        setColor(YELLOW);
        gotoxy(x,y);
        cout << setw(20) << "CODIGO DEL EQUIPO" << setw(20) << "TIPO DE EQUIPO" << setw(40) << "DESCRIPCION"<< setw(20) <<"NUMERO DE SERIE" << setw(20) << "ESTADO";
        setColor(LIGHTCYAN);
        gotoxy(x,++y);
        cout<< "------------------------------------------------------------------------------------------------------------------------";
            setColor(WHITE);
            gotoxy(x,++y);
            cout << setw(20) << getCodificacionMaquina();
            cout << setw(20) << getTipo();
            cout << setw(40) << getDescripcion();
            cout << setw(20) << getNumeroSerie();
            if (getEstado()==1){cout << setw(20) <<"Operativa";}else{cout << setw(20) <<"No Operativa";}





}

bool Maquinas::escribirDisco(int pos){
    bool grabo=false;
        FILE *f;
        if (pos == -1){
            f = fopen("Maquinas.dat", "ab");
            if (f == NULL){
                msj("***NO SE PUEDO ABRIR EL ARCHIVO***", rlutil::WHITE, rlutil::RED);
                return grabo;
            }
        }
        else{
            f = fopen("Maquinas.dat", "rb+");
            if (f == NULL){
                msj("***NO SE PUEDO ABRIR EL ARCHIVO***", rlutil::WHITE, rlutil::RED);
                return grabo;
            }
            fseek(f, pos * sizeof(Maquinas), 0);
        }
        grabo = fwrite(this, sizeof(Maquinas), 1, f);
        fclose(f);
        return grabo;
}

bool Maquinas::leerDisco(){
 bool leyo;

FILE *f;
f = fopen("Maquinas.dat", "rb");
if (f == NULL){
return false;
}

leyo = fread(this, sizeof(Maquinas), 1, f);
fclose(f);

return leyo;

}

bool Maquinas::leerDisco(int pos){
 bool leyo=false;

FILE *f;
f = fopen("Maquinas.dat", "rb");
if (f == NULL){
msj("***NO SE PUEDO ABRIR EL ARCHIVO***", rlutil::WHITE, rlutil::RED);
return leyo;
}

fseek(f, pos * sizeof(Maquinas), 0);
leyo = fread(this, sizeof(Maquinas), 1, f);
fclose(f);


return leyo;

}







///FUNCIONES GLOBALES DE MAQUINAS

bool mostrarDetallesMaquinas(){
Maquinas reg;
char cod[15];
int x=6, y=5;
int  codigoValidado, pos=0;
char sigue, continuar;


setlocale(LC_ALL,"spanish");
title("DETALLES DEL EQUIPO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
cout<<"CODIFICACION DEL EQUIPO: ";
cin.ignore();
cin.getline(cod, 15);

codigoValidado=validarCodigo(cod);

///SE VALIDA LA ELECCION

while(!(codigoValidado==1)){
setColor(LIGHTRED);
gotoxy(x,++y);
cout<<"***NO EXISTE ESA CODIFICACION EN NUESTROS REGISTROS***";
setColor(WHITE);
gotoxy(x,++y);
cout<<"DESEA CONTINUAR S/N ? : ";
cin>>sigue;
continuar=towupper(sigue);
if (continuar == 'S'){
setColor(WHITE);
gotoxy(x,++y);
cout<<"INGRESE NUEVAMENTE LA CODIFICACION DEL EQUIPO: ";
cin.ignore();
cin.getline(cod, 15);
codigoValidado=validarCodigo(cod);
}else {return false;}
}
///FIN DE LA VALIDACION

while (reg.leerDisco(pos++)==true){
if(strcmp(reg.getCodificacionMaquina(),cod)==0){

cout << left;
gotoxy(x,++y);
setColor(YELLOW);
cout << "CÓDIGO DEL EQUIPO: ";
setColor(LIGHTCYAN);
cout<< reg.getCodificacionMaquina()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "TIPO DE EQUIPO: ";
setColor(LIGHTCYAN);
cout<< reg.getTipo()<<endl;
setColor(YELLOW);
gotoxy(x,++y);
cout << "DESCRIPCIÓN: ";
setColor(LIGHTCYAN);
cout<< reg.getDescripcion()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "NÚMERO DE SERIE: ";
setColor(LIGHTCYAN);
cout<< reg.getNumeroSerie()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "ESTADO ACTUAL: ";
setColor(LIGHTCYAN);
if(reg.getEstado()==true){cout<< "OPERATIVA";}else{cout<<"NO OPERATIVA";}

}
}

}

int validarCodigo(char *cod){
Maquinas aux;
int i = 0;

if (aux.leerDisco()==false){return -1;}else{

    while (aux.leerDisco(i++)){
    if(strcmp(aux.getCodificacionMaquina(),cod)==0){
    return 1;
    }
  }
}
return 0;
}

void listarMaquinas(){
    Maquinas aux;
    int i=0, x=6, y=5;

        setlocale(LC_ALL,"spanish");
        title("LISTADOS DE LOS EQUIPOS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        recuadro(2,2,127,27);
        recuadro(4,3,123,25);
        cout << left;
        setColor(YELLOW);
        gotoxy(x,y);
        cout << setw(20) << "CODIGO DEL EQUIPO" << setw(20) << "TIPO DE EQUIPO" << setw(40) << "DESCRIPCION"<< setw(20) <<"NUMERO DE SERIE" << setw(20) << "ESTADO";
        setColor(LIGHTCYAN);
        gotoxy(x,++y);
        cout<< "------------------------------------------------------------------------------------------------------------------------";

        while (aux.leerDisco(i++)){
            setColor(WHITE);
            gotoxy(x,++y);
            cout << setw(20) << aux.getCodificacionMaquina();
            cout << setw(20) << aux.getTipo();
            cout << setw(40)<< aux.getDescripcion();
            cout << setw(20) << aux.getNumeroSerie();
            if (aux.getEstado()==1){cout << setw(20) <<"Operativa";}else{cout << setw(20) <<"No Operativa";}

        }
}
