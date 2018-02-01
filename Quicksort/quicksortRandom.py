import random

def crearListaAl(n):
	MAX_VAL = input("Maximo valor: ")
	lista = []

	for i in range(n):
		lista.append(random.randint(0,MAX_VAL))
	return lista

def quickSort(lista):
	quickSortR(lista, 0, len(lista)-1)

def quickSortR(lista,primerValor,ultimoValor):	
	
	if primerValor < ultimoValor:
		pMedio = particion(lista, primerValor, ultimoValor)
		
		quickSortR(lista, primerValor, pMedio-1)
		quickSortR(lista, pMedio+1, ultimoValor)


def particion(lista, primerValor, ultimoValor):
	# Quicksort Random
	valorRan = random.randint(primerValor, ultimoValor)
	pivote = lista[valorRan]
	temp = lista[primerValor]
	lista[primerValor] = pivote
	lista[valorRan] = temp
	
	pIzquierda = primerValor+1
	pDerecha = ultimoValor
	done = False
	
	while not done:

		while pIzquierda <= pDerecha and lista[pIzquierda] <= pivote:
			pIzquierda = pIzquierda+1

		while lista[pDerecha] >= pivote and pDerecha >= pIzquierda:
			pDerecha = pDerecha-1

		if pDerecha < pIzquierda:
			done = True
		else:
			temp = lista[pIzquierda]
			lista[pIzquierda] = lista[pDerecha]
			lista[pDerecha] = temp

	temp = lista[primerValor]
	lista[primerValor] = lista[pDerecha]
	lista[pDerecha] = temp

	return pDerecha

n = input("Valor de n: ")
lista = crearListaAl(n)
print "\nLista sin ordenar:", (lista)
quickSort(lista)
print "Lista Ordenada:", (lista), "\n"

