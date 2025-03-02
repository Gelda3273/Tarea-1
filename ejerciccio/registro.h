#ifndef REGISTRO_H //verifica si el archivo esta definido 
#define REGISTRO_H //si no esta definido, lo define 

#include <iostream> //uso de librería iostram para la entrada y salida de datos 

struct Registro {//Definimos una estructura llamada registro
	int id;//Declaración de variable tipo entero para guarda el valor del id 
	char nombre[30];//Declaración de varible de tipo char que nos sobre pase de los 30 caracteres para guardar el nombre
	float salario;//Declaración de variable tipo float para guardar salarios en decimales 
};

#endif  //termina con la verficación para inclusion del archivo
#pragma once // Directiva para evitar la inclusión múltiple del archivo.
