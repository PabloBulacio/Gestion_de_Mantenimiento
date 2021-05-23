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



///METODOS DE LA CLASE VALE ENTRADA SALIDA
int valeEntradaSalida::getNroVale(){
    return NroVale;
}

int valeEntradaSalida::getLegajo(){
    return Legajo;
}

int valeEntradaSalida::getOt(){
    return Ot;
}

bool valeEntradaSalida::getTipoVale(){
    return TipoVale;
}

Fecha   valeEntradaSalida::getFechaGestion(){
    return FechaGestion;
}

void    valeEntradaSalida::setNroVale(int nv){
    NroVale=nv;
}

void    valeEntradaSalida::setLegajo(int leg){
    Legajo=leg;
}

void    valeEntradaSalida::setOt(int ot){
    Ot=ot;
}

void    valeEntradaSalida::setTipoVale(bool tv){
    TipoVale=tv;
}

void valeEntradaSalida::setFechaGestion(Fecha fg){
    FechaGestion=fg;
}

bool valeEntradaSalida::cargar(bool es){

    bool cargo, escribio, ok=false;
    int  opcion , OTvalidado, codigoValidado, cant=0, item, i, legajo, legajovalidado, ot;
    char sigue, continuar;
    Items reg[9];
    Fecha fecha;

if (es==false){///SE CARGA VALES DE SALIDA


do{
int x=6, y=5;


system ("cls");
setlocale(LC_ALL,"spanish");
title("CARGAR VALE DE SALIDA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTBLUE);
cout<<"VALE NRO.: ";

cant=cantidadValeEntradaSalida();

setColor(WHITE);
cout<<cant+1;

this->setNroVale(cant+1);

gotoxy(x,y=y+2);
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

this->setOt(ot);


gotoxy(x,++y);
cout<<"INGRESE EL NÚMERO DE LEGAJO DEL SOLICITANTE: ";
cin>>legajo;

legajovalidado=validarLegajo(legajo);

///SE VALIDA LA ELECCION

while(!(legajovalidado==1)){
setColor(LIGHTRED);
gotoxy(x,++y);
cout<<"***NO EXISTE ESE LEGAJO EN NUESTROS REGISTROS***";
setColor(WHITE);
gotoxy(x,++y);
cout<<"DESEA CONTINUAR S/N ? : ";
cin>>sigue;
continuar=towupper(sigue);
if (continuar == 'S'){
setColor(WHITE);
gotoxy(x,++y);
cout<<"INGRESE NUEVAMENTE EL NÚMERO DE LEGAJO DEL SOLICITANTE: ";
cin>>legajo;
legajovalidado=validarLegajo(legajo);

}else {return false;}

}
///FIN DE LA VALIDACION

this->setLegajo(legajo);

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

///SE LLAMA A LA FUNCION DE CARGAR ITEMS

item=0;


do{

if (ok==true){item++;}

ok=reg[item].cargar(cant+1, item+1, false);


}while (ok == true && item < 9);

///FIN DE LA CARGA


this->mostrar(reg, item+1, false);

x=6;
y=item+10;

gotoxy(x,y);
setColor(LIGHTRED);
cout<<"NOTA: ";
setColor(LIGHTCYAN);
cout<<"ANTES DE CONTINUAR PUEDE ELEGIR LAS SIGUIENTES OPCIONES: ";
gotoxy(x,++y);
setColor(LIGHTGREEN);
cout << setw(50) << "1.EMPEZAR DE NUEVO Y CARGAR  LOS DATOS"<< setw(35) << "2.FINALIZAR SIN GUARDAR" << setw(35) << "3.FINALIZAR Y GUARDAR";
setColor(WHITE);
gotoxy(x,++y);
cout<<"ELIJA UNA OPCIÓN (1-3): ";
cin>>opcion;


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


for(i=0; i< item +1; i++){
reg[i].escribirDisco();
}
this->setTipoVale(false);
return true;

}


}else{///SE CARGA DE VALES DE ENTRADA

do{
int x=6, y=5;


system ("cls");
setlocale(LC_ALL,"spanish");
title("CARGAR VALE DE ENTRADA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTBLUE);
cout<<"VALE NRO.: ";

cant=cantidadValeEntradaSalida();

setColor(WHITE);
cout<<cant+1;

this->setNroVale(cant+1);

gotoxy(x,y=y+2);
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

this->setOt(ot);


gotoxy(x,++y);
cout<<"INGRESE EL NÚMERO DE LEGAJO DEL SOLICITANTE: ";
cin>>legajo;

legajovalidado=validarLegajo(legajo);

///SE VALIDA LA ELECCION

while(!(legajovalidado==1)){
setColor(LIGHTRED);
gotoxy(x,++y);
cout<<"***NO EXISTE ESE LEGAJO EN NUESTROS REGISTROS***";
setColor(WHITE);
gotoxy(x,++y);
cout<<"DESEA CONTINUAR S/N ? : ";
cin>>sigue;
continuar=towupper(sigue);
if (continuar == 'S'){
setColor(WHITE);
gotoxy(x,++y);
cout<<"INGRESE NUEVAMENTE EL NÚMERO DE LEGAJO DEL SOLICITANTE: ";
cin>>legajo;
legajovalidado=validarLegajo(legajo);

}else {return false;}

}
///FIN DE LA VALIDACION

this->setLegajo(legajo);

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

///SE LLAMA A LA FUNCION DE CARGAR ITEMS

item=0;

do{

if (ok==true){item++;}

ok=reg[item].cargar(cant+1, item+1, false);


}while (ok == true && item < 9);

///FIN DE LA CARGA


this->mostrar(reg, item+1, true);

x=6;
y=item+10;

gotoxy(x,y);
setColor(LIGHTRED);
cout<<"NOTA: ";
setColor(LIGHTCYAN);
cout<<"ANTES DE CONTINUAR PUEDE ELEGIR LAS SIGUIENTES OPCIONES: ";
gotoxy(x,++y);
setColor(LIGHTGREEN);
cout << setw(50) << "1.EMPEZAR DE NUEVO Y CARGAR  LOS DATOS"<< setw(35) << "2.FINALIZAR SIN GUARDAR" << setw(35) << "3.FINALIZAR Y GUARDAR";
setColor(WHITE);
gotoxy(x,++y);
cout<<"ELIJA UNA OPCIÓN (1-3): ";
cin>>opcion;


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

if (opcion==2){return false;} else{


for(i=0; i<item+1; i++){
reg[i].escribirDisco();
}
this->setTipoVale(true);
return true;

}



}///FIN DE ELSE



}

void valeEntradaSalida::mostrar(Items *reg, int cant, bool es){
  Repuestos auxR;
  int x=6, y=5, i, j;

  if (es==false){

        setlocale(LC_ALL,"spanish");
        title("LISTADO DE ITEMS SEGUN VALE DE SALIDA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        recuadro(2,2,127,27);
        recuadro(4,3,123,25);
        cout << left;
        setColor(YELLOW);
        gotoxy(x,y);
        cout << setw(10) << "VALE N°" << setw(10) << "ITEM N°" << setw(12) << "N° PARTE"<< setw(36) <<"DESCRIPCION" << setw(14) <<"CANT.SOLICIT" << setw(14) << "PRECIO $" << setw(14) << "SUB-TOTAL $";
        setColor(LIGHTCYAN);
        gotoxy(x,++y);
        cout<< "------------------------------------------------------------------------------------------------------------------------";

           for(i=0; i<cant; i++){
                j=0;
                while (auxR.leerDisco(j++)){
                   if(reg[i].getNroParte()==auxR.getNroParte()){
                        setColor(WHITE);
                        gotoxy(x,++y);
                        cout << setw(10) << reg[i].getNroVale();
                        cout << setw(10) << reg[i].getItem();
                        cout << setw(12) << reg[i].getNroParte();
                        cout << setw(36) << auxR.getDescripcion();
                        cout <<setw(14) <<  reg[i].getCant();
                        cout <<setw(14) <<  reg[i].getPU();
                        cout <<setw(14) <<  reg[i].getCant()*reg[i].getPU();

                   }

                }
            }

  }else{
         setlocale(LC_ALL,"spanish");
        title("LISTADO DE ITEMS SEGUN VALE DE ENTRADA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        recuadro(2,2,127,27);
        recuadro(4,3,123,25);
        cout << left;
        setColor(YELLOW);
        gotoxy(x,y);
        cout << setw(10) << "VALE N°" << setw(10) << "ITEM N°" << setw(12) << "N° PARTE"<< setw(36) <<"DESCRIPCION" << setw(12) <<"CANT.INCORP" << setw(12) << "PRECIO $" << setw(14) << "SUB-TOTAL $";
        setColor(LIGHTCYAN);
        gotoxy(x,++y);
        cout<< "------------------------------------------------------------------------------------------------------------------------";

           for(i=0; i<cant; i++){
                j=0;
                while (auxR.leerDisco(j++)){
                   if(reg[i].getNroParte()==auxR.getNroParte()){
                        setColor(WHITE);
                        gotoxy(x,++y);
                        cout << setw(10) << reg[i].getNroVale();
                        cout << setw(10) << reg[i].getItem();
                        cout << setw(12) << reg[i].getNroParte();
                        cout << setw(36) << auxR.getDescripcion();
                        cout <<setw(12) <<  reg[i].getCant();
                        cout <<setw(12) <<  reg[i].getPU();
                        cout <<setw(14) <<  reg[i].getCant()*reg[i].getPU();

                   }

                }
            }
}
}

bool valeEntradaSalida::escribirDisco(int pos){
bool grabo=false;
        FILE *f;
        if (pos == -1){
            f = fopen("valeEntradaSalida.dat", "ab");
            if (f == NULL){
                msj("***NO SE PUEDO ABRIR EL ARCHIVO***", rlutil::WHITE, rlutil::RED);
                return grabo;
            }
        }
        else{
            f = fopen("valeEntradaSalida.dat", "rb+");
            if (f == NULL){
                msj("***NO SE PUEDO ABRIR EL ARCHIVO***", rlutil::WHITE, rlutil::RED);
                return grabo;
            }
            fseek(f, pos * sizeof(valeEntradaSalida), 0);
        }
        grabo = fwrite(this, sizeof(valeEntradaSalida), 1, f);
        fclose(f);
        return grabo;
}

bool valeEntradaSalida::leerDisco(){
 bool leyo;

FILE *f;
f = fopen("valeEntradaSalida.dat", "rb");
if (f == NULL){
return false;
}

leyo = fread(this, sizeof(valeEntradaSalida), 1, f);
fclose(f);

return leyo;
}

bool valeEntradaSalida::leerDisco(int pos){
 bool leyo=false;

FILE *f;
f = fopen("valeEntradaSalida.dat", "rb");
if (f == NULL){
return leyo;
}

fseek(f, pos * sizeof(valeEntradaSalida), 0);
leyo = fread(this, sizeof(valeEntradaSalida), 1, f);
fclose(f);


return leyo;
}




///FUNCIONES GLOBALES DE CLASE VALE DE ENTRADA Y SALIDA

int cantidadValeEntradaSalida(){
int bytes, cant;

FILE *f=fopen("valeEntradaSalida.dat","rb");
if (f==NULL){return 0;}

fseek(f, 0, SEEK_END); ///SEEK_SET --> 0 , SEEK_CUR --> 1 , SEEK_END --> 2
bytes=ftell(f);
fclose(f);
cant=bytes/sizeof(valeEntradaSalida);

return cant;
}

void listarValeEntradaSalida(){
int x=6, y=5, i=0;
valeEntradaSalida auxV;


    setlocale(LC_ALL,"spanish");
    title("LISTADO DE VALES DE ENTRADA Y SALIDA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    recuadro(2,2,127,27);
    recuadro(4,3,123,25);
    cout << left;
    setColor(YELLOW);
    gotoxy(x,y);
    cout << setw(10) << "VALE N°" << setw(10) << "LEGAJO N°" << setw(10) << "OT N°"<< setw(36) <<"TIPO" << setw(14) <<"FECHA GESTIÓN";
    setColor(LIGHTCYAN);
    gotoxy(x,++y);
    cout<< "------------------------------------------------------------------------------------------------------------------------";


                while (auxV.leerDisco(i++)){
                        setColor(WHITE);
                        gotoxy(x,++y);
                        cout << setw(10) << auxV.getNroVale();
                        cout << setw(10) << auxV.getLegajo();
                        cout << setw(10) << auxV.getOt();
                        if (auxV.getTipoVale()==true){cout << setw(36) <<"Vale de Entrada";}else{cout << setw(36) <<"Vale de Salida";}
                        cout << setw(2);
                        cout << right;
                        cout << setfill('0');
                        cout << auxV.getFechaGestion().getDia();
                        cout << left;
                        cout << setfill(' ');
                        cout << "/";
                        cout << setw(2);
                        cout << right;
                        cout << setfill('0');
                        cout << auxV.getFechaGestion().getMes();
                        cout << left;
                        cout << setfill(' ');
                        cout << "/";
                        cout << setw(6);
                        cout << auxV.getFechaGestion().getAnio();
                        }

}

void listarNroVale(bool es){
int x=6, y=5, i=0;
valeEntradaSalida auxV;




if (es==false){

    setlocale(LC_ALL,"spanish");
    title("LISTADO POR NÚMERO DE VALE DE SALIDA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    recuadro(2,2,127,27);
    recuadro(4,3,123,25);
    cout << left;
    setColor(YELLOW);
    gotoxy(x,y);
    cout << setw(14) << "VALE N°" << setw(14) << "LEGAJO N°" << setw(14) << "OT N°"<< setw(36) <<"TIPO" << setw(14) <<"FECHA GESTIÓN";
    setColor(LIGHTCYAN);
    gotoxy(x,++y);
    cout<< "------------------------------------------------------------------------------------------------------------------------";


                while (auxV.leerDisco(i++)){
                        if (auxV.getTipoVale()==false){
                        setColor(WHITE);
                        gotoxy(x,++y);
                        cout << setw(14) << auxV.getNroVale();
                        cout << setw(14) << auxV.getLegajo();
                        cout << setw(14) << auxV.getOt();
                        cout << setw(36) <<"Vale de Salida";
                        cout << setw(2);
                        cout << right;
                        cout << setfill('0');
                        cout << auxV.getFechaGestion().getDia();
                        cout << left;
                        cout << setfill(' ');
                        cout << "/";
                        cout << setw(2);
                        cout << right;
                        cout << setfill('0');
                        cout << auxV.getFechaGestion().getMes();
                        cout << left;
                        cout << setfill(' ');
                        cout << "/";
                        cout << setw(6);
                        cout << auxV.getFechaGestion().getAnio();
                        }
                }


  }else{

    setlocale(LC_ALL,"spanish");
    title("LISTADO POR NÚMERO DE VALE DE ENTRADA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    recuadro(2,2,127,27);
    recuadro(4,3,123,25);
    cout << left;
    setColor(YELLOW);
    gotoxy(x,y);
    cout << setw(14) << "VALE N°" << setw(14) << "LEGAJO N°" << setw(14) << "OT N°"<< setw(36) <<"TIPO" << setw(14) <<"FECHA GESTIÓN";
    setColor(LIGHTCYAN);
    gotoxy(x,++y);
    cout<< "------------------------------------------------------------------------------------------------------------------------";


                while (auxV.leerDisco(i++)){
                        if (auxV.getTipoVale()==true){
                        setColor(WHITE);
                        gotoxy(x,++y);
                        cout << setw(14) << auxV.getNroVale();
                        cout << setw(14) << auxV.getLegajo();
                        cout << setw(14) << auxV.getOt();
                        cout << setw(36) <<"Vale de Entrada";
                        cout << setw(2);
                        cout << right;
                        cout << setfill('0');
                        cout << auxV.getFechaGestion().getDia();
                        cout << left;
                        cout << setfill(' ');
                        cout << "/";
                        cout << setw(2);
                        cout << right;
                        cout << setfill('0');
                        cout << auxV.getFechaGestion().getMes();
                        cout << left;
                        cout << setfill(' ');
                        cout << "/";
                        cout << setw(6);
                        cout << auxV.getFechaGestion().getAnio();
                        }
                }




}
}

valeEntradaSalida extraerDiscoVale(int pos){
valeEntradaSalida reg;

FILE *f;
f = fopen("valeEntradaSalida.dat", "rb");
if (f == NULL){
exit;
}

fseek(f, pos * sizeof(valeEntradaSalida), 0);
fread(&reg, sizeof(valeEntradaSalida), 1, f);
fclose(f);


return reg;
}

void ordenarValeOt(bool es){

int cantV, posmin, x=6, y=5, h=0, i=0, j=0, k=0;
valeEntradaSalida *v, auxV;



///GENERO UN VECTOR DE VALES CON MEMORIA DINAMICA
cantV=cantidadValeEntradaSalida();

v=new valeEntradaSalida [cantV];
if (v==NULL){exit;};

for (k=0; k<cantV; k++){
    v[k]=extraerDiscoVale(k);
    }
///FIN

///SE ORDENA EL VECTOR POR NUMERO DE OT
for(i=0; i<cantV-1; i++){
        posmin = i;
        for(j=i+1; j<cantV; j++){
            if (v[posmin].getOt()>v[j].getOt()){
                posmin = j;
            }
        }
        auxV = v[i];
        v[i] = v[posmin];
        v[posmin] = auxV;
    }
///FIN


if (es==false){

    setlocale(LC_ALL,"spanish");
    title("VALES DE SALIDA ORDENADOS POR NÚMERO DE OT", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    recuadro(2,2,127,27);
    recuadro(4,3,123,25);
    cout << left;
    setColor(YELLOW);
    gotoxy(x,y);
    cout << setw(14) << "VALE N°" << setw(14) << "LEGAJO N°" << setw(14) << "OT N°"<< setw(36) <<"TIPO" << setw(14) <<"FECHA GESTIÓN";
    setColor(LIGHTCYAN);
    gotoxy(x,++y);
    cout<< "------------------------------------------------------------------------------------------------------------------------";


                for(h=0; h<cantV; h++){

                        if (v[h].getTipoVale()==false){
                        setColor(WHITE);
                        gotoxy(x,++y);
                        cout << setw(14) << v[h].getNroVale();
                        cout << setw(14) << v[h].getLegajo();
                        cout << setw(14) << v[h].getOt();
                        if (v[h].getTipoVale()==true){cout << setw(36) <<"Vale de Entrada";}else{cout << setw(36) <<"Vale de Salida";};
                        cout << setw(2);
                        cout << right;
                        cout << setfill('0');
                        cout << v[h].getFechaGestion().getDia();
                        cout << left;
                        cout << setfill(' ');
                        cout << "/";
                        cout << setw(2);
                        cout << right;
                        cout << setfill('0');
                        cout << v[h].getFechaGestion().getMes();
                        cout << left;
                        cout << setfill(' ');
                        cout << "/";
                        cout << setw(6);
                        cout << v[h].getFechaGestion().getAnio();
                        }
                }
  }else{

    setlocale(LC_ALL,"spanish");
    title("VALES DE ENTRADA ORDENADOS POR NÚMERO DE OT", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    recuadro(2,2,127,27);
    recuadro(4,3,123,25);
    cout << left;
    setColor(YELLOW);
    gotoxy(x,y);
    cout << setw(14) << "VALE N°" << setw(14) << "LEGAJO N°" << setw(14) << "OT N°"<< setw(36) <<"TIPO" << setw(14) <<"FECHA GESTIÓN";
    setColor(LIGHTCYAN);
    gotoxy(x,++y);
    cout<< "------------------------------------------------------------------------------------------------------------------------";


                for(h=0; h<cantV; h++){

                        if (v[h].getTipoVale()==true){
                        setColor(WHITE);
                        gotoxy(x,++y);
                        cout << setw(14) << v[h].getNroVale();
                        cout << setw(14) << v[h].getLegajo();
                        cout << setw(14) << v[h].getOt();
                        if (v[h].getTipoVale()==true){cout << setw(36) <<"Vale de Entrada";}else{cout << setw(36) <<"Vale de Salida";};
                        cout << setw(2);
                        cout << right;
                        cout << setfill('0');
                        cout << v[h].getFechaGestion().getDia();
                        cout << left;
                        cout << setfill(' ');
                        cout << "/";
                        cout << setw(2);
                        cout << right;
                        cout << setfill('0');
                        cout << v[h].getFechaGestion().getMes();
                        cout << left;
                        cout << setfill(' ');
                        cout << "/";
                        cout << setw(6);
                        cout << v[h].getFechaGestion().getAnio();
                        }
                }




}


}

bool consultaNroVale(bool es){

Items auxI;
Repuestos auxR;
valeEntradaSalida auxV;
OT auxO;
Personas auxPnas;
Personal auxPnal;
bool validado;
char sigue, continuar;

do{

int nv, x=6, y=5, i=0, j=0, k, l=0, m, cont1=0, cont2=0;


system ("cls");
setlocale(LC_ALL,"spanish");
title("CONSULTAS POR NÚMERO DE VALE", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTGREEN);
cout<<"NÚMERO DE VALE: ";
setColor(WHITE);
cin>>nv;

///SE VALIDA EL NRO VALE
validado=validarVale(nv);

while (validado==false){

        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***NO EXISTE ESE NUMERO DE VALE EN NUESTROS REGISTROS***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR S/N ? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        cout<<"INGRESE NUEVAMENTE EL NÚMERO DE VALE: ";
        cin>>nv;

        validado=validarVale(nv);
        }else {return false;}
}
///FIN DE LA VALIDACIÓN

while(auxV.leerDisco(i++)){

if(auxV.getNroVale()==nv && auxV.getTipoVale()==es){

cout << left;
gotoxy(x,++y);
setColor(YELLOW);
cout << "NÚMERO DE VALE: ";
setColor(LIGHTCYAN);
cout<< auxV.getNroVale()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "LEGAJO: ";
setColor(LIGHTCYAN);
cout << setw(6) << auxV.getLegajo();

///SE BUSCA EL NOMBRE Y APELLIDO MEDIANTE EL LEGAJO
while(auxPnal.leerDisco(j++)){
        if(auxPnal.getLegajo()==auxV.getLegajo()){
            k=0;
            while(auxPnas.leerDisco(k++)){
                if(strcmp(auxPnas.getDni(),auxPnal.getDni())==0){
                    setColor(YELLOW);
                    cout << setw(20) << "APELLIDO Y NOMBRE: ";
                    setColor(LIGHTCYAN);
                    cout<< auxPnas.getApellidos() <<", " << auxPnas.getNombres();

                }
            }
        }
}
///FIN DE LA BUSQUEDA

setColor(YELLOW);
gotoxy(x,++y);
cout << "ORDEN DE TRABAJO NRO.: ";
setColor(LIGHTCYAN);
cout<< auxV.getOt()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "TIPO DE VALE: ";
setColor(LIGHTCYAN);
if (auxV.getTipoVale()==true){cout << setw(20) <<"VALE DE ENTRADA";}else{cout << setw(20) <<"VALE DE SALIDA";}
gotoxy(x,++y);
setColor(YELLOW);
cout << "FECHA SOLICITADA: ";
setColor(LIGHTCYAN);
cout << setw(2);
cout << right;
cout << setfill('0');
cout << auxV.getFechaGestion().getDia();
cout << left;
cout << setfill(' ');
cout << "/";
cout << setw(2);
cout << right;
cout << setfill('0');
cout << auxV.getFechaGestion().getMes();
cout << left;
cout << setfill(' ');
cout << "/";
cout << setw(6);
cout << auxV.getFechaGestion().getAnio();

cout << left;
setColor(LIGHTCYAN);
gotoxy(x,++y);
cout<< "------------------------------------------------------------------------------------------------------------------------";
setColor(YELLOW);
gotoxy(x+45,++y);
cout << setw(30) << "REPUESTOS SOLICITADOS";
setColor(LIGHTCYAN);
gotoxy(x,++y);
cout<< "------------------------------------------------------------------------------------------------------------------------";
setColor(YELLOW);
gotoxy(x,++y);
cout << setw(16) << "ITEM N°" << setw(16) << "N° PARTE"<< setw(16) <<"MARCA"<< setw(16) <<"MODELO"<< setw(26) <<"DESCRIPCIÓN" << setw(16) <<"CANT.SOLICIT";
setColor(LIGHTCYAN);
gotoxy(x,++y);
cout<< "------------------------------------------------------------------------------------------------------------------------";

                while (auxI.leerDisco(l++)){
                   if(auxI.getNroVale()==nv){
                        setColor(WHITE);
                        gotoxy(x,++y);
                        cout << setw(16) << auxI.getItem();
                        cout << setw(16) << auxI.getNroParte();
                        m=0;
                        while(auxR.leerDisco(m++)){
                                if(auxR.getNroParte()==auxI.getNroParte()){
                                cout << setw(16) << auxR.getMarca();
                                cout << setw(16) << auxR.getModelo();
                                cout << setw(26) << auxR.getDescripcion();
                                }
                        }
                        cout <<setw(16) <<  auxI.getCant();


                   }

                }
cont1++;
}else{cont2++;}

}

if(cont2>0 && cont1==0){
msj("*** NO CORRESPONDE EL NUMERO CON EL TIPO DE VALE ***", rlutil::WHITE, rlutil::RED);
}

setColor(LIGHTGREEN);
gotoxy(x,y+2);
cout<<"DESEA CONTINUAR REALIZANDO CONSULTAS S/N ? : ";
setColor(WHITE);
cin>>sigue;
continuar=towupper(sigue);

}while(continuar=='S');
}

bool consultaNroValeFecha(bool es){
Fecha fecha1, fecha2;
valeEntradaSalida auxV;
Personas auxPnas;
Personal auxPnal;
char sigue, continuar;
bool ok;
int x, y, i=0, j, k;

do{
x=6, y=5;

system ("cls");
setlocale(LC_ALL,"spanish");
title("CONSULTAS DE VALES POR RANGO DE FECHA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTGREEN);
cout<<"FECHA 1 (DESDE): ";
setColor(WHITE);
fecha1.cargar(x, ++y);

x=30;
y=5;
gotoxy(x,y);
setColor(LIGHTGREEN);
cout<<"FECHA 2 (HASTA): ";
setColor(WHITE);
fecha2.cargar(x, ++y);

if(fecha2 >= fecha1){ok=true;}
else{
     x=60, y=5;
     msj("***LA SEGUNDA FECHA NO PUEDE SER INFERIOR A LA PRIMERA***", rlutil::WHITE, rlutil::RED);
     setColor(WHITE);
     gotoxy(x,y);
     cout<<"DESEA CONTINUAR S/N ? : ";
     cin>>sigue;
     continuar=towupper(sigue);
     if (continuar == 'S'){
     ok=false;}
     else {return false;}
    }
}while(ok==false);

    setlocale(LC_ALL,"spanish");
    if (es==false){title("CONSULTAS DE VALES DE SALIDA POR RANGO DE FECHA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);}else{
                title("CONSULTAS DE VALES DE ENTRADA POR RANGO DE FECHA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
                };
    recuadro(2,2,127,27);
    recuadro(4,3,123,25);

    x=6, y=5;
    setColor(LIGHTGREEN);
    gotoxy(x,y);
    cout<<"FECHA DESDE: ";
    setColor(WHITE);
    fecha1.mostrar();
    setColor(LIGHTGREEN);
    gotoxy(x,++y);
    cout<<"FECHA HASTA: ";
    setColor(WHITE);
    fecha2.mostrar();

    x=6, y=8;
    cout << left;
    setColor(YELLOW);
    gotoxy(x,y);
    cout << setw(10) << "VALE NRO." << setw(10) << "LEGAJO" << setw(12) << "APELLIDO"<< setw(20) << "NOMBRE"<< setw(10) <<"OT NRO." << setw(20) <<"TIPO DE VALE" << setw(12) << "FECHA GENERADA";
    setColor(LIGHTCYAN);
    gotoxy(x,++y);
    cout<< "------------------------------------------------------------------------------------------------------------------------";


                while (auxV.leerDisco(i++)){
                   if(auxV.getTipoVale()==es){
                        if(auxV.getFechaGestion() >= fecha1 && auxV.getFechaGestion() <= fecha2){
                            setColor(WHITE);
                            gotoxy(x,++y);
                            cout << setw(10) << auxV.getNroVale();
                            cout << setw(10) << auxV.getLegajo();
                            j=0;
                            while(auxPnal.leerDisco(j++)){
                                if(auxPnal.getLegajo()==auxV.getLegajo()){
                                k=0;
                                    while(auxPnas.leerDisco(k++)){
                                        if(strcmp(auxPnas.getDni(),auxPnal.getDni())==0){
                                            cout << setw(12) << auxPnas.getApellidos();
                                            cout << setw(20) << auxPnas.getNombres();
                                        }
                                    }
                                }
                            }
                            cout << setw(10) << auxV.getOt();
                            if (es==true){cout << setw(20) <<"VALE DE ENTRADA";}else{cout << setw(20) <<"VALE DE SALIDA";};
                            cout << setw(2);
                            cout << right;
                            cout << setfill('0');
                            cout << auxV.getFechaGestion().getDia();
                            cout << left;
                            cout << setfill(' ');
                            cout << "/";
                            cout << setw(2);
                            cout << right;
                            cout << setfill('0');
                            cout << auxV.getFechaGestion().getMes();
                            cout << left;
                            cout << setfill(' ');
                            cout << "/";
                            cout << setw(4);
                            cout << auxV.getFechaGestion().getAnio();


                       }

                   }

                }


}

bool validarVale(int nv){
valeEntradaSalida auxV;
int i = 0;

    while (auxV.leerDisco(i++)){
        if(auxV.getNroVale()==nv){
            return true;
        }
    }
  return false ;
}


