#include <iostream>    // Para la entrada y salida de datos (cout, cin)  
#include <vector>      // Para usar el contenedor vector (similar a una lista en Python)  
#include <numeric>     // Para la función accumulate (para sumar los elementos de un vector)  
#include <algorithm>   // Para las funciones max_element y min_element (para encontrar el máximo y mínimo)  
#include <limits>      // Para acceder a los límites numéricos (usado para limpiar la entrada)  

using namespace std;  // Para no tener que escribir std:: delante de cout, cin, etc.  

int main() {
    int n;  // Declara una variable entera 'n' para guardar la cantidad de estudiantes  

    // 1. Pedir al usuario la cantidad de estudiantes  
    while (true) {  // Inicia un bucle infinito.  Se repetirá hasta que el usuario ingrese una entrada válida  
        cout << "Ingrese la cantidad de estudiantes: ";  // Muestra un mensaje al usuario pidiendo la cantidad de estudiantes  
        cin >> n;  // Lee la entrada del usuario y la guarda en la variable 'n'  

        if (cin.fail() || n <= 0) {  // Verifica si la entrada fue inválida (no es un número o es menor o igual a cero)  
            cout << "Entrada invalida. Ingrese un numero entero positivo." << endl;  // Muestra un mensaje de error  
            cin.clear();  // Limpia el estado de error de 'cin' (para poder leer nuevas entradas)  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta la entrada incorrecta del buffer (hasta encontrar un salto de línea)  
        }
        else {
            break;  // Si la entrada es válida, sale del bucle 'while'  
        }
    }

    vector<double> calificaciones;  // Declara un vector de 'double' llamado 'calificaciones' para guardar las notas  

    // 2. Ingresar las calificaciones de cada estudiante  
    for (int i = 0; i < n; ++i) {  // Inicia un bucle 'for' que se ejecuta 'n' veces (una vez por estudiante)  
        double calificacion;  // Declara una variable 'double' para guardar la calificación de un estudiante  
        while (true) {  // Inicia otro bucle 'while' para asegurarse de que la calificación sea válida  
            cout << "Ingrese la calificacion del estudiante " << i + 1 << ": ";  // Muestra un mensaje pidiendo la calificación del estudiante  
            cin >> calificacion;  // Lee la calificación del usuario y la guarda en la variable 'calificacion'  

            if (cin.fail() || calificacion < 0 || calificacion > 100) {  // Verifica si la entrada es inválida (no es un número o está fuera del rango 0-100)  
                cout << "Entrada invalida. La calificacion debe estar entre 0 y 100." << endl;  // Muestra un mensaje de error  
                cin.clear();  // Limpia el estado de error de 'cin'  
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta la entrada incorrecta del buffer  
            }
            else {
                calificaciones.push_back(calificacion);  // Agrega la calificación al final del vector 'calificaciones'  
                break;  // Si la entrada es válida, sale del bucle 'while'  
            }
        }
    }

    // 3. Calcular estadisticas  
    if (!calificaciones.empty()) {  // Verifica si el vector 'calificaciones' no está vacío (si se ingresaron calificaciones)  
        double max_calificacion = *max_element(calificaciones.begin(), calificaciones.end());  // Encuentra la calificación más alta y la guarda en 'max_calificacion'  
        double min_calificacion = *min_element(calificaciones.begin(), calificaciones.end());  // Encuentra la calificación más baja y la guarda en 'min_calificacion'  
        double promedio = accumulate(calificaciones.begin(), calificaciones.end(), 0.0) / calificaciones.size();  // Calcula el promedio de las calificaciones y lo guarda en 'promedio'  

        int aprobados = 0;  // Declara una variable entera 'aprobados' para contar los estudiantes aprobados  
        for (double c : calificaciones) {  // Inicia un bucle 'for' para recorrer todas las calificaciones en el vector  
            if (c >= 60) {  // Verifica si la calificación es mayor o igual a 60 (aprobado)  
                aprobados++;  // Incrementa el contador de aprobados  
            }
        }
        int reprobados = calificaciones.size() - aprobados;  // Calcula la cantidad de estudiantes reprobados  

        // 4. Mostrar resultados  
        cout << "\n--- Estadisticas de Calificaciones ---" << endl;  // Muestra un encabezado  
        cout << "Calificacion mas alta: " << max_calificacion << endl;  // Muestra la calificación más alta  
        cout << "Calificacion mas baja: " << min_calificacion << endl;  // Muestra la calificación más baja  
        cout << "Promedio de las calificaciones: " << promedio << endl;  // Muestra el promedio  
        cout << "Cantidad de estudiantes aprobados: " << aprobados << endl;  // Muestra la cantidad de aprobados  
        cout << "Cantidad de estudiantes reprobados: " << reprobados << endl;  // Muestra la cantidad de reprobados  
    }
    else {
        cout << "No se ingresaron calificaciones." << endl;  // Muestra un mensaje si no se ingresaron calificaciones  
    }

    return 0;  // Indica que el programa se ejecutó correctamente  
}