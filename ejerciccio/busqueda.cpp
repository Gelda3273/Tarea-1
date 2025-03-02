//Miguel Garcia 2290-24-9850
#include "busqueda.h"//Se incluye al header de busqueda.h como declaraci�n de este archivio .cpp
#include <fstream>//uso de librer�a fstream para el manejo de archivos 

using namespace std; // Implementacion para ya no usar "std" en el codigo

int buscarPosicion(int idBuscado) {//decLara una funcion que nos ayuda a buscar la id del archivo segun su posicion
    ifstream archivo("datos.dat", ios::binary);//abre el arhivo en modo de lectura binaria 

    // Si el archivo no se pudo abrir, retorna -1 indicando un error
    if (!archivo.is_open()) return -1;

    Registro reg;  // Variable donde se almacenar� temporalmente cada registro le�do
    int pos = 0;   // Contador de posici�n para identificar en qu� �ndice est� el registro buscado

    // Lee el archivo registro por registro hasta llegar al final
    while (archivo.read((char*)&reg, sizeof(Registro))) {

        if (reg.id == idBuscado) {
            archivo.close(); // Cierra el archivo antes de salir
            return pos;      // Retorna la posici�n donde se encontr� el registro
        }
        pos++; // Si no es el registro buscado, aumenta la posici�n y sigue leyendo
    }

    archivo.close(); // Cierra el archivo al finalizar la busqueda
    return -1;       // Si no se encontro el ID retorna -1 
}