import random

def crearListaAl(n):
    MAX_VAL = 1000
    lista = []

    for i in range(n):
        lista.append(random.randint(0,MAX_VAL))
    return lista

def quicksort(lista, primero, ultimo):
    centro = ultimo/2
    pivote = lista[centro]
    i = primero
    j = ultimo
    hecho = True

    while hecho:
        '''
        while lista[i] < pivote:
            i = i+1
        while lista[j] > pivote:
            j = j-1
        '''
        while i <= j and lista[i] <= pivote:
            i = i+1

        while lista[j] >= pivote and j >= i:
            j = j-1
            
        if i < j:
            hecho = False
        else:
            aux = lista[i]
            lista[i] = lista[j]
            lista[j] = aux

        if primero < j:
            quicksort(lista, primero, j)
            
        if i < ultimo:
            quicksort(lista, i, ultimo)

n = 10
lista = crearListaAl(n)
print(lista)
quicksort(lista, 0, len(lista)-1)
print(lista)
