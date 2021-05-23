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



///METODOS DE LA CLASE PERSONAL

char* Personal::getDni(){
    return Dni;
}

int Personal::getLegajo(){
    return Legajo;
}

char* Personal::getEspecialidad(){
    return Especialidad;
}

char* Personal::getTurno(){
    return Turno;
}

char* Personal::getCategoria(){
    return Categoria;
}

bool Personal::getEstado(){
    return Estado;
}

void Personal::setDni(char *dni){
    strcpy(Dni, dni);
}

void Personal::setLegajo(int legajo){
    Legajo=legajo;
}

void Personal::setEspecialidad(char *especialidad){
    strcpy(Especialidad, especialidad);
}

void Personal::setTurno(char *turno){
    strcpy(Turno, turno);
}

void Personal::setCategoria(char *categoria){
    strcpy(Categoria, categoria);
}

void Personal::setEstado(bool estado){
    Estado=estado;
}

void Personal::mostrar(Personas *Persona){


        system("cls");
        setlocale(LC_ALL,"spanish");
        title("DATOS LABORALES", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        recuadro(2,2,127,27);
        recuadro(4,3,123,25);
        cout << left;
        setColor(YELLOW);
        gotoxy(6,5);
        cout << setw(10) << "LEGAJO"<< setw(20) << "APELLIDO/S" << setw(20) << "NOMBRE/S" << setw(25) << "ESPECIALIDAD" << setw(25) << "CATEGORIA"<< setw(10) <<"TURNO";
        setColor(LIGHTCYAN);
        gotoxy(6,6);
        cout<< "------------------------------------------------------------------------------------------------------------------------";
            setColor(WHITE);
            gotoxy(6,7);
            cout << setw(10) << getLegajo();
            cout << setw(20) << Persona->getApellidos();
            cout << setw(20) << Persona->getNombres();
            cout << setw(25) << getEspecialidad();
            cout << setw(25) << getCategoria();
            cout << setw(10) << getTurno();


}

void Personal::mostrarconEstado(){
        Personas aux;
        int i=0;

        system("cls");
        setlocale(LC_ALL,"spanish");
        title("DATOS LABORALES", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        recuadro(2,2,127,27);
        recuadro(4,3,123,25);
        cout << left;
        setColor(YELLOW);
        gotoxy(6,5);
        cout << setw(10) << "LEGAJO"<< setw(20) << "APELLIDO/S" << setw(20) << "NOMBRE/S" << setw(22) << "ESPECIALIDAD" << setw(25) << "CATEGORIA"<< setw(10) <<"TURNO" << setw(12) <<"ESTADO";
        setColor(LIGHTCYAN);
        gotoxy(6, 6);
        cout<< "------------------------------------------------------------------------------------------------------------------------";

        while(aux.leerDisco(i++)){
            if(strcmp(aux.getDni(),getDni())==0){

            setColor(WHITE);
            gotoxy(6,7);
            cout << setw(10) << getLegajo();
            cout << setw(20) << aux.getApellidos();
            cout << setw(20) << aux.getNombres();
            cout << setw(22) << getEspecialidad();
            cout << setw(25) << getCategoria();
            cout << setw(10) << getTurno();
            if (getEstado()==1){cout << setw(12) <<"Trabaja";}else{cout << setw(12) <<"No Trabaja";}
            }
        }
}

bool Personal::cargar(Personal *nuevopersonal, Personas *nueva){

    bool cargo, escribio;
    int legajo, legajovalidado, opcion;



cargo=Personas::cargar(nueva);
if (cargo==true){


do{
int x=6, y=5;

system ("cls");
setlocale(LC_ALL,"spanish");
title("DATOS LABORALES", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);

gotoxy(x,y);
cout<<"LEGAJO: ";
cin>>legajo;

legajovalidado=validarLegajo(legajo);

///SE VALIDA LA ELECCION
if(legajovalidado==-1 || legajovalidado==0){
nuevopersonal->setLegajo(legajo);}
else{
        while(legajovalidado==1){
        setColor(LIGHTRED);
        gotoxy(x,++y);
        cout<<"***YA EXISTE ESE NUMERO EN NUESTROS REGISTROS***";
        setColor(WHITE);
        gotoxy(x,++y);
        cout<<"INGRESE NUEVAMENTE EL LEGAJO: ";
        cin>>legajo;
        legajovalidado=validarLegajo(legajo);
        }
        nuevopersonal->setLegajo(legajo);
    }
///FIN DE LA VALIDACION

gotoxy(x,++y);
cout<<"ESPECIALIDAD: ";
gotoxy(x,++y);
setColor(YELLOW);
cout << setw(20) << "1.Eléctrico" << setw(20) << "2.Mecánico" << setw(20) << "3.Electromecánico"<< setw(20) <<"4.Electrónico"<< setw(20)<<"5.Herrero";
setColor(WHITE);
gotoxy(x,++y);
cout<<"ELIJA UNA OPCIÓN (1-5): ";
cin>>opcion;

///SE VALIDA LA ELECCION DE ESPECIALIDAD
while (!(opcion>0 && opcion<=5)){
    msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);
    setColor(WHITE);
    gotoxy(x,++y);
    cout<<"ELIJA UNA OPCIÓN (1-5): ";
    cin>>opcion;
}
///FIN DE LA VALIDACION

char vec[5][20]={"Eléctrico","Mecánico","Electromecánico","Electrónico","Herrero"};

nuevopersonal->setEspecialidad(vec[opcion-1]);

gotoxy(x,++y);
cout<<"TURNO: ";
gotoxy(x,++y);
setColor(YELLOW);
cout << setw(20) << "1.Mañana" << setw(20) << "2.Tarde" << setw(20) << "3.Noche";
setColor(WHITE);
gotoxy(x,++y);
cout<<"ELIJA UNA OPCIÓN (1-3): ";
cin>>opcion;

///SE VALIDA LA ELECCION DE TURNO
while (!(opcion>0 && opcion<=3)){
    msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);
    setColor(WHITE);
    gotoxy(x,++y);
    cout<<"ELIJA UNA OPCIÓN (1-3): ";
    cin>>opcion;
}
///FIN DE LA VALIDACION

char vec2[3][20]={"Mañana","Tarde","Noche"};

nuevopersonal->setTurno(vec2[opcion-1]);

gotoxy(x,++y);
cout<<"CATEGORIA: ";
gotoxy(x,++y);
setColor(YELLOW);
cout << setw(20) << "1.Ayudante" << setw(20) << "2.Medio Oficial" << setw(20) << "3.Oficial"<< setw(20) <<"4.Oficial Múltiple";
gotoxy(x,++y);
cout << setw(30) << "5.Administrativo Técnico" << setw(20) << "6.Supervisor" << setw(30) << "7.Jefe de Mantenimiento";
setColor(WHITE);
gotoxy(x,++y);
cout<<"ELIJA UNA OPCIÓN (1-7): ";
cin>>opcion;

///SE VALIDA LA ELECCION DE TURNO
while (!(opcion>0 && opcion<=7)){
    msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);
    setColor(WHITE);
    gotoxy(x,++y);
    cout<<"ELIJA UNA OPCIÓN (1-7): ";
    cin>>opcion;
}
///FIN DE LA VALIDACION

char vec3[7][30]={"Ayudante","Medio Oficial","Oficial", "Oficial Múltiple","Administrativo Técnico","Supervisor","Jefe de Mantenimiento"};

nuevopersonal->setCategoria(vec3[opcion-1]);

nuevopersonal->mostrar(nueva);

x=6;
y=10;

gotoxy(x,y);
setColor(LIGHTRED);
cout<<"NOTA: ";
setColor(LIGHTCYAN);
cout<<"ANTES DE CONTINUAR PUEDE ELEGIR LAS SIGUIENTES OPCIONES: ";
gotoxy(x,12);
setColor(LIGHTGREEN);
cout << setw(40) << "1.MODIFICAR LOS DATOS LABORALES"<< setw(30) << "2.FINALIZAR SIN GUARDAR" << setw(30) << "3.FINALIZAR Y GUARDAR";
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
nuevopersonal->setEstado(true);
nuevopersonal->setDni(nueva->getDni());
return true;}


} else{return false;}

}

bool Personal::escribirDisco(int pos){
   bool grabo=false;
        FILE *f;
        if (pos == -1){
            f = fopen("Personal.dat", "ab");
            if (f == NULL){
                msj("***NO SE PUEDO ABRIR EL ARCHIVO***", rlutil::WHITE, rlutil::RED);
                return grabo;
            }
        }
        else{
            f = fopen("Personal.dat", "rb+");
            if (f == NULL){
                msj("***NO SE PUEDO ABRIR EL ARCHIVO***", rlutil::WHITE, rlutil::RED);
                return grabo;
            }
            fseek(f, pos * sizeof(Personal), 0);
        }
        grabo = fwrite(this, sizeof(Personal), 1, f);
        fclose(f);
        return grabo;

}

bool Personal::leerDisco(){
 bool leyo;

FILE *f;
f = fopen("Personal.dat", "rb");
if (f == NULL){
return false;
}

leyo = fread(this, sizeof(Personal), 1, f);
fclose(f);

return leyo;

}

bool Personal::leerDisco(int pos){
 bool leyo=false;

FILE *f;
f = fopen("Personal.dat", "rb");
if (f == NULL){
msj("***NO SE PUEDO ABRIR EL ARCHIVO***", rlutil::WHITE, rlutil::RED);
return leyo;
}

fseek(f, pos * sizeof(Personal), 0);
leyo = fread(this, sizeof(Personal), 1, f);
fclose(f);


return leyo;

}




///FUNCIONES GLOBALES DE CLASE PERSONAL
bool mostrarDetallesLaboral(){

    Personal reg;
    Personas aux;
    int legajo, legajovalidado;
    int x=6, y=5, i=0;
    char sigue, continuar;

setlocale(LC_ALL,"spanish");
title("MOSTRAR DETALLES LABORALES", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);


gotoxy(x,y);
cout<<"LEGAJO: ";
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
cout<<"INGRESE NUEVAMENTE EL LEGAJO: ";
cin>>legajo;
legajovalidado=validarLegajo(legajo);

}else {return false;}

}
///FIN DE LA VALIDACION

while (reg.leerDisco(i++)){
    int j=0;
        while(aux.leerDisco(j++)){
            if(strcmp(reg.getDni(),aux.getDni())==0 && reg.getLegajo()==legajo){

cout << left;
gotoxy(x,++y);
setColor(YELLOW);
cout << "LEGAJO: ";
setColor(LIGHTCYAN);
cout<< reg.getLegajo()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "APELLIDO/S: ";
setColor(LIGHTCYAN);
cout<< aux.getApellidos()<<endl;
setColor(YELLOW);
gotoxy(x,++y);
cout << "NOMBRE/S: ";
setColor(LIGHTCYAN);
cout<< aux.getNombres()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "ESPECIALIDAD: ";
setColor(LIGHTCYAN);
cout<< reg.getEspecialidad()<<endl;
setColor(YELLOW);
gotoxy(x,++y);
cout << "TURNO: ";
setColor(LIGHTCYAN);
cout<< reg.getTurno()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "CATEGORÍA: ";
setColor(LIGHTCYAN);
cout<< reg.getCategoria()<<endl;
gotoxy(x,++y);
setColor(YELLOW);
cout << "ESTADO ACTUAL: ";
setColor(LIGHTCYAN);
if(reg.getEstado()==true){cout<< "TRABAJA";}else{cout<<"NO TRABAJA";}

}
}
}
}

int buscarPosicion(int legajo){
    Personal aux;
    int i=0;

    while (aux.leerDisco(i++)){
    if(aux.getLegajo()==legajo ){
    return i;
    }
  }
}

void listarPersonal(){
        Personal aux;
        Personas persona;
        int i=0;
        int x=6, y=5;

        system("cls");
        setlocale(LC_ALL,"spanish");
        title("LISTADO DE TODO EL PERSONAL", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        recuadro(2,2,127,27);
        recuadro(4,3,123,25);
        cout << left;
        setColor(YELLOW);
        gotoxy(x,y);
        cout << setw(10) << "LEGAJO"<< setw(20) << "APELLIDO/S" << setw(20) << "NOMBRE/S" << setw(20) << "ESPECIALIDAD" << setw(25) << "CATEGORIA"<< setw(10) <<"TURNO" << setw(15) <<"ESTADO";
        setColor(LIGHTCYAN);
        gotoxy(x,++y);
        cout<< "------------------------------------------------------------------------------------------------------------------------";
        while (aux.leerDisco(i++)){
                int j=0;
            while(persona.leerDisco(j++)){
                if(strcmp(aux.getDni(),persona.getDni())==0){
                setColor(WHITE);
                gotoxy(x,++y);
                cout << setw(10) << aux.getLegajo();
                cout << setw(20) << persona.getApellidos();
                cout << setw(20) << persona.getNombres();
                cout << setw(20) << aux.getEspecialidad();
                cout << setw(25) << aux.getCategoria();
                cout << setw(10) << aux.getTurno();
                if (aux.getEstado()==1){cout << setw(15) <<"Trabaja";}else{cout << setw(15) <<"No Trabaja";}

                }
            }
        }


    }

int validarLegajo(int legajo){
Personal aux;
int i = 0;

if (aux.leerDisco()==false){return -1;}else{

    while (aux.leerDisco(i++)){
    if(aux.getLegajo() == legajo){
    return 1;
    }
  }
}
return 0;
}

bool modificar_x_legajo(){

    Personal aux;
    char especialidad[20];
    char turno[20];
    char categoria[30];
    char sigue, continuar, confirma, eleccion;
    int x=6, y=5, legajo, opcion, pos, legajovalidado;
    bool ok=true;
    char vec[5][20]={"Electrico","Mecanico","Electromecanico","Electronico","Herrero"};
    char vec3[7][30]={"Ayudante","Medio Oficial","Oficial", "Oficial Multiple","Administrativo Tecnico","Supervisor","Jefe de Mantenimiento"};
    char vec2[3][20]={"Manana","Tarde","Noche"};


system ("cls");
setlocale(LC_ALL,"spanish");
title("MODIFICACION DE DATOS LABORALES", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);

gotoxy(x,y);
cout<<"NRO. DE LEGAJO: ";
cin>>legajo;

legajovalidado=validarLegajo(legajo);

///SE VALIDA EL LEGAJO
while(legajovalidado!=1){
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
cout<<"INGRESE NUEVAMENTE EL NRO. LEGAJO: ";
cin>>legajo;
legajovalidado=validarLegajo(legajo);
}else {return false;}

}
///FIN DE LA VALIDACION


pos=buscarPosicion(legajo);
aux.leerDisco(pos-1);
aux.mostrarconEstado();

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
cout << setw(25) << "1. ESPECIALIDAD" << setw(25) << "2. CATEGORIA"<< setw(10) <<"3. TURNO";
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
cout<<"ESPECIALIDAD: ";
gotoxy(x,++y);
setColor(YELLOW);
cout << setw(20) << "1.Electrico" << setw(20) << "2.Mecanico" << setw(20) << "3.Electromecanico"<< setw(20) <<"4.Electronico"<< setw(20)<<"5.Herrero";
setColor(WHITE);
gotoxy(x,++y);
cout<<"ELIJA UNA OPCION (1-5): ";
cin>>opcion;

///SE VALIDA LA ELECCION DE ESPECIALIDAD
while (!(opcion>0 && opcion<=5)){
    msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);
    setColor(WHITE);
    gotoxy(x,++y);
    cout<<"ELIJA UNA OPCION (1-5): ";
    cin>>opcion;
}
///FIN DE LA VALIDACION

gotoxy(x,++y);
cout<<"CONFIRMA EL CAMBIO REALIZADO S/N?: ";
cin>>eleccion;
confirma=towupper(eleccion);
if(confirma=='S'){
aux.setEspecialidad(vec[opcion-1]);
aux.escribirDisco(pos-1);
return ok;
}
opcion=0;

break;

case (2):

gotoxy(x,++y);
cout<<"CATEGORIA: ";
gotoxy(x,++y);
setColor(YELLOW);
cout << setw(20) << "1.Ayudante" << setw(20) << "2.Medio Oficial" << setw(20) << "3.Oficial"<< setw(20) <<"4.Oficial Multiple";
gotoxy(x,++y);
cout << setw(30) << "5.Administrativo Tecnico" << setw(20) << "6.Supervisor" << setw(30) << "7.Jefe de Mantenimiento";
setColor(WHITE);
gotoxy(x,++y);
cout<<"ELIJA UNA OPCION (1-7): ";
cin>>opcion;

///SE VALIDA LA ELECCION DE TURNO
while (!(opcion>0 && opcion<=7)){
    msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);
    setColor(WHITE);
    gotoxy(x,++y);
    cout<<"ELIJA UNA OPCION (1-7): ";
    cin>>opcion;
}
///FIN DE LA VALIDACION

gotoxy(x,++y);
cout<<"CONFIRMA EL CAMBIO REALIZADO S/N?: ";
cin>>eleccion;
confirma=towupper(eleccion);
if(confirma=='S'){
aux.setCategoria(vec3[opcion-1]);
aux.escribirDisco(pos-1);
return ok;
}
opcion=0;
break;

case (3):

gotoxy(x,++y);
cout<<"TURNO: ";
gotoxy(x,++y);
setColor(YELLOW);
cout << setw(20) << "1.Manana" << setw(20) << "2.Tarde" << setw(20) << "3.Noche";
setColor(WHITE);
gotoxy(x,++y);
cout<<"ELIJA UNA OPCION (1-3): ";
cin>>opcion;

///SE VALIDA LA ELECCION DE TURNO
while (!(opcion>0 && opcion<=3)){
    msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);
    setColor(WHITE);
    gotoxy(x,++y);
    cout<<"ELIJA UNA OPCION (1-3): ";
    cin>>opcion;
}
///FIN DE LA VALIDACION

gotoxy(x,++y);
cout<<"CONFIRMA EL CAMBIO REALIZADO S/N?: ";
cin>>eleccion;
confirma=towupper(eleccion);
if(confirma=='S'){
aux.setTurno(vec2[opcion-1]);
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
        }while (!(opcion>=0 && opcion<=3));


    break;

}


}while(opcion>0 && opcion<=3);

}

bool bajaLogica(){

Personal aux;
char sigue, continuar, confirma, eleccion;
int x=6, y=5, legajo, opcion, pos, legajovalidado;


system ("cls");
setlocale(LC_ALL,"spanish");
title("REALIZACION DE BAJA LOGICA DE UN EMPLEADO POR LEGAJO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
recuadro(2,2,127,27);
recuadro(4,3,123,25);

gotoxy(x,y);
cout<<"NRO. DE LEGAJO: ";
cin>>legajo;

legajovalidado=validarLegajo(legajo);

///SE VALIDA EL LEGAJO
while(legajovalidado!=1){
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
cout<<"INGRESE NUEVAMENTE EL NRO. LEGAJO: ";
cin>>legajo;
legajovalidado=validarLegajo(legajo);
}else {return false;}

}
///FIN DE LA VALIDACION


pos=buscarPosicion(legajo);
aux.leerDisco(pos-1);
aux.mostrarconEstado();

x=6;
y=10;

gotoxy(x,y);
setColor(LIGHTRED);
cout<<"NOTA: ";
setColor(YELLOW);
cout<<"REALIZANDO LA BAJA SOLO SE CAMBIARA EL ESTADO DEL EMPLEADO";

x=6;
y=12;

gotoxy(x,++y);
setColor(WHITE);
cout<<"CONFIRMA LA BAJA DEL EMPLEADO S/N?: ";
cin>>eleccion;
confirma=towupper(eleccion);
if(confirma=='S'){
aux.setEstado(false);
aux.escribirDisco(pos-1);
return true;

}
return false;
}

