#include <bits/stdc++.h>
#include <chrono>
using namespace std;

const int SIZE = 5; //Cambiar tamaño de las matrices

/*****
* int** mulMat
******
* Se hace la multiplicacion entre 2 matrices, de la forma tradicional.
******
* Input:
*   int mat1[SIZE][SIZE]: Arreglo de arreglos con la primera matriz.
*   int mat2[SIZE][SIZE]: Arreglo de arreglos con la segunda matriz.
******
* Returns:
*   int**: Retorna una arreglo de arreglos que contiene el resultado
*       de la multiplicación.
*****/
int** mulMat(int mat1[SIZE][SIZE], int mat2[SIZE][SIZE]) {
    int** rslt = new int*[SIZE];
    for (int i = 0; i < SIZE; i++) {
        rslt[i] = new int[SIZE];
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            rslt[i][j] = 0;

            for (int k = 0; k < SIZE; k++) {
                rslt[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return rslt;
}

/*****
* void freeMatrix
******
* Libera la memoria de una matriz.
******
* Input:
*   int** matrix: Matriz a la cual se le libera la memoria.
******
* Returns:
*   No se retorna nada ya que la función es de tipo void.
*****/
void freeMatrix(int** matrix) {
    for (int i = 0; i < SIZE; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

/*****
* void readMatrix
******
* Lee la matriz del archivo dado para guardarlo en un arreglo de arreglos.
******
* Input:
*   ifstream& file: Archivo a leer.
*   int matrix[SIZE][SIZE]: Matriz para guardar el input.
******
* Returns:
*   No se retorna nada ya que la función es de tipo void.
*****/
void readMatrix(ifstream& file, int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        string line;
        getline(file, line);
        stringstream ss(line);
        for (int j = 0; j < SIZE; ++j) {
            ss >> matrix[i][j];
        }
    }
}

/*****
* void printMatrix
******
* Imprime una matriz por consola.
******
* Input:
*   int** matrix: La matriz a imprimir.
******
* Returns:
*   No se retorna nada ya que la función es de tipo void.
*****/
void printMatrix(int** matrix) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

/*****
* int main
******
* Se encarga de leer los archivos de prueba.
* Se encarga de llamar a la funcion mulMat.
* Se encarga de medir el tiempo de la multiplicacion.
******
* Input:
*   No recibe inputs.
******
* Returns:
*   int: Retorna 0 si no hay problemas en la ejecucion.
*****/
int main() {
    int mat1[SIZE][SIZE]; // Arreglo para la primera matriz
    int mat2[SIZE][SIZE]; // Arreglo para la segunda matriz

    ifstream file("DatasetMatrices/matrices_" + to_string(SIZE) + ".txt");

    if (!file) {
        cerr << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    // Leer la primera matriz
    readMatrix(file, mat1);

    // Leer el separador '-'
    string separator;
    getline(file, separator);

    // Leer la segunda matriz
    readMatrix(file, mat2);

    file.close();

    double total_time = 0.0;

    for (int test = 0; test < 10; ++test) {
        // Inicia el temporizador
        auto start = chrono::high_resolution_clock::now();

        // Realizar la multiplicación de matrices
        int** result = mulMat(mat1, mat2);

        // Detiene el temporizador
        auto end = chrono::high_resolution_clock::now();

        // Calcular el tiempo transcurrido en microsegundos
        chrono::duration<double, micro> elapsed_time = end - start;

        // Sumar el tiempo de esta prueba
        total_time += elapsed_time.count();

        // Imprimir el resultado y el tiempo transcurrido
        cout << "Prueba " << (test + 1) << " - Tiempo transcurrido: " << elapsed_time.count() << " µs" << endl;

        cout << "Resultado:\n";
        printMatrix(result);
        cout << "\n";

        // Liberar la memoria de la matriz resultado
        freeMatrix(result);
    }

    // Calcular el promedio del tiempo
    double average_time = total_time / 10.0;
    cout << "Tiempo promedio: " << average_time << " µs" << endl;

    return 0;
}

//Sacado de:
//https://www.geeksforgeeks.org/c-program-multiply-two-matrices/