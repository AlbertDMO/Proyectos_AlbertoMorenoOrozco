#!/usr/bin/env python

'''Implementacion del algoritmo de fibonacci ingenuo'''

import time

def Fibonacci_Ingenuo(n):
	if n == 0 or n == 1:
		return n
	else:
		a = 0
		b = 1
		
		for i in range(2, n+1):
			c = a + b
			a = b
			b = c
		
		return c

def main():
	n = input("Ingrese el valor de n a calcular: ")
	inicio=time.time()
	#resultado = Fibonacci_Ingenuo(n)
	print "El resultado de la F",n,"es",Fibonacci_Ingenuo(n)#resultado
	print "Tiempo de ejecucion : ", (time.time()-inicio)
	

main()


