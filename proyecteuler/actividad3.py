def fib(n):

    a,b =1,2
    k=0

    while a<=n:

        if a%2 != 0:
            k+=a

        a,b =b,a+b

    return k

for i in [2,4,6,7,10,13,14,2120,212000]:
    print(fib(i))


#este es mi tercer cambio en git