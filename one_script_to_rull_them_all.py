import subprocess
import itertools

numero_de_elementos = [100, 200, 500, 1000, 2000, 5000, 7500, 10000, 15000, 30000,
                       50000, 75000, 100000, 200000, 500000, 750000, 1000000, 1250000, 
                       1500000, 2000000]
tipo_de_vetor = ["a", "d", "o", "po"]

combinacoes = list(itertools.product(numero_de_elementos, tipo_de_vetor))

for numero_de_elementos, tipo_de_vetor in combinacoes:
    comando = f"./insertion_sort {numero_de_elementos} -{tipo_de_vetor} > results_insertion.txt"
    try:
        subprocess.run(comando, shell=True, check=True)
    except subprocess.CalledProcessError as e:
        print(f"Erro ao executar o comando: {comando}")
        print(e)