#include <iostream>   // Para la entrada y salida de datos (cout, cin)  
#include <vector>     // Para usar el contenedor vector (similar a una lista en Python)  

using namespace std;  // Para no tener que escribir std:: delante de cout, cin, etc.  

// Funcion para verificar si un numero es primo  
bool esPrimo(int numero) {
    if (numero <= 1) return false;  // Los numeros menores o iguales a 1 no son primos  
    for (int i = 2; i * i <= numero; ++i) {  // Itera desde 2 hasta la raiz cuadrada del numero  
        if (numero % i == 0) return false;  // Si el numero es divisible por 'i', no es primo  
    }
    return true;  // Si no se encontro ningun divisor, el numero es primo  
}

int main() {
    int n;  // Declara una variable entera 'n' para guardar la cantidad de numeros primos a generar  

    // Pedir al usuario un numero entero positivo N  
    cout << "Ingrese un numero entero positivo N: ";  // Muestra un mensaje pidiendo al usuario que ingrese un numero  
    cin >> n;  // Lee la entrada del usuario y la guarda en la variable 'n'  

    // Validar que N sea un entero positivo  
    if (n <= 0) {  // Verifica si 'n' es menor o igual a cero  
        cout << "Por favor, ingrese un numero entero positivo." << endl;  // Muestra un mensaje de error  
        return 1;  // Termina el programa con un codigo de error (1)  
    }

    vector<int> primos;  // Declara un vector de enteros llamado 'primos' para guardar los numeros primos  

    // Generar los primeros N numeros primos  
    int numero = 2;  // Comienza a buscar numeros primos desde el 2  
    while (primos.size() < n) {  // Mientras no se hayan encontrado 'n' numeros primos  
        if (esPrimo(numero)) {  // Verifica si el numero actual es primo  
            primos.push_back(numero);  // Agrega el numero primo al vector 'primos'  
        }
        numero++;  // Incrementa el numero para seguir buscando primos  
    }

    // Imprimir la lista de numeros primos generados  
    cout << "Los primeros " << n << " numeros primos son:" << endl;  // Muestra un mensaje indicando la lista de primos  
    for (int primo : primos) {  // Itera sobre cada numero primo en el vector 'primos'  
        cout << primo << " ";  // Imprime el numero primo seguido de un espacio  
    }
    cout << endl;  // Imprime un salto de linea al final  

    return 0;  // Termina el programa con un codigo de exito (0)  
}