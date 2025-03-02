//Miguel Garcia 2290-24-9850
#include "insercion.h" //Se llama al header de insercion.h como declaración de este archivio .cpp
#include <fstream> //uso de librería fstream para el manejo de archivos

using namespace std;//Implementacion para ya no usar "std" en el codigo 

void insertarRegistro(Registro nuevo) {//metodo que recibe un registro y lo guarda en el archivo
	ofstream archivo("datos.dat", ios::binary | ios::app);//// Abre el archivo en modo binario y agrega datos al final.
	if (!archivo.is_open()) {//Condiciona de si en caso de que no se habra el archivo muestre el texto de error al abrir el archivo
		cerr << "Error abriendo archivo!";//Imprime texto en pantalla
			return;
	}

	archivo.write((char*)&nuevo, sizeof(Registro)); //Obtiene la dirección de la memoria de 
	//la variable y convierte esa dirección a un puntero de tipo char*.
	archivo.close();//cierra el archivo
		cout << "Registro insertado correctamente!" << endl;//Imprime texto en pantalla 
}



