#ifndef REGISTRO_H //verifica si el archivo esta definido 
#define REGISTRO_H //si no esta definido, lo define 

#include <iostream> //uso de librer�a iostram para la entrada y salida de datos 

struct Registro {//Definimos una estructura llamada registro
	int id;//Declaraci�n de variable tipo entero para guarda el valor del id 
	char nombre[30];//Declaraci�n de varible de tipo char que nos sobre pase de los 30 caracteres para guardar el nombre
	float salario;//Declaraci�n de variable tipo float para guardar salarios en decimales 
};

#endif  //termina con la verficaci�n para inclusion del archivo
#pragma once // Directiva para evitar la inclusi�n m�ltiple del archivo.
