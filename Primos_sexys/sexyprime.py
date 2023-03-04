
def sexyprimo(y):
    i=2

    while i < y:
        if y%i == 0:
            break
        else:
            i+=1

    if y != None:
        z=y+6
        j=2
        while j < z:
            if z%i == 0:
                break
            else:
                i+=1

    if y != z != None:
        print(y,z)

sexyprimo(21)
    


    