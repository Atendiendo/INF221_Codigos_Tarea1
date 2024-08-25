import numpy as np

def write_array_to_file(filename, arrays):
    with open(filename, 'w') as file:
        for size, array in arrays:
            file.write(f"{size}\n")
            file.write(' '.join(map(str, array)) + '\n')

# Ordenado
ordered_arrays = [
    (10**1, list(range(10**1))),
    (10**2, list(range(10**2))),
    (10**3, list(range(10**3))),
    (10**4, list(range(10**4))),
]

write_array_to_file('ordered_arrays.txt', ordered_arrays)

# Invertido
inverted_arrays = [
    (10**1, list(range(10**1, 0, -1))),
    (10**2, list(range(10**2, 0, -1))),
    (10**3, list(range(10**3, 0, -1))),
    (10**4, list(range(10**4, 0, -1))),
]

write_array_to_file('inverted_arrays.txt', inverted_arrays)

# Randomizado
def random_array(size):
    return np.random.permutation(size).tolist()

random_arrays = [
    (10**1, random_array(10**1)),
    (10**2, random_array(10**2)),
    (10**3, random_array(10**3)),
    (10**4, random_array(10**4)),
]

write_array_to_file('random_arrays.txt', random_arrays)