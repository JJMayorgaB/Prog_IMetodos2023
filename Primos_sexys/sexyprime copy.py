
def comprueba_primo(n):
    #Comprueba si el argumento de entrada n es o no es un numero primo
    if n <= 1: #n debe ser un numero natural
        return False
    for i in range(2, int(n/2)):
        if n % i == 0:
            return False
    return True

def sexyprime(n):
    k = 0
    i = 5 # El primer primo sexy es (5, 11)
    while True:
        if comprueba_primo(i) and comprueba_primo(i+6):
            k += 1
            if k == n: # Se ha encontrado la n-esima pareja de primos sexys
                return (i, i+6)
        i += 1

# Vamos a sacar los primero N parejas de primos sexys
for N in range(1,10) :
    print(sexyprime(N))
