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
    std::ifstream inputFile("inverted_arrays.txt");
    std::string line;
    //Cambiar aca el tamaño del arreglo [10 - 10^5]
    int targetSize = 10;
    int N;
    int* arr = nullptr;

    if (!inputFile) {
        std::cerr << "No se pudo abrir el archivo." << std::endl;
        return 1;
    }

    // Leer el archivo línea por línea
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);

        // Verifica si la línea contiene el tamaño del arreglo
        if (ss >> N && N == targetSize) {
            // Reservar memoria para el arreglo
            arr = new int[N];

            // Lee la siguiente línea que contiene los números
            if (std::getline(inputFile, line)) {
                std::stringstream ssNumbers(line);
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
        std::copy(arr, arr + N, arrCopy);

        // Inicia el temporizador
        auto start = std::chrono::high_resolution_clock::now();

        sort(arrCopy, arrCopy + N);

        // Detiene el temporizador
        auto end = std::chrono::high_resolution_clock::now();

        // Calcular el tiempo transcurrido en microsegundos
        std::chrono::duration<double, std::micro> elapsed_time = end - start;

        // Sumar el tiempo de esta prueba
        total_time += elapsed_time.count();

        // Imprimir el tiempo transcurrido en microsegundos para esta prueba
        std::cout << "Prueba " << (test + 1) << " - Tiempo transcurrido: " << elapsed_time.count() << " µs" << std::endl;
        
        cout << "Arreglo ordenado: \n";
        printArray(arrCopy, N);
        cout << "\n";

        // Liberar la memoria
        delete[] arrCopy;
    }

    // Calcular el promedio del tiempo
    cout << "\n";
    double average_time = total_time / 10.0;
    std::cout << "Tiempo promedio: " << average_time << " µs" << std::endl;

    // Liberar la memoria del arreglo original
    delete[] arr;

    return 0;
}