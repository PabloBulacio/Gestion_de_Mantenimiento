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


///METODOS DE LA CLASE PERSONAS
char*  Personas::getDni(){
    return Dni;
}

char* Personas::getApellidos(){
    return Apellidos;
}

char* Personas::getNombres(){
    return Nombres;
}

int  Personas::getEdad(){
    return Edad;
}

char* Personas::getDireccion(){
    return Direccion;
}

char* Personas::getTelefono(){
return Telefono;
}

Fecha Personas::getFechaNacimiento(){
    return FechaNacimiento;
}

void Personas::setDni(char* dni){
    strcpy(Dni, dni);
}

void Personas::setApellidos(char *apellidos){
    strcpy(Apellidos,apellidos);
}

void Personas::setNombres(char *nombres){
    strcpy(Nombres, nombres);
}

void Personas::setEdad(int edad){
    Edad=edad;
}

void Personas::setDireccion(char *direccion){
    strcpy(Direccion, direccion);
}

void Personas::setTelefono(char* telefono){
    strcpy(Telefono,telefono);
}

void Personas::setFechaNacimiento(Fecha fecha){
    FechaNacimiento=fecha;
}

void Personas::modificarFecha(int x, int y){

this->FechaNacimiento.cargar(x, ++y);

}

void Personas::mostrar(){

        setlocale(LC_ALL,"spanish");
        title("DATOS PERSONALES", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        recuadro(2,2,127,27);
        recuadro(4,3,123,25);
        cout << left;
        setColor(YELLOW);
        gotoxy(6,5);
        cout << setw(10) << "DNI" << setw(20) << "APELLIDO/S" << setw(20) << "NOMBRE/S"<< setw(35) <<"DIRECCIÓN" << setw(16) << "TELÉFONO" << setw(6) << "EDAD" << setw(10) << "F. NACIMIENTO";
        setColor(LIGHTCYAN);
        gotoxy(6,6);
        cout<< "------------------------------------------------------------------------------------------------------------------------";
            setColor(WHITE);
            gotoxy(6,7);
            cout << setw(10) << getDni();
            cout << setw(20) << getApellidos();
            cout << setw(20) << getNombres();
            cout << setw(35) << getDireccion();
            cout << setw(16) << getTelefono();
            cout << setw(7)  << getEdad();
            cout << setw(2);
            cout << right;
            cout << setfill('0');
            cout << FechaNacimiento.getDia();
            cout << left;
            cout << setfill(' ');
            cout << "/";
            cout << setw(2);
            cout << right;
            cout << setfill('0');
            cout << FechaNacimiento.getMes();
            cout << left;
            cout << setfill(' ');
            cout << "/";
            cout << setw(6);
            cout << FechaNacimiento.getAnio();









}

bool Personas::cargar(Personas *nuevo){
    char nombres[50], apellidos[50], direccion[100];
    char dni[15], telefono[15], confirma, eleccion;
    bool validado;
    int x=6, y=5, anio, mes, dia, edad, dnivalidado;


system ("cls");
setlocale(LC_ALL,"spanish");
title("DATOS PERSONALES", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);

gotoxy(x,y);
cout<<"NRO. DE DNI: ";
cin.ignore();
cin.getline(dni, 15);


dnivalidado=validarDni(dni);

///SE VALIDA LA ELECCION
if(dnivalidado==-1 || dnivalidado==0){
nuevo->setDni(dni);}
else{
        while(dnivalidado==1){
        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***YA EXISTE ESE NUMERO EN NUESTROS REGISTROS***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"INGRESE NUEVAMENTE EL NRO. DE DNI: ";
        cin.getline(dni, 15);
        dnivalidado=validarDni(dni);
        }
        nuevo->setDni(dni);
    }
///FIN DE LA VALIDACION


gotoxy(x,++y);
cout<<"NOMBRE/S: ";
cin.getline(nombres, 50);//TODO: VALIDAR NOMBRE y APELLIDO
nuevo->setNombres(nombres);
gotoxy(x,++y);
cout<<"APELLIDO/S: ";
cin.getline(apellidos, 50);
nuevo->setApellidos(apellidos);
gotoxy(x,++y);
cout<<"DIRECCIÓN: ";
cin.getline(direccion, 100);
nuevo->setDireccion(direccion);
gotoxy(x,++y);
cout<<"TELÉFONO: ";
cin.getline(telefono, 15);
nuevo->setTelefono(telefono);
gotoxy(x,++y);
cout<<"FECHA DE NACIMIENTO: ";
nuevo->FechaNacimiento.cargar(x, ++y);

///SE AVERIGUA EN FORMA AUTOMATICA LA EDAD
anio=nuevo->FechaNacimiento.getAnio();
mes=nuevo->FechaNacimiento.getMes();
dia=nuevo->FechaNacimiento.getDia();

edad=nuevo->FechaNacimiento.cantAniosHastaHoy(dia, mes, anio);
///SE ASIGNA LA EDAD
nuevo->setEdad(edad);

///SE MUESTRA LO CARGADO HASTA ESTE PUNTO
system("cls");
nuevo->mostrar();

x=6;
y=10;

gotoxy(x,y);
setColor(LIGHTRED);
cout<<"NOTA: ";
setColor(LIGHTCYAN);
cout<<"LOS DATOS PERSONALES SE GUARDARÁ MOMENTANEAMENTE Y NO PODRÁN SER MODIFICADOS HASTA SU CONFIRMACION FINAL";
setColor(WHITE);
gotoxy(x,12);
cout<<"¿CONTINÚA CARGANDO S/N?: ";
cin>>eleccion;
confirma=towupper(eleccion);

///SE VALIDA LA ELECCION
while (!(confirma=='S' || confirma=='N')){
    msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);
    setColor(WHITE);
    gotoxy(x,++y);
    cout<<"¿CONTINÚA CARGANDO S/N?: ";
    cin>>eleccion;
    confirma=towupper(eleccion);
}

///FIN DE LA VALIDACION
if (confirma=='S'){

    return true;

}else{
    return false;

}


}

bool Personas::escribirDisco(int pos){
   bool grabo=false;
        FILE *f;
        if (pos == -1){
            f = fopen("Personas.dat", "ab");
            if (f == NULL){
                msj("***NO SE PUEDO ABRIR EL ARCHIVO***", rlutil::WHITE, rlutil::RED);
                return grabo;
            }
        }
        else{
            f = fopen("Personas.dat", "rb+");
            if (f == NULL){
                msj("***NO SE PUEDO ABRIR EL ARCHIVO***", rlutil::WHITE, rlutil::RED);
                return grabo;
            }
            fseek(f, pos * sizeof(Personas), 0);
        }
        grabo = fwrite(this, sizeof(Personas), 1, f);
        fclose(f);
        return grabo;

}

bool Personas::leerDisco(){
 bool leyo;

FILE *f;
f = fopen("Personas.dat", "rb");
if (f == NULL){
return false;
}

leyo = fread(this, sizeof(Personas), 1, f);
fclose(f);

return leyo;

}

bool Personas::leerDisco(int pos){
 bool leyo=false;

FILE *f;
f = fopen("Personas.dat", "rb");
if (f == NULL){
msj("***NO SE PUEDO ABRIR EL ARCHIVO***", rlutil::WHITE, rlutil::RED);
return leyo;
}

fseek(f, pos * sizeof(Personas), 0);
leyo = fread(this, sizeof(Personas), 1, f);
fclose(f);


return leyo;

}







///FUNCIONES GLOBALES DE CLASES PERSONAS

bool mostrarDetallesPersonas(){

    Personas reg;
    char dni[15], sigue, continuar;
    int x=6, y=5, pos=0, dnivalidado;

setlocale(LC_ALL,"spanish");
title("MOSTRAR DETALLES PERSONALES", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
cout<<"DNI: ";
cin.ignore();
cin.getline(dni, 15);

dnivalidado=validarDni(dni);

///SE VALIDA LA ELECCION

while(!(dnivalidado==1)){
setColor(LIGHTRED);
gotoxy(x,++y);
cout<<"***NO EXISTE ESE DNI EN NUESTROS REGISTROS***";
setColor(WHITE);
gotoxy(x,++y);
cout<<"DESEA CONTINUAR S/N ? : ";
cin>>sigue;
continuar=towupper(sigue);
if (continuar == 'S'){
setColor(WHITE);
gotoxy(x,++y);
cout<<"INGRESE NUEVAMENTE EL DNI: ";
cin.ignore();
cin.getline(dni, 15);
dnivalidado=validarDni(dni);
}else {return false;}
}
///FIN DE LA VALIDACION

while (reg.leerDisco(pos++)==true){
if(strcmp(reg.getDni(),dni)==0){

cout << left;
gotoxy(x,++y);
setColor(YELLOW);
cout << "DNI: ";
setColor(LIGHTCYAN);
cout<< reg.getDni()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "APELLIDO/S: ";
setColor(LIGHTCYAN);
cout<< reg.getApellidos()<<endl;
setColor(YELLOW);
gotoxy(x,++y);
cout << "NOMBRE/S: ";
setColor(LIGHTCYAN);
cout<< reg.getNombres()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "DIRECCIÓN: ";
setColor(LIGHTCYAN);
cout<< reg.getDireccion()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "TELÉFONO: ";
setColor(LIGHTCYAN);
cout<< reg.getTelefono()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "FECHA DE NACIMIENTO: ";
setColor(LIGHTCYAN);
cout << setw(2);
cout << right;
cout << setfill('0');
cout << reg.getFechaNacimiento().getDia();
cout << left;
cout << setfill(' ');
cout << "/";
cout << setw(2);
cout << right;
cout << setfill('0');
cout << reg.getFechaNacimiento().getMes();
cout << left;
cout << setfill(' ');
cout << "/";
cout << setw(6);
cout << reg.getFechaNacimiento().getAnio();
cout<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "EDAD: ";
setColor(LIGHTCYAN);
cout<< reg.getEdad()<<endl;

}
}
}

bool validar_nombres_apellidos(char *nombre, int tam){
int i, cont=0;
bool validado=false;

for (i=0; i<tam; i++){
        if (nombre[i]==NULL || nombre[i]==' '){
            cont++;
        }

}

if (cont==tam){
    return validado;
} else{
    validado=true;
    return validado;
    }

}

int buscarPosicion(char *dni){
    Personas aux;
    int i=0;

    while (aux.leerDisco(i++)){
    if(strcmp(aux.getDni(),dni)==0){
    return i;
    }
  }
}

int validarDni(char *dni){
Personas aux;
int i = 0;

if (aux.leerDisco()==false){return -1;}else{

    while (aux.leerDisco(i++)){
    if(strcmp(aux.getDni(),dni)==0){
    return 1;
    }
  }
}
return 0;
}

void listarPersonas(){
        Personas aux;

        int i = 0;
        int x=6, y=5;

        system("cls");
        setlocale(LC_ALL,"spanish");
        title("LISTADO DE DATOS PERSONALES", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        recuadro(2,2,127,27);
        recuadro(4,3,123,25);
        cout << left;
        setColor(YELLOW);
        gotoxy(x,y);
        cout << setw(10) << "DNI" << setw(20) << "APELLIDO/S" << setw(20) << "NOMBRE/S"<< setw(35) <<"DIRECCION" << setw(16) << "TELEFONO" << setw(6) << "EDAD" << setw(10) << "F. NACIMIENTO";
        setColor(LIGHTCYAN);
        gotoxy(x,++y);
        cout<< "------------------------------------------------------------------------------------------------------------------------";

        while (aux.leerDisco(i++)){
            setColor(WHITE);
            gotoxy(x,++y);
            cout << setw(10) << aux.getDni();
            cout << setw(20) << aux.getApellidos();
            cout << setw(20) << aux.getNombres();
            cout << setw(35) << aux.getDireccion();
            cout << setw(16) << aux.getTelefono();
            cout << setw(7) <<  aux.getEdad();
            cout << setw(2);
            cout << right;
            cout << setfill('0');
            cout << aux.getFechaNacimiento().getDia();
            cout << left;
            cout << setfill(' ');
            cout << "/";
            cout << setw(2);
            cout << right;
            cout << setfill('0');
            cout << aux.getFechaNacimiento().getMes();
            cout << left;
            cout << setfill(' ');
            cout << "/";
            cout << setw(6);
            cout << aux.getFechaNacimiento().getAnio();
        }


}

bool modificar_x_dni(){
    Personas aux;

    char nombres[50], apellidos[50], direccion[100];
    char dni[15], telefono[15],continuar, sigue, confirma, eleccion;
    bool validado, ok=true, modifico;
    int x=6, y=5, anio, mes, dia, edad, dnivalidado, opcion, pos;




system ("cls");
setlocale(LC_ALL,"spanish");
title("MODIFICACION DE DATOS PERSONALES", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);

gotoxy(x,y);
cout<<"NRO. DE DNI: ";
cin.ignore();
cin.getline(dni, 15);

dnivalidado=validarDni(dni);

///SE VALIDA LA ELECCION
while(!(dnivalidado==1)){
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
cout<<"INGRESE NUEVAMENTE EL NRO. DE DNI: ";
cin.ignore();
cin.getline(dni, 15);
dnivalidado=validarDni(dni);
}else {return false;}

}
///FIN DE LA VALIDACION


pos=buscarPosicion(dni);
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
cout << setw(20) << "1. APELLIDO/S" << setw(20) << "2. NOMBRE/S"<< setw(20) <<"3. DIRECCION" << setw(20) << "4. TELEFONO"<< setw(20) << "5. F. NACIMIENTO";
gotoxy(x,++y);
setColor(LIGHTCYAN);
cout<< "------------------------------------------------------------------------------------------------------------------------";



gotoxy(x,++y);
setColor(WHITE);
cout<<"ELIJA UNA OPCION (1-5): ";
cin>>opcion;

do{

switch(opcion){

case 1:
    gotoxy(x,++y);
    cout<<"APELLIDO/S: ";
    cin.ignore();
    cin.getline(apellidos, 50);
    gotoxy(x,++y);
    cout<<"CONFIRMA EL CAMBIO REALIZADO S/N?: ";
    cin>>eleccion;
    confirma=towupper(eleccion);
    if(confirma=='S'){
            aux.setApellidos(apellidos);
            aux.escribirDisco(pos-1);
            return ok;
    }
    opcion=0;
    break;

case 2:
    gotoxy(x,++y);
    cout<<"NOMBRE/S: ";
    cin.ignore();
    cin.getline(nombres, 50);
    gotoxy(x,++y);
    cout<<"CONFIRMA EL CAMBIO REALIZADO S/N?: ";
    cin>>eleccion;
    confirma=towupper(eleccion);
    if(confirma=='S'){
            aux.setNombres(nombres);
            aux.escribirDisco(pos-1);
            return ok;
    }
    opcion=0;
    break;

case 3:
    gotoxy(x,++y);
    cout<<"DIRECCION: ";
    cin.ignore();
    cin.getline(direccion, 100);
    gotoxy(x,++y);
    cout<<"CONFIRMA EL CAMBIO REALIZADO S/N?: ";
    cin>>eleccion;
    confirma=towupper(eleccion);
    if(confirma=='S'){
            aux.setDireccion(direccion);
            aux.escribirDisco(pos-1);
            return ok;
    }
    opcion=0;
    break;

case 4:
    gotoxy(x,++y);
    cout<<"TELEFONO: ";
    cin.ignore();
    cin.getline(telefono, 15);
    gotoxy(x,++y);
    cout<<"CONFIRMA EL CAMBIO REALIZADO S/N?: ";
    cin>>eleccion;
    confirma=towupper(eleccion);
    if(confirma=='S'){
            aux.setTelefono(telefono);
            aux.escribirDisco(pos-1);
            return ok;
    }
    opcion=0;
    break;

case 5:
    gotoxy(x,++y);
    cout<<"FECHA DE NACIMIENTO: ";
    aux.modificarFecha(x, ++y);
    gotoxy(20,++y);
    cout<<"CONFIRMA EL CAMBIO REALIZADO S/N?: ";
    cin>>eleccion;
    confirma=towupper(eleccion);
    if(confirma=='S'){
    ///SE AVERIGUA EN FORMA AUTOMATICA LA EDAD
    anio=aux.getFechaNacimiento().getAnio();
    mes=aux.getFechaNacimiento().getMes();
    dia=aux.getFechaNacimiento().getDia();

    edad=aux.getFechaNacimiento().cantAniosHastaHoy(dia, mes, anio);
    ///SE ASIGNA LA EDAD
    aux.setEdad(edad);
    ///SE GUARDA LOS CAMBIOS
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
        cout<<"ELIJA UNA OPCION (1-5): ";
        cin>>opcion;
        }else {opcion=0;}
        }while (!(opcion>=0 && opcion<=5));


    break;

}


}while(opcion>0 && opcion<=5);

}




