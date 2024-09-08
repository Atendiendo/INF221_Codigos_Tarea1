import os
import numpy as np

# Crear la carpeta 'DatasetMatrices' si no existe
os.makedirs('DatasetMatrices', exist_ok=True)

# Tamaños de las matrices
sizes = [2, 5, 10, 15, 30, 50, 100, 250]

# Generar y guardar matrices
for size in sizes:
    # Generar dos matrices
    matrix1 = np.random.randint(0, 100, size=(size, size))
    matrix2 = np.random.randint(0, 100, size=(size, size))
    
    # Guardar en un archivo dentro de 'DatasetMatrices'
    filename = os.path.join('DatasetMatrices', f'matrices_{size}.txt')
    with open(filename, 'w') as f:
        # Guardar primera matriz
        np.savetxt(f, matrix1, fmt='%d')
        
        # Separar con una línea
        f.write('-\n')
        
        # Guardar segunda matriz
        np.savetxt(f, matrix2, fmt='%d')

#Codigo generado con chatgpt