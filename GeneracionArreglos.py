import os
import numpy as np

def write_array_to_file(filename, arrays):
    # Crear la carpeta 'DatasetArreglos' si no existe
    os.makedirs('DatasetArreglos', exist_ok=True)
    
    # Especificar la ruta completa del archivo
    filepath = os.path.join('DatasetArreglos', filename)
    
    with open(filepath, 'w') as file:
        for size, array in arrays:
            file.write(f"{size}\n")
            file.write(' '.join(map(str, array)) + '\n')

# Ordenado
ordered_arrays = [
    (10**1, list(range(10**1))),
    (10**2, list(range(10**2))),
    (10**3, list(range(10**3))),
    (10**4, list(range(10**4))),
    (10**5, list(range(10**5))),
    (10**6, list(range(10**6))),
]

write_array_to_file('ordered_arrays.txt', ordered_arrays)

# Invertido
inverted_arrays = [
    (10**1, list(range(10**1, 0, -1))),
    (10**2, list(range(10**2, 0, -1))),
    (10**3, list(range(10**3, 0, -1))),
    (10**4, list(range(10**4, 0, -1))),
    (10**5, list(range(10**5, 0, -1))),
    (10**6, list(range(10**6, 0, -1))),
]

write_array_to_file('inverted_arrays.txt', inverted_arrays)

# Randomizado
def random_array(size):
    return np.random.randint(0, size, size).tolist()

random_arrays = [
    (10**1, random_array(10**1)),
    (10**2, random_array(10**2)),
    (10**3, random_array(10**3)),
    (10**4, random_array(10**4)),
    (10**5, random_array(10**5)),
    (10**6, random_array(10**6)),
]

write_array_to_file('random_arrays.txt', random_arrays)

#Codigo generado con chatgpt