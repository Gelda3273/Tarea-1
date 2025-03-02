//Miguel Garcia 2290-24-9850
#include "eliminacion.h" //Se incluye al header de elimimacion.h como declaración de este archivio .cpp
#include "registro.h" //se incluye el header de registro para el uso de los datos 
#include <fstream>///uso de librería fstream para el manejo de archivos
#include <cstdio>//incluye funciones especailes para editar los archivos como rename y remove

using namespace std;//Implementacion para ya no usar "std" en el codigo 

void eliminarRegistro(int idEliminar) {//metodo que nos ayuda a eliminar un resgistro por su id 
	ifstream entrada("datos.dat", ios::binary);// abre el archivo orginial en modo lectura binaria
	if (!entrada.is_open()) { //Condiciona de si en caso de que no se habra el archivo muestre el texto de error al abrir el archivo
		cerr << "Error abriendo archivo!";//imprime texto en pantalla
		return;
	}

	ofstream salida("temp.dat", ios::binary);//se crea un archivo temporal dodne se guardan los datos que nos se va a eliminar 
	Registro reg;//declara variable de tipo registro (reg)
	bool eliminado = false;//varable de tipo booleano para verficar si el registro fue eliminado
	
	//Lee un registro completo desde el archivo de entrada 
	//y lo almacena en una variable reg
	while (entrada.read((char*)&reg, sizeof(Registro))) {
		if (reg.id != idEliminar) {//si le id no correspodne al que queremos eliminar solo copia los datos de ese id 
			salida.write((char*)&reg, sizeof(Registro));//escribe los datos del registro al archivo temporal
		}

		else {
			eliminado = true;//verifica si el registro ha sido eliminado 
		}
	}

	entrada.close();//se cierra el archivo original
	salida.close();//se cierra el archivo temporal

	remove("datos.dat"); //elimina el registro original con los datos desactualizados 
	rename("temp.dat", "datos.dat");//renombra al archivo temporal como datos.dat 

	if (eliminado) cout << "Regitro elimnado!" << endl;// si el registro fue eliminado se muestra el mensaje registro eliminado 
	else cout << "Registro no encontrado!" << endl;//si no se encuentra muestra error mencionado que no se encontro el registro
}