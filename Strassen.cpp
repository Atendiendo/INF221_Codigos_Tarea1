#include <bits/stdc++.h>
#include <chrono>
using namespace std;

const int SIZE = 2; //Cambiar tamaño de las matrices

/*****
* void addMatrix
******
* Hace la suma entre 2 matrices.
******
* Input:
*   int **A : Matriz 1 a sumar.
*   int **B : Matriz 2 a sumar.
*   int **C : Matriz para guardar la suma.
*   int size: Tamaño de las matrices.
******
* Returns:
*   No se retorna nada ya que la función es de tipo void.
*****/
void addMatrix(int **A, int **B, int **C, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

/*****
* void subtractMatrix
******
* Hace la resta entre 2 matrices.
******
* Input:
*   int **A : Matriz 1 a sumar.
*   int **B : Matriz 2 a sumar.
*   int **C : Matriz para guardar la resta.
*   int size: Tamaño de las matrices.
******
* Returns:
*   No se retorna nada ya que la función es de tipo void.
*****/
void subtractMatrix(int **A, int **B, int **C, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

/*****
* void strassen
******
* Hace el algoritmo de Strassen para multiplicar 2 matrices.
******
* Input:
*   int **A : Matriz 1 a multiplicar.
*   int **B : Matriz 2 a multiplicar.
*   int **C : Matriz para guardar la multiplicacion.
*   int size: Tamaño de las matrices.
******
* Returns:
*   No se retorna nada ya que la función es de tipo void.
*****/
void strassen(int **A, int **B, int **C, int size) {
    if (size == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = size / 2;
    int **A11 = new int*[newSize];
    int **A12 = new int*[newSize];
    int **A21 = new int*[newSize];
    int **A22 = new int*[newSize];
    int **B11 = new int*[newSize];
    int **B12 = new int*[newSize];
    int **B21 = new int*[newSize];
    int **B22 = new int*[newSize];
    int **C11 = new int*[newSize];
    int **C12 = new int*[newSize];
    int **C21 = new int*[newSize];
    int **C22 = new int*[newSize];
    int **M1 = new int*[newSize];
    int **M2 = new int*[newSize];
    int **M3 = new int*[newSize];
    int **M4 = new int*[newSize];
    int **M5 = new int*[newSize];
    int **M6 = new int*[newSize];
    int **M7 = new int*[newSize];
    int **tempA = new int*[newSize];
    int **tempB = new int*[newSize];

    for (int i = 0; i < newSize; i++) {
        A11[i] = new int[newSize];
        A12[i] = new int[newSize];
        A21[i] = new int[newSize];
        A22[i] = new int[newSize];
        B11[i] = new int[newSize];
        B12[i] = new int[newSize];
        B21[i] = new int[newSize];
        B22[i] = new int[newSize];
        C11[i] = new int[newSize];
        C12[i] = new int[newSize];
        C21[i] = new int[newSize];
        C22[i] = new int[newSize];
        M1[i] = new int[newSize];
        M2[i] = new int[newSize];
        M3[i] = new int[newSize];
        M4[i] = new int[newSize];
        M5[i] = new int[newSize];
        M6[i] = new int[newSize];
        M7[i] = new int[newSize];
        tempA[i] = new int[newSize];
        tempB[i] = new int[newSize];
    }

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }

    // M1 = (A11 + A22) * (B11 + B22)
    addMatrix(A11, A22, tempA, newSize);
    addMatrix(B11, B22, tempB, newSize);
    strassen(tempA, tempB, M1, newSize);

    // M2 = (A21 + A22) * B11
    addMatrix(A21, A22, tempA, newSize);
    strassen(tempA, B11, M2, newSize);

    // M3 = A11 * (B12 - B22)
    subtractMatrix(B12, B22, tempB, newSize);
    strassen(A11, tempB, M3, newSize);

    // M4 = A22 * (B21 - B11)
    subtractMatrix(B21, B11, tempB, newSize);
    strassen(A22, tempB, M4, newSize);

    // M5 = (A11 + A12) * B22
    addMatrix(A11, A12, tempA, newSize);
    strassen(tempA, B22, M5, newSize);

    // M6 = (A21 - A11) * (B11 + B12)
    subtractMatrix(A21, A11, tempA, newSize);
    addMatrix(B11, B12, tempB, newSize);
    strassen(tempA, tempB, M6, newSize);

    // M7 = (A12 - A22) * (B21 + B22)
    subtractMatrix(A12, A22, tempA, newSize);
    addMatrix(B21, B22, tempB, newSize);
    strassen(tempA, tempB, M7, newSize);

    // C11 = M1 + M4 - M5 + M7
    addMatrix(M1, M4, tempA, newSize);
    subtractMatrix(tempA, M5, tempB, newSize);
    addMatrix(tempB, M7, C11, newSize);

    // C12 = M3 + M5
    addMatrix(M3, M5, C12, newSize);

    // C21 = M2 + M4
    addMatrix(M2, M4, C21, newSize);

    // C22 = M1 - M2 + M3 + M6
    subtractMatrix(M1, M2, tempA, newSize);
    addMatrix(tempA, M3, tempB, newSize);
    addMatrix(tempB, M6, C22, newSize);

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    for (int i = 0; i < newSize; i++) {
        delete[] A11[i]; delete[] A12[i]; delete[] A21[i]; delete[] A22[i];
        delete[] B11[i]; delete[] B12[i]; delete[] B21[i]; delete[] B22[i];
        delete[] C11[i]; delete[] C12[i]; delete[] C21[i]; delete[] C22[i];
        delete[] M1[i]; delete[] M2[i]; delete[] M3[i]; delete[] M4[i];
        delete[] M5[i]; delete[] M6[i]; delete[] M7[i]; delete[] tempA[i];
        delete[] tempB[i];
    }
    delete[] A11; delete[] A12; delete[] A21; delete[] A22;
    delete[] B11; delete[] B12; delete[] B21; delete[] B22;
    delete[] C11; delete[] C12; delete[] C21; delete[] C22;
    delete[] M1; delete[] M2; delete[] M3; delete[] M4;
    delete[] M5; delete[] M6; delete[] M7; delete[] tempA;
    delete[] tempB;
}

/*****
* void padMatrix
******
* Realiza padding en una matriz para que sea de tamaño potencia de 2.
******
* Input:
*   int** original: La matriz original.
*   int n: El tamaño original de la matriz (n x n).
*   int** padded: La nueva matriz con el padding.
*   int newSize: El nuevo tamaño de la matriz con padding (potencia de 2).
******
* Returns:
*   No se retorna nada ya que la función es de tipo void.
*****/
void padMatrix(int** original, int n, int** padded, int newSize) {
    // Inicializar la nueva matriz con ceros
    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            padded[i][j] = 0;
        }
    }

    // Copiar los elementos de la matriz original a la nueva matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            padded[i][j] = original[i][j];
        }
    }
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
void readMatrix(std::ifstream& file, int** matrix) {
    for (int i = 0; i < SIZE; ++i) {
        std::string line;
        std::getline(file, line);
        std::stringstream ss(line);
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
* Se encarga de llamar a la funcion transposeMatrix, para transponer una matriz.
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
    int newSize = pow(2, ceil(log2(SIZE))); // Calcular la siguiente potencia de 2
    int **mat1 = new int*[SIZE];
    int **mat2 = new int*[SIZE];
    int **rslt = new int*[newSize];

    for (int i = 0; i < SIZE; i++) {
        mat1[i] = new int[SIZE];
        mat2[i] = new int[SIZE];
    }
    for (int i = 0; i < newSize; i++) {
        rslt[i] = new int[newSize];
    }

    ifstream file("DatasetMatrices/matrices_" + to_string(SIZE) + ".txt");

    // Leer la primera matriz
    readMatrix(file, mat1);

    // Leer el separador '-'
    string separator;
    getline(file, separator);

    // Leer la segunda matriz
    readMatrix(file, mat2);

    double total_time = 0.0;

    for (int test = 0; test < 10; ++test) {
        // Inicia el temporizador
        auto start = chrono::high_resolution_clock::now();
        // Padding a las matrices a multiplicar
        int **paddedMat1 = new int*[newSize];
        int **paddedMat2 = new int*[newSize];

        for (int i = 0; i < newSize; i++) {
            paddedMat1[i] = new int[newSize];
            paddedMat2[i] = new int[newSize];
        }

        padMatrix(mat1, SIZE, paddedMat1, newSize);
        padMatrix(mat2, SIZE, paddedMat2, newSize);

        strassen(paddedMat1, paddedMat2, rslt, newSize);

        // Detiene el temporizador
        auto end = chrono::high_resolution_clock::now();

        // Calcular el tiempo transcurrido en microsegundos
        chrono::duration<double, micro> elapsed_time = end - start;
        total_time += elapsed_time.count();

        // Liberar memoria de matrices con padding
        for (int i = 0; i < newSize; i++) {
            delete[] paddedMat1[i];
            delete[] paddedMat2[i];
        }
        delete[] paddedMat1;
        delete[] paddedMat2;
    }

    // Calcular el tiempo promedio
    double average_time = total_time / 10;

    cout << "Resultado: \n";
    printMatrix(rslt);

    // Imprimir el tiempo promedio transcurrido en microsegundos
    cout << "Tiempo promedio: " << average_time << " µs" << endl;

    for (int i = 0; i < SIZE; i++) {
        delete[] mat1[i];
        delete[] mat2[i];
    }
    for (int i = 0; i < newSize; i++) {
        delete[] rslt[i];
    }
    delete[] mat1;
    delete[] mat2;
    delete[] rslt;

    return 0;
}

//Codigo generado con chatgpt