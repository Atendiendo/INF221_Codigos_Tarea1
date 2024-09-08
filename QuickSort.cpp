#include <bits/stdc++.h>
using namespace std;

/*****
* int partition
******
* Recorre todo el subarreglo entregado desde arr[low...high],
* para ir moviendo el elemento del pivote a su index ordenado
* y para conocer su index ordenado
******
* Input:
*   int arr[]: El arreglo a ordenar.
*   int low: Index izquierdo del subarreglo.
*   int high: Index derecho del subarreglo.
*   int pivot: Elemento del pivote elegido.
******
* Returns:
*   int: Retorna el index del pivote en su posicion ordenada
*****/
//rearrange the elements to get the actual pivot index
int partition(int arr[], int low, int high, int pivot) {
	int PIndex = low;
    
    //Recorrer el arreglo desde low hasta high
    for(int i=low;i<=high;i++) {   
        //Si el elemento actual es menor al elemento del pivote
        if(arr[i]<=pivot) {
            // Swap PIndex element with current element.
            //Intercambiar elemento del pivote con el actual
            swap(arr[PIndex],arr[i]);
            //Incrementar indice pivote
            PIndex++;
        }
    }
    
    PIndex--;
    
	return PIndex;
}

/*****
* void quickSort
******
* Se escoge el ultimo elemento como pivote y llamando a la
* funcion partition(), se conoce su indice ordenado.
* Conociendo su indice, se separa el subarreglo en 2,
* con centro, el indice pivote.
* Esto se hace recursivamente hasta que los subarreglos solo tienen
* 1 elemento.
******
* Input:
*   int arr[]: El arreglo a ordenar.
*   int low: Index izquierdo del subarreglo.
*   int high: Index derecho del subarreglo.
******
* Returns:
*   No se retorna nada ya que la función es de tipo void.
*****/
// We divide the array into two subarrays around 
// the pivot and recursively call for them separately.
void quickSort(int arr[], int low, int high) {
	if(low < high) {
	    int pivot = arr[high];
        
        //Rearrange and get the actual pivot index
	    int PIndex = partition(arr, low, high, pivot);
	
        // solve for the left and right subarrays
        quickSort(arr, low, PIndex-1);
        quickSort(arr, PIndex+1, high);
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
* Se encarga de llamar a la funcion quickSort
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
    ifstream inputFile("DatasetArreglos/ordered_arrays.txt");
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

        quickSort(arrCopy, 0 , N-1);

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

//Sacado de:
//https://www.scaler.com/topics/quick-sort-in-cpp/