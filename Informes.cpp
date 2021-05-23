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

float consumoPorMaquina(Fecha fecha1, Fecha fecha2, char *cod){
OT auxO;
valeEntradaSalida auxV;
Items auxI;
int i=0, j, k;
float total=0, devuelto;

while(auxO.leerDisco(i++)){
    if(strcmp(auxO.getCodificacionMaquina(), cod)==0){
        j=0;
        while(auxV.leerDisco(j++)){
            if(auxV.getOt()==auxO.getOt() && auxV.getTipoVale()==false && auxV.getFechaGestion() >=fecha1 && auxV.getFechaGestion() <= fecha2){
                k=0;
                while(auxI.leerDisco(k++)){
                    if(auxI.getNroVale()==auxV.getNroVale()){
                       devuelto=devoluciones(auxV.getFechaGestion().getAnio(),auxV.getFechaGestion().getMes(), auxI.getNroParte(), auxI.getCant());
                       total+=(auxI.getPU()*auxI.getCant())-devuelto;
                    }
                }
            }
        }
    }
}

return total;
}

int cantRepPrecio(Fecha fecha1, Fecha fecha2,int precio1, int precio2){
valeEntradaSalida auxV;
Items auxI;
int i=0, j, k;
int total=0, devuelto=0;

while(auxV.leerDisco(i++)){
    if(auxV.getTipoVale()== false && auxV.getFechaGestion() >= fecha1 && auxV.getFechaGestion() <= fecha2){
        j=0;
        while(auxI.leerDisco(j++)){
            if(auxI.getNroVale()==auxV.getNroVale()){
                if(auxI.getPU()>=precio1 && auxI.getPU() <= precio2){
                    devuelto=devolucionesCant(fecha1, fecha2, auxI.getNroParte());
                    total+=auxI.getCant()-devuelto;
                }

            }
        }
    }
}

return total;
}

int cantRepMaquina(Fecha fecha1, Fecha fecha2,char *cod){
OT auxO;
valeEntradaSalida auxV;
Items auxI;
int i=0, j, k;
int total=0;

while(auxO.leerDisco(i++)){
    if(strcmp(auxO.getCodificacionMaquina(), cod)==0){
        j=0;
        while(auxV.leerDisco(j++)){
            if(auxV.getOt()==auxO.getOt()&& auxV.getTipoVale()==false && auxV.getFechaGestion() >=fecha1 && auxV.getFechaGestion() <= fecha2){
                k=0;
                while(auxI.leerDisco(k++)){
                    if(auxI.getNroVale()==auxV.getNroVale()){
                        total+=auxI.getCant();
                    }
                }
            }
        }
    }
}

return total;
}

float consumoPorMaquinaClasificado(Fecha fecha1, Fecha fecha2, char *cod, char *clasificado){
OT auxO;
valeEntradaSalida auxV;
Items auxI;
int i=0, j, k;
float total=0, devuelto;

while(auxO.leerDisco(i++)){
    if(strcmp(auxO.getCodificacionMaquina(), cod)==0 && strcmp(auxO.getClasificado(), clasificado)==0){
        j=0;
        while(auxV.leerDisco(j++)){
            if(auxV.getOt()==auxO.getOt() && auxV.getTipoVale()==false && auxV.getFechaGestion() >=fecha1 && auxV.getFechaGestion() <= fecha2){
                k=0;
                while(auxI.leerDisco(k++)){
                    if(auxI.getNroVale()==auxV.getNroVale()){
                       devuelto=devoluciones(auxV.getFechaGestion().getAnio(),auxV.getFechaGestion().getMes(), auxI.getNroParte(), auxI.getCant());
                       total+=(auxI.getPU()*auxI.getCant())-devuelto;
                    }
                }
            }
        }
    }
}

return total;
}

int cantRepMaquinaClasificado(Fecha fecha1, Fecha fecha2,char *cod, char *clasificado){
OT auxO;
valeEntradaSalida auxV;
Items auxI;
int i=0, j, k;
int total=0;

while(auxO.leerDisco(i++)){
    if(strcmp(auxO.getCodificacionMaquina(), cod)==0 && strcmp(auxO.getClasificado(), clasificado)==0){
        j=0;
        while(auxV.leerDisco(j++)){
            if(auxV.getOt()==auxO.getOt()&& auxV.getTipoVale()==false && auxV.getFechaGestion() >=fecha1 && auxV.getFechaGestion() <= fecha2){
                k=0;
                while(auxI.leerDisco(k++)){
                    if(auxI.getNroVale()==auxV.getNroVale()){
                        total+=auxI.getCant();
                    }
                }
            }
        }
    }
}

return total;
}

float devoluciones(int anio, int mes, int np, int cant){
float devuelto=0;
Items auxI;
valeEntradaSalida auxV;
int i=0, j;

while(auxV.leerDisco(i++)){
    if(auxV.getTipoVale()==true && auxV.getFechaGestion().getAnio()==anio && auxV.getFechaGestion().getMes()==mes){
        j=0;
        while(auxI.leerDisco(j++)){
            if(auxI.getNroVale()==auxV.getNroVale()){
                if (auxI.getNroParte()==np){
                        if(cant==auxI.getCant()){devuelto+=auxI.getPU();}
                            if (cant < auxI.getCant()){
                                devuelto+=cant*auxI.getPU();
                            }
                                if(cant > auxI.getCant()){
                                    devuelto+=auxI.getCant()*auxI.getPU();
                                }
                }
            }
        }

    }
}
return devuelto;
}

int devolucionesCant(Fecha fecha1, Fecha fecha2, int np){
int devuelto=0;
Items auxI;
valeEntradaSalida auxV;
int i=0, j;

while(auxV.leerDisco(i++)){
    if(auxV.getTipoVale()==true && auxV.getFechaGestion() >= fecha1 && auxV.getFechaGestion() <= fecha2){
        j=0;
        while(auxI.leerDisco(j++)){
            if(auxI.getNroVale()==auxV.getNroVale()){
                if (auxI.getNroParte()==np){
                       devuelto+=auxI.getCant();
                }
            }
        }

    }
}
return devuelto;
}

bool informeAnual(){
valeEntradaSalida auxV;
Items auxI;
char sigue, continuar;

do{

int anio, x=6, y=5, i=0, j, k;
float acu, devuelto;


system ("cls");
setlocale(LC_ALL,"spanish");
title("INFORME DE CONSUMO ANUAL", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTGREEN);
cout<<"INGRESE AÑO: ";
setColor(WHITE);
cin>>anio;

///SE VALIDA EL AÑO

while (!(anio >= 1900 && anio <=2021)){

        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***NO CORRESPONDE A UN RANGO ESTABLECIDO***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR S/N ? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        cout<<"INGRESE NUEVAMENTE EL AÑO: ";
        cin>>anio;
        }else {return false;}
}
///FIN DE LA VALIDACIÓN

cout << left;
gotoxy(x,++y);
setColor(YELLOW);
cout << "CONSUMOS DEL AÑO: ";
setColor(LIGHTCYAN);
cout<< anio;
cout << left;
setColor(LIGHTCYAN);
gotoxy(x,++y);
cout<< "------------------------------------------------------------------------------------------------------------------------";
setColor(YELLOW);
gotoxy(x+45,++y);
cout << setw(30) << "CONSUMO ANUAL DISCRIMINADO POR MES";
setColor(LIGHTCYAN);
gotoxy(x,++y);
cout<< "------------------------------------------------------------------------------------------------------------------------";
setColor(YELLOW);
gotoxy(x,++y);
cout << setw(16) << "MES" << setw(16) << "CONSUMO";
setColor(LIGHTCYAN);
gotoxy(x,++y);
cout<< "------------------------------------------------------------------------------------------------------------------------";

char mes[12][11];
  strcpy(mes[0],"ENERO");
  strcpy(mes[1],"FEBRERO");
  strcpy(mes[2],"MARZO");
  strcpy(mes[3],"ABRIL");
  strcpy(mes[4],"MAYO");
  strcpy(mes[5],"JUNIO");
  strcpy(mes[6],"JULIO");
  strcpy(mes[7],"AGOSTO");
  strcpy(mes[8],"SEPTIEMBRE");
  strcpy(mes[9],"OCTUBRE");
  strcpy(mes[10],"NOVIEMBRE");
  strcpy(mes[11],"DICIEMBRE");

for(i=0; i<12; i++){

    setColor(WHITE);
    gotoxy(x,++y);
    cout << setw(16) << mes[i];
    j=0;
    acu=0;
    while(auxV.leerDisco(j++)){
        devuelto=0;
        if(auxV.getFechaGestion().getMes()==i+1 && auxV.getTipoVale()== false && auxV.getFechaGestion().getAnio()== anio){
           k=0;
            while(auxI.leerDisco(k++)){
              if(auxI.getNroVale()==auxV.getNroVale()){
                    devuelto=devoluciones(anio,i+1, auxI.getNroParte(), auxI.getCant());
                    acu+=(auxI.getPU()*auxI.getCant())-devuelto;
                }
            }
        }
    }
    cout << "$ " <<acu;

}

setColor(LIGHTGREEN);
gotoxy(x,y+2);
cout<<"DESEA CONTINUAR REALIZANDO CONSULTAS S/N ? : ";
setColor(WHITE);
cin>>sigue;
continuar=towupper(sigue);

}while(continuar=='S');


}

bool informePorClasificado(){

Fecha fecha1, fecha2;
Maquinas auxM;
char sigue, continuar;
bool ok;
int x, y, i, cant, opcion;
float total;
char vecClasificado[4][20]= {"Preventivo","Correctivo","Predictivo","Otros"};
char vec[20];

do{///SE REPITE LA CONSULTA SI ES DESEADO

do{///SE COMIENZA LA CONSULTA SI HAY ERROR DE FECHAS
x=6, y=5;

system ("cls");
setlocale(LC_ALL,"spanish");
title("INFORME DE CONSUMOS SEGÚN CLASIFICACIÓN Y RANGO DE FECHAS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTGREEN);
cout<<"TIPOS DE CLASIFICACIÓN PARA CONSULTAR: ";
gotoxy(x,++y);
setColor(YELLOW);
cout << setw(20) << "1.PREVENTIVOS" << setw(20) << "2.CORRECTIVOS" << setw(20) << "3.PREDICTIVOS" << setw(20) << "4. OTROS";
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

strcpy(vec, vecClasificado[opcion-1]);

gotoxy(x,++y);
setColor(LIGHTGREEN);
cout<<"FECHA 1 (DESDE): ";
setColor(WHITE);
fecha1.cargar(x, ++y);

x=30;

gotoxy(x,--y);
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
    title("INFORME DE CONSUMOS SEGÚN CLASIFICACIÓN Y RANGO DE FECHAS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
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

    x=6, y=6;

    cout << left;
    setColor(LIGHTCYAN);
    gotoxy(x,++y);
    cout<< "------------------------------------------------------------------------------------------------------------------------";
    setColor(YELLOW);
    gotoxy(x+30,++y);
    cout << "CONSUMOS OBTENIDOS A PARTIR DE: ";
    setColor(WHITE);
    cout<< setw(30) << vec;
    setColor(LIGHTCYAN);
    gotoxy(x,++y);
    cout<< "------------------------------------------------------------------------------------------------------------------------";
    setColor(YELLOW);
    gotoxy(x,++y);
    cout << setw(10) << "CÓDIGO" << setw(20) << "TIPO" << setw(30) << "DESCRIPCIÓN" <<setw(15) << "TOTAL $"<< setw(15) << "CANTIDAD";
    setColor(LIGHTCYAN);
    gotoxy(x,++y);
    cout<< "------------------------------------------------------------------------------------------------------------------------";
    i=0;
    while(auxM.leerDisco(i++)){
            cant=0;
            gotoxy(x,++y);
            cout << setw(10) <<auxM.getCodificacionMaquina();
            cout << setw(20) <<auxM.getTipo();
            cout << setw(30) <<auxM.getDescripcion();
            total=consumoPorMaquinaClasificado(fecha1, fecha2, auxM.getCodificacionMaquina(), vec);
            cout <<"$ "<< setw(15) <<total;
            cant=cantRepMaquinaClasificado(fecha1, fecha2, auxM.getCodificacionMaquina(), vec);
            cout << setw(15) <<cant;

    }
setColor(LIGHTGREEN);
gotoxy(x,y+2);
cout<<"DESEA CONTINUAR REALIZANDO CONSULTAS S/N ? : ";
setColor(WHITE);
cin>>sigue;
continuar=towupper(sigue);

}while(continuar=='S');

}

bool informePorMaquinas(){

Fecha fecha1, fecha2;
Maquinas auxM;
char sigue, continuar;
bool ok;
int x, y, i, cant;
float total;

do{///SE REPITE LA CONSULTA SI ES DESEADO

do{///SE COMIENZA LA CONSULTA SI HAY ERROR DE FECHAS
x=6, y=5;

system ("cls");
setlocale(LC_ALL,"spanish");
title("INFORME DE CONSUMOS POR MAQUINAS POR RANGO DE FECHA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
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
    title("INFORME DE CONSUMOS POR MAQUINAS POR RANGO DE FECHA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
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

    x=6, y=6;

    cout << left;
    setColor(LIGHTCYAN);
    gotoxy(x,++y);
    cout<< "------------------------------------------------------------------------------------------------------------------------";
    setColor(YELLOW);
    gotoxy(x+30,++y);
    cout << setw(30) << "CONSUMO DISCRIMINADO POR MÁQUINA SEGÚN FECHAS INDICADAS";
    setColor(LIGHTCYAN);
    gotoxy(x,++y);
    cout<< "------------------------------------------------------------------------------------------------------------------------";
    setColor(YELLOW);
    gotoxy(x,++y);
    cout << setw(10) << "CÓDIGO" << setw(20) << "TIPO" << setw(30) << "DESCRIPCIÓN" <<setw(15) << "TOTAL $"<< setw(15) << "CANTIDAD";
    setColor(LIGHTCYAN);
    gotoxy(x,++y);
    cout<< "------------------------------------------------------------------------------------------------------------------------";
    i=0;
    while(auxM.leerDisco(i++)){
            cant=0;
            gotoxy(x,++y);
            cout << setw(10) <<auxM.getCodificacionMaquina();
            cout << setw(20) <<auxM.getTipo();
            cout << setw(30) <<auxM.getDescripcion();
            total=consumoPorMaquina(fecha1, fecha2, auxM.getCodificacionMaquina());
            cout <<"$ "<< setw(15) <<total;
            cant=cantRepMaquina(fecha1, fecha2, auxM.getCodificacionMaquina());
            cout << setw(15) <<cant;

    }
setColor(LIGHTGREEN);
gotoxy(x,y+2);
cout<<"DESEA CONTINUAR REALIZANDO CONSULTAS S/N ? : ";
setColor(WHITE);
cin>>sigue;
continuar=towupper(sigue);

}while(continuar=='S');

}

bool informeRepuestosPrecio(){

Fecha fecha1, fecha2;
char sigue, continuar;
bool ok;
int x, y, cant;


do{///SE REPITE LA CONSULTA SI ES DESEADO

do{///SE COMIENZA LA CONSULTA SI HAY ERROR DE FECHAS
x=6, y=5;

system ("cls");
setlocale(LC_ALL,"spanish");
title("INFORME DE CONSUMOS POR RANGO DE PRECIOS Y RANGO DE FECHA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
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
    title("INFORME DE CONSUMOS POR RANGO DE PRECIOS Y RANGO DE FECHA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
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

    x=6, y=6;

    cout << left;
    setColor(LIGHTCYAN);
    gotoxy(x,++y);
    cout<< "------------------------------------------------------------------------------------------------------------------------";
    setColor(YELLOW);
    gotoxy(x+30,++y);
    cout << setw(30) << "CONSUMO DISCRIMINADO POR RANGO DE PRECIOS SEGÚN FECHAS INDICADAS";
    setColor(LIGHTCYAN);
    gotoxy(x,++y);
    cout<< "------------------------------------------------------------------------------------------------------------------------";
    setColor(YELLOW);
    gotoxy(x,++y);
    cout << setw(30) << "RANGO $" << setw(15) << "CANTIDAD";
    setColor(LIGHTCYAN);
    gotoxy(x,++y);
    cout<< "------------------------------------------------------------------------------------------------------------------------";

    cant=cantRepPrecio(fecha1, fecha2, 1, 1000);
    gotoxy(x,++y);
    cout << setw(30) << "$1 - $1.000";
    if(cant<0){cout << setw(30) << "0";}else{cout << setw(30) << cant;}

    cant=cantRepPrecio(fecha1, fecha2, 1001, 10000);
    gotoxy(x,++y);
    cout << setw(30) << "$1.001 - $10.000";
    if(cant<0){cout << setw(30) << "0";}else{cout << setw(30) << cant;}

    cant=cantRepPrecio(fecha1, fecha2, 10001, 100000);
    gotoxy(x,++y);
    cout << setw(30) << "$10.001 - $100.000";
    if(cant<0){cout << setw(30) << "0";}else{cout << setw(30) << cant;}

    cant=cantRepPrecio(fecha1, fecha2, 100001, 1000000);
    gotoxy(x,++y);
    cout << setw(30) << "$100.001 - $1.000.000";
    if(cant<0){cout << setw(30) << "0";}else{cout << setw(30) << cant;}

    cant=cantRepPrecio(fecha1, fecha2, 1000001, 10000000);
    gotoxy(x,++y);
    cout << setw(30) << "$1.000.001 - $10.000.000";
    if(cant<0){cout << setw(30) << "0";}else{cout << setw(30) << cant;}

setColor(LIGHTGREEN);
gotoxy(x,y+2);
cout<<"DESEA CONTINUAR REALIZANDO CONSULTAS S/N ? : ";
setColor(WHITE);
cin>>sigue;
continuar=towupper(sigue);

}while(continuar=='S');

}
