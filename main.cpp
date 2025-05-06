#include <iostream>
#include <fstream> //Es una librería que proporciona operaciones de entrada y salida en streams de archivos
//Se deriva de istream and ostream
//En C++ un "stream" es la representación de una serie de butes que fluyen entre un programa y una fuente o destino externa
#include <string>
#include <cstring>

using namespace std;

/* ***************************** Declaración de funciones *********************************** */

//Metodo uno Archivos

void crear_txt(char *name);
bool leer(char *name, char *datos, unsigned long long tam);
void escribir(char *name, char *datos, unsigned long long int tam, bool f);
unsigned long long tamano(char *name);


//Codificacion

void codificar(int semilla, char *name, char *guardar);
void texto_bin(char *text, char *bin, unsigned long long tam);
void metodo1(char *bin, int semilla, unsigned long long tam, bool f);
unsigned int reglas(char *bloque, int semilla, unsigned int cantidad);
void bin_texto(char *bin, char *texto, unsigned long long tam);
char bloque_char(char *bloque);

//Decodificar

void decodificar(int semilla,char *name, char *guardar);
unsigned int reglas1(char *bloque, int semilla, unsigned int cantidad);

//Metodo dos Archivos

void crear_txt(string name);
void escribir(string texto, string nombre, bool modo);
string leer(string nombre, bool modo);

//Codificacion

bool codificacion(int semilla, string nombre, string snombre);
string texto_bin(string texto);
string int_bin(char letra);
string reglas_codificacion(string binario, int semilla, bool f);
string metodo2(string bloque);
string bin_texto(string binario);
char convert_letra (string bloque);

//Decodificacion

bool decodificacion(int semilla, string nombre, string svnombre);
string metodo2_deco(string bloque);

//Aplicación

bool acceso(string user, string clave, bool acess);
bool verificar(string texto, string user, string pass, bool f);
void ingreso();
string type(bool acess);
void user_op(string user);
unsigned int consult_sa(string user, string texto, bool f, unsigned int rest);
int finish(string user, string limit, string texto, int saldo);


/* *********************************** Main ************************************** */

int main() {

    short int op,semi,metodo,met;

    bool acess; //acceso

    string nombre,guardar;
    char name [15], save [15];
    string user, clave;

    do{

        cout << endl << "******************** Bienvenido ***********************" << endl;
        cout << endl << "1. Codificar  un archivo: " << endl;
        cout << "2. Decodificar un archivo: " << endl;
        cout << "3. Aplicacion" << endl;
        cout << "0. Para terminar" << endl;
        cout << endl << "Ingrese la opcion que desee: ";
        cin >> op;

        switch (op) {

        case 0:
        {
            cout << endl << "Gracias, hasta la proxima." << endl;

            break;

        }

        case 1:
        {
            //Codificacion

            cout << endl << "Elija el metodo a codificar: ";
            cin >> met;

            if(met==1){

                cout << endl << "Digite el nombre del archivo (con extension): ";
                cin >> name;
                cout << endl << "Digite el nombre del archivo a guardar(sin extension): ";
                cin >> save;
                cout << endl << "Ingrese que semilla desea usar para la codificacion:";
                cin >> semi;

                codificar(semi,name,save);
            }

            else{

                cout << endl << "Digite el nombre de su archivo(sin extension): ";
                cin >> nombre;
                nombre+=".txt";
                cout << endl << "Digite el nombre del archivo a guardar(sin extension): ";
                cin >> guardar;
                guardar+=".dat";
                cout << endl << "Ingrese que semilla desea usar para la codificacion:";
                cin >> semi;

                codificacion(semi,nombre,guardar);

            }

            break;
        }

        case 2:
        {
            //Decodificacion


            cout << endl << "Eliga el metodo de decodificacion del archivo: ";
            cin >> metodo;

            if(metodo==1){

                cout << endl << "Digite el nombre del archivo (con extension): ";
                cin >> name;
                cout << endl << "Digite el nombre del archivo a guardar(con extension): ";
                cin >> save;
                cout << endl << "Ingrese que semilla desea usar para la codificacion:";
                cin >> semi;

                decodificar(semi,name,save);
            }

            else{

                cout << endl << "Digite el nombre de su archivo(sin extension): ";
                cin >> nombre;
                nombre+=".dat";
                cout << endl << "Digite el nombre del archivo a guardar(sin extension): ";
                cin >> guardar;
                guardar+=".txt";
                cout << endl << "Ingrese que semilla desea usar para la codificacion:";
                cin >> semi;

                decodificacion(semi,nombre,guardar);

            }

            break;

        }

        case 3:
        {
            //Aplicacion

            cout << endl << "1.Ingresar como administrador"<<endl;
            cout << "2.Ingresar como usuario "<<endl;
            cin >> op;

            if(op==1){

                //Admin
                cout << endl << "Digite el id: ";
                cin >> user;
                cout << endl << "Digite la clave de acceso: ";
                cin >> clave;

                acess = true;

                if(acceso(user, clave, acess)){
                    cout << endl << "Ha ingresado como Administrador"<< endl;
                    ingreso();

                }
                else{
                    cout << endl << "Clave incorrecta";
                }

            }

            //Usuarios
            else if(op==2){
                cout << endl << "Digite el id: ";
                cin >> user;
                cout << endl << "Digite la clave de acceso: ";
                cin >> clave;
                acess = false;

                if(acceso(user,clave,acess)){
                    cout << endl << "Ha ingresado correctamente"<<endl;
                    user_op(user);
                }
                else{
                    cout << endl << "Clave incorrecta"<<endl;
                }

            }

            else cout << endl << "La transaccion ha sido cancelada...";

            break;

        }

        }

    }

    while (op!=0);

    return 0;

}


/* *************************************** Funcines ************************************ */

//Método 1

void codificar(int semilla, char *name, char *guardar){

    bool result = true;
    unsigned long long tam = 0;
    tam = tamano(name);

    char *data, *binario;

    try {

        // Memoria dinamica
        data = new char [tam+1];
        binario = new char [8*tam+1];


        if(leer(name,data,tam)){
            texto_bin(data,binario,tam);
            metodo1(binario,semilla,8*tam,true);

            bin_texto(binario,data,tam);
            escribir(guardar,data,tam,false);
        }
        delete [] binario;
        delete [] data;



    }  catch (...) { //captura todas las excepciones posibles, sin importar el tipo específico de la excepción.
        //result = false;
        cout << endl << "Se presenta una excepcion." << endl;

    }

}

void texto_bin(char *text, char *bin, unsigned long long tam){

    for(unsigned long long i=0;i<tam;i++){
        for(int j=0;j<=7;j++) bin[i*8+j]= ((text[i]<<j)&128)/128;
    }
    bin[8*tam]='\0';
}


void metodo1(char *bin, int semilla, unsigned long long tam, bool f){

    char *bloque;
    unsigned int uno=0;

    bloque = new char [semilla+1];
    bloque[semilla]='\0';


    //True Codificar

    if(f){
        for(unsigned long long i=0,j=0,bloques=0;i<tam;i++,j++){
            bloque[j] = bin[i];
            if((i+1)%semilla==0 || i==tam-1){
                uno = reglas(bloque,semilla,uno);
                j=-1;
                for(int d=0;d<semilla;d++){
                    if(bloque[d]!=-1) bin[semilla*bloques+d]=bloque[d];
                    bloque[d] = -1;

                }

                bloques++;

            }
        }
    }

    else{
        for(unsigned long long i=0,j=0,bloques=0;i<tam;i++,j++){
            bloque[j] = bin[i];
            if((i+1)%semilla==0 || i==tam-1){
                uno = reglas1(bloque,semilla,uno);
                j=-1;
                for(int d=0;d<semilla;d++){
                    if(bloque[d]!=-1) bin[semilla*bloques+d]=bloque[d];
                    bloque[d] = -1;

                }
                bloques++;
            }
        }
    }
    delete [] bloque;
}

//Codificar
unsigned int reglas(char *bloque, int semilla, unsigned int cantidad){

    static bool band = true;
    unsigned int uno=0;

    if (band || semilla-cantidad==cantidad){
        for(int i=0;i<semilla;i++){
            uno+=bloque[i];
            if(bloque[i]!=-1) bloque[i]=1-bloque[i]; //Ecuacion para invertir bits.

        }
        band = false;
    }

    else if(semilla-cantidad>cantidad){
        for(int i=0;i<semilla;i++){
            uno+=bloque[i];
            if(i%2==1 && bloque[i]!=-1) bloque[i]=1-bloque[i];
        }
    }

    else{
        for(int i=0;i<semilla;i++){
            uno+=bloque[i];
            if((i+1)%3==0 && bloque[i]!=-1) bloque[i]=1-bloque[i];
        }
    }

    return uno;
}


//Decodificar
unsigned int reglas1(char *bloque, int semilla, unsigned int cantidad)
{
    static bool band = true;
    unsigned int uno = 0;


    if (band ||semilla-cantidad==cantidad){
        for(int i=0;i<semilla;i++){
            if(bloque[i]!=-1){
                bloque[i]=1-bloque[i]; //Ecuacion para invertir bits.-- Modificación del binario

            }
            uno+=bloque[i];
        }
        band = false;

    }
    else if(semilla-cantidad>cantidad){
        for(int i=0;i<semilla;i++){
            if((i%2)==1 && bloque[i]!=-1) bloque[i]=1-bloque[i];
            uno+=bloque[i];
        }

    }
    else{
        for(int i=0;i<semilla;i++){
            if((i+1)%3==0 && bloque[i]!=-1) bloque[i]=1-bloque[i];
            uno+=bloque[i];
        }
    }
    return uno;
}


void bin_texto(char *bin, char *texto, unsigned long long tam){

    char *bloque;
    bloque = new char [9];
    bloque[8] = '\0';

    for(unsigned long long i=0,j=0,k=0;i<8*tam;i++,j++){
        bloque[j] = bin[i];
        if((i+1)%8==0){
            texto[k]=bloque_char(bloque);
            k++;
            j=-1;
        }
    }
    delete [] bloque;

}

char bloque_char(char *bloque)
{
    int k = 128,l=0;
    for(int i=0;i<=7;i++,k/=2) l+=bloque[i]*k;
    return char(l);
}

void decodificar(int semilla, char *name, char *guardar)
{
    bool result = true;
    unsigned long long tam = 0;
    tam = tamano(name);

    char *data, *binario;

    try {

        // Memoria dinamica
        data = new char [tam+1];
        binario = new char [8*tam+1];


        if(leer(name,data,tam)){
            texto_bin(data,binario,tam);
            metodo1(binario,semilla,8*tam,false);
            bin_texto(binario,data,tam);
            escribir(guardar,data,tam,true);
        }
        delete [] binario;
        delete [] data;



    }  catch (...) {
        result = false;

    }

}

void crear_txt(char *name){

    fstream text(name, fstream::out);
    text.close();
}


void escribir(char *name, char *datos, unsigned long long tam, bool f){

    fstream text;

    if(f){
        text.open(name, fstream::out );
        text << datos;
    }
    else{
        text.open(name, fstream::out | fstream::binary);
        text.write(datos,tam);

    }
    text.close();
}


bool leer(char *name, char *datos, unsigned long long tam){

    fstream text(name, fstream::in | fstream:: binary);
    bool confirm = text.is_open();
    if(confirm){
        for(unsigned long long j=0; j<tam; j++) datos[j] = text.get();
        datos[tam]='\0';
    }

    else{
        cout << endl << "No se ha podido abrir el archivo.";
    }

    return confirm;
}

unsigned long long tamano(char *name){

    unsigned long long int tam=0;
    fstream text(name, fstream::in | fstream::ate | fstream:: binary);
    if (text.is_open()) {
        tam = text.tellg();

    }
    text.close();
    return tam;
}

//Método 2

bool codificacion(int semilla, string nombre, string guardar){

    bool result = true;
    string texto, binario;
    try {

        texto = leer(nombre,true); // Extraer el contenido del archivo
        binario = texto_bin(texto);
        binario = reglas_codificacion(binario, semilla, true);
        texto = bin_texto(binario);
        escribir(texto,guardar,false);

    }  catch (...) {
        result = false;
    }

    return result;
}

string texto_bin(string texto){

    string binario,aux;

    //recorre el texto letra por letra
    for(unsigned long long i=0;i<texto.length();i++){
        aux = int_bin(int(texto[i]));
        binario.append(aux);
    }
    return binario;
}

string int_bin(char letra){

    string binario;
    //0b10000000
    for(int i=0;i<8;i++) binario.push_back(((letra<<i)&128)/128);
    return binario;

}

string reglas_codificacion(string binario, int semilla, bool f){

    string bloque, datos;


    if(f){
        //Recorre todo el binario
        //Codificacion es rotacion a la derecha
        for(unsigned long long i=0;i<binario.length();i++){
            bloque.push_back(binario[i]);
            //Verificar que el bloque este correctamente dividido
            if((i+1)%semilla==0 || i==binario.length()-1){
                bloque = metodo2(bloque);
                datos.append(bloque);
                bloque.clear();
            }
        }
    }
    //Decodificacion
    else{
        for(unsigned long long i=0;i<binario.length();i++){
            bloque.push_back(binario[i]);
            if((i+1)%semilla==0 || i==binario.length()-1){
                bloque = metodo2_deco(bloque);
                datos.append(bloque);
                bloque.clear();
            }
        }

    }

    return datos;
}

string metodo2(string bloque){

    string datos;
    //
    datos.push_back(bloque[bloque.length()-1]);
    for(unsigned long long i=0;i<bloque.length()-1;i++){
        datos.push_back(bloque[i]);
    }
    return datos;
}

string metodo2_deco(string bloque){

    string datos;
    for(unsigned long long i=0;i<bloque.length()-1;i++){
        datos.push_back(bloque[i+1]);

    }
    datos.push_back(bloque[0]);

    return datos;
}

string bin_texto(string binario){

    string datos,bloque;

    for(unsigned long long i=0; i<binario.length();i++){
        bloque.push_back(binario[i]);
        if((i+1)%8==0){
            datos.push_back(convert_letra(bloque));
            bloque.clear();
        }
    }
    return datos;
}

char convert_letra(string bloque){
    char l=0;
    for(unsigned long long i=0, k=128 ;i<bloque.length();i++,k/=2){
        l+= k*bloque[i];
    }
    return l;
}

bool decodificacion (int semilla, string nombre, string svnombre){

    string bin, texto;
    bool result = true;
    try {
        texto = leer(nombre,false);
        bin = texto_bin(texto);
        bin = reglas_codificacion(bin, semilla, false);
        texto = bin_texto(bin);
        escribir(texto,svnombre,true);

    }  catch (...) {
        result = false;

    }
    return result;
}

void crear_txt(string name){
    fstream text(name, fstream::out);
    text.close();
}

void escribir(string texto, string nombre, bool modo)
{
    if(modo){
        fstream text(nombre, fstream::out);
        text << texto;
        text.close();

    }
    else{
        fstream text(nombre, fstream::out | fstream::binary);
        text << texto;
        text.close();

    }
}


string leer(string nombre, bool modo)
{
    string datos;
    fstream text;
    unsigned long long tam;

    // True- Convencional
    if(modo){
        text.open(nombre, fstream::in);
        if(text.is_open()){
            while(!text.eof()) datos.push_back(text.get());
            datos.pop_back();

        }
        else cout << endl << "El archivo no pudo ser abierto" << endl;

    }
    else{
        // fstream::ate posiciona el curso al final del archivo
        text.open(nombre, fstream::in | fstream::binary | fstream::ate);
        if(text.is_open()){
            tam = text.tellg();     //obtenemos la cantidad de carac
            text.seekg(0);          //posiciona el curso al inicio de las cadenas
            for(unsigned long long i=0; i<tam; i++) datos.push_back(text.get());

        }
        else cout << endl << "El archivo no pudo ser abierto" << endl;

    }
    text.close();
    return datos;
}

//Aplicación

// Ordenar los includes
string txt;

bool acceso(string user, string clave, bool acess)
{
    bool result = false;
    string texto, binario, limitador = ",";


    try {
        texto = leer(type(acess),false);
        binario = texto_bin(texto);
        binario = reglas_codificacion(binario,4,false);
        texto = bin_texto(binario);
        txt=texto;
        result = verificar(texto,user,clave,acess);

    }  catch (...){
        cout << endl << "Ha ocurrido una excepcion";
    }

    return result;
}

bool verificar(string texto, string user, string pass, bool f)
{

    char limitador[] = ",.\n";
    char *c, *cadena;
    int pos=0;
    bool result = false;
    // Version 1.3- Administrador
    if(f){
        string limit = texto.substr(0, texto.find(','));
        if(user==limit){
            texto.erase(0, texto.find(',')+1);
            limit = texto.substr(0, texto.find(','));
            if(pass==limit)result = true;

        }
    }
    //Usuarios
    else{
        c = &texto[0]; // Convertimos el string
        cadena = strtok(c,limitador);
        if(cadena !=NULL){
            while (cadena !=NULL){
                if(cadena==user) pos++;
                else if (cadena==pass)pos++;
                if(pos==2){
                    result =  true;
                    break;
                }
                cadena = strtok(NULL, limitador);
            }
        }
    }

    return result;
}

void ingreso()
{

    string id,pass,money,data,texto;

    cout << endl << "Digite el id de usuario: ";
    cin >>id;
    cout << endl << "Digite la clave: ";
    cin >> pass;
    cout << endl << "Digite el saldo: ";
    cin >> money;


    //Version 1.2

    id+=",";
    id.append(pass+",");
    data = id.append(money+".");

    //Codificar
    texto = texto_bin(data);
    texto = reglas_codificacion(texto,4,true);
    string binario = bin_texto(texto);

    escribir(binario,"prueba.dat",false);
    cout << endl << "Usuario registrado."<<endl;
}

//Switch
string type(bool acess)
{
    string name;
    if(acess){
        //adminstrador
        name= "sudo.dat";
    }
    else{
        //usuarios
        name= "prueba.dat";
    }
    return name;
}

void user_op(string user){

    unsigned int op, rest=0;
    bool f;

    cout << endl << "1.Consultar saldo"<<endl;
    cout << "2.Retirar dinero"<<endl;
    cin >> op;

    if(op==1){
        f=true;
        if(consult_sa(user,txt,f,rest)==0){
            cout << endl << "No tienes fondos"<<endl;
        }
        else{
            cout << endl << "Se han descontado 1000$"<<endl;
            cout <<"Saldo total: "<<consult_sa(user,txt,f,rest)<<"$"<<endl;
        }

    }
    else if (op==2){
        f=false;
        if(consult_sa(user,txt,f,rest)==0){
            cout << endl << "No tienes fondos."<<endl;
        }
        else{
            cout << endl << "Cantidad a retirar: "<<endl;
            cin >> rest;
            cout << "Saldo total: " << consult_sa(user,txt,f,rest) <<"$" << endl;

        }

    }

}

unsigned int consult_sa(string user, string texto, bool f, unsigned int rest){


    string limit, copy, binario, texto1;
    char k;
    unsigned int saldo=0,x=0,pos=0;

    pos = (texto.find('.'));
    limit = texto.substr(texto.find(user,0),pos);
    copy = limit;
    //Version 1.1
    for(unsigned int m=0;m<copy.length();m++){
        k = copy[m];
        if(k==','){
            copy.erase(0,m+1);
            m = 0;

        }
    }

    //Funcion para actualizar saldo y guardar
    saldo = stoi(copy);
    if(saldo==0){
        x = 0;
    }
    else if(saldo>=1000){
        if(f) x=finish(user,limit,txt,saldo-1000);

        else x =finish(user,limit,txt,saldo-rest);

    }
    //Retirar
    else if(saldo<=rest){
        cout << endl << "No tienes fondos suficientes.";

    }
    return x;
}


//Actualizacion de datos.
int finish(string user, string limit, string texto, int saldo){

    string scopy;
    char c;
    scopy = to_string(saldo);
    try {
        //Actualizacion del usuario segun el saldo.
        if(saldo == 0){
            for(unsigned long long i=0,k=0;i<limit.length();i++){
                c = limit[i];
                if(c == ',')k++;
                else if(k==2){
                    limit.replace(i,limit.find("."),scopy);
                    texto.replace(texto.find(user),texto.find('.'),limit);
                }
            }
        }
        if(saldo!=0){
            limit.replace(limit.length()-scopy.length(),limit.find("."),scopy);
            texto.replace(texto.find(user),texto.find('.'),limit);
        }

        //Codificar la informacion del usuario.
        texto = texto_bin(texto);
        texto = reglas_codificacion(texto,4,true);
        string binario = bin_texto(texto);

        escribir(binario,"prueba.dat",false);

    }  catch (...) {
        cout << endl << "La transaccion ha sido cancelada.";
    }

    return saldo;
}


