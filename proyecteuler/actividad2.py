def max_factorprimo(x):
    
    f = 2   

    while f <= x:
        if x % f == 0:
            x //= f
        else:
            f += 1

    return f

for i in [10,30,35,210,29398,29400,600851475243]:
    print(max_factorprimo(i)) 