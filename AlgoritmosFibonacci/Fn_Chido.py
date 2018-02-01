#!/usr/bin/env python
import time

'''Implementacion del algoritmo de fibonacci Chido'''

def main():
	a=input("Ingrese n :")
	inicio=time.time()
	print "Resultado:", (fibonacci(a))
	print "Tiempo de ejecucion : ", (time.time()-inicio) 

def fibonacci(n):
    arreglo=[[1,1],[1,0]]
    arreglodos=exp(arreglo,n)
    return arreglodos[1][0]        
    
def exp(a,n):
    if n==1:
        return a
    if n%2==0:
        x=exp(a,n/2)
        return mult(x,x)
    if n%2==1:
        x=exp(a,(n-1)/2)
        return mult(mult(x,x),a)

def mult(a,b):
    arregloaux=[[0,0],[0,0]]
    arregloaux[0][0]=(a[0][0]*b[0][0])+(a[0][1]*b[1][0])
    arregloaux[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1]
    arregloaux[1][0]=a[1][0]*b[0][0]+a[1][1]*b[1][0]
    arregloaux[1][1]=a[1][0]*b[0][1]+a[1][1]*b[1][1]
    return arregloaux    

main()


