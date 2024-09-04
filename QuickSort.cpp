#include <bits/stdc++.h>
using namespace std;

//rearrange the elements to get the actual pivot index
int partition(int arr[], int low, int high, int pivot){
	int PIndex = low;
    
	// Traverse the array from low to high
    for(int i=low;i<=high;i++) {   
        
        // If the current element is smaller than the pivot element
        if(arr[i]<=pivot) {
            // Swap PIndex element with current element.
            swap(arr[PIndex],arr[i]);
            // Increment the pointer.
            PIndex++;
        }
    }
    
    PIndex--;
    
	return PIndex;
}

// We divide the array into two subarrays around 
// the pivot and recursively call for them separately.
void quickSort(int arr[], int low, int high){
	if(low < high) {
	    int pivot = arr[high];
        
            //Rearrange and get the actual pivot index
	    int PIndex = partition(arr, low, high, pivot);
	
            // solve for the left and right subarrays
            quickSort(arr, low, PIndex-1);
            quickSort(arr, PIndex+1, high);
	}
}

// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << " " << arr[i];
}

int main()
{
	//Cambiar aca el tipo de arreglo
    std::ifstream inputFile("ordered_arrays.txt");
    std::string line;
    //Cambiar aca el tamaño del arreglo [10 - 10^5]
    int targetSize = 10000;
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

        quickSort(arrCopy, 0 , N-1);

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
//https://www.scaler.com/topics/quick-sort-in-cpp/