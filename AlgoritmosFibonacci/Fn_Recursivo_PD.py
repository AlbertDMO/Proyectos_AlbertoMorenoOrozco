#!/usr/bin/env python
import sys
import time

'''Implementacion del algoritmo de fibonacci recursivo con Programacion Dinamica'''

def main():
	# pone un limite a las recursiones maximas en python
	sys.setrecursionlimit(2000)
	n = input("Ingrese el valor de n a calcular: ")
	inicio=time.time()
	tabla = creaTabla(n)
	#print tabla
	#n = Fibonacci_Recursivo_PD(n, tabla)
	print "El resultado de la F",n,"es",Fibonacci_Recursivo_PD(n, tabla)
	print "Tiempo de ejecucion : ", (time.time()-inicio)

	
def Fibonacci_Recursivo_PD(n, tabla):
	if tabla[n] != -1:
		return tabla[n]
	else:
		tabla[n] = Fibonacci_Recursivo_PD(n-1, tabla)+Fibonacci_Recursivo_PD(n-2, tabla)
		return tabla[n]
		
def creaTabla(n):
	tabla = []
	for i in range(0, n+1):
		if i <= 2:
			tabla.append(1)
		else:
			tabla.append(-1)
	return tabla

main()


