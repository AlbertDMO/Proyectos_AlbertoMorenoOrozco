#!/usr/bin/env python
import sys
import math
import time

'''Implementacion del algoritmo de fibonacci recursivo con Programacion Dinamica'''

def main():
	#Pone un limite a las recursiones maximas en python
	#sys.setrecursionlimit(2000)
	n = input("Ingrese el valor de n a calcular: ")
	inicio=time.time()
	print "El resultado de la F",n,"es",Fibonacci_Tramposo(n)
	print "Tiempo de ejecucion : ", (time.time()-inicio)	
	
def Fibonacci_Tramposo(n):
	return myPow((1 + math.sqrt(5)) /2, n) / math.sqrt(5)

def myPow(a, n):
	if n == 0:
		return 1
	elif n == 1:
		return a
	elif esPar(n):
		t = myPow(a, n/2)
		return t*t
	else:
		t = myPow(a, n/2)
		return t*t*a

def esPar(n):
	if n % 2:
		return False
	else:
		return True

main()
