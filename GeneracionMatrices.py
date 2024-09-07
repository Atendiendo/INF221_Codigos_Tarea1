import numpy as np

# Tamaños de las matrices
sizes = [5, 10, 100, 250, 500, 1000]

# Generar y guardar matrices
for size in sizes:
    # Generar dos matrices
    matrix1 = np.random.randint(0, 100, size=(size, size))
    matrix2 = np.random.randint(0, 100, size=(size, size))
    
    # Guardar en un archivo
    filename = f'matrices_{size}.txt'
    with open(filename, 'w') as f:
        # Guardar primera matriz
        np.savetxt(f, matrix1, fmt='%d')
        
        # Separar con una línea
        f.write('-\n')
        
        # Guardar segunda matriz
        np.savetxt(f, matrix2, fmt='%d')

#Codigo generado con chatgpt