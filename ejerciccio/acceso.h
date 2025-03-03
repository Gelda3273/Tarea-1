#ifndef ACCESO_H  //evita la inclucion multiple de un mismo archi
#define ACCESO_H  //define constante simbolico 

#include "registro.h" //incluye en contenido de un archivo 
#include <fstream> //biblioteca para manejo de archivo 

void leerArchivo();  //define unna funcion que se llama leerArchivo
void buscarPorID(int idBuscado);  //realiza busqueda en una base de datos

#endif //se utiliza para marcar el final de una condicion de copil
#pragma once //sirve para indicar un archivo de cabecera 
