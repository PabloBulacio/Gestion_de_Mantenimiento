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


bool copiarPersonas(bool nuevo){

Personas auxP;
char si, ok, sigue, continuar;
int x=6, y=5;
const char *rutaDatos= "datos/Personas.dat";
const char *rutaBackups= "backups/Personas.bkp";


if (nuevo==true){

system ("cls");
setlocale(LC_ALL,"spanish");
title("COPIAS DE SEGURIDAD DEL ARCHIVO PERSONA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTGREEN);
cout<<"CONFIRMA ALMACENAR Y COPIAR EL ARCHIVO DE PERSONAS (S/N)?: ";
setColor(WHITE);
cin>>si;
ok=towupper(si);

if (ok=='N'){return false;}

while(!(ok == 'S')){

        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***ERROR EN LA CONFIRMACIÓN***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        setColor(LIGHTGREEN);
        cout<<"DESEA ALMACENAR Y COPIAR LOS ARCHIVOS DE PERSONAS (S/N)?: ";
        setColor(WHITE);
        cin>>si;

        ok=towupper(si);
        if (ok=='N'){return false;}

        }else {return false;}
}

FILE *origen=fopen("Personas.dat", "rb");
if (origen==NULL){return false;}


FILE *destinoDatos=fopen(rutaDatos, "wb");
if (destinoDatos==NULL){
fclose(origen);
return false;}


FILE *destinoBackups=fopen(rutaBackups, "wb");
if (destinoBackups==NULL){
fclose(origen);
fclose(destinoDatos);
return false;}


while(fread(&auxP, sizeof(Personas), 1, origen)){
    fwrite(&auxP, sizeof(Personas), 1, destinoDatos);
    fwrite(&auxP, sizeof(Personas), 1, destinoBackups);
}

fclose(origen);
fclose(destinoDatos);
fclose(destinoBackups);

msj("**LA COPIA SE HA REALIZADO CORRECTAMENTE**", rlutil::WHITE, rlutil::GREEN);

return true;


}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA MANUAL
else{

FILE *origen=fopen("Personas.dat", "rb");
if (origen==NULL){return false;}


FILE *destinoDatos=fopen(rutaDatos, "wb");
if (destinoDatos==NULL){
fclose(origen);
return false;}


FILE *destinoBackups=fopen(rutaBackups, "wb");
if (destinoBackups==NULL){
fclose(origen);
fclose(destinoDatos);
return false;}


while(fread(&auxP, sizeof(Personas), 1, origen)){
    fwrite(&auxP, sizeof(Personas), 1, destinoDatos);
    fwrite(&auxP, sizeof(Personas), 1, destinoBackups);
}

fclose(origen);
fclose(destinoDatos);
fclose(destinoBackups);

return true;

}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA AUTOMÁTICA


}

bool copiarPersonal(bool nuevo){
Personal auxP;
char si, ok, sigue, continuar;
int x=6, y=5;
const char *rutaDatos= "datos/Personal.dat";
const char *rutaBackups= "backups/Personal.bkp";


if (nuevo==true){

system ("cls");
setlocale(LC_ALL,"spanish");
title("COPIAS DE SEGURIDAD DEL ARCHIVO PERSONAL", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTGREEN);
cout<<"CONFIRMA ALMACENAR Y COPIAR EL ARCHIVO DE PERSONAL (S/N)?: ";
setColor(WHITE);
cin>>si;
ok=towupper(si);

if (ok=='N'){return false;}

while(!(ok == 'S')){

        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***ERROR EN LA CONFIRMACIÓN***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        setColor(LIGHTGREEN);
        cout<<"DESEA ALMACENAR Y COPIAR LOS ARCHIVOS DE PERSONAL (S/N)?: ";
        setColor(WHITE);
        cin>>si;

        ok=towupper(si);
        if (ok=='N'){return false;}

        }else {return false;}
}

FILE *origen=fopen("Personal.dat", "rb");
if (origen==NULL){return false;}


FILE *destinoDatos=fopen(rutaDatos, "wb");
if (destinoDatos==NULL){
fclose(origen);
return false;}


FILE *destinoBackups=fopen(rutaBackups, "wb");
if (destinoBackups==NULL){
fclose(origen);
fclose(destinoDatos);
return false;}


while(fread(&auxP, sizeof(Personal), 1, origen)){
    fwrite(&auxP, sizeof(Personal), 1, destinoDatos);
    fwrite(&auxP, sizeof(Personal), 1, destinoBackups);
}

fclose(origen);
fclose(destinoDatos);
fclose(destinoBackups);

msj("**LA COPIA SE HA REALIZADO CORRECTAMENTE**", rlutil::WHITE, rlutil::GREEN);

return true;


}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA MANUAL
else{

FILE *origen=fopen("Personal.dat", "rb");
if (origen==NULL){return false;}


FILE *destinoDatos=fopen(rutaDatos, "wb");
if (destinoDatos==NULL){
fclose(origen);
return false;}


FILE *destinoBackups=fopen(rutaBackups, "wb");
if (destinoBackups==NULL){
fclose(origen);
fclose(destinoDatos);
return false;}


while(fread(&auxP, sizeof(Personal), 1, origen)){
    fwrite(&auxP, sizeof(Personal), 1, destinoDatos);
    fwrite(&auxP, sizeof(Personal), 1, destinoBackups);
}

fclose(origen);
fclose(destinoDatos);
fclose(destinoBackups);

return true;

}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA AUTOMÁTICA

}

bool copiarMaquinas(bool nuevo){
Maquinas reg;
char si, ok, sigue, continuar;
int x=6, y=5;
const char *rutaDatos= "datos/Maquinas.dat";
const char *rutaBackups= "backups/Maquinas.bkp";


if (nuevo==true){

system ("cls");
setlocale(LC_ALL,"spanish");
title("COPIAS DE SEGURIDAD DEL ARCHIVO MAQUINAS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTGREEN);
cout<<"CONFIRMA ALMACENAR Y COPIAR EL ARCHIVO DE MAQUINAS (S/N)?: ";
setColor(WHITE);
cin>>si;
ok=towupper(si);

if (ok=='N'){return false;}

while(!(ok == 'S')){

        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***ERROR EN LA CONFIRMACIÓN***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        setColor(LIGHTGREEN);
        cout<<"DESEA ALMACENAR Y COPIAR LOS ARCHIVOS DE MAQUINAS (S/N)?: ";
        setColor(WHITE);
        cin>>si;

        ok=towupper(si);
        if (ok=='N'){return false;}

        }else {return false;}
}

FILE *origen=fopen("Maquinas.dat", "rb");
if (origen==NULL){return false;}


FILE *destinoDatos=fopen(rutaDatos, "wb");
if (destinoDatos==NULL){
fclose(origen);
return false;}


FILE *destinoBackups=fopen(rutaBackups, "wb");
if (destinoBackups==NULL){
fclose(origen);
fclose(destinoDatos);
return false;}


while(fread(&reg, sizeof(Maquinas), 1, origen)){
    fwrite(&reg, sizeof(Maquinas), 1, destinoDatos);
    fwrite(&reg, sizeof(Maquinas), 1, destinoBackups);
}

fclose(origen);
fclose(destinoDatos);
fclose(destinoBackups);

msj("**LA COPIA SE HA REALIZADO CORRECTAMENTE**", rlutil::WHITE, rlutil::GREEN);

return true;


}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA MANUAL
else{

FILE *origen=fopen("Maquinas.dat", "rb");
if (origen==NULL){return false;}


FILE *destinoDatos=fopen(rutaDatos, "wb");
if (destinoDatos==NULL){
fclose(origen);
return false;}


FILE *destinoBackups=fopen(rutaBackups, "wb");
if (destinoBackups==NULL){
fclose(origen);
fclose(destinoDatos);
return false;}


while(fread(&reg, sizeof(Maquinas), 1, origen)){
    fwrite(&reg, sizeof(Maquinas), 1, destinoDatos);
    fwrite(&reg, sizeof(Maquinas), 1, destinoBackups);
}

fclose(origen);
fclose(destinoDatos);
fclose(destinoBackups);

return true;

}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA AUTOMÁTICA

}

bool copiarRepuestos(bool nuevo){
Repuestos reg;
char si, ok, sigue, continuar;
int x=6, y=5;
const char *rutaDatos= "datos/Repuestos.dat";
const char *rutaBackups= "backups/Repuestos.bkp";


if (nuevo==true){

system ("cls");
setlocale(LC_ALL,"spanish");
title("COPIAS DE SEGURIDAD DEL ARCHIVO REPUESTOS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTGREEN);
cout<<"CONFIRMA ALMACENAR Y COPIAR EL ARCHIVO DE REPUESTOS (S/N)?: ";
setColor(WHITE);
cin>>si;
ok=towupper(si);

if (ok=='N'){return false;}

while(!(ok == 'S')){

        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***ERROR EN LA CONFIRMACIÓN***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        setColor(LIGHTGREEN);
        cout<<"DESEA ALMACENAR Y COPIAR LOS ARCHIVOS DE REPUESTOS (S/N)?: ";
        setColor(WHITE);
        cin>>si;

        ok=towupper(si);
        if (ok=='N'){return false;}

        }else {return false;}
}

FILE *origen=fopen("Repuestos.dat", "rb");
if (origen==NULL){return false;}


FILE *destinoDatos=fopen(rutaDatos, "wb");
if (destinoDatos==NULL){
fclose(origen);
return false;}


FILE *destinoBackups=fopen(rutaBackups, "wb");
if (destinoBackups==NULL){
fclose(origen);
fclose(destinoDatos);
return false;}


while(fread(&reg, sizeof(Repuestos), 1, origen)){
    fwrite(&reg, sizeof(Repuestos), 1, destinoDatos);
    fwrite(&reg, sizeof(Repuestos), 1, destinoBackups);
}

fclose(origen);
fclose(destinoDatos);
fclose(destinoBackups);

msj("**LA COPIA SE HA REALIZADO CORRECTAMENTE**", rlutil::WHITE, rlutil::GREEN);

return true;


}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA MANUAL
else{

FILE *origen=fopen("Repuestos.dat", "rb");
if (origen==NULL){return false;}


FILE *destinoDatos=fopen(rutaDatos, "wb");
if (destinoDatos==NULL){
fclose(origen);
return false;}


FILE *destinoBackups=fopen(rutaBackups, "wb");
if (destinoBackups==NULL){
fclose(origen);
fclose(destinoDatos);
return false;}


while(fread(&reg, sizeof(Repuestos), 1, origen)){
    fwrite(&reg, sizeof(Repuestos), 1, destinoDatos);
    fwrite(&reg, sizeof(Repuestos), 1, destinoBackups);
}

fclose(origen);
fclose(destinoDatos);
fclose(destinoBackups);

return true;

}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA AUTOMÁTICA
}

bool copiarOt(bool nuevo){
OT reg;
char si, ok, sigue, continuar;
int x=6, y=5;
const char *rutaDatos= "datos/OT.dat";
const char *rutaBackups= "backups/OT.bkp";


if (nuevo==true){

system ("cls");
setlocale(LC_ALL,"spanish");
title("COPIAS DE SEGURIDAD DEL ARCHIVO OT", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTGREEN);
cout<<"CONFIRMA ALMACENAR Y COPIAR EL ARCHIVO DE OT (S/N)?: ";
setColor(WHITE);
cin>>si;
ok=towupper(si);

if (ok=='N'){return false;}

while(!(ok == 'S')){

        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***ERROR EN LA CONFIRMACIÓN***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        setColor(LIGHTGREEN);
        cout<<"DESEA ALMACENAR Y COPIAR LOS ARCHIVOS DE OT (S/N)?: ";
        setColor(WHITE);
        cin>>si;

        ok=towupper(si);
        if (ok=='N'){return false;}

        }else {return false;}
}

FILE *origen=fopen("OT.dat", "rb");
if (origen==NULL){return false;}


FILE *destinoDatos=fopen(rutaDatos, "wb");
if (destinoDatos==NULL){
fclose(origen);
return false;}


FILE *destinoBackups=fopen(rutaBackups, "wb");
if (destinoBackups==NULL){
fclose(origen);
fclose(destinoDatos);
return false;}


while(fread(&reg, sizeof(OT), 1, origen)){
    fwrite(&reg, sizeof(OT), 1, destinoDatos);
    fwrite(&reg, sizeof(OT), 1, destinoBackups);
}

fclose(origen);
fclose(destinoDatos);
fclose(destinoBackups);

msj("**LA COPIA SE HA REALIZADO CORRECTAMENTE**", rlutil::WHITE, rlutil::GREEN);

return true;


}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA MANUAL
else{

FILE *origen=fopen("OT.dat", "rb");
if (origen==NULL){return false;}


FILE *destinoDatos=fopen(rutaDatos, "wb");
if (destinoDatos==NULL){
fclose(origen);
return false;}


FILE *destinoBackups=fopen(rutaBackups, "wb");
if (destinoBackups==NULL){
fclose(origen);
fclose(destinoDatos);
return false;}


while(fread(&reg, sizeof(OT), 1, origen)){
    fwrite(&reg, sizeof(OT), 1, destinoDatos);
    fwrite(&reg, sizeof(OT), 1, destinoBackups);
}

fclose(origen);
fclose(destinoDatos);
fclose(destinoBackups);

return true;

}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA AUTOMÁTICA

}

bool copiarStock(bool nuevo){
Stock reg;
char si, ok, sigue, continuar;
int x=6, y=5;
const char *rutaDatos= "datos/Stock.dat";
const char *rutaBackups= "backups/Stock.bkp";


if (nuevo==true){

system ("cls");
setlocale(LC_ALL,"spanish");
title("COPIAS DE SEGURIDAD DEL ARCHIVO STOCK", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTGREEN);
cout<<"CONFIRMA ALMACENAR Y COPIAR EL ARCHIVO DE STOCK (S/N)?: ";
setColor(WHITE);
cin>>si;
ok=towupper(si);

if (ok=='N'){return false;}

while(!(ok == 'S')){

        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***ERROR EN LA CONFIRMACIÓN***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        setColor(LIGHTGREEN);
        cout<<"DESEA ALMACENAR Y COPIAR LOS ARCHIVOS DE STOCK (S/N)?: ";
        setColor(WHITE);
        cin>>si;

        ok=towupper(si);
        if (ok=='N'){return false;}

        }else {return false;}
}

FILE *origen=fopen("Stock.dat", "rb");
if (origen==NULL){return false;}


FILE *destinoDatos=fopen(rutaDatos, "wb");
if (destinoDatos==NULL){
fclose(origen);
return false;}


FILE *destinoBackups=fopen(rutaBackups, "wb");
if (destinoBackups==NULL){
fclose(origen);
fclose(destinoDatos);
return false;}


while(fread(&reg, sizeof(Stock), 1, origen)){
    fwrite(&reg, sizeof(Stock), 1, destinoDatos);
    fwrite(&reg, sizeof(Stock), 1, destinoBackups);
}

fclose(origen);
fclose(destinoDatos);
fclose(destinoBackups);

msj("**LA COPIA SE HA REALIZADO CORRECTAMENTE**", rlutil::WHITE, rlutil::GREEN);

return true;


}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA MANUAL
else{

FILE *origen=fopen("Stock.dat", "rb");
if (origen==NULL){return false;}


FILE *destinoDatos=fopen(rutaDatos, "wb");
if (destinoDatos==NULL){
fclose(origen);
return false;}


FILE *destinoBackups=fopen(rutaBackups, "wb");
if (destinoBackups==NULL){
fclose(origen);
fclose(destinoDatos);
return false;}


while(fread(&reg, sizeof(Stock), 1, origen)){
    fwrite(&reg, sizeof(Stock), 1, destinoDatos);
    fwrite(&reg, sizeof(Stock), 1, destinoBackups);
}

fclose(origen);
fclose(destinoDatos);
fclose(destinoBackups);

return true;

}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA AUTOMÁTICA


}

bool copiarValeEntradaSalida(bool nuevo){
valeEntradaSalida reg;
Items aux;
char si, ok, sigue, continuar;
int x=6, y=5;
const char *rutaDatos= "datos/valeEntradaSalida.dat";
const char *rutaDatosItems= "datos/Items.dat";
const char *rutaBackups= "backups/valeEntradaSalida.bkp";
const char *rutaBackupsItems= "backups/Items.bkp";


if (nuevo==true){

system ("cls");
setlocale(LC_ALL,"spanish");
title("COPIAS DE SEGURIDAD DEL ARCHIVO VALE DE ENTRADA/SALIDA E ÍTEMS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTGREEN);
cout<<"CONFIRMA ALMACENAR Y COPIAR LOS ARCHIVOS DE VALE DE ENTRADA/SALIDA E ÍTEMS (S/N)?: ";
setColor(WHITE);
cin>>si;
ok=towupper(si);

if (ok=='N'){return false;}

while(!(ok == 'S')){

        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***ERROR EN LA CONFIRMACIÓN***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        setColor(LIGHTGREEN);
        cout<<"CONFIRMA ALMACENAR Y COPIAR LOS ARCHIVOS DE VALE DE ENTRADA/SALIDA E ÍTEMS (S/N)?: ";
        setColor(WHITE);
        cin>>si;

        ok=towupper(si);
        if (ok=='N'){return false;}

        }else {return false;}
}

FILE *origen=fopen("valeEntradaSalida.dat", "rb");
if (origen==NULL){return false;}

FILE *origenItems=fopen("Items.dat","rb");
if (origenItems==NULL){
fclose(origen);
return false;}


FILE *destinoDatos=fopen(rutaDatos, "wb");
if (destinoDatos==NULL){
fclose(origen);
fclose(origenItems);
return false;}

FILE *destinoDatosItems=fopen(rutaDatosItems, "wb");
if (destinoDatos==NULL){
fclose(origen);
fclose(origenItems);
fclose(destinoDatos);
return false;}


FILE *destinoBackups=fopen(rutaBackups, "wb");
if (destinoBackups==NULL){
fclose(origen);
fclose(origenItems);
fclose(destinoDatos);
fclose(destinoDatosItems);
return false;}

FILE *destinoBackupsItems=fopen(rutaBackupsItems, "wb");
if (destinoBackups==NULL){
fclose(origen);
fclose(origenItems);
fclose(destinoDatos);
fclose(destinoDatosItems);
fclose(destinoBackups);
return false;}


while(fread(&reg, sizeof(valeEntradaSalida), 1, origen)){
    fwrite(&reg, sizeof(valeEntradaSalida), 1, destinoDatos);
    fwrite(&reg, sizeof(valeEntradaSalida), 1, destinoBackups);
}

while(fread(&aux, sizeof(Items), 1, origenItems)){
    fwrite(&aux, sizeof(Items), 1, destinoDatosItems);
    fwrite(&aux, sizeof(Items), 1, destinoBackupsItems);
}

fclose(origen);
fclose(origenItems);
fclose(destinoDatos);
fclose(destinoDatosItems);
fclose(destinoBackups);
fclose(destinoBackupsItems);

msj("**LA COPIA SE HA REALIZADO CORRECTAMENTE**", rlutil::WHITE, rlutil::GREEN);

return true;


}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA MANUAL
else{

FILE *origen=fopen("valeEntradaSalida.dat", "rb");
if (origen==NULL){return false;}

FILE *origenItems=fopen("Items.dat","rb");
if (origenItems==NULL){
fclose(origen);
return false;}


FILE *destinoDatos=fopen(rutaDatos, "wb");
if (destinoDatos==NULL){
fclose(origen);
fclose(origenItems);
return false;}

FILE *destinoDatosItems=fopen(rutaDatosItems, "wb");
if (destinoDatos==NULL){
fclose(origen);
fclose(origenItems);
fclose(destinoDatos);
return false;}


FILE *destinoBackups=fopen(rutaBackups, "wb");
if (destinoBackups==NULL){
fclose(origen);
fclose(origenItems);
fclose(destinoDatos);
fclose(destinoDatosItems);
return false;}

FILE *destinoBackupsItems=fopen(rutaBackupsItems, "wb");
if (destinoBackups==NULL){
fclose(origen);
fclose(origenItems);
fclose(destinoDatos);
fclose(destinoDatosItems);
fclose(destinoBackups);
return false;}


while(fread(&reg, sizeof(valeEntradaSalida), 1, origen)){
    fwrite(&reg, sizeof(valeEntradaSalida), 1, destinoDatos);
    fwrite(&reg, sizeof(valeEntradaSalida), 1, destinoBackups);
}

while(fread(&aux, sizeof(Items), 1, origenItems)){
    fwrite(&aux, sizeof(Items), 1, destinoDatosItems);
    fwrite(&aux, sizeof(Items), 1, destinoBackupsItems);
}

fclose(origen);
fclose(origenItems);
fclose(destinoDatos);
fclose(destinoDatosItems);
fclose(destinoBackups);
fclose(destinoBackupsItems);

return true;

}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA AUTOMÁTICA

}

bool copiarTodo(){

char si, ok, sigue, continuar;
int x=6, y=5;
bool okey;


system ("cls");
setlocale(LC_ALL,"spanish");
title("COPIAS DE SEGURIDAD DE TODOS LOS ARCHIVOS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTGREEN);
cout<<"CONFIRMA ALMACENAR Y COPIAR TODOS LOS ARCHIVOS (S/N)?: ";
setColor(WHITE);
cin>>si;
ok=towupper(si);

if (ok=='N'){return false;}

while(!(ok == 'S')){

        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***ERROR EN LA CONFIRMACIÓN***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        setColor(LIGHTGREEN);
        cout<<"DESEA ALMACENAR Y COPIAR TODOS LOS ARCHIVOS (S/N)?: ";
        setColor(WHITE);
        cin>>si;

        ok=towupper(si);
        if (ok=='N'){return false;}

        }else {return false;}
}

int cont=0;

okey=copiarPersonas(false);
if (okey==false){
        msj("***NO SE PUDO REALIZAR LA COPIA DE PERSONAS CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);
        cont++;}

okey=copiarPersonal(false);
if (okey==false){
        msj("***NO SE PUDO REALIZAR LA COPIA DE PERSONAL CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);
        cont++;}

okey=copiarMaquinas(false);
if (okey==false){
        msj("***NO SE PUDO REALIZAR LA COPIA DE MAQUINAS CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);
        cont++;}

okey=copiarRepuestos(false);
if (okey==false){
        msj("***NO SE PUDO REALIZAR LA COPIA DE REPUESTOS CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);
        cont++;}

okey=copiarOt(false);
if (okey==false){
        msj("***NO SE PUDO REALIZAR LA COPIA DE OT CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);
        cont++;}

okey=copiarStock(false);
if (okey==false){
        msj("***NO SE PUDO REALIZAR LA COPIA DE STOCK CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);
        cont++;}

okey=copiarValeEntradaSalida(false);
if (okey==false){
        msj("***NO SE PUDO REALIZAR LA COPIA DE VALE DE ENTRADA/SALIDA e ÍTEMS CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);
        cont++;}

if (cont==0){
        msj("**TODAS LAS COPIAS SE HAN REALIZADO CORRECTAMENTE**", rlutil::WHITE, rlutil::GREEN);
        return true;}
else{msj("***UNO O MÁS ARCHIVOS NO SE HAN PODIDO COPIAR CORRECTAMENTE***", rlutil::WHITE, rlutil::RED); }


}

bool restaurarPersonas(bool nuevo){
Personas reg;
char si, ok, sigue, continuar;
int x=6, y=5, i;
bool validado;

const char *rutaBackups= "backups/Personas.bkp";


if (nuevo==true){

system ("cls");
setlocale(LC_ALL,"spanish");
title("RESTAURAR COPIAS DE SEGURIDAD DEL ARCHIVO PERSONAS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTGREEN);
cout<<"CONFIRMA RESTAURAR COPIAS DE SEGURIDAD DEL ARCHIVO PERSONAS (S/N)?: ";
setColor(WHITE);
cin>>si;
ok=towupper(si);

if (ok=='N'){return false;}

while(!(ok == 'S')){

        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***ERROR EN LA CONFIRMACIÓN***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        setColor(LIGHTGREEN);
        cout<<"CONFIRMA RESTAURAR COPIAS DE SEGURIDAD DEL ARCHIVO PERSONAS (S/N)?: ";
        setColor(WHITE);
        cin>>si;

        ok=towupper(si);
        if (ok=='N'){return false;}

        }else {return false;}
}

const int cantPin=5;
int vec[cantPin], pin[cantPin];

gotoxy(x,++y);
setColor(LIGHTCYAN);
cout<<"***PARA COMPLETAR LA CONFIRMACION ESCRIBA EL SIGUIENTE CÓDIGO DE SEGURIDAD***";

///SE VALIDA EL CODIGO DE SEGURIDAD, SINO SE PUEDE VOLVER A EMPEZAR LA VALIDACION

do{
gotoxy(x,++y);
setColor(YELLOW);
cout<<"CÓDIGO DE SEGURIDAD: ";
setColor(LIGHTGREEN);

pin_numerico(vec, cantPin);

gotoxy(x,++y);
setColor(YELLOW);
cout<<"INGRESE EL CÓDIGO DE SEGURIDAD: ";


int derecha=36, abajo=y-1, ancho=2, alto=2;


setColor(WHITE);
for(i=0; i<cantPin; i++){

derecha=derecha+2;

recuadro(derecha, abajo, ancho, alto);

abajo=++abajo;

gotoxy(++derecha,abajo);

cin>>pin[i];

abajo=--abajo;
}

validado=validarPin(vec, pin, cantPin);

if(validado==false){
        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***PIN INCORRECTO***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){ validado=false;}else {return false;}
}

}while(validado==false);


///FIN DE LA VALIDACION

FILE *origen=fopen(rutaBackups, "rb");
if (origen==NULL){return false;}


FILE *destino=fopen("Personas.dat", "wb");
if (destino==NULL){
fclose(origen);
return false;}



while(fread(&reg, sizeof(Personas), 1, origen)){
    fwrite(&reg, sizeof(Personas), 1, destino);

}

fclose(origen);
fclose(destino);


msj("**LA RESTAURACION SE HA REALIZADO CORRECTAMENTE**", rlutil::WHITE, rlutil::GREEN);

return true;


}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA MANUAL
else{

FILE *origen=fopen(rutaBackups, "rb");
if (origen==NULL){return false;}


FILE *destino=fopen("Personas.dat", "wb");
if (destino==NULL){
fclose(origen);
return false;}



while(fread(&reg, sizeof(Personas), 1, origen)){
    fwrite(&reg, sizeof(Personas), 1, destino);

}

fclose(origen);
fclose(destino);

return true;


}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA AUTOMÁTICA

}

bool restaurarPersonal(bool nuevo){
Personal reg;
char si, ok, sigue, continuar;
int x=6, y=5, i;
bool validado;

const char *rutaBackups= "backups/Personal.bkp";


if (nuevo==true){

system ("cls");
setlocale(LC_ALL,"spanish");
title("RESTAURAR COPIAS DE SEGURIDAD DEL ARCHIVO PERSONAL", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTGREEN);
cout<<"CONFIRMA RESTAURAR COPIAS DE SEGURIDAD DEL ARCHIVO PERSONAL (S/N)?: ";
setColor(WHITE);
cin>>si;
ok=towupper(si);

if (ok=='N'){return false;}

while(!(ok == 'S')){

        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***ERROR EN LA CONFIRMACIÓN***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        setColor(LIGHTGREEN);
        cout<<"CONFIRMA RESTAURAR COPIAS DE SEGURIDAD DEL ARCHIVO PERSONAL (S/N)?: ";
        setColor(WHITE);
        cin>>si;

        ok=towupper(si);
        if (ok=='N'){return false;}

        }else {return false;}
}

const int cantPin=5;
int vec[cantPin], pin[cantPin];

gotoxy(x,++y);
setColor(LIGHTCYAN);
cout<<"***PARA COMPLETAR LA CONFIRMACION ESCRIBA EL SIGUIENTE CÓDIGO DE SEGURIDAD***";

///SE VALIDA EL CODIGO DE SEGURIDAD, SINO SE PUEDE VOLVER A EMPEZAR LA VALIDACION

do{
gotoxy(x,++y);
setColor(YELLOW);
cout<<"CÓDIGO DE SEGURIDAD: ";
setColor(LIGHTGREEN);

pin_numerico(vec, cantPin);

gotoxy(x,++y);
setColor(YELLOW);
cout<<"INGRESE EL CÓDIGO DE SEGURIDAD: ";


int derecha=36, abajo=y-1, ancho=2, alto=2;


setColor(WHITE);
for(i=0; i<cantPin; i++){

derecha=derecha+2;

recuadro(derecha, abajo, ancho, alto);

abajo=++abajo;

gotoxy(++derecha,abajo);

cin>>pin[i];

abajo=--abajo;
}

validado=validarPin(vec, pin, cantPin);

if(validado==false){
        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***PIN INCORRECTO***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){ validado=false;}else {return false;}
}

}while(validado==false);


///FIN DE LA VALIDACION

FILE *origen=fopen(rutaBackups, "rb");
if (origen==NULL){return false;}


FILE *destino=fopen("Personal.dat", "wb");
if (destino==NULL){
fclose(origen);
return false;}



while(fread(&reg, sizeof(Personal), 1, origen)){
    fwrite(&reg, sizeof(Personal), 1, destino);

}

fclose(origen);
fclose(destino);


msj("**LA RESTAURACION SE HA REALIZADO CORRECTAMENTE**", rlutil::WHITE, rlutil::GREEN);

return true;


}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA MANUAL
else{

FILE *origen=fopen(rutaBackups, "rb");
if (origen==NULL){return false;}


FILE *destino=fopen("Personal.dat", "wb");
if (destino==NULL){
fclose(origen);
return false;}



while(fread(&reg, sizeof(Personal), 1, origen)){
    fwrite(&reg, sizeof(Personal), 1, destino);

}

fclose(origen);
fclose(destino);

return true;


}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA AUTOMÁTICA

}

bool restaurarMaquinas(bool nuevo){
Maquinas reg;
char si, ok, sigue, continuar;
int x=6, y=5, i;
bool validado;

const char *rutaBackups= "backups/Maquinas.bkp";


if (nuevo==true){

system ("cls");
setlocale(LC_ALL,"spanish");
title("RESTAURAR COPIAS DE SEGURIDAD DEL ARCHIVO MAQUINAS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTGREEN);
cout<<"CONFIRMA RESTAURAR COPIAS DE SEGURIDAD DEL ARCHIVO MAQUINAS (S/N)?: ";
setColor(WHITE);
cin>>si;
ok=towupper(si);

if (ok=='N'){return false;}

while(!(ok == 'S')){

        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***ERROR EN LA CONFIRMACIÓN***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        setColor(LIGHTGREEN);
        cout<<"CONFIRMA RESTAURAR COPIAS DE SEGURIDAD DEL ARCHIVO MAQUINAS (S/N)?: ";
        setColor(WHITE);
        cin>>si;

        ok=towupper(si);
        if (ok=='N'){return false;}

        }else {return false;}
}

const int cantPin=5;
int vec[cantPin], pin[cantPin];

gotoxy(x,++y);
setColor(LIGHTCYAN);
cout<<"***PARA COMPLETAR LA CONFIRMACION ESCRIBA EL SIGUIENTE CÓDIGO DE SEGURIDAD***";

///SE VALIDA EL CODIGO DE SEGURIDAD, SINO SE PUEDE VOLVER A EMPEZAR LA VALIDACION

do{
gotoxy(x,++y);
setColor(YELLOW);
cout<<"CÓDIGO DE SEGURIDAD: ";
setColor(LIGHTGREEN);

pin_numerico(vec, cantPin);

gotoxy(x,++y);
setColor(YELLOW);
cout<<"INGRESE EL CÓDIGO DE SEGURIDAD: ";


int derecha=36, abajo=y-1, ancho=2, alto=2;


setColor(WHITE);
for(i=0; i<cantPin; i++){

derecha=derecha+2;

recuadro(derecha, abajo, ancho, alto);

abajo=++abajo;

gotoxy(++derecha,abajo);

cin>>pin[i];

abajo=--abajo;
}

validado=validarPin(vec, pin, cantPin);

if(validado==false){
        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***PIN INCORRECTO***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){ validado=false;}else {return false;}
}

}while(validado==false);


///FIN DE LA VALIDACION

FILE *origen=fopen(rutaBackups, "rb");
if (origen==NULL){return false;}


FILE *destino=fopen("Maquinas.dat", "wb");
if (destino==NULL){
fclose(origen);
return false;}



while(fread(&reg, sizeof(Maquinas), 1, origen)){
    fwrite(&reg, sizeof(Maquinas), 1, destino);

}

fclose(origen);
fclose(destino);


msj("**LA RESTAURACION SE HA REALIZADO CORRECTAMENTE**", rlutil::WHITE, rlutil::GREEN);

return true;


}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA MANUAL
else{

FILE *origen=fopen(rutaBackups, "rb");
if (origen==NULL){return false;}


FILE *destino=fopen("Maquinas.dat", "wb");
if (destino==NULL){
fclose(origen);
return false;}



while(fread(&reg, sizeof(Maquinas), 1, origen)){
    fwrite(&reg, sizeof(Maquinas), 1, destino);

}

fclose(origen);
fclose(destino);

return true;


}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA AUTOMÁTICA

}

bool restaurarRepuestos(bool nuevo){
Repuestos reg;
char si, ok, sigue, continuar;
int x=6, y=5, i;
bool validado;

const char *rutaBackups= "backups/Repuestos.bkp";


if (nuevo==true){

system ("cls");
setlocale(LC_ALL,"spanish");
title("RESTAURAR COPIAS DE SEGURIDAD DEL ARCHIVO REPUESTOS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTGREEN);
cout<<"CONFIRMA RESTAURAR COPIAS DE SEGURIDAD DEL ARCHIVO REPUESTOS (S/N)?: ";
setColor(WHITE);
cin>>si;
ok=towupper(si);

if (ok=='N'){return false;}

while(!(ok == 'S')){

        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***ERROR EN LA CONFIRMACIÓN***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        setColor(LIGHTGREEN);
        cout<<"CONFIRMA RESTAURAR COPIAS DE SEGURIDAD DEL ARCHIVO REPUESTOS (S/N)?: ";
        setColor(WHITE);
        cin>>si;

        ok=towupper(si);
        if (ok=='N'){return false;}

        }else {return false;}
}

const int cantPin=5;
int vec[cantPin], pin[cantPin];

gotoxy(x,++y);
setColor(LIGHTCYAN);
cout<<"***PARA COMPLETAR LA CONFIRMACION ESCRIBA EL SIGUIENTE CÓDIGO DE SEGURIDAD***";

///SE VALIDA EL CODIGO DE SEGURIDAD, SINO SE PUEDE VOLVER A EMPEZAR LA VALIDACION

do{
gotoxy(x,++y);
setColor(YELLOW);
cout<<"CÓDIGO DE SEGURIDAD: ";
setColor(LIGHTGREEN);

pin_numerico(vec, cantPin);

gotoxy(x,++y);
setColor(YELLOW);
cout<<"INGRESE EL CÓDIGO DE SEGURIDAD: ";


int derecha=36, abajo=y-1, ancho=2, alto=2;


setColor(WHITE);
for(i=0; i<cantPin; i++){

derecha=derecha+2;

recuadro(derecha, abajo, ancho, alto);

abajo=++abajo;

gotoxy(++derecha,abajo);

cin>>pin[i];

abajo=--abajo;
}

validado=validarPin(vec, pin, cantPin);

if(validado==false){
        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***PIN INCORRECTO***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){ validado=false;}else {return false;}
}

}while(validado==false);


///FIN DE LA VALIDACION

FILE *origen=fopen(rutaBackups, "rb");
if (origen==NULL){return false;}


FILE *destino=fopen("Repuestos.dat", "wb");
if (destino==NULL){
fclose(origen);
return false;}



while(fread(&reg, sizeof(Repuestos), 1, origen)){
    fwrite(&reg, sizeof(Repuestos), 1, destino);

}

fclose(origen);
fclose(destino);


msj("**LA RESTAURACION SE HA REALIZADO CORRECTAMENTE**", rlutil::WHITE, rlutil::GREEN);

return true;


}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA MANUAL
else{

FILE *origen=fopen(rutaBackups, "rb");
if (origen==NULL){return false;}


FILE *destino=fopen("Repuestos.dat", "wb");
if (destino==NULL){
fclose(origen);
return false;}



while(fread(&reg, sizeof(Repuestos), 1, origen)){
    fwrite(&reg, sizeof(Repuestos), 1, destino);

}

fclose(origen);
fclose(destino);

return true;


}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA AUTOMÁTICA

}

bool restaurarOt(bool nuevo){
OT reg;
char si, ok, sigue, continuar;
int x=6, y=5, i;
bool validado;

const char *rutaBackups= "backups/OT.bkp";


if (nuevo==true){

system ("cls");
setlocale(LC_ALL,"spanish");
title("RESTAURAR COPIAS DE SEGURIDAD DEL ARCHIVO OT", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTGREEN);
cout<<"CONFIRMA RESTAURAR COPIAS DE SEGURIDAD DEL ARCHIVO OT (S/N)?: ";
setColor(WHITE);
cin>>si;
ok=towupper(si);

if (ok=='N'){return false;}

while(!(ok == 'S')){

        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***ERROR EN LA CONFIRMACIÓN***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        setColor(LIGHTGREEN);
        cout<<"CONFIRMA RESTAURAR COPIAS DE SEGURIDAD DEL ARCHIVO OT (S/N)?: ";
        setColor(WHITE);
        cin>>si;

        ok=towupper(si);
        if (ok=='N'){return false;}

        }else {return false;}
}

const int cantPin=5;
int vec[cantPin], pin[cantPin];

gotoxy(x,++y);
setColor(LIGHTCYAN);
cout<<"***PARA COMPLETAR LA CONFIRMACION ESCRIBA EL SIGUIENTE CÓDIGO DE SEGURIDAD***";

///SE VALIDA EL CODIGO DE SEGURIDAD, SINO SE PUEDE VOLVER A EMPEZAR LA VALIDACION

do{
gotoxy(x,++y);
setColor(YELLOW);
cout<<"CÓDIGO DE SEGURIDAD: ";
setColor(LIGHTGREEN);

pin_numerico(vec, cantPin);

gotoxy(x,++y);
setColor(YELLOW);
cout<<"INGRESE EL CÓDIGO DE SEGURIDAD: ";


int derecha=36, abajo=y-1, ancho=2, alto=2;


setColor(WHITE);
for(i=0; i<cantPin; i++){

derecha=derecha+2;

recuadro(derecha, abajo, ancho, alto);

abajo=++abajo;

gotoxy(++derecha,abajo);

cin>>pin[i];

abajo=--abajo;
}

validado=validarPin(vec, pin, cantPin);

if(validado==false){
        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***PIN INCORRECTO***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){ validado=false;}else {return false;}
}

}while(validado==false);


///FIN DE LA VALIDACION

FILE *origen=fopen(rutaBackups, "rb");
if (origen==NULL){return false;}


FILE *destino=fopen("OT.dat", "wb");
if (destino==NULL){
fclose(origen);
return false;}



while(fread(&reg, sizeof(OT), 1, origen)){
    fwrite(&reg, sizeof(OT), 1, destino);

}

fclose(origen);
fclose(destino);


msj("**LA RESTAURACION SE HA REALIZADO CORRECTAMENTE**", rlutil::WHITE, rlutil::GREEN);

return true;


}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA MANUAL
else{

FILE *origen=fopen(rutaBackups, "rb");
if (origen==NULL){return false;}


FILE *destino=fopen("OT.dat", "wb");
if (destino==NULL){
fclose(origen);
return false;}



while(fread(&reg, sizeof(OT), 1, origen)){
    fwrite(&reg, sizeof(OT), 1, destino);

}

fclose(origen);
fclose(destino);

return true;


}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA AUTOMÁTICA

}

bool restaurarStock(bool nuevo){
Stock reg;
char si, ok, sigue, continuar;
int x=6, y=5, i;
bool validado;

const char *rutaBackups= "backups/Stock.bkp";


if (nuevo==true){

system ("cls");
setlocale(LC_ALL,"spanish");
title("RESTAURAR COPIAS DE SEGURIDAD DEL ARCHIVO STOCK", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTGREEN);
cout<<"CONFIRMA RESTAURAR COPIAS DE SEGURIDAD DEL ARCHIVO STOCK (S/N)?: ";
setColor(WHITE);
cin>>si;
ok=towupper(si);

if (ok=='N'){return false;}

while(!(ok == 'S')){

        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***ERROR EN LA CONFIRMACIÓN***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        setColor(LIGHTGREEN);
        cout<<"CONFIRMA RESTAURAR COPIAS DE SEGURIDAD DEL ARCHIVO STOCK (S/N)?: ";
        setColor(WHITE);
        cin>>si;

        ok=towupper(si);
        if (ok=='N'){return false;}

        }else {return false;}
}

const int cantPin=5;
int vec[cantPin], pin[cantPin];

gotoxy(x,++y);
setColor(LIGHTCYAN);
cout<<"***PARA COMPLETAR LA CONFIRMACION ESCRIBA EL SIGUIENTE CÓDIGO DE SEGURIDAD***";

///SE VALIDA EL CODIGO DE SEGURIDAD, SINO SE PUEDE VOLVER A EMPEZAR LA VALIDACION

do{
gotoxy(x,++y);
setColor(YELLOW);
cout<<"CÓDIGO DE SEGURIDAD: ";
setColor(LIGHTGREEN);

pin_numerico(vec, cantPin);

gotoxy(x,++y);
setColor(YELLOW);
cout<<"INGRESE EL CÓDIGO DE SEGURIDAD: ";


int derecha=36, abajo=y-1, ancho=2, alto=2;


setColor(WHITE);
for(i=0; i<cantPin; i++){

derecha=derecha+2;

recuadro(derecha, abajo, ancho, alto);

abajo=++abajo;

gotoxy(++derecha,abajo);

cin>>pin[i];

abajo=--abajo;
}

validado=validarPin(vec, pin, cantPin);

if(validado==false){
        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***PIN INCORRECTO***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){ validado=false;}else {return false;}
}

}while(validado==false);


///FIN DE LA VALIDACION

FILE *origen=fopen(rutaBackups, "rb");
if (origen==NULL){return false;}


FILE *destino=fopen("Stock.dat", "wb");
if (destino==NULL){
fclose(origen);
return false;}



while(fread(&reg, sizeof(Stock), 1, origen)){
    fwrite(&reg, sizeof(Stock), 1, destino);

}

fclose(origen);
fclose(destino);


msj("**LA RESTAURACION SE HA REALIZADO CORRECTAMENTE**", rlutil::WHITE, rlutil::GREEN);

return true;


}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA MANUAL
else{

FILE *origen=fopen(rutaBackups, "rb");
if (origen==NULL){return false;}


FILE *destino=fopen("Stock.dat", "wb");
if (destino==NULL){
fclose(origen);
return false;}



while(fread(&reg, sizeof(Stock), 1, origen)){
    fwrite(&reg, sizeof(Stock), 1, destino);

}

fclose(origen);
fclose(destino);

return true;


}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA AUTOMÁTICA

}

bool restaurarValeEntradaSalida(bool nuevo){
valeEntradaSalida reg;
Items aux;
char si, ok, sigue, continuar;
int x=6, y=5, i;
bool validado;

const char *rutaBackups= "backups/valeEntradaSalida.bkp";
const char *rutaBackupsItems= "backups/Items.bkp";


if (nuevo==true){

system ("cls");
setlocale(LC_ALL,"spanish");
title("RESTAURAR COPIAS DE SEGURIDAD DEL ARCHIVO VALE DE ENTRADA/SALIDA E ÍTEMS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTGREEN);
cout<<"CONFIRMA RESTAURAR LOS ARCHIVOS DE VALE DE ENTRADA/SALIDA E ÍTEMS (S/N)?: ";
setColor(WHITE);
cin>>si;
ok=towupper(si);

if (ok=='N'){return false;}

while(!(ok == 'S')){

        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***ERROR EN LA CONFIRMACIÓN***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        setColor(LIGHTGREEN);
        cout<<"CONFIRMA RESTAURAR LOS ARCHIVOS DE VALE DE ENTRADA/SALIDA E ÍTEMS (S/N)?: ";
        setColor(WHITE);
        cin>>si;

        ok=towupper(si);
        if (ok=='N'){return false;}

        }else {return false;}
}

const int cantPin=5;
int vec[cantPin], pin[cantPin];

gotoxy(x,++y);
setColor(LIGHTCYAN);
cout<<"***PARA COMPLETAR LA CONFIRMACION ESCRIBA EL SIGUIENTE CÓDIGO DE SEGURIDAD***";

///SE VALIDA EL CODIGO DE SEGURIDAD, SINO SE PUEDE VOLVER A EMPEZAR LA VALIDACION

do{
gotoxy(x,++y);
setColor(YELLOW);
cout<<"CÓDIGO DE SEGURIDAD: ";
setColor(LIGHTGREEN);

pin_numerico(vec, cantPin);

gotoxy(x,++y);
setColor(YELLOW);
cout<<"INGRESE EL CÓDIGO DE SEGURIDAD: ";


int derecha=36, abajo=y-1, ancho=2, alto=2;


setColor(WHITE);
for(i=0; i<cantPin; i++){

derecha=derecha+2;

recuadro(derecha, abajo, ancho, alto);

abajo=++abajo;

gotoxy(++derecha,abajo);

cin>>pin[i];

abajo=--abajo;
}

validado=validarPin(vec, pin, cantPin);

if(validado==false){
        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***PIN INCORRECTO***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){ validado=false;}else {return false;}
}

}while(validado==false);


///FIN DE LA VALIDACION

FILE *origen=fopen(rutaBackups, "rb");
if (origen==NULL){return false;}

FILE *origenItems=fopen(rutaBackupsItems,"rb");
if (origenItems==NULL){
fclose(origen);
return false;}


FILE *destino=fopen("valeEntradaSalida.dat", "wb");
if (destino==NULL){
fclose(origen);
fclose(origenItems);
return false;}

FILE *destinoItems=fopen("Items.dat", "wb");
if (destinoItems==NULL){
fclose(origen);
fclose(origenItems);
fclose(destino);
return false;}


while(fread(&reg, sizeof(valeEntradaSalida), 1, origen)){
    fwrite(&reg, sizeof(valeEntradaSalida), 1, destino);
}

while(fread(&aux, sizeof(Items), 1, origenItems)){
    fwrite(&aux, sizeof(Items), 1, destinoItems);
}

fclose(origen);
fclose(origenItems);
fclose(destino);
fclose(destinoItems);

msj("**LA RESTAURACION SE HA REALIZADO CORRECTAMENTE**", rlutil::WHITE, rlutil::GREEN);

return true;


}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA MANUAL
else{

FILE *origen=fopen(rutaBackups, "rb");
if (origen==NULL){return false;}

FILE *origenItems=fopen(rutaBackupsItems,"rb");
if (origenItems==NULL){
fclose(origen);
return false;}


FILE *destino=fopen("valeEntradaSalida.dat", "wb");
if (destino==NULL){
fclose(origen);
fclose(origenItems);
return false;}

FILE *destinoItems=fopen("Items.dat", "wb");
if (destinoItems==NULL){
fclose(origen);
fclose(origenItems);
fclose(destino);
return false;}



while(fread(&reg, sizeof(valeEntradaSalida), 1, origen)){
    fwrite(&reg, sizeof(valeEntradaSalida), 1, destino);
}

while(fread(&aux, sizeof(Items), 1, origenItems)){
    fwrite(&aux, sizeof(Items), 1, destinoItems);
}

fclose(origen);
fclose(origenItems);
fclose(destino);
fclose(destinoItems);


return true;

}///HASTA ACA SE TERMINA DE REALIZAR EN FORMA AUTOMÁTICA
}

bool restaurarTodo(){
char si, ok, sigue, continuar;
int x=6, y=5, i;
bool okey;
bool validado;


system ("cls");
setlocale(LC_ALL,"spanish");
title("RESTAURAR COPIAS DE SEGURIDAD DE TODOS LOS ARCHIVOS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
setColor(LIGHTGREEN);
cout<<"CONFIRMA RESTAURAR TODOS LOS ARCHIVOS (S/N)?: ";
setColor(WHITE);
cin>>si;
ok=towupper(si);

if (ok=='N'){return false;}

while(!(ok == 'S')){

        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***ERROR EN LA CONFIRMACIÓN***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){
        gotoxy(x,++y);
        setColor(LIGHTGREEN);
        cout<<"DESEA RESTAURAR TODOS LOS ARCHIVOS (S/N)?: ";
        setColor(WHITE);
        cin>>si;

        ok=towupper(si);
        if (ok=='N'){return false;}

        }else {return false;}
}

const int cantPin=5;
int vec[cantPin], pin[cantPin];

gotoxy(x,++y);
setColor(LIGHTCYAN);
cout<<"***PARA COMPLETAR LA CONFIRMACION ESCRIBA EL SIGUIENTE CÓDIGO DE SEGURIDAD***";

///SE VALIDA EL CODIGO DE SEGURIDAD, SINO SE PUEDE VOLVER A EMPEZAR LA VALIDACION

do{
gotoxy(x,++y);
setColor(YELLOW);
cout<<"CÓDIGO DE SEGURIDAD: ";
setColor(LIGHTGREEN);

pin_numerico(vec, cantPin);

gotoxy(x,++y);
setColor(YELLOW);
cout<<"INGRESE EL CÓDIGO DE SEGURIDAD: ";


int derecha=36, abajo=y-1, ancho=2, alto=2;


setColor(WHITE);
for(i=0; i<cantPin; i++){

derecha=derecha+2;

recuadro(derecha, abajo, ancho, alto);

abajo=++abajo;

gotoxy(++derecha,abajo);

cin>>pin[i];

abajo=--abajo;
}

validado=validarPin(vec, pin, cantPin);

if(validado==false){
        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***PIN INCORRECTO***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"DESEA CONTINUAR (S/N)? : ";
        cin>>sigue;
        continuar=towupper(sigue);
        if (continuar == 'S'){ validado=false;}else {return false;}
}

}while(validado==false);

///FIN DE LA VALIDACION

int cont=0;

okey=restaurarPersonas(false);
if (okey==false){
        msj("***NO SE PUDO REALIZAR LA RESTAURACION DE PERSONAS CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);
        cont++;}

okey=restaurarPersonal(false);
if (okey==false){
        msj("***NO SE PUDO REALIZAR LA RESTAURACION DE PERSONAL CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);
        cont++;}

okey=restaurarMaquinas(false);
if (okey==false){
        msj("***NO SE PUDO REALIZAR LA RESTAURACION DE MAQUINAS CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);
        cont++;}

okey=restaurarRepuestos(false);
if (okey==false){
        msj("***NO SE PUDO REALIZAR LA RESTAURACION DE REPUESTOS CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);
        cont++;}

okey=restaurarOt(false);
if (okey==false){
        msj("***NO SE PUDO REALIZAR LA RESTAURACION DE OT CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);
        cont++;}

okey=restaurarStock(false);
if (okey==false){
        msj("***NO SE PUDO REALIZAR LA RESTAURACION DE STOCK CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);
        cont++;}

okey=restaurarValeEntradaSalida(false);
if (okey==false){
        msj("***NO SE PUDO REALIZAR LA RESTAURACION DE VALE DE ENTRADA/SALIDA e ÍTEMS CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);
        cont++;}

if (cont==0){
        msj("**TODAS LAS RESTAURACIONES SE HAN REALIZADO CORRECTAMENTE**", rlutil::WHITE, rlutil::GREEN);
        return true;}
else{msj("***UNO O MÁS ARCHIVOS NO SE HAN PODIDO RESTAURAR CORRECTAMENTE***", rlutil::WHITE, rlutil::RED); }
}
