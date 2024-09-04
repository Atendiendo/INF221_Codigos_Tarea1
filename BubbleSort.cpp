// Optimized implementation of Bubble sort
#include <bits/stdc++.h>
#include <chrono>
using namespace std;

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << " " << arr[i];
}

// Driver program to test above functions
int main()
{
    //Cambiar aca el tipo de arreglo
    std::ifstream inputFile("random_arrays.txt");
    std::string line;
    //Cambiar aca el tamaño del arreglo [10 - 10^5]
    int targetSize = 100000;
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

        bubbleSort(arrCopy, N);

        // Detiene el temporizador
        auto end = std::chrono::high_resolution_clock::now();

        // Calcular el tiempo transcurrido en microsegundos
        std::chrono::duration<double, std::micro> elapsed_time = end - start;

        // Sumar el tiempo de esta prueba
        total_time += elapsed_time.count();

        // Imprimir el tiempo transcurrido en microsegundos para esta prueba
        std::cout << "Prueba " << (test + 1) << " - Tiempo transcurrido: " << elapsed_time.count() << " µs" << std::endl;
        /*
        cout << "Sorted array: \n";
        printArray(arr, N);
        cout << "\n";
        */
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
// This code is contributed by shivanisinghss2110

//Sacado de:
//https://www.geeksforgeeks.org/bubble-sort-algorithm/