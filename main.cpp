#include <iostream>
#include <fstream> //Es una librería que proporciona operaciones de entrada y salida en streams de archivos
//Se deriva de istream and ostream
//En C++ un "stream" es la representación de una serie de butes que fluyen entre un programa y una fuente o destino externa
#include <string>

using namespace std;

/* ***************************** Declaración de funciones *********************************** */

void escribirCharPorChar(const string& nomArchivo);
void escribirLineaporLinea(const string& nomArchivo);
void leerCharPorChar(const string& nomArchivo);
void leerLineaPorLinea(const string& nomArchivo);


/* *********************************** Main ************************************** */

int main() {

    ofstream fout;

    string line;

    const string nomArchivo = "ejemplo1.txt";


    escribirCharPorChar(nomArchivo);


    //escribirLineaporLinea(nomArchivo);


    leerCharPorChar(nomArchivo);


    //leerLineaPorLinea(nomArchivo);

    fout.open("ejemplo1.txt"); //borrar archivo


    escribirCharPorChar(nomArchivo);


    return 0;
}


/* *************************************** Funcines ************************************ */

void escribirCharPorChar(const string& nomArchivo) { //Se pasa el nombre del archivo por referencia y se define como constante
    //todo esto para evitar que se cambie el valor y no se cree una copia de un string
    ofstream file(nomArchivo, ios::out | ios::app); // Se crea el archivo o se pone al final si ya existe
    if (!file.is_open()) {
        cerr << "Error abriendo archivo: " << nomArchivo << endl;
        return;
    }

    string text = "Esto es un texto de muestra y es escrito letra a letra. \n";
    for (char c : text) { //un for basado en rango, también se puede hacer con arreglos
        file.put(c); // Escritura
    }

    file.close();
    cout << "ok char" << endl;
}

void escribirLineaporLinea(const string& nomArchivo) {
    ofstream file(nomArchivo, ios::out | ios::app); // Open file in append mode
    if (!file.is_open()) {
        cerr << "Error abriendo archivo: " << nomArchivo << endl;
        //stream de error estándar, más eficiente que cout, que se almacena (unbuffered)
        return;
    }

    string linea;
    cout << "Ingrese el texto y presione Enter para finalizar:" << endl;
    while (getline(cin, linea) && !linea.empty()) {
        //Se lee una linea de standart input "cin" y lo guarda en la variable "linea" y devuelve un "true" si
        //se lee exitosamente. linea.empty devuelve un "true" si el string está vacío, es decir, si hay ENTER después de un vacío
        file << linea << endl; // Se escribe en archivo linea por linea
    }

    file.close();
    cout << "ok string" << endl;
}

void leerCharPorChar(const string& nomArchivo) {
    ifstream file(nomArchivo);
    if (!file.is_open()) {
        cerr << "Error abriendo archivo: " << nomArchivo << endl;
        return;
    }

    cout << "Leyendo char por char:" << endl;
    char c;
    while (file.get(c)) { // Read character by character
        cout << c;
    }

    file.close();
}

void leerLineaPorLinea(const string& nomArchivo) {
    ifstream file(nomArchivo);
    if (!file.is_open()) {
        cerr << "Error abriendo archivo: " << nomArchivo << endl;
        return;
    }

    cout << "Lectura linea por linea:" << endl;
    string linea;
    while (getline(file, linea)) { // Read line by line
        cout << linea << endl;
    }

    file.close();
}

