#!/usr/bin/env python

import Fn_Chido
import Fn_Ingenuo
import Fn_Recursivo
import Fn_Recursivo_PD
import Fn_Tramposo

def main():
	print "1: Fn_Ingenuo"
	print "2: Fn_Recursivo"
	print "3: Fn_Recursivo_PD"
	print "4: Fn_Tramposo"
	print "5: Fn_Chido"
	a = input("Ingrese la opcion deseada: ")
	
	if a == 1:
		Fn_I()
	elif a == 2:
		Fn_R()
	elif a == 3:
		Fn_PD()
	elif a == 4:
		Fn_T()
	elif a == 5:
		Fn_Ch()
	else:
		print "opcion invalida"
		main()


main()

