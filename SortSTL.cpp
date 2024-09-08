#include <bits/stdc++.h>
using namespace std;

/*****
* void printArray
******
* Imprime un arreglo por consola
******
* Input:
*   int arr[]: El arreglo a imprimir
*   int n: Tamaño del arreglo.
******
* Returns:
*   No se retorna nada ya que la función es de tipo void.
*****/
void printArray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++)
        cout << " " << arr[i];
}

/*****
* int main
******
* Se encarga de leer los archivos de prueba
* Se encarga de llamar a la funcion Sort de la STL
* Se encarga de medir el tiempo de cada prueba y sacar el promedio
******
* Input:
*   No recibe inputs
******
* Returns:
*   int: Retorna 0 si no hay problemas en la ejecucion.
*****/
int main() {
    //Cambiar aca el tipo de arreglo
    ifstream inputFile("DatasetArreglos/inverted_arrays.txt");
    string line;
    //Cambiar aca el tamaño del arreglo [10 - 10^5]
    int targetSize = 10;
    int N;
    int* arr = nullptr;

    if (!inputFile) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    // Leer el archivo línea por línea
    while (getline(inputFile, line)) {
        stringstream ss(line);

        // Verifica si la línea contiene el tamaño del arreglo
        if (ss >> N && N == targetSize) {
            // Reservar memoria para el arreglo
            arr = new int[N];

            // Lee la siguiente línea que contiene los números
            if (getline(inputFile, line)) {
                stringstream ssNumbers(line);
                int i = 0;
                int number;
                while (ssNumbers >> number && i < N) {
                    arr[i++] = number;
                }
                break;  // Salir del bucle una vez que se ha encontrado el arreglo deseado
            }
        }
    }

    inputFile.close();

    double total_time = 0.0;

    for (int test = 0; test < 10; ++test) {
        // Crear una copia del arreglo original para cada prueba
        int* arrCopy = new int[N];
        copy(arr, arr + N, arrCopy);

        // Inicia el temporizador
        auto start = chrono::high_resolution_clock::now();

        sort(arrCopy, arrCopy + N);

        // Detiene el temporizador
        auto end = chrono::high_resolution_clock::now();

        // Calcular el tiempo transcurrido en microsegundos
        chrono::duration<double, micro> elapsed_time = end - start;

        // Sumar el tiempo de esta prueba
        total_time += elapsed_time.count();

        // Imprimir el tiempo transcurrido en microsegundos para esta prueba
        cout << "Prueba " << (test + 1) << " - Tiempo transcurrido: " << elapsed_time.count() << " µs" << endl;
        
        cout << "Arreglo ordenado: \n";
        printArray(arrCopy, N);
        cout << "\n";

        // Liberar la memoria
        delete[] arrCopy;
    }

    // Calcular el promedio del tiempo
    cout << "\n";
    double average_time = total_time / 10.0;
    cout << "Tiempo promedio: " << average_time << " µs" << endl;

    // Liberar la memoria del arreglo original
    delete[] arr;

    return 0;
}