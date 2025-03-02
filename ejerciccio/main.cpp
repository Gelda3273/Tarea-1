#include <iostream>
#include "registro.h"
#include "acceso.h"
#include "insercion.h"
#include "busqueda.h"
#include "eliminacion.h"
#include "modificacion.h"

using namespace std;  

void mostrarMenu() {
    cout << "\n===== GESTION DE ARCHIVOS ====="
        << "\n1. Mostrar todos"
        << "\n2. Buscar por ID"
        << "\n3. Agregar registro"
        << "\n4. Modificar registro"
        << "\n5. Eliminar registro"
        << "\n6. Salir"
        << "\nOpcion: ";
}

int main() {
    int opcion, id;  
    Registro reg; //

    do {  // 
        mostrarMenu();//
        cin >> opcion;//
        cin.ignore(); // 

        switch (opcion) { //
            leerArchivo();//
            break;//

        case 2:
            cout << "ID a buscar: ";//
            cin >> id;//
            buscarPorID(id); //
            break;//

        case 3:
            cout << "Nuevo registro:\nID: ";
            cin >> reg.id;//
            cout << "Nombre: ";//
            cin.ignore();// 
            cin.getline(reg.nombre, 30);//
            cout << "Salario: ";//
            cin >> reg.salario;// 
            insertarRegistro(reg);//
            break;//


        case 4:
            cout << "ID a modificar: ";
            cin >> reg.id;
            cout << "Nuevo nombre: ";
            cin.ignore();
            cin.getline(reg.nombre, 30);
            cout << "Nuevo salario: ";
            cin >> reg.salario;
            break;


        case 5:
            cout << "ID a eliminar: ";
            cin >> id;
            eliminarRegistro(id);
            break;

        }
    } while (opcion != 6);  

    return 0;