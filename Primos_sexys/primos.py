def primo(y):
    i=2
    while i < y:
        if y%i == 0:
            break
        else:
            i+=1
            val = True
        return y
    

print(primo(4))
print(primo(5))
print(primo(6))
print(primo())