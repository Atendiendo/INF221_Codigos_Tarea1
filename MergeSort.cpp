#include <bits/stdc++.h>
using namespace std;

/*****
* void merge
******
* Junta 2 subarreglos de arr[]
* Primer subarreglo es arr[l..m]
* Segundo subarreglo es arr[m+1..r]
* Se dejan ordenados ambos subarreglos dentro de arr[]
******
* Input:
*   int arr[]: El arreglo a ordenar.
*   int l: Index izquierdo del primer subarreglo.
*   int m: Index derecho del primer subarreglo,
*       e index izquierdo de segundo subarreglo.
*   int r: Index derecho de segundo subarreglo.
******
* Returns:
*   No se retorna nada ya que la función es de tipo void.
*****/
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    //Crear arreglos temporales
    int L[n1], R[n2];

    //Copiar datos a arreglos temporales L[] y R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    //Junta los arreglos temporales devuelta en arr[l..r]
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

    //Copia los elementos restantes de L[],
    //si es no esta vacio
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    //Copia los elementos restantes de R[],
    //si es no esta vacio
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/*****
* void mergeSort
******
* Separa recursivamente el arreglo a la mitad,
* para luego cuando solo quede 1 elemento se empieze a devolver la
* recursividad, para empezar a ordenar y juntar todo dentro de merge().
******
* Input:
*   int arr[]: El arreglo a ordenar.
*   int l: Index izquierdo del subarreglo.
*   int r: Index derecho del subarreglo.
******
* Returns:
*   No se retorna nada ya que la función es de tipo void.
*****/
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

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
* Se encarga de llamar a la funcion mergeSort
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
    ifstream inputFile("DatasetArreglos/random_arrays.txt");
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

        mergeSort(arrCopy, 0, N - 1);

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

    cout << "\n";
    // Calcular el promedio del tiempo
    double average_time = total_time / 10.0;
    cout << "Tiempo promedio: " << average_time << " µs" << endl;

    // Liberar la memoria del arreglo original
    delete[] arr;

    return 0;
}

//Sacado de:
//https://www.geeksforgeeks.org/merge-sort/