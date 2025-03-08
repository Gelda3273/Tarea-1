#include <iostream>   // Para la entrada y salida de datos (cout, cin)  
#include <vector>     // Para usar el contenedor vector (similar a una lista en Python)  
#include <numeric>    // Para la función accumulate (para sumar los elementos de un vector)  
#include <algorithm>  // Para la función max_element (para encontrar el elemento máximo)  

using namespace std;  // Para no tener que escribir std:: delante de cout, cin, etc.  

int main() {
    vector<double> ventas(7);  // Declara un vector de 'double' llamado 'ventas' con tamaño 7 (uno por día)  

    // 1. Ingresar las ventas de cada dia  
    cout << "Ingrese las ventas de cada dia de la semana:" << endl;  // Muestra un mensaje al usuario  
    for (int i = 0; i < 7; ++i) {  // Itera 7 veces (una por cada día de la semana)  
        cout << "Dia " << i + 1 << ": ";  // Muestra el número del día  
        cin >> ventas[i];  // Lee la venta del usuario y la guarda en la posición 'i' del vector  

        // Validar que la venta sea un numero no negativo  
        if (cin.fail() || ventas[i] < 0) {  // Verifica si la entrada es invalida o negativa  
            cout << "Entrada invalida. Ingrese un numero no negativo." << endl;  // Muestra un mensaje de error  
            cin.clear();  // Limpia el estado de error de 'cin'  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta la entrada incorrecta del buffer  
            --i;  // Decrementa 'i' para repetir la entrada del mismo dia  
        }
    }

    // 2. Calcular el total de ventas de la semana  
    double totalVentas = accumulate(ventas.begin(), ventas.end(), 0.0);  // Suma todos los elementos del vector 'ventas'  

    // 3. Encontrar el dia con mayores ventas  
    int diaMaxVentas = max_element(ventas.begin(), ventas.end()) - ventas.begin();  // Encuentra el indice del elemento maximo  

    // 4. Verificar si hubo algun dia sin ventas  
    bool huboDiaSinVentas = false;  // Inicializa una variable para indicar si hubo un dia sin ventas  
    for (double venta : ventas) {  // Itera sobre cada venta en el vector 'ventas'  
        if (venta == 0) {  // Si la venta es igual a 0  
            huboDiaSinVentas = true;  // Marca que hubo un dia sin ventas  
            break;  // Sale del bucle, ya que solo necesitamos saber si hubo al menos un dia sin ventas  
        }
    }

    // 5. Mostrar los resultados  
    cout << "\n--- Resultados ---" << endl;  // Muestra un encabezado  
    cout << "Total de ventas de la semana: " << totalVentas << endl;  // Muestra el total de ventas  
    cout << "El dia con mayores ventas fue el Dia " << diaMaxVentas + 1 << endl;  // Muestra el dia con mayores ventas  

    if (huboDiaSinVentas) {  // Si hubo un dia sin ventas  
        cout << "Hubo al menos un dia sin ventas." << endl;  // Muestra el mensaje correspondiente  
    }
    else {
        cout << "No hubo ningun dia sin ventas." << endl;  // Muestra el mensaje correspondiente  
    }

    return 0;  // Termina el programa con un codigo de exito (0)  
}
