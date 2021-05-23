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

void menu_principal(){

    int opc, opcion;
    bool guardo, eliminado;

    initUI();
    title("", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);




    do {
            system("cls");
            setlocale(LC_ALL,"spanish");
            title("GESTIÓN DE MANTENIMIENTO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);


            recuadro(2,2,127,27);
            recuadro(4,3,123,25);
            gotoxy(55, 10);
            setColor(WHITE);
            cout<<"1) PERSONAL"<<endl;
            gotoxy(55, 11);
            cout<<"2) REPUESTOS"<<endl;
            gotoxy(55, 12);
            cout<<"3) STOCK"<<endl;
            gotoxy(55, 13);
            cout<<"4) ORDENES DE TRABAJO"<<endl;
            gotoxy(55, 14);
            cout<<"5) MAQUINAS"<<endl;
            gotoxy(55, 15);
            cout<<"6) INFORMES"<<endl;
            gotoxy(55, 16);
            cout<<"7) CONFIGURACION"<<endl;
            gotoxy(55, 18);
            setColor(WHITE);
            cout<<"0) SALIR DEL PROGRAMA"<<endl;
            cout<<endl<<endl;
            gotoxy(55, 20);
            setColor(LIGHTCYAN);
            cout<<"ELIJA UNA OPCION: ";
            setColor(WHITE);
            cin>>opc;


         switch (opc){
            case (1):menu_personal();
                break;
            case (2):menu_repuestos();
                break;
            case (3):menu_stock();
                break;
            case (4):menu_ordenesTrabajo();
                break;
            case (5):menu_maquinas();
                break;
            case (6):menu_informes();
                break;
            case (7):menu_configuracion();
                break;
            case (0): cls();
                break;
            default:
                    msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);
                break;

            }
    }while (opc!=0);
}

void menu_personal(){
    Personal nuevo, *p;
    Personas nuevapersona, *np;

    int opcion;
    bool cargo, escribio, guardo, modificado, bajaok;

    p=&nuevo;
    np=&nuevapersona;

 do{


            system ("cls");
            setlocale(LC_ALL,"spanish");
            title("MENÚ PERSONAL", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);

            recuadro(2,2,127,27);
            recuadro(4,3,123,25);

            gotoxy(55, 10);
            setColor(WHITE);
            cout<<"1) NUEVO PERSONAL"<<endl;
            gotoxy(55, 11);
            cout<<"2) MODIFICAR DATOS PERSONALES POR DNI"<<endl;
            gotoxy(55, 12);
            cout<<"3) MODIFICAR DATOS LABORALES POR LEGAJO"<<endl;
            gotoxy(55, 13);
            cout<<"4) MOSTRAR DATOS PERSONALES POR DNI"<<endl;
            gotoxy(55, 14);
            cout<<"5) LISTAR DATOS PERSONALES"<<endl;
            gotoxy(55, 15);
            cout<<"6) MOSTRAR DATOS LABORALES POR LEGAJO"<<endl;
            gotoxy(55, 16);
            cout<<"7) LISTAR DATOS LABORALES"<<endl;
            gotoxy(55, 17);
            cout<<"8) DAR DE BAJA"<<endl;
            gotoxy(55, 19);
            setColor(WHITE);
            cout<<"0) VOLVER AL MENÚ ANTERIOR"<<endl;
            cout<<endl<<endl;
            gotoxy(55, 21);
            setColor(LIGHTCYAN);
            cout<<"ELIJA UNA OPCION: ";
            setColor(WHITE);
            cin>>opcion;


        switch (opcion){
                    case 1:cargo=nuevo.cargar(p, np);
                        if (cargo==true){
                            escribio=nuevapersona.escribirDisco();
                            if (escribio==true){
                                guardo=nuevo.escribirDisco();
                                if (guardo==true){msj("**EL NUEVO PERSONAL SE GUARDO CON EXITO**", rlutil::WHITE, rlutil::GREEN);} else{msj("***NO SE PUDO GUARDAR EN EL DISCO CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                            }else{msj("***NO SE PUDO GUARDAR CORRECTAMENTE LA PERSONA***", rlutil::WHITE, rlutil::RED);}
                                        }else{msj("***NO SE PUDO CARGAR CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                    break;
                    case 2: modificado=modificar_x_dni();
                                if (modificado==true){
                                    msj("**LOS CAMBIOS SE GUARDARON CON EXITO**", rlutil::WHITE, rlutil::GREEN);
                                }else{msj("***NO SE PUDO REALIZAR LOS CAMBIOS CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                    break;
                    case 3: modificado=modificar_x_legajo();
                                if (modificado==true){
                                    msj("**LOS CAMBIOS SE GUARDARON CON EXITO**", rlutil::WHITE, rlutil::GREEN);
                                }else{msj("***NO SE PUDO REALIZAR LOS CAMBIOS CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                        break;
                    case 4: mostrarDetallesPersonas();
                            system("pause>null");
                        break;
                    case 5: listarPersonas();
                            system("pause>null");
                        break;
                    case 6: mostrarDetallesLaboral();
                            system("pause>null");
                        break;
                    case 7: listarPersonal();
                            system("pause>null");
                        break;
                    case 8: bajaok=bajaLogica();
                            if (bajaok==true){
                                    msj("**LA BAJA SE REALIZO CON EXITO**", rlutil::WHITE, rlutil::GREEN);
                                }else{msj("***NO SE PUDO REALIZAR LA BAJA CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}

                        break;
                    case 0: cls();
                        break;
                    default:
                         msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);

                        break;


                    }
                    }while(opcion!=0);

}

void menu_repuestos(){

    Repuestos nuevo;

    bool cargo, escribio, guardo, modificado, bajaok;
    int opcion;



 do{

            system ("cls");
            setlocale(LC_ALL,"spanish");
            title("MENÚ REPUESTOS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);

            recuadro(2,2,127,27);
            recuadro(4,3,123,25);

            gotoxy(55, 10);
            setColor(WHITE);
            cout<<"1) NUEVO REPUESTO"<<endl;
            gotoxy(55,11);
            cout<<"2) MODIFICAR REPUESTO POR NRO. PARTE"<<endl;
            gotoxy(55, 12);
            cout<<"3) MOSTRAR REPUESTO POR NRO. PARTE"<<endl;
             gotoxy(55, 13);
            cout<<"4) LISTADO DE REPUESTOS"<<endl;
            gotoxy(55, 15);
            setColor(WHITE);
            cout<<"0) VOLVER AL MENÚ ANTERIOR"<<endl;
            cout<<endl<<endl;
            gotoxy(55, 17);
            setColor(LIGHTCYAN);
            cout<<"ELIJA UNA OPCION: ";
            setColor(WHITE);
            cin>>opcion;


        switch (opcion){
                    case (1): cargo=nuevo.cargar();
                                if (cargo==true){
                                guardo=nuevo.escribirDisco();
                                if (guardo==true){msj("**EL NUEVO REPUESTO SE GUARDO CON EXITO**", rlutil::WHITE, rlutil::GREEN);} else{msj("***NO SE PUDO GUARDAR EN EL DISCO CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                                }else{msj("***NO SE PUDO CARGAR CORRECTAMENTE EL REPUESTO***", rlutil::WHITE, rlutil::RED);}

                        break;
                    case (2):modificado=modificar_repuestos();
                                if (modificado==true){
                                    msj("**LOS CAMBIOS SE GUARDARON CON EXITO**", rlutil::WHITE, rlutil::GREEN);
                                }else{msj("***NO SE PUDO REALIZAR LOS CAMBIOS CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                        break;
                    case (3):mostrarDetallesRepuestos();
                              system("pause>null");
                        break;
                    case (4):listarRepuestos();
                              system("pause>null");
                        break;
                    case (0): cls();
                        break;
                    default:
                         msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);

                        break;


                    }
                    }while(opcion!=0);

}

void menu_vale_entrada(){

    valeEntradaSalida nuevo;
    int opcion;
    bool cargo, guardo;


 do{

            system ("cls");
            setlocale(LC_ALL,"spanish");
            title("MENÚ VALE DE ENTRADA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);

            recuadro(2,2,127,27);
            recuadro(4,3,123,25);

            gotoxy(55, 10);
            setColor(WHITE);
            cout<<"1) NUEVO VALE DE ENTRADA"<<endl;
            gotoxy(55,11);
            cout<<"2) LISTAR POR NRO. VALE"<<endl;
            gotoxy(55,12);
            cout<<"3) LISTAR POR OT"<<endl;
            gotoxy(55, 13);
            cout<<"4) CONSULTAR NÚMERO DE VALE"<<endl;
            gotoxy(55, 14);
            cout<<"5) CONSULTAR NRO. VALE POR FECHA"<<endl;
            gotoxy(55, 16);
            setColor(WHITE);
            cout<<"0) VOLVER AL MENÚ ANTERIOR"<<endl;
            cout<<endl<<endl;
            gotoxy(55, 18);
            setColor(LIGHTCYAN);
            cout<<"ELIJA UNA OPCION: ";
            setColor(WHITE);
            cin>>opcion;


        switch (opcion){
                    case (1): cargo=nuevo.cargar(true);
                                if (cargo==true){
                                guardo=nuevo.escribirDisco();
                                if (guardo==true){
                                actualizarStock(nuevo, true);
                                msj("**EL NUEVO VALE SE GUARDO CON EXITO**", rlutil::WHITE, rlutil::GREEN);} else{msj("***NO SE PUDO GUARDAR EN EL DISCO CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                                }else{msj("***NO SE PUDO CARGAR CORRECTAMENTE EL VALE***", rlutil::WHITE, rlutil::RED);}
                        break;
                    case (2):   listarNroVale(true);
                                system("pause>null");
                        break;
                    case (3):   ordenarValeOt(true);
                                system("pause>null");
                        break;
                    case (4):   consultaNroVale(true);
                                system("pause>null");
                        break;
                    case (5):   consultaNroValeFecha(true);
                                system("pause>null");
                        break;
                    case (0): cls();
                        break;
                    default:
                         msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);

                        break;


                    }
                    }while(opcion!=0);

}

void menu_vale_salida(){

    valeEntradaSalida nuevo;
    int opcion;
    bool cargo, guardo;


 do{

            system ("cls");
            setlocale(LC_ALL,"spanish");
            title("MENÚ VALE DE SALIDA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);

            recuadro(2,2,127,27);
            recuadro(4,3,123,25);

            gotoxy(55, 10);
            setColor(WHITE);
            cout<<"1) NUEVO VALE DE SALIDA"<<endl;
            gotoxy(55,11);
            cout<<"2) LISTAR POR NRO. VALE"<<endl;
            gotoxy(55,12);
            cout<<"3) LISTAR POR OT"<<endl;
            gotoxy(55, 13);
            cout<<"4) CONSULTAR NÚMERO DE VALE"<<endl;
            gotoxy(55, 14);
            cout<<"5) CONSULTAR NRO. VALE POR FECHA"<<endl;
            gotoxy(55, 16);
            setColor(WHITE);
            cout<<"0) VOLVER AL MENÚ ANTERIOR"<<endl;
            cout<<endl<<endl;
            gotoxy(55, 18);
            setColor(LIGHTCYAN);
            cout<<"ELIJA UNA OPCION: ";
            setColor(WHITE);
            cin>>opcion;


        switch (opcion){
                    case (1): cargo=nuevo.cargar(false);
                                if (cargo==true){
                                guardo=nuevo.escribirDisco();
                                if (guardo==true){
                                actualizarStock(nuevo, false);
                                msj("**EL NUEVO VALE SE GUARDO CON EXITO ACTUALIZANDO EL STOCK**", rlutil::WHITE, rlutil::GREEN);} else{msj("***NO SE PUDO GUARDAR EN EL DISCO CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                                }else{msj("***NO SE PUDO CARGAR CORRECTAMENTE EL VALE***", rlutil::WHITE, rlutil::RED);}
                        break;
                    case (2):   listarNroVale(false);
                                system("pause>null");
                        break;
                    case (3):   ordenarValeOt(false);
                                system("pause>null");
                        break;
                    case (4):   consultaNroVale(false);
                                system("pause>null");
                        break;
                    case (5):   consultaNroValeFecha(false);
                                system("pause>null");
                        break;
                    case (0): cls();
                        break;
                    default:
                         msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);

                        break;


                    }
                    }while(opcion!=0);

}

void menu_stock(){
    Stock nuevo;
    bool cargo, guardo;
    int opcion;


 do{

            system ("cls");
            setlocale(LC_ALL,"spanish");
            title("MENÚ STOCK", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);

            recuadro(2,2,127,27);
            recuadro(4,3,123,25);

            gotoxy(55, 10);
            setColor(WHITE);
            cout<<"1) NUEVO ITEM AL STOCK"<<endl;
            gotoxy(55,11);
            cout<<"2) MOSTRAR ITEM POR NRO. PARTE"<<endl;
            gotoxy(55,12);
            cout<<"3) VALE DE ENTRADA"<<endl;
            gotoxy(55,13);
            cout<<"4) VALE DE SALIDA"<<endl;
            gotoxy(55, 14);
            cout<<"5) ORDENAR STOCK POR..."<<endl;
            gotoxy(55, 15);
            cout<<"6) LISTAR STOCK EXCEDIDO"<<endl;
            gotoxy(55, 17);
            setColor(WHITE);
            cout<<"0) VOLVER AL MENÚ ANTERIOR"<<endl;
            cout<<endl<<endl;
            gotoxy(55, 19);
            setColor(LIGHTCYAN);
            cout<<"ELIJA UNA OPCION: ";
            setColor(WHITE);
            cin>>opcion;


        switch (opcion){
                    case (1): cargo=nuevo.cargar();
                                if (cargo==true){
                                guardo=nuevo.escribirDisco();
                                if (guardo==true){msj("**EL ITEM SE GUARDO CON EXITO**", rlutil::WHITE, rlutil::GREEN);} else{msj("***NO SE PUDO GUARDAR EN EL DISCO CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                                }else{msj("***NO SE PUDO CARGAR CORRECTAMENTE EL ITEM AL STOCK***", rlutil::WHITE, rlutil::RED);}


                        break;
                    case (2):   mostrarDetallesStock();
                                system("pause>null");
                        break;
                    case (3):   menu_vale_entrada();
                        break;
                    case (4):   menu_vale_salida();
                        break;
                    case (5):   ordenarStock();
                                system("pause>null");
                        break;
                    case (6):   listarStockExcedido();
                                system("pause>null");
                        break;
                    case (0): cls();
                        break;
                    default:
                         msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);

                        break;


                    }
                    }while(opcion!=0);

}

void menu_maquinas(){

    Maquinas nuevo;
    int opcion;
    bool cargo, escribio, guardo, modificado, bajaok;



 do{


            system ("cls");
            setlocale(LC_ALL,"spanish");
            title("MENÚ DE LOS EQUIPOS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);

            recuadro(2,2,127,27);
            recuadro(4,3,123,25);

            gotoxy(55, 10);
            setColor(WHITE);
            cout<<"1) ALTA DE UN NUEVO EQUIPO"<<endl;
            gotoxy(55, 11);
            cout<<"2) MOSTRAR DATOS DE UN EQUIPO"<<endl;
            gotoxy(55, 12);
            cout<<"3) LISTAR TODOS LOS EQUIPOS"<<endl;
            gotoxy(55, 17);
            setColor(WHITE);
            cout<<"0) VOLVER AL MENÚ ANTERIOR"<<endl;
            cout<<endl<<endl;
            gotoxy(55, 19);
            setColor(LIGHTCYAN);
            cout<<"ELIJA UNA OPCION: ";
            setColor(WHITE);
            cin>>opcion;


        switch (opcion){
                    case 1:cargo=nuevo.cargar();
                            if (cargo==true){
                                guardo=nuevo.escribirDisco();
                                if (guardo==true){msj("**EL NUEVO EQUIPO SE GUARDO CON EXITO**", rlutil::WHITE, rlutil::GREEN);} else{msj("***NO SE PUDO GUARDAR EN EL DISCO CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                            }else{msj("***NO SE PUDO CARGAR CORRECTAMENTE EL EQUIPO***", rlutil::WHITE, rlutil::RED);}

                    break;
                    case 2:mostrarDetallesMaquinas();
                           system("pause>null");
                        break;
                    case 3: listarMaquinas();
                            system("pause>null");
                        break;
                    case 0: cls();
                        break;
                    default:
                         msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);
                         break;


                    }
                    }while(opcion!=0);

}

void menu_ordenesTrabajo(){
    OT nueva;
    int opcion;
    bool cargo, escribio, guardo, modificado, bajaok, cerrado;


 do{

            system ("cls");
            setlocale(LC_ALL,"spanish");
            title("MENÚ ORDENES DE TRABAJO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);

            recuadro(2,2,127,27);
            recuadro(4,3,123,25);

            gotoxy(55, 10);
            setColor(WHITE);
            cout<<"1) GENERAR ORDEN DE TRABAJO"<<endl;
            gotoxy(55,11);
            cout<<"2) CERRAR ORDENES DE TRABAJO"<<endl;
            gotoxy(55, 12);
            cout<<"3) MOSTRAR OT"<<endl;
            gotoxy(55, 13);
            cout<<"4) LISTAR OT"<<endl;
            gotoxy(55, 15);
            setColor(WHITE);
            cout<<"0) VOLVER AL MENÚ ANTERIOR"<<endl;
            cout<<endl<<endl;
            gotoxy(55, 17);
            setColor(LIGHTCYAN);
            cout<<"ELIJA UNA OPCION: ";
            gotoxy(73, 17);
            setColor(WHITE);
            cin>>opcion;

        switch (opcion){
                    case (1):cargo=nueva.cargar();
                                if (cargo==true){
                                guardo=nueva.escribirDisco();
                                if (guardo==true){msj("**LA NUEVA OT SE GUARDO CON EXITO**", rlutil::WHITE, rlutil::GREEN);} else{msj("***NO SE PUDO GUARDAR EN EL DISCO CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                            }else{msj("***NO SE PUDO CARGAR CORRECTAMENTE LA OT***", rlutil::WHITE, rlutil::RED);}
                        break;
                    case (2):cerrado=cerrarOT();
                                if (cerrado==true){
                                    msj("**LA OT ESTA CUMPLIDA**", rlutil::WHITE, rlutil::GREEN);
                                }else{msj("***NO SE PUDO CUMPLIR LA OT CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}

                        break;
                    case (3):mostrarDetalles();
                            system("pause>null");
                        break;
                    case (4):listarOT();
                            system("pause>null");
                        break;
                    case (0): cls();
                        break;
                    default:
                         msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);

                        break;


                    }
                    }while(opcion!=0);

}

void menu_informes(){

    int opcion;


 do{

            system ("cls");
            setlocale(LC_ALL,"spanish");
            title("MENÚ INFORMES", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);

            recuadro(2,2,127,27);
            recuadro(4,3,123,25);

            gotoxy(55, 10);
            setColor(WHITE);
            cout<<"1) INFORME DE CONSUMO ANUAL "<<endl;
            gotoxy(55,11);
            cout<<"2) INFORME DE CONSUMO POR MÁQUINA"<<endl;
            gotoxy(55, 12);
            cout<<"3) INFORME DE CONSUMO SEGÚN CLASIFICACIÓN"<<endl;
            gotoxy(55, 13);
            cout<<"4) INFORME DE CONSUMO SEGÚN RANGO DE PRECIO"<<endl;
            gotoxy(55, 16);
            setColor(WHITE);
            cout<<"0) VOLVER AL MENÚ ANTERIOR"<<endl;
            cout<<endl<<endl;
            gotoxy(55, 18);
            setColor(LIGHTCYAN);
            cout<<"ELIJA UNA OPCION: ";
            gotoxy(73, 18);
            setColor(WHITE);
            cin>>opcion;


        switch (opcion){
                    case (1): informeAnual();
                                system("pause>null");
                        break;
                    case (2): informePorMaquinas();
                                system("pause>null");
                        break;
                    case (3): informePorClasificado();
                                system("pause>null");
                        break;
                    case (4): informeRepuestosPrecio();
                                system("pause>null");
                        break;
                    case (0): cls();
                        break;
                    default:
                         msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);

                        break;
                    }
    }while(opcion!=0);

}

void menu_configuracion(){

    int opcion;



 do{

            system ("cls");
            setlocale(LC_ALL,"spanish");
            title("MENÚ CONFIGURACION", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);

            recuadro(2,2,127,27);
            recuadro(4,3,123,25);

            gotoxy(55, 10);
            setColor(WHITE);
            cout<<"1) REALIZAR COPIAS DE SEGURIDAD"<<endl;
            gotoxy(55,11);
            cout<<"2) RESTAURAR COPIAS DE SEGURIDAD"<<endl;
            gotoxy(55, 12);
            cout<<"3) EXPORTAR DATOS"<<endl;
            gotoxy(55, 16);
            setColor(WHITE);
            cout<<"0) VOLVER AL MENÚ ANTERIOR"<<endl;
            cout<<endl<<endl;
            gotoxy(55, 18);
            setColor(LIGHTCYAN);
            cout<<"ELIJA UNA OPCION: ";
            gotoxy(73, 18);
            setColor(WHITE);
            cin>>opcion;


        switch (opcion){
                    case (1): menu_realizar_copias();
                                system("pause>null");
                        break;
                    case (2): menu_restaurar_copias();
                                system("pause>null");
                        break;
                    case (3): menu_exportar_datos();
                                system("pause>null");
                        break;
                    case (0): cls();
                        break;
                    default:
                         msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);

                        break;


                    }
                    }while(opcion!=0);


}

void menu_realizar_copias(){

    int opcion;
    bool ok, nuevo=true;


 do{

            system ("cls");
            setlocale(LC_ALL,"spanish");
            title("MENÚ COPIAS DE SEGURIDAD", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);

            recuadro(2,2,127,27);
            recuadro(4,3,123,25);

            gotoxy(55, 10);
            setColor(WHITE);
            cout<<"1) PERSONAS"<<endl;
            gotoxy(55,11);
            cout<<"2) PERSONAL"<<endl;
            gotoxy(55, 12);
            cout<<"3) MAQUINAS"<<endl;
            gotoxy(55, 13);
            cout<<"4) REPUESTOS"<<endl;
            gotoxy(55, 14);
            cout<<"5) OT"<<endl;
            gotoxy(55, 15);
            cout<<"6) STOCK"<<endl;
            gotoxy(55, 16);
            cout<<"7) VALE DE ENTRADA/SALIDA E ITEMS"<<endl;
            gotoxy(55, 17);
            cout<<"8) TODOS LOS ARCHIVOS"<<endl;
            gotoxy(55, 19);
            setColor(WHITE);
            cout<<"0) VOLVER AL MENÚ ANTERIOR"<<endl;
            cout<<endl<<endl;
            gotoxy(55, 21);
            setColor(LIGHTCYAN);
            cout<<"ELIJA UNA OPCION: ";
            gotoxy(73, 21);
            setColor(WHITE);
            cin>>opcion;


        switch (opcion){
                    case (1):   ok=copiarPersonas(nuevo);
                    if (ok==false){msj("***NO SE PUDO COPIAR PERSONAS CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                        break;
                    case (2):   ok=copiarPersonal(nuevo);
                    if (ok==false){msj("***NO SE PUDO COPIAR PERSONAL CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                        break;
                    case (3):   ok=copiarMaquinas(nuevo);
                    if (ok==false){msj("***NO SE PUDO COPIAR MAQUINAS CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                        break;
                    case (4):   ok=copiarRepuestos(nuevo);
                    if (ok==false){msj("***NO SE PUDO COPIAR REPUESTOS CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                        break;
                    case (5):   ok=copiarOt(nuevo);
                    if (ok==false){msj("***NO SE PUDO COPIAR OT CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                        break;
                    case (6):   ok=copiarStock(nuevo);
                    if (ok==false){msj("***NO SE PUDO COPIAR STOCK CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                        break;
                    case (7):   ok=copiarValeEntradaSalida(nuevo);
                    if (ok==false){msj("***NO SE PUDO COPIAR VALE DE ENTRADA/SALIDA E ITEMS CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                        break;
                    case (8):   copiarTodo();
                        break;
                    case (0):
                        break;
                    default:
                         msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);
                        break;
                    }
    }while(opcion!=0);


}

void menu_restaurar_copias(){

    int opcion;
    bool ok, nuevo=true;



 do{

            system ("cls");
            setlocale(LC_ALL,"spanish");
            title("MENÚ RESTAURAR COPIAS DE SEGURIDAD", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);

            recuadro(2,2,127,27);
            recuadro(4,3,123,25);

            gotoxy(55, 10);
            setColor(WHITE);
            cout<<"1) PERSONAS"<<endl;
            gotoxy(55,11);
            cout<<"2) PERSONAL"<<endl;
            gotoxy(55, 12);
            cout<<"3) MAQUINAS"<<endl;
            gotoxy(55, 13);
            cout<<"4) REPUESTOS"<<endl;
            gotoxy(55, 14);
            cout<<"5) OTs"<<endl;
            gotoxy(55, 15);
            cout<<"6) STOCK"<<endl;
            gotoxy(55, 16);
            cout<<"7) VALE DE ENTRADA/SALIDA E ITEMS"<<endl;
            gotoxy(55, 17);
            cout<<"8) TODOS LOS ARCHIVOS"<<endl;
            gotoxy(55, 19);
            setColor(WHITE);
            cout<<"0) VOLVER AL MENÚ ANTERIOR"<<endl;
            cout<<endl<<endl;
            gotoxy(55, 21);
            setColor(LIGHTCYAN);
            cout<<"ELIJA UNA OPCION: ";
            gotoxy(73, 21);
            setColor(WHITE);
            cin>>opcion;


        switch (opcion){
                    case (1):   ok=restaurarPersonas(nuevo);
                    if (ok==false){msj("***NO SE PUDO RESTAURAR PERSONAS CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                        break;
                    case (2):   ok=restaurarPersonal(nuevo);
                    if (ok==false){msj("***NO SE PUDO RESTAURAR PERSONAL CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                        break;
                    case (3):   ok=restaurarMaquinas(nuevo);
                    if (ok==false){msj("***NO SE PUDO RESTAURAR MAQUINAS CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                        break;
                    case (4):   ok=restaurarRepuestos(nuevo);
                    if (ok==false){msj("***NO SE PUDO RESTAURAR REPUESTOS CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                        break;
                    case (5):   ok=restaurarOt(nuevo);
                    if (ok==false){msj("***NO SE PUDO RESTAURAR OT CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                        break;
                    case (6):   ok=restaurarStock(nuevo);
                    if (ok==false){msj("***NO SE PUDO RESTAURAR STOCK CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                        break;
                    case (7):   ok=restaurarValeEntradaSalida(nuevo);
                    if (ok==false){msj("***NO SE PUDO RESTAURAR VALE DE ENTRADA/SALIDA E ITEMS CORRECTAMENTE***", rlutil::WHITE, rlutil::RED);}
                        break;
                    case (8):   restaurarTodo();
                        break;
                    case (0):
                        break;
                    default:
                         msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);
                        break;


                    }
    }while(opcion!=0);


}

void menu_exportar_datos(){

    int opcion;


 do{

            system ("cls");
            setlocale(LC_ALL,"spanish");
            title("MENÚ EXPORTAR DATOS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);

            recuadro(2,2,127,27);
            recuadro(4,3,123,25);

            gotoxy(55, 10);
            setColor(WHITE);
            cout<<"1) PERSONAS"<<endl;
            gotoxy(55,11);
            cout<<"2) PERSONAL"<<endl;
            gotoxy(55, 12);
            cout<<"3) MAQUINAS"<<endl;
            gotoxy(55, 13);
            cout<<"4) REPUESTOS"<<endl;
            gotoxy(55, 14);
            cout<<"5) OT"<<endl;
            gotoxy(55, 15);
            cout<<"6) STOCK"<<endl;
            gotoxy(55, 16);
            cout<<"7) VALE DE ENTRADA Y SALIDA"<<endl;
            gotoxy(55, 17);
            cout<<"8) TODOS LOS ARCHIVOS"<<endl;
            gotoxy(55, 19);
            setColor(WHITE);
            cout<<"0) VOLVER AL MENÚ ANTERIOR"<<endl;
            cout<<endl<<endl;
            gotoxy(55, 21);
            setColor(LIGHTCYAN);
            cout<<"ELIJA UNA OPCION: ";
            gotoxy(73, 21);
            setColor(WHITE);
            cin>>opcion;


        switch (opcion){
                    case (1):
                        break;
                    case (2):
                        break;
                    case (3):
                        break;
                    case (4):
                        break;
                    case (5):
                        break;
                    case (6):
                        break;
                    case (7):
                        break;
                    case (8):
                        break;
                    case (0):
                        break;
                    default:
                         msj("***OPCION INCORRECTA***", rlutil::WHITE, rlutil::RED);
                        break;


                    }
    }while(opcion!=0);


}

