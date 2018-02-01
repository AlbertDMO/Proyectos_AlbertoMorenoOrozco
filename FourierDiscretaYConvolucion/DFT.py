#!/usr/bin/env python

#import math
import cmath

def DFT(f, N):
	Fu = []
	for u in range(N):
		temp = 0
		for x in range(N):
			temp += f[x]*cmath.exp(((-2j)*cmath.pi*x*u)/(N+0j))
			print temp
		temp /= (N+0j)
		z = complex(round(temp.real,4),round(temp.imag,4))
		print "append",z
		Fu.append(z)
	return Fu

def main():
	#Obtener los valores de f(x)
	f = input("Dame los valores de la funcion f(x) separados por comas: \n")
	N = len(f)
	#DFT
	resultado = DFT(f, N)
	
	print "\nF(u)=",resultado
	#print "Posicion de origen, (n0=0)=", r_origen

main()
input()


