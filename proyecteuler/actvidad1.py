def comprueba_primo(n):
    #Comprueba si el argumento de entrada n es o no es un numero primo
    if n <= 1: #n debe ser un numero natural
        return False
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

def sumaprimos(x):  

    k=0 

    for i in range(1,(x+1)):
    
        if comprueba_primo(i) == True:
            k+=i

    return k

print(sumaprimos(3))
print(sumaprimos(10))
print(sumaprimos(98))
