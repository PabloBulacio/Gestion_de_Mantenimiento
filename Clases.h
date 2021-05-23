#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED


class Fecha{
    private:
    int dia, mes, anio;
    bool esbisiesto(int);
    void NumeroSerieaFecha(int);

    public:

        int getDia();
        int getMes();
        int getAnio();
        void setDia(int);
        void setMes(int);
        void setAnio(int);
        bool cargar(int, int);
        void mostrar();
        bool escribirDisco(int);
        bool leerDisco(int);
        Fecha();
        void MostrarFechaTexto();
        int NumeroSerie();
        bool operator >=(Fecha &);
        bool operator <=(Fecha &);
        bool operator ==(Fecha &);
        Fecha operator+(int);
        int operator -(Fecha &);
        void operator +=(int);
        int operator==(const char*);
        friend istream & operator>>(istream &, Fecha &);
        friend ostream & operator<<(ostream &, Fecha &);
        int cantDiasMes();
        int cantDiasHabilesMes();
        int cantAniosHastaHoy(int, int, int);

};

class Personas{
protected:
    char Dni[15];
    char Apellidos[50];
    char Nombres[50];
    Fecha FechaNacimiento;
    int Edad;
    char Direccion[50];
    char Telefono[15];

public:

    char* getDni();
    char* getApellidos();
    char* getNombres();
    int getEdad();
    char* getDireccion();
    char* getTelefono();
    Fecha getFechaNacimiento();
    void setDni(char* );
    void setApellidos(char *);
    void setNombres(char *);
    void setEdad(int);
    void setDireccion(char *);
    void setTelefono(char* );
    void setFechaNacimiento(Fecha);
    void modificarFecha(int, int);
    bool cargar(Personas *);
    void mostrar();
    bool escribirDisco(int = -1);
    bool leerDisco();
    bool leerDisco(int);





};

class Personal:public Personas{
private:
    int Legajo;
    char Dni[15];
    char Especialidad[20];
    char Turno[20];
    char Categoria[30];
    bool Estado;

public:
    char* getDni();
    int getLegajo();
    char* getEspecialidad();
    char* getTurno();
    char* getCategoria();
    bool getEstado();
    void setDni(char* );
    void setLegajo(int);
    void setEspecialidad(char *);
    void setTurno(char *);
    void setCategoria(char *);
    void setEstado(bool);
    bool cargar(Personal *a, Personas *b);
    void mostrar(Personas *);
    void mostrar();
    void mostrarconEstado();
    bool escribirDisco(int = -1);
    bool leerDisco();
    bool leerDisco(int);





};

class Maquinas{
private:
    char CodificacionMaquina[15];
    char Tipo[25];
    char Descripcion[50];
    char NumeroSerie[25];
    bool Estado=false;
public:
    char* getCodificacionMaquina();
    char* getTipo();
    char* getDescripcion();
    char* getNumeroSerie();
    bool getEstado();
    void setCodificacionMaquina(char *);
    void setTipo(char *);
    void setDescripcion(char *);
    void setNumeroSerie(char *);
    void setEstado(bool);
    bool cargar();
    void mostrar();
    bool escribirDisco(int = -1);
    bool leerDisco();
    bool leerDisco(int);

};

class OT{
private:
    int Ot=0;
    Fecha FechaGestion;
    Fecha FechaEstimada;
    Fecha FechaCumplida;
    char CodificacionMaquina[15];
    char Clasificado[20];
    char Criticidad[20];
    char Problema[150];
    char Solucion[150];
    bool Estado=true; ///SI ES TRUE LA OT ESTA EN PROCESO Y SI ES FALSE LA OT ESTA CUMPLIDA
public:
    int getOt();
    Fecha getFechaGestion();
    Fecha getFechaEstimada();
    Fecha getFechaCumplida();
    char * getCodificacionMaquina();
    char * getClasificado();
    char * getCriticidad();
    char * getProblema();
    char * getSolucion();
    bool getEstado();
    void setOt(int);
    void setFechaGestion(Fecha);
    void setFechaEstimada(Fecha);
    void setFechaCumplida(Fecha);
    void modificarFecha(int, int);
    void setCodificacionMaquina(char *);
    void setClasificado(char *);
    void setCriticidad(char *);
    void setProblema(char *);
    void setSolucion(char *);
    void setEstado(bool);
    bool cargar();
    void mostrar();
    bool escribirDisco(int = -1);
    bool leerDisco();
    bool leerDisco(int);

};

class Repuestos{
private:
    int NroParte;
    char Marca[20];
    char Modelo[20];
    char Descripcion [50];
    char Tipo[20];
    float Precio;
    bool Estado=false;

public:

    int getNroParte();
    char* getMarca();
    char* getModelo();
    char* getDescripcion();
    char* getTipo();
    float getPrecio();
    bool getEstado();
    void setNroParte(int);
    void setMarca(char *);
    void setModelo(char *);
    void setDescripcion(char *);
    void setTipo(char *);
    void setPrecio(float);
    void setEstado(bool);
    bool cargar();
    void mostrar();
    bool escribirDisco(int= -1);
    bool leerDisco();
    bool leerDisco(int);
    void obtenerTipo(int np);






};

class Stock{
private:
    int NroParte;
    int StockActual=0;
    int StockMinimo=0;
    int StockMaximo=0;
    char Ubicado[20]="Indefinido";


public:
    int getNroParte();
    int getStockActual();
    int getStockMinimo();
    int getStockMaximo();
    char * getUbicado();
    void setNroParte(int);
    void setStockActual(int);
    void setStockMinimo(int);
    void setStockMaximo(int);
    void setUbicado(char *);
    bool cargar();
    void mostrar();
    void mostrar(int, int, int);
    bool escribirDisco(int = -1);
    bool leerDisco();
    bool leerDisco(int);




};

class Items{
private:
    int NroVale;
    int Item;
    int NroParte;
    int Cant;
    float PU;

public:
    int getNroVale();
    int getItem();
    int getNroParte();
    int getCant();
    float getPU();
    void setNroVale(int);
    void setItem(int);
    void setNroParte(int);
    void setCant(int);
    void setPU(float);
    bool cargar(int,int, bool);
    void mostrar();
    bool escribirDisco(int= -1);
    bool leerDisco();
    bool leerDisco(int);


};

class valeEntradaSalida{

private:
    int NroVale;
    int Legajo;
    int Ot;
    bool TipoVale; ///SI ES 1 ES VALE DE ENTRADA Y SI ES 0 ES VALE DE SALIDA
    Fecha FechaGestion;

public:
    int getNroVale();
    int getLegajo();
    int getOt();
    bool getTipoVale();
    Fecha getFechaGestion();
    void setNroVale(int);
    void setLegajo(int);
    void setOt(int);
    void setTipoVale(bool);
    void setFechaGestion(Fecha);
    bool cargar(bool);
    void mostrar(Items *, int, bool);
    bool escribirDisco(int= -1);
    bool leerDisco();
    bool leerDisco(int);

};


///DECLARACIONES DE FUNCIONES GLOBALES CLASE PERSONAL
bool mostrarDetallesLaboral();
int buscarPosicion(int);
void listarPersonal();
int validarLegajo(int);
bool modificar_x_legajo();
bool bajaLogica();


///DECLARACIONES DE FUNCIONES GLOBALES CLASE PERSONAS
bool mostrarDetallesPersonas();
bool validar_nombres_apellidos(char *, int);
int buscarPosicion(char *);
void listarPersonas();
int validarDni(char *);
bool modificar_x_dni();


///DECLARACIONES DE FUNCIONES GLOBALES CLASE MAQUINAS
bool mostrarDetallesMaquinas();
int validarCodigo(char *);
void listarMaquinas();



///DECLARACIONES DE FUNCIONES GLOBALES CLASE OT
bool cerrarOT();
bool mostrarDetalles();
void mostrarCumplido(OT);
int buscarPos(int);
int cantidad_OT();
void listarOT();
int validarOT(int);


 ///DECLARACIONES DE FUNCIONES GLOBALES CLASE REPUESTOS

bool mostrarDetallesRepuestos();
int buscarPosicionNp(int);
bool modificar_repuestos();
void listarRepuestos();
int validarNroParte(int);
int cantidadRepuestos();


 ///DECLARACIONES DE FUNCIONES GLOBALES CLASE STOCK
bool mostrarDetallesStock();
int validarNroParteStock(int);
bool validarCantActualStock(int , int);
void ordenarStock();
void ordenarStockNroParte(Stock *, int);
void ordenarStockMinimo(Stock *, int);
void ordenarStockMaximo(Stock *, int);
int cantidadStock();
Stock extraerDisco(int);
void listarStockExcedido();
void actualizarStock(valeEntradaSalida, bool);


 ///DECLARACIONES DE FUNCIONES GLOBALES CLASE ITEMS
int cantidadItems(int);


///DECLARACIONES DE VUNCIONES GLOBALES CLASE VALE ENTRADA Y SALIDA
int cantidadValeEntradaSalida();
void listarValeEntradaSalida();
void listarNroVale(bool);
valeEntradaSalida extraerDiscoVale(int);
void ordenarValeOt(bool);
bool consultaNroVale(bool);
bool consultaNroValeFecha(bool);
bool validarVale(int);

#endif // CLASES_H_INCLUDED
