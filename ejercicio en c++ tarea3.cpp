#include <iostream> //libreria para entrada y salida de datos 
#include <vector> //libreria para trabajar con vectores

using namespace std; //para no tener que escribir std::cout o std::cin


bool esPrimo(int num) { //Función para comprobar si un numero es primo
    if (num <= 1) return false; //si el numero es menor o igual a 1 no es primo
    for (int i = 2; i * i <= num; i++) { //es un bucle for que se utiliza para comprobar si un numero num es primo.
        if (num % i == 0) return false; //se utiliza para comprobar si un numero num es divisible por otro numero i.
    }
    return true; //si no se ccmple ninguna de las condiciones anteriores el numero es primo 
}

int main() { //punto de entrada del programa y es donde comienza la ejecución del codigo.

    int n; //se utiliza para almacenar un valor entero.
    cout << "Ingrese un número entero positivo N: "; //para imprimir un mensaje en la pantalla y pedir al usuario que ingrese un numero entero positivo.
    cin >> n; //para leer un valor desde la entrada estándar (teclado) y almacenarlo en la variable n

    // Validar que N sea un numero entero positivo
    while (n <= 0) {
        cout << "Error. N debe ser un número entero positivo. "; // para imprimir un mensaje de error en la pantalla.
        cout << "Ingrese un número entero positivo N: "; //para imprimir un mensaje en la pantalla y pedir al usuario que ingrese un numero entero positivo
        cin >> n; //para leer un valor desde la entrada estándar(teclado) y almacenarlo en la variable n.

    vector<int> primos; //declara un vector de enteros llamado primos.
    int num = 2; // declarar una variable entera llamada num e inicializarla con el valor 2
    while (primos.size() < n) { // para crear un bucle que se repite mientras el tamaño del vector primos sea menor que el valor de la variable n.
        if (esPrimo(num)) { //para evaluar si un numero es primo utilizando una funcion llamada esPrimo.
            primos.push_back(num); //para agregar un elemento al final de un vector llamado primos.
        }
        num++; //incrementa el valor de una variable entera llamada num

    }

    cout << "Los primeros " << n << " números primos son: "; //imprime un mensaje en la pantalla que indica los primeros n numeros primos.
    for (int i = 0; i < primos.size(); i++) {
        cout << primos[i] << " "; //se utiliza para imprimir el elemento i-esimo del vector primos en la pantalla.

    }
    cout << endl; // para insertar un salto de linea en la salida estandar.


    return 0; //devolver 0 para indicar quer el programa se ejecuto correctamente
}

