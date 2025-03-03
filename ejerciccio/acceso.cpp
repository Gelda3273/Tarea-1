#include "acceso.h"  // Incluye el archivo de encabezado acceso.h donde se definen estructuras y funciones necesarias.  
#include <iostream>   // Incluye la biblioteca estándar de entrada y salida de C++.  

using namespace std;  // Permite usar el espacio de nombres estándar sin necesidad de escribir 'std::' antes de cada elemento.  

void leerArchivo() {   
    ifstream archivo("datos.dat", ios::binary); // Abre el archivo "datos.dat" en modo binario para leer.  
    if (!archivo.is_open()) {  // Verifica si el archivo se abrió correctamente.  
        cerr << "Error al abrir el archivo!"; // Imprime un mensaje de error si el archivo no se puede abrir.  
        return; // Termina la función si el archivo no está accesible.  
    }  
    
    Registro reg; // Declara una variable 'reg' de tipo 'Registro' para almacenar los datos leídos.  
    while (archivo.read((char*)&reg, sizeof(Registro))) { // Lee el archivo en bloques del tamaño de 'Registro'.  
        cout << "\nID: " << reg.id  // Imprime el ID del registro actual.  
             << "\nNombre: " << reg.nombre // Imprime el nombre del registro actual.  
             << "\nSalario: " << reg.salario << endl; // Imprime el salario del registro actual.  
    }  
    
    archivo.close(); // Cierra el archivo después de leer todos los registros.  
}   

void buscarPorID(int idBuscado) {   
    ifstream archivo("datos.dat", ios::binary); // Abre el archivo "datos.dat" en modo binario para buscar.  
    if (!archivo.is_open()) { // Verifica si el archivo se abrió correctamente.  
        cerr << "Error al abrir el archivo!"; // Imprime un mensaje de error si el archivo no se puede abrir.  
        return; // Termina la función si el archivo no está accesible.  
    }  
    
    Registro reg; // Declara una variable 'reg' para almacenar los registros leídos.  
    bool encontrado = false; // Inicializa la bandera 'encontrado' como 'false'.  
    
    while (archivo.read((char*)&reg, sizeof(Registro)) && !encontrado) { // Bucle para leer el archivo hasta que no haya más registros o se encuentre el buscado.  
        if (reg.id == idBuscado) { // Verifica si el ID del registro actual coincide con 'idBuscado'.  
            cout << "\nRegistro encontrado:" // Imprime que se ha encontrado el registro.  
                 << "\nNombre: " << reg.nombre // Imprime el nombre del registro encontrado.  
                 << "\nSalario: " << reg.salario << endl; // Imprime el salario del registro encontrado.  
            encontrado = true; // Marca la bandera 'encontrado' como 'true'.  
        }   
    }  
    
    if (!encontrado) cout << "Registro no encontrado!" << endl; // Imprime un mensaje si no se encuentra el registro.  
    
    archivo.close(); // Cierra el archivo después de la búsqueda.  
}  
