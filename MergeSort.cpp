#include <bits/stdc++.h>
using namespace std;

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[],
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[],
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// l is for left index and r is right index of the
// sub-array of arr to be sorted
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << " " << arr[i];
}

// Driver code
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

        mergeSort(arrCopy, 0, N - 1);

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


//Sacado de:
//https://www.geeksforgeeks.org/merge-sort/