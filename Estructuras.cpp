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

void mostrar_fecha_estructura(Fecha_Estructura reg){
    cout << reg.dia<< "/" << reg.mes << "/" << reg.anio << endl;
}

Fecha_Estructura hoy(){
Fecha_Estructura reg;

time_t tm;
tm = time(NULL);
struct tm *f;
f=localtime(&tm);

reg.dia= f->tm_mday;
reg.mes= f->tm_mon+1;
reg.anio= f->tm_year+1900;

return reg;

}
