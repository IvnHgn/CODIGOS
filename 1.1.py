import random

# Generar el vector de forma aleatoria
vector = [random.randint(100, 999) for _ in range(20)]

# Mostrar el vector generado
print("Vector generado aleatoriamente:")
print(vector)

# a. Encontrar el menor valor y contar cuántas veces se repite
min_value = min(vector)
min_count = vector.count(min_value)
print("\nMenor valor en el vector:", min_value)
print("Se repite", min_count, "veces.")

# b. Encontrar el mayor valor y sus posiciones
max_value = max(vector)
max_positions = [i for i, x in enumerate(vector) if x == max_value]
print("\nMayor valor en el vector:", max_value)
print("Se encuentra en la(s) posición(es):", max_positions)
