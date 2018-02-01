#!/usr/bin/env python
import sys
import time

'''Implementacion del algoritmo de fibonacci recursivo'''

def main():
	# pone un limite a las recursiones maximas en python
	sys.setrecursionlimit(2000)
	n = input("Ingrese el valor de n a calcular: ")
	inicio=time.time()
	print "El resultado de la F",n,"es",Fibonacci_Recursivo(n)
	print "Tiempo de ejecucion : ", (time.time()-inicio)


def Fibonacci_Recursivo(n):
	if n == 0 or n == 1:
		return n
	else:
		return Fibonacci_Recursivo(n-1)+Fibonacci_Recursivo(n-2)

main()


