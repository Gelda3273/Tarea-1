#include <stdio.h> 

int main() {
	int variable = 10; // declara una variable entera
	int* puntero = &variable; // Asigna la direccion de la variable al puntero 

	printf("Ejercicio 1: \n");
	printf("Direccion de la vvariable: %P\n", (void*)&variable); //Muestra la direccion 
	printf("Valor usando puntero: %d\n\n", *puntero); //Muestra el valor utilizando el puntero 

	return 0;
}