#include "acceso.h" //hola
#include <iostream> 

using namespace std; 

void leerArchivo(){ 
	ifstream archivo("datos.dat", ios::binary);
	if (!archivo.is_open()) { lhljhjlhhkghjgjhgjhy
		cerr << "Error al abrir el archivo!";
		return;
	}

	Registro reg;
	while (archivo.read((char*)&reg, sizeof(Registro))) {
		cout << "\nID: " << reg.id 
			<< "\nNombre: " << reg.nombre
			<< "\nSalario: " << reg.salario << endl;
	}

	archivo.close();
}

void buscarPorID(int idBuscado) {
	ifstream archivo("datos.dat", ios::binary); 
	if (!archivo.is_open()) { 
		cerr << "Error al abrir el archivo!";
		return;
	}

	Registro reg;
	bool encontrado = false;
	while (archivo.read((char*)&reg, sizeof(Registro)) && !encontrado) {
		if (reg.id == idBuscado) {
			cout << "\nRegistro encontrado:"
				<< "\nNombre: " << reg.nombre
				<< "\nSalario: " << reg.salario << endl;
			encontrado = true;
		}
	}
	if (!encontrado) cout << "Registro no encontrado!" << endl; 
	archivo.close();
}


