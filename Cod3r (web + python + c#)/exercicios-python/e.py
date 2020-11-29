def dig_pow(n, p):
    stack: list = []
    sum: int = 0
    limit: int = n
    pot: int = p

    while limit > 0:
        digit: int = limit % 10
        stack.append(digit)
        limit //= 10
    stack.reverse()
   
    for num in stack:
        sum += num ** pot
        pot += 1
  
    k: int = sum // n
    if sum % n != 0:
        return -1
    else:
        return k


numero = int(input("n: "))
potencia = int(input("p: "))
print(dig_pow(numero, potencia))