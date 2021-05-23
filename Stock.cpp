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

///FUNCIONES GLOBALES DE CLASE STOCK
bool mostrarDetallesStock(){
Stock aux;
Repuestos reg;

int x=6, y=5, i=0;
int np, npvalidado;
char sigue, continuar;

setlocale(LC_ALL,"spanish");
title("DATOS DETALLADOS DEL REPUESTO EN EL STOCK", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
cout<<"NÚMERO DE PARTE: ";
cin>>np;

npvalidado=validarNroParteStock(np);

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

while (reg.leerDisco(i++)==true){
        int j=0;
            while(aux.leerDisco(j++)){
                if(reg.getNroParte()==aux.getNroParte() && aux.getNroParte()==np){

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
gotoxy(x,++y);
setColor(YELLOW);
cout << "STOCK MÍNIMO: ";
setColor(LIGHTCYAN);
cout<<aux.getStockMinimo()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "STOCK MÁXIMO: ";
setColor(LIGHTCYAN);
cout<<aux.getStockMaximo()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "STOCK ACTUAL: ";
setColor(LIGHTCYAN);
cout<<aux.getStockActual()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "UBICADO: ";
setColor(LIGHTCYAN);
cout<<aux.getUbicado()<<endl;
}
}
}
}

void ordenarStock(){
  Stock auxS, *s;
  Repuestos auxR, *r;
  int x=6, y=5, i=0, j=0, cantS, opcion;

setlocale(LC_ALL,"spanish");
title("ELIJA LA OPCION DE ORDENAMIENTO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);

cantS=cantidadStock();

s=new Stock [cantS];
if (s==NULL){exit;};

for (i=0; i<cantS; i++){
    s[i]=extraerDisco(i);
    }

cout << left;
setColor(YELLOW);
gotoxy(x,y);
cout << setw(25) << "1) POR NRO. PARTE" << setw(25) << "2) POR STOCK MÍNIMO" << setw(25) << "3) POR STOCK MÁXIMO";
setColor(LIGHTCYAN);
gotoxy(x,++y);
cout<< "------------------------------------------------------------------------------------------------------------------------";
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

switch (opcion){
case 1: ordenarStockNroParte(s, cantS);
        system("pause>null");
    break;
case 2: ordenarStockMinimo(s, cantS);
        system("pause>null");
    break;
case 3: ordenarStockMaximo(s, cantS);
        system("pause>null");
    break;
default:
    break;

}
delete s;

}

void ordenarStockNroParte(Stock *s, int cantS){
int x=6, y=5, i, j, posmin;
Stock aux;
Repuestos auxR;

for(i=0; i<cantS-1; i++){
        posmin = i;
        for(j=i+1; j<cantS; j++){
            if (s[posmin].getNroParte()>s[j].getNroParte()){
                posmin = j;
            }
        }
        aux = s[i];
        s[i] = s[posmin];
        s[posmin] = aux;
    }





setlocale(LC_ALL,"spanish");
title("LISTADO DEL STOCK ORDENADOS POR NRO PARTE", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);
cout << left;
setColor(YELLOW);
gotoxy(x,y);
cout << setw(10) << "N° PARTE" << setw(12) << "MARCA" << setw(12) << "MODELO"<< setw(36) <<"DESCRIPCION" << setw(12) <<"S.MIN" << setw(12) << "S.MÁX" << setw(12) << "S.ACTUAL" << setw(12) << "UBICADO";
setColor(LIGHTCYAN);
gotoxy(x,++y);
cout<< "------------------------------------------------------------------------------------------------------------------------";


for(i=0; i<cantS; i++){
    j=0;
    while(auxR.leerDisco(j++)){
        if(s[i].getNroParte() == auxR.getNroParte()){
            setColor(WHITE);
            gotoxy(x,++y);
            cout << setw(10) << auxR.getNroParte();
            cout << setw(12) << auxR.getMarca();
            cout << setw(12) << auxR.getModelo();
            cout << setw(36) << auxR.getDescripcion();
            cout <<setw(12) <<s[i].getStockMinimo();
            cout <<setw(12) <<s[i].getStockMaximo();
            cout <<setw(12) <<s[i].getStockActual();
            cout <<setw (12) <<s[i].getUbicado();

        }
    }
}

}

void ordenarStockMinimo(Stock *s, int cantS){
int x=6, y=5, i, j, posmin;
Stock aux;
Repuestos auxR;

for(i=0; i<cantS-1; i++){
        posmin = i;
        for(j=i+1; j<cantS; j++){
            if (s[posmin].getStockMinimo()>s[j].getStockMinimo()){
                posmin = j;
            }
        }
        aux = s[i];
        s[i] = s[posmin];
        s[posmin] = aux;
    }





setlocale(LC_ALL,"spanish");
title("LISTADO DEL STOCK ORDENADOS POR STOCK MÍNIMO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);
cout << left;
setColor(YELLOW);
gotoxy(x,y);
cout << setw(10) << "N° PARTE" << setw(12) << "MARCA" << setw(12) << "MODELO"<< setw(36) <<"DESCRIPCION" << setw(12) <<"S.MIN" << setw(12) << "S.MÁX" << setw(12) << "S.ACTUAL" << setw(12) << "UBICADO";
setColor(LIGHTCYAN);
gotoxy(x,++y);
cout<< "------------------------------------------------------------------------------------------------------------------------";


for(i=0; i<cantS; i++){
    j=0;
    while(auxR.leerDisco(j++)){
        if(s[i].getNroParte() == auxR.getNroParte()){
            setColor(WHITE);
            gotoxy(x,++y);
            cout << setw(10) << auxR.getNroParte();
            cout << setw(12) << auxR.getMarca();
            cout << setw(12) << auxR.getModelo();
            cout << setw(36) << auxR.getDescripcion();
            cout <<setw(12) <<s[i].getStockMinimo();
            cout <<setw(12) <<s[i].getStockMaximo();
            cout <<setw(12) <<s[i].getStockActual();
            cout <<setw (12) <<s[i].getUbicado();

        }
    }
}

}

void ordenarStockMaximo(Stock *s, int cantS){
int x=6, y=5, i, j, posmax;
Stock aux;
Repuestos auxR;

for(i=0; i<cantS-1; i++){
        posmax = i;
        for(j=i+1; j<cantS; j++){
            if (s[posmax].getStockMaximo() < s[j].getStockMaximo()){
                posmax = j;
            }
        }
        aux = s[i];
        s[i] = s[posmax];
        s[posmax] = aux;
    }





setlocale(LC_ALL,"spanish");
title("LISTADO DEL STOCK ORDENADOS POR STOCK MÁXIMO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);
cout << left;
setColor(YELLOW);
gotoxy(x,y);
cout << setw(10) << "N° PARTE" << setw(12) << "MARCA" << setw(12) << "MODELO"<< setw(36) <<"DESCRIPCION" << setw(12) <<"S.MIN" << setw(12) << "S.MÁX" << setw(12) << "S.ACTUAL" << setw(12) << "UBICADO";
setColor(LIGHTCYAN);
gotoxy(x,++y);
cout<< "------------------------------------------------------------------------------------------------------------------------";


for(i=0; i<cantS; i++){
    j=0;
    while(auxR.leerDisco(j++)){
        if(s[i].getNroParte() == auxR.getNroParte()){
            setColor(WHITE);
            gotoxy(x,++y);
            cout << setw(10) << auxR.getNroParte();
            cout << setw(12) << auxR.getMarca();
            cout << setw(12) << auxR.getModelo();
            cout << setw(36) << auxR.getDescripcion();
            cout <<setw(12) <<s[i].getStockMinimo();
            cout <<setw(12) <<s[i].getStockMaximo();
            cout <<setw(12) <<s[i].getStockActual();
            cout <<setw (12) <<s[i].getUbicado();

        }
    }
}
}

void listarStockExcedido(){
int x=6, y=5, i, j, cantS;
Stock  *s;
Repuestos auxR;

cantS=cantidadStock();

s=new Stock [cantS];
if (s==NULL){exit;};

for (i=0; i<cantS; i++){
    s[i]=extraerDisco(i);
    }


setlocale(LC_ALL,"spanish");
title("LISTADO DEL STOCK EXCEDIDO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);
cout << left;
setColor(YELLOW);
gotoxy(x,y);
cout << setw(10) << "N° PARTE" << setw(12) << "MARCA" << setw(12) << "MODELO"<< setw(36) <<"DESCRIPCION" << setw(12) <<"S.MIN" << setw(12) << "S.MÁX" << setw(12) << "S.ACTUAL" << setw(12) << "UBICADO";
setColor(LIGHTCYAN);
gotoxy(x,++y);
cout<< "------------------------------------------------------------------------------------------------------------------------";


for(i=0; i<cantS; i++){
    if(s[i].getStockActual() > s[i].getStockMaximo()){
            j=0;
            while(auxR.leerDisco(j++)){
                if(s[i].getNroParte() == auxR.getNroParte()){
                    setColor(WHITE);
                    gotoxy(x,++y);
                    cout << setw(10) << auxR.getNroParte();
                    cout << setw(12) << auxR.getMarca();
                    cout << setw(12) << auxR.getModelo();
                    cout << setw(36) << auxR.getDescripcion();
                    cout <<setw(12) <<s[i].getStockMinimo();
                    cout <<setw(12) <<s[i].getStockMaximo();
                    cout <<setw(12) <<s[i].getStockActual();
                    cout <<setw (12) <<s[i].getUbicado();

                }
            }
    }
}
delete s;
}

int validarNroParteStock(int np){
Stock auxS;
Repuestos auxR;
int i = 0;

if (auxR.leerDisco()==false){return -1;}else{
    while (auxR.leerDisco(i++)){
        if(auxR.getNroParte() == np){
            int j=0;
            while (auxS.leerDisco(j++)){
                    if(auxS.getNroParte() == np){return 1;}

            }
            return 2;
        }
    }
  return 0;
}

}

bool validarCantActualStock(int np, int cant){
Stock auxS;
int i = 0;

if (auxS.leerDisco()==false){return false;}else{
   while (auxS.leerDisco(i++)){
        if(auxS.getNroParte() == np){
                if(auxS.getStockActual()>=cant){
                    return true;
                }
        }
    }
}
  return false ;
}

int cantidadStock(){
int bytes, cant;

FILE *f=fopen("Stock.dat","rb");
if (f==NULL){
setColor(LIGHTRED);
return 0;
    }
fseek(f, 0, SEEK_END); ///SEEK_SET --> 0 , SEEK_CUR --> 1 , SEEK_END --> 2
bytes=ftell(f);
fclose(f);
cant=bytes/sizeof(Stock);

return cant;
}

Stock extraerDisco(int pos){
Stock reg;

FILE *f;
f = fopen("Stock.dat", "rb");
if (f == NULL){
exit;
}

fseek(f, pos * sizeof(Stock), 0);
fread(&reg, sizeof(Stock), 1, f);
fclose(f);


return reg;
}

void actualizarStock(valeEntradaSalida nuevo, bool es){
Stock reg, auxS;
Items auxI;
int i=0, j, ns=0;

if (es==false){
while(auxI.leerDisco(i++)){
    if(auxI.getNroVale()== nuevo.getNroVale()){
        j=0;
        while(auxS.leerDisco(j++)){
            if(auxS.getNroParte() == auxI.getNroParte()){
                ///reg=extraerDisco(j);///
                ns=auxS.getStockActual() - auxI.getCant();
                auxS.setStockActual(ns);
                auxS.escribirDisco(j-1);
            }
        }

    }

}
}else{
while(auxI.leerDisco(i++)){
    if(auxI.getNroVale()== nuevo.getNroVale()){
        j=0;
        while(auxS.leerDisco(j++)){
            if(auxS.getNroParte() == auxI.getNroParte()){
                reg=extraerDisco(j);
                ns+=reg.getStockActual() + auxI.getCant();
                reg.setStockActual(ns);
                reg.escribirDisco(j);
            }
        }
    }

}

}

}


///METODOS DE LA CLASE STOCK

int Stock::getNroParte(){
    return NroParte;
}

int Stock::getStockActual(){
    return StockActual;
}

int Stock::getStockMinimo(){
    return StockMinimo;
}

int Stock::getStockMaximo(){
    return StockMaximo;
}

char * Stock::getUbicado(){
    return Ubicado;
}

void Stock::setNroParte(int np){
    NroParte=np;
}

void Stock::setStockActual(int stock){
    StockActual=stock;
}

void Stock::setStockMinimo(int smin){
    StockMinimo=smin;
}

void Stock::setStockMaximo(int smax){
    StockMaximo=smax;
}

void Stock::setUbicado(char *ubicado){
    strcpy(Ubicado, ubicado);
}

bool Stock::cargar(){
    int np, npvalidado, opcion, smin, smax, sactual;
    char continuar, sigue, ubicado[20];


do{
int x=6, y=5;

system ("cls");
setlocale(LC_ALL,"spanish");
title("NUEVO ITEM AL STOCK", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);

gotoxy(x,y);
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
case 1:
        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***YA EXISTE ESE ITEM EN EL STOCK***";
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
case 2:
    break;
}

}while(!(npvalidado==2));

///FIN DE LA VALIDACION

this->setNroParte(np);

gotoxy(x,++y);
setColor(WHITE);
cout<<"INGRESE UN VALOR ENTERO COMO STOCK MINIMO: ";
cin>>smin;

while (smin <= 0){
setColor(LIGHTRED);
gotoxy(x,++y);
cout<<"***EL VALOR INGRESADO ES INCORRECTO***";
setColor(WHITE);
gotoxy(x,++y);
cout<<"INGRESE UN VALOR ENTERO COMO STOCK MÍNIMO: ";
cin>>smin;

}


this->setStockMinimo(smin);

gotoxy(x,++y);
setColor(WHITE);
cout<<"INGRESE EL VALOR ENTERO COMO STOCK MAXIMO: ";
cin>>smax;

while (this->getStockMinimo()>smax){
setColor(LIGHTRED);
gotoxy(x,++y);
cout<<"***EL VALOR INGRESADO TIENE QUE SER MAYOR O IGUAL AL STOCK MÍNIMO***";
setColor(WHITE);
gotoxy(x,++y);
cout<<"INGRESE EL VALOR ENTERO COMO STOCK MAXIMO: ";
cin>>smax;

}

this->setStockMaximo(smax);

gotoxy(x,++y);
cout<<"INGRESE EL VALOR ENTERO COMO STOCK ACTUAL: ";
cin>>sactual;

while (sactual < 0){
setColor(LIGHTRED);
gotoxy(x,++y);
cout<<"***EL VALOR INGRESADO ES INCORRECTO***";
setColor(WHITE);
gotoxy(x,++y);
cout<<"INGRESE UN VALOR ENTERO COMO STOCK ACTUAL: ";
cin>>sactual;

}

this->setStockActual(sactual);


gotoxy(x,++y);
cout<<"INGRESE LA UBICACION: ";
cin.ignore();
cin.getline(ubicado, 20);

this->setUbicado(ubicado);



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

if (opcion==3){return true;}
else{return false;}

}

void Stock::mostrar(){
Repuestos aux;
int x=6, y=5, i=0;

        setlocale(LC_ALL,"spanish");
        title("INFORMACION DEL ITEM A INCORPORAR AL STOCK", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        recuadro(2,2,127,27);
        recuadro(4,3,123,25);
        cout << left;
        setColor(YELLOW);
        gotoxy(x,y);
        cout << setw(10) << "N° PARTE" << setw(12) << "MARCA" << setw(12) << "MODELO"<< setw(36) <<"DESCRIPCION" << setw(12) <<"S.MIN" << setw(12) << "S.MÁX" << setw(12) << "S.ACTUAL" << setw(12) << "UBICADO";
        setColor(LIGHTCYAN);
        gotoxy(x,++y);
        cout<< "------------------------------------------------------------------------------------------------------------------------";

            while(aux.leerDisco(i++)){
                    if(aux.getNroParte()==this->getNroParte()){
            setColor(WHITE);
            gotoxy(x,++y);
            cout << setw(10) << aux.getNroParte();
            cout << setw(12) << aux.getMarca();
            cout << setw(12) << aux.getModelo();
            cout << setw(36) << aux.getDescripcion();
            cout <<setw(12) <<this->getStockMinimo();
            cout <<setw(12) <<this->getStockMaximo();
            cout <<setw(12) <<this->getStockActual();
            cout <<setw (12) <<this->getUbicado();
                    }
            }
}

void Stock::mostrar(int np, int x, int y){
  Repuestos auxR;
  int i=0, j;


        cout << left;
        setColor(YELLOW);
        gotoxy(x,++y);
        cout << setw(10) << "N° PARTE" << setw(12) << "MARCA" << setw(12) << "MODELO"<< setw(36) <<"DESCRIPCION" << setw(12) <<"S.MIN" << setw(12) << "S.MÁX" << setw(12) << "S.ACTUAL" << setw(12) << "UBICADO";
        setColor(LIGHTCYAN);
        gotoxy(x,++y);
        cout<< "------------------------------------------------------------------------------------------------------------------------";

            while(auxR.leerDisco(i++)){
                    if(auxR.getNroParte()==np){
                        j=0;
                            while(this->leerDisco(j++)){
                                    if(this->getNroParte()==np){
                                        setColor(WHITE);
                                        gotoxy(x,++y);
                                        cout << setw(10) << auxR.getNroParte();
                                        cout << setw(12) << auxR.getMarca();
                                        cout << setw(12) << auxR.getModelo();
                                        cout << setw(36) << auxR.getDescripcion();
                                        cout <<setw(12) <<this->getStockMinimo();
                                        cout <<setw(12) <<this->getStockMaximo();
                                        cout <<setw(12) <<this->getStockActual();
                                        cout <<setw (12) <<getUbicado();
                                    }
                            }
                    }
            }
}

bool Stock::escribirDisco(int pos){
 bool grabo=false;
        FILE *f;
        if (pos == -1){
            f = fopen("Stock.dat", "ab");
            if (f == NULL){
                msj("***NO SE PUEDO ABRIR EL ARCHIVO***", rlutil::WHITE, rlutil::RED);
                return grabo;
            }
        }
        else{
            f = fopen("Stock.dat", "rb+");
            if (f == NULL){
                msj("***NO SE PUEDO ABRIR EL ARCHIVO***", rlutil::WHITE, rlutil::RED);
                return grabo;
            }
            fseek(f, pos * sizeof(Stock), 0);
        }
        grabo = fwrite(this, sizeof(Stock), 1, f);
        fclose(f);
        return grabo;
}

bool Stock::leerDisco(){
 bool leyo;

FILE *f;
f = fopen("Stock.dat", "rb");
if (f == NULL){
return false;
}

leyo = fread(this, sizeof(Stock), 1, f);
fclose(f);

return leyo;

}

bool Stock::leerDisco(int pos){
 bool leyo=false;

FILE *f;
f = fopen("Stock.dat", "rb");
if (f == NULL){
return leyo;
}

fseek(f, pos * sizeof(Stock), 0);
leyo = fread(this, sizeof(Stock), 1, f);
fclose(f);


return leyo;
}

