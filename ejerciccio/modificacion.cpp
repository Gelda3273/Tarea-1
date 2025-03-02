
#include "modificacion.h"
#include "busqueda.h"
#include <fstream> 
 
using namespace std;

void modificarRegistro(Registro modificado) {
	fstream archivo("datos.dat", ios::binary | ios::in | ios::out);
	if (!archivo.is_open()) {
		cerr << "Error al abrir el archivo!";
		return;
	}

	int pos = buscarPosicion(modificado.id); 
	if (pos == -1) { 
		cout << "Regitro no encontrado!" << endl;
		return;
	}

	archivo.seekp(pos * sizeof(Registro));
	
	archivo.write((char*)&modificado, sizeof(Registro));
	archivo.close();
	cout << "Registro modificado!" << endl;
}
	