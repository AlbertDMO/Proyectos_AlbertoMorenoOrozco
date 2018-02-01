import random
#random.seed(1234)

def arregloRand(n):
    valorMax = 100 # I don't want to get Java / C++ into trouble
    arreglo = [n]*0
    for i in xrange(n):
        arreglo.append([random.randint(0,valorMax)])
    return arreglo

def guardarArre(arregloA, filename):
    f = open(filename, 'w')
    for i, arreglo in enumerate([arregloA]):
        if i != 0:
            f.write("\n")
        for line in arreglo:
            f.write("\t".join(map(str, line)) + "\n")
n = 10
arregloA = arregloRand(n)
guardarArre(arregloA, "arregloQS.in") 