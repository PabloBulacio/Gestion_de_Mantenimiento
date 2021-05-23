#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

float devoluciones(int, int, int, int);
int devolucionesCant(Fecha, Fecha, int);
float consumoPorMaquina(Fecha, Fecha, char *);
float consumoPorMaquinaClasificado(Fecha, Fecha, char *, char *);
int cantRepMaquina(Fecha, Fecha, char *);
int cantRepMaquinaClasificado(Fecha, Fecha, char *, char *);
int cantRepPrecio(Fecha, Fecha,int, int);
bool informeAnual();
bool informePorMaquinas();
bool informePorCriticidad();
bool informePorClasificado();
bool informeRepuestosPrecio();



#endif // INFORMES_H_INCLUDED
