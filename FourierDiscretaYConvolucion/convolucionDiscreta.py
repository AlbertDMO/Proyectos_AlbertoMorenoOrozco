#!/usr/bin/env python

def listaAsociativa(origen, tamano):
	l = []
	for i in range(0,origen):
		l.append(-i)
		l.sort()
	j = 1
	for i in range(origen,tamano):
		l.append(j)
		j += 1
	return l
	
def convolucion(h, h_asoc, x, x_asoc):
	suma = 0
	cont = 0
	resultado = []
	low = x_asoc[0] - h_asoc[0]
	high = x_asoc[len(x_asoc)-1] - h_asoc[len(h_asoc)-1] + 1
	
	for n0 in range(low, high):
		h_asoc_temp = h_asoc[0:len(h_asoc)]
		
		for j in range(0, len(h_asoc_temp)):
			h_asoc_temp[j] = h_asoc_temp[j] + n0
		
		for j in range(0,len(h_asoc_temp)):
			if h_asoc_temp[j] in x_asoc:
				suma += h[j]*x[x_asoc.index(h_asoc_temp[j])]
		
		resultado.append(suma)
		suma = 0
		cont += 1
		if n0 == 0:
			origen = cont 
		
	return resultado, origen
	

def main():
	#Obtener los valores de h(n)
	h = input("Dame los valores de la funcion h(n) separados por comas: \n")
	h_origen = input("Posicion del valor de origen: ")
	h_asoc = listaAsociativa(h_origen, len(h))
	#print h
	#print h_asoc
	
	#obtener los valores de x(n)
	x = input("Dame los valores de la funcion x(n) separados por comas: \n")
	x_origen = input("Posicion del valor de origen: ")
	x_asoc = listaAsociativa(x_origen, len(x))
	#print x
	#print x_asoc
	
	#obtenemos h(-k)
	for i in range(0,len(h_asoc)):
		h_asoc[i] = h_asoc[i]*(-1)
	
	#Convolucion
	resultado, r_origen = convolucion(h, h_asoc, x, x_asoc)
	
	print "\ny(n0)=",resultado
	print "Posicion de origen, (n0=0)=", r_origen

main()
input()

