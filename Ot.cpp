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


///METODOS DE LA CLASE OT
int OT::getOt(){
    return Ot;
}

Fecha  OT::getFechaGestion(){
    return FechaGestion;
}

Fecha  OT::getFechaEstimada(){
    return FechaEstimada;
}

Fecha  OT::getFechaCumplida(){
    return FechaCumplida;
}

char * OT::getCodificacionMaquina(){
    return CodificacionMaquina;
}

char * OT::getClasificado(){
    return Clasificado;
}

char * OT::getCriticidad(){
    return Criticidad;
}

char * OT::getProblema(){
    return Problema;
}

char * OT::getSolucion(){
    return Solucion;
}

bool   OT::getEstado(){
    return Estado;
}

void   OT::setOt(int ot){
    Ot=ot;
}

void   OT::setFechaGestion(Fecha fecha){
    FechaGestion=fecha;
}

void   OT::setFechaEstimada(Fecha fecha){
    FechaEstimada=fecha;
}

void   OT::setFechaCumplida(Fecha fecha){
    FechaCumplida=fecha;
}

void   OT::setCodificacionMaquina(char *codigo){
    strcpy(CodificacionMaquina, codigo);
}

void   OT::setClasificado(char *cla){
   strcpy(Clasificado, cla);

}

void   OT::setCriticidad(char *cri){
    strcpy(Criticidad, cri);


}

void   OT::setProblema(char *problema){
    strcpy(Problema, problema);
}

void   OT::setSolucion(char *solucion){
    strcpy(Solucion, solucion);
}

void   OT::setEstado(bool estado){
    Estado=estado;
}

void OT::modificarFecha(int x, int y){

this->FechaCumplida.cargar(x, ++y);

}

bool OT::cargar(){

    char cod[15], descripcion[50], nroSerie[25], problema[150],continuar, sigue;
    bool cargo, escribio;
    int  opcion , codigoValidado, cant;
    Fecha a, &b=a;

do{
int x=6, y=5;

system ("cls");
setlocale(LC_ALL,"spanish");
title("CARGA DE ORDEN DE TRABAJO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTBLUE);
cout<<"ORDEN DE TRABAJO NÚMERO: ";

cant=cantidad_OT();

setColor(WHITE);
cout<<cant+1;

this->setOt(cant+1);



gotoxy(x,y=y+2);
cout<<"CODIFICACION DEL EQUIPO: ";
cin.ignore();
cin.getline(cod, 15);

codigoValidado=validarCodigo(cod);

///SE VALIDA LA ELECCION
if(codigoValidado==1){
this->setCodificacionMaquina(cod);}
else{
        while(codigoValidado==0){
        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***NO EXISTE ESA CODIFICACION EN NUESTROS REGISTROS***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR S/N ? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        cout<<"INGRESE NUEVAMENTE LA CODIFICACION DEL EQUIPO: ";
        cin.ignore();
        cin.getline(cod, 15);
        codigoValidado=validarCodigo(cod);
        }else {return false;}
        }
        this->setCodificacionMaquina(cod);
    }
///FIN DE LA VALIDACION

gotoxy(x,++y);
cout<<"TIPO DE OT: ";
gotoxy(x,++y);
setColor(YELLOW);
cout << setw(20) << "1.Preventivo" << setw(20) << "2.Correctivo" << setw(20) << "3.Predictivo" << setw(20) << "4. Otros";
setColor(WHITE);
gotoxy(x,++y);
cout<<"ELIJA UNA OPCIÓN (1-4): ";
cin>>opcion;

///SE VALIDA LA ELECCION DEL TIPO
while (!(opcion>0 && opcion<=4)){
    msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);
    setColor(WHITE);
    gotoxy(x,++y);
    cout<<"ELIJA UNA OPCIÓN (1-4): ";
    cin>>opcion;
}
///FIN DE LA VALIDACION

char vecClasificado[4][20]= {"Preventivo","Correctivo","Predictivo","Otros"};

this->setClasificado(vecClasificado[opcion-1]);

gotoxy(x,++y);
cout<<"SELECCIONE EL NIVEL DE CRITICIDAD: ";
gotoxy(x,++y);
setColor(YELLOW);
cout << setw(20) << "1.Urgente" << setw(20) << "2.Alto" << setw(20) << "3.Medio" << setw(20) << "4. Bajo";
setColor(WHITE);
gotoxy(x,++y);
cout<<"ELIJA UNA OPCIÓN (1-4): ";
cin>>opcion;

///SE VALIDA LA ELECCION DEL TIPO
while (!(opcion>0 && opcion<=4)){
    msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);
    setColor(WHITE);
    gotoxy(x,++y);
    cout<<"ELIJA UNA OPCIÓN (1-4): ";
    cin>>opcion;
}
///FIN DE LA VALIDACION


char vecCriticidad[4][20]= {"Urgente","Alto","Medio","Bajo"};

this->setCriticidad(vecCriticidad[opcion-1]);

gotoxy(x,++y);
cout<<"DESCRIBA MUY PERO MUY BREVEMENTE EL PROBLEMA: ";
cin.ignore();
cin.getline(problema, 150);

this->setProblema(problema);

gotoxy(x,++y);
cout<<"FECHA SOLICITADA: ";
gotoxy(x,++y);
setColor(YELLOW);
cout<< "1.Modo Manual: El ingreso es por teclado ";
gotoxy(x,++y);
cout<< "2.Modo Automático: Se toma la fecha actual automaticamente";
setColor(WHITE);
gotoxy(x,++y);
cout<<"ELIJA UNA OPCIÓN (1-2): ";
cin>>opcion;

///SE VALIDA LA ELECCION DEL TIPO
while (!(opcion>0 && opcion<=2)){
    msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);
    setColor(WHITE);
    gotoxy(x,++y);
    cout<<"ELIJA UNA OPCIÓN (1-2): ";
    cin>>opcion;
}
///FIN DE LA VALIDACION

switch (opcion){
case 1:

this->FechaGestion.cargar(x, ++y);

break;

case 2:

this->getFechaGestion().getDia();
this->getFechaGestion().getMes();
this->getFechaGestion().getAnio();
this->setFechaGestion(getFechaGestion());

break;

}

x=35;
y=y-2;

gotoxy(x,++y);
cout<<"FECHA ESTIMADA DE REALIZACION: ";

this->FechaEstimada.cargar(x, ++y);
a=this->getFechaGestion();

while (!(this->getFechaEstimada() >= b)){
setColor(LIGHTRED);
msj("**LA FECHA INGRESADA NO PUEDE SER MENOR A LA SOLICITADA**", rlutil::WHITE, rlutil::RED);

x=x+35;
y=y-2;
gotoxy(x,++y);
cout<<"FECHA ESTIMADA DE REALIZACION: ";

this->FechaEstimada.cargar(x, ++y);
a=this->getFechaGestion();
}

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

void OT::mostrar(){
    int x=6, y=5;

        setlocale(LC_ALL,"spanish");
        title("INFORMACION DE LA ORDEN DE TRABAJO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        recuadro(2,2,127,27);
        recuadro(4,3,123,25);
        cout << left;
        setColor(YELLOW);
        gotoxy(x,y);
        cout << setw(8) << "N° OT" << setw(14) << "COD. EQUIPO" << setw(14) <<"CRITICIDAD" << setw(45) <<"DESCRIPCION DEL PROBLEMA" << setw(12) << "F.SOL"<< setw(12) << "F.EST" << setw(12) << "ESTADO";
        setColor(LIGHTCYAN);
        gotoxy(x,++y);
        cout<< "------------------------------------------------------------------------------------------------------------------------";
            setColor(WHITE);
            gotoxy(x,++y);
            cout << setw(8) << getOt();
            cout << setw(14) << getCodificacionMaquina();
            cout << setw(14) << getCriticidad();
            cout << setw(45) << getProblema();
            cout << setw(2);
            cout << right;
            cout << setfill('0');
            cout << getFechaGestion().getDia();
            cout << left;
            cout << setfill(' ');
            cout << "/";
            cout << setw(2);
            cout << right;
            cout << setfill('0');
            cout << getFechaGestion().getMes();
            cout << left;
            cout << setfill(' ');
            cout << "/";
            cout << setw(6);
            cout << getFechaGestion().getAnio();
            cout << setw(2);
            cout << right;
            cout << setfill('0');
            cout << getFechaEstimada().getDia();
            cout << left;
            cout << setfill(' ');
            cout << "/";
            cout << setw(2);
            cout << right;
            cout << setfill('0');
            cout << getFechaEstimada().getMes();
            cout << left;
            cout << setfill(' ');
            cout << "/";
            cout << setw(6);
            cout << getFechaEstimada().getAnio();
            if(getEstado()==true){cout << setw(12) << "NO CUMPLIDA";}else{cout << setw(12) <<"CUMPLIDA";}



}

bool OT::escribirDisco(int pos){
    bool grabo=false;
        FILE *f;
        if (pos == -1){
            f = fopen("OT.dat", "ab");
            if (f == NULL){
                msj("***NO SE PUEDO ABRIR EL ARCHIVO***", rlutil::WHITE, rlutil::RED);
                return grabo;
            }
        }
        else{
            f = fopen("OT.dat", "rb+");
            if (f == NULL){
                msj("***NO SE PUEDO ABRIR EL ARCHIVO***", rlutil::WHITE, rlutil::RED);
                return grabo;
            }
            fseek(f, pos * sizeof(OT), 0);
        }
        grabo = fwrite(this, sizeof(OT), 1, f);
        fclose(f);
        return grabo;
}

bool OT::leerDisco(){
 bool leyo;

FILE *f;
f = fopen("OT.dat", "rb");
if (f == NULL){
return false;
}

leyo = fread(this, sizeof(OT), 1, f);
fclose(f);

return leyo;

}

bool OT::leerDisco(int pos){
 bool leyo=false;

FILE *f;
f = fopen("OT.dat", "rb");
if (f == NULL){
msj("***NO SE PUEDO ABRIR EL ARCHIVO***", rlutil::WHITE, rlutil::RED);
return leyo;
}

fseek(f, pos * sizeof(OT), 0);
leyo = fread(this, sizeof(OT), 1, f);
fclose(f);


return leyo;

}






 ///FUNCIONES GLOBALES DE CLASE OT

 bool cerrarOT(){
    OT aux;
    Fecha a, &b=a;
    char Solucion[150], sigue, continuar;
    bool cargo, escribio;
    int  ot, opcion , OTvalidado, cant, pos;


do{
int x=6, y=5;

system ("cls");
setlocale(LC_ALL,"spanish");
title("CERRAR OT", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
cout<<"NRO. DE OT: ";
cin>>ot;

OTvalidado=validarOT(ot);

///SE VALIDA LA OT
while(OTvalidado!=1){

if(OTvalidado==0){
setColor(LIGHTRED);
gotoxy(x,++y);
cout<<"***ESA OT YA ESTA CUMPLIDA***";

}else{
setColor(LIGHTRED);
gotoxy(x,++y);
cout<<"***NO EXISTE ESA OT EN NUESTROS REGISTROS***";
setColor(WHITE);
}

setColor(WHITE);
gotoxy(x,++y);
cout<<"DESEA CONTINUAR S/N ? : ";
cin>>sigue;
continuar=towupper(sigue);
if (continuar == 'S'){
gotoxy(x,++y);
cout<<"INGRESE NUEVAMENTE EL NRO. DE OT: ";
cin>>ot;
OTvalidado=validarOT(ot);

}else {return false;}

}
///FIN DE LA VALIDACION


pos=buscarPos(ot);
aux.leerDisco(pos-1);
aux.mostrar();

x=6;
y=10;

gotoxy(x,y);
cout<<"DESCRIBA MUY PERO MUY BREVEMENTE LA SOLUCION: ";
cin.ignore();
cin.getline(Solucion, 150);

aux.setSolucion(Solucion);


gotoxy(x,++y);
cout<<"FECHA CUMPLIDA: ";
gotoxy(x,++y);
setColor(YELLOW);
cout<< "1.Modo Manual: El ingreso es por teclado ";
gotoxy(x,++y);
cout<< "2.Modo Automático: Se toma la fecha actual automaticamente";
setColor(WHITE);
gotoxy(x,++y);
cout<<"ELIJA UNA OPCIÓN (1-2): ";
cin>>opcion;

///SE VALIDA LA ELECCION DEL TIPO
while (!(opcion>0 && opcion<=2)){
    msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);
    setColor(WHITE);
    gotoxy(x,++y);
    cout<<"ELIJA UNA OPCIÓN (1-2): ";
    cin>>opcion;
}
///FIN DE LA VALIDACION


switch (opcion){
case 1:

aux.modificarFecha(x, y);
a=aux.getFechaGestion();

while (!(aux.getFechaCumplida() >= b)){
setColor(LIGHTRED);
msj("**LA FECHA INGRESADA NO PUEDE SER MENOR A LA SOLICITADA**", rlutil::WHITE, rlutil::RED);
x=x+15;
aux.modificarFecha(x, y);
a=aux.getFechaGestion();
}

break;

case 2:
aux.getFechaCumplida().getDia();
aux.getFechaCumplida().getMes();
aux.getFechaCumplida().getAnio();
aux.setFechaCumplida(aux.getFechaCumplida());
break;

}




mostrarCumplido(aux);

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
aux.setEstado(false);
aux.escribirDisco(pos-1);
return true;}

}

bool mostrarDetalles(){
OT reg;
int x=6, y=5, pos=0;
char sigue, continuar;
int  ot, OTvalidado;

setlocale(LC_ALL,"spanish");
title("INFORMACION DE LA ORDEN DE TRABAJO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
cout<<"NRO. DE OT: ";
cin>>ot;

OTvalidado=validarOT(ot);

///SE VALIDA LA OT
while(!(OTvalidado==1 || OTvalidado==0)){

setColor(LIGHTRED);
gotoxy(x,++y);
cout<<"***NO EXISTE ESA OT EN NUESTROS REGISTROS***";
setColor(WHITE);
gotoxy(x,++y);
cout<<"DESEA CONTINUAR S/N ? : ";
cin>>sigue;
continuar=towupper(sigue);
if (continuar == 'S'){
gotoxy(x,++y);
cout<<"INGRESE NUEVAMENTE EL NRO. DE OT: ";
cin>>ot;
OTvalidado=validarOT(ot);

}else {return false;}

}
///FIN DE LA VALIDACION

while (reg.leerDisco(pos++)==true){
if(reg.getOt()==ot){

cout << left;
gotoxy(x,++y);
setColor(YELLOW);
cout << "NUMERO DE OT: ";
setColor(LIGHTCYAN);
cout<< reg.getOt()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "CODIGO DEL EQUIPO: ";
setColor(LIGHTCYAN);
cout<< reg.getCodificacionMaquina()<<endl;
setColor(YELLOW);
gotoxy(x,++y);
cout << "DETALLES DEL PROBLEMA: ";
setColor(LIGHTCYAN);
cout<< reg.getProblema()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "DETALLES DE LO REALIZADO: ";
setColor(LIGHTCYAN);
cout<< reg.getSolucion()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "FECHA SOLICITADA: ";
setColor(LIGHTCYAN);
cout << setw(2);
cout << right;
cout << setfill('0');
cout << reg.getFechaGestion().getDia();
cout << left;
cout << setfill(' ');
cout << "/";
cout << setw(2);
cout << right;
cout << setfill('0');
cout << reg.getFechaGestion().getMes();
cout << left;
cout << setfill(' ');
cout << "/";
cout << setw(6);
cout << reg.getFechaGestion().getAnio();
cout<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "FECHA ESTIMADA: ";
setColor(LIGHTCYAN);
cout << setw(2);
cout << right;
cout << setfill('0');
cout << reg.getFechaEstimada().getDia();
cout << left;
cout << setfill(' ');
cout << "/";
cout << setw(2);
cout << right;
cout << setfill('0');
cout << reg.getFechaEstimada().getMes();
cout << left;
cout << setfill(' ');
cout << "/";
cout << setw(6);
cout << reg.getFechaEstimada().getAnio();
cout<<endl;
if(reg.getEstado()==false){
gotoxy(x,++y);
setColor(YELLOW);
cout << "FECHA CUMPLIDA: ";
setColor(LIGHTCYAN);
cout << setw(2);
cout << right;
cout << setfill('0');
cout << reg.getFechaCumplida().getDia();
cout << left;
cout << setfill(' ');
cout << "/";
cout << setw(2);
cout << right;
cout << setfill('0');
cout << reg.getFechaCumplida().getMes();
cout << left;
cout << setfill(' ');
cout << "/";
cout << setw(6);
cout << reg.getFechaCumplida().getAnio();
cout<<endl;
}
gotoxy(x,++y);
setColor(YELLOW);
cout << "ESTADO ACTUAL: ";
setColor(LIGHTCYAN);
if(reg.getEstado()==true){cout<< "NO CUMPLIDA";}else{cout<<"CUMPLIDA";}

}
}

}

void mostrarCumplido(OT aux){

        int x=6, y=5;

        setlocale(LC_ALL,"spanish");
        title("INFORMACION DE LA OT CUMPLIDA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        recuadro(2,2,127,27);
        recuadro(4,3,123,25);
        cout << left;
        setColor(YELLOW);
        gotoxy(x,y);
        cout << setw(8) << "N° OT" << setw(12) << "COD. EQUIPO" << setw(38) <<"DESCRIPCION DEL PROBLEMA" << setw(38) <<"DESCRIPCION DE LA SOLUCION"<< setw(10) << "F. SOL"<< setw(10) << "F. CUMPL";
        setColor(LIGHTCYAN);
        gotoxy(x,++y);
        cout<< "------------------------------------------------------------------------------------------------------------------------";

            setColor(WHITE);
            gotoxy(x,++y);
            cout << setw(8) << aux.getOt();
            cout << setw(12) << aux.getCodificacionMaquina();
            cout << setw(38) << aux.getProblema();
            cout << setw(38) << aux.getSolucion();
            cout << setw(2);
            cout << right;
            cout << setfill('0');
            cout << aux.getFechaGestion().getDia();
            cout << left;
            cout << setfill(' ');
            cout << "/";
            cout << setw(2);
            cout << right;
            cout << setfill('0');
            cout << aux.getFechaGestion().getMes();
            cout << left;
            cout << setfill(' ');
            cout << "/";
            cout << setw(6);
            cout << aux.getFechaGestion().getAnio();
            cout << setw(2);
            cout << right;
            cout << setfill('0');
            cout << aux.getFechaCumplida().getDia();
            cout << left;
            cout << setfill(' ');
            cout << "/";
            cout << setw(2);
            cout << right;
            cout << setfill('0');
            cout << aux.getFechaCumplida().getMes();
            cout << left;
            cout << setfill(' ');
            cout << "/";
            cout << setw(6);
            cout << aux.getFechaCumplida().getAnio();


}

int cantidad_OT(){
int bytes, cant;

FILE *f=fopen("OT.dat","rb");
if (f==NULL){
setColor(LIGHTRED);
return 0;
    }
fseek(f, 0, SEEK_END); ///SEEK_SET --> 0 , SEEK_CUR --> 1 , SEEK_END --> 2
bytes=ftell(f);
fclose(f);
cant=bytes/sizeof(OT);

return cant;
}

int buscarPos(int ot){
    OT aux;
    int i=0;

    while (aux.leerDisco(i++)){
    if(aux.getOt()==ot ){
    return i;
    }
  }
}

int validarOT(int ot){
OT aux;
int i = 0;

if (aux.leerDisco()==false){return -1;}else{

    while (aux.leerDisco(i++)){
    if(aux.getOt() == ot){
            if(aux.getEstado()==true){
                return 1;
            }else{return 0;}

    }
  }
}
return -2;
}

void listarOT(){
    OT aux;
    int i=0, x=6, y=5;

        setlocale(LC_ALL,"spanish");
        title("LISTADOS DE LAS OT", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        recuadro(2,2,127,27);
        recuadro(4,3,123,25);
        cout << left;
        setColor(YELLOW);
        gotoxy(x,y);
        cout << setw(8) << "N° OT" << setw(14) << "COD. EQUIPO" << setw(14) <<"CRITICIDAD" << setw(45) <<"DESCRIPCION DEL PROBLEMA" << setw(12) << "FECHA SOL."<< setw(12) << "FECHA EST."  << setw(12) << "ESTADO";
        setColor(LIGHTCYAN);
        gotoxy(x,++y);
        cout<< "------------------------------------------------------------------------------------------------------------------------";

        while (aux.leerDisco(i++)){
            setColor(WHITE);
            gotoxy(x,++y);
            cout << setw(8)  << aux.getOt();
            cout << setw(14) << aux.getCodificacionMaquina();
            cout << setw(14) << aux.getCriticidad();
            cout << setw(45) << aux.getProblema();
            cout << setw(2);
            cout << right;
            cout << setfill('0');
            cout << aux.getFechaGestion().getDia();
            cout << left;
            cout << setfill(' ');
            cout << "/";
            cout << setw(2);
            cout << right;
            cout << setfill('0');
            cout << aux.getFechaGestion().getMes();
            cout << left;
            cout << setfill(' ');
            cout << "/";
            cout << setw(6);
            cout << aux.getFechaGestion().getAnio();
            cout << setw(2);
            cout << right;
            cout << setfill('0');
            cout << aux.getFechaEstimada().getDia();
            cout << left;
            cout << setfill(' ');
            cout << "/";
            cout << setw(2);
            cout << right;
            cout << setfill('0');
            cout << aux.getFechaEstimada().getMes();
            cout << left;
            cout << setfill(' ');
            cout << "/";
            cout << setw(6);
            cout << aux.getFechaEstimada().getAnio();
            if(aux.getEstado()==true){cout << setw(12) << "NO CUMPLIDA";}else{cout << setw(12) <<"CUMPLIDA";}

        }
}
