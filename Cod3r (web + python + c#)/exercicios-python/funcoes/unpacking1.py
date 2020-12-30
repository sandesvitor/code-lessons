'''
 *args    => tupla

 **kwargs => dict
'''


#packing
def soma_de_n(*numeros):
    print(type(numeros))
    soma = 0
    for n in numeros:
        soma += n
    return soma

#unpacking
tupla_nums = (1, 4, 5, 7)
print(soma_de_n(*tupla_nums))

print(soma_de_n(1,2,3,4,5,6,7,8,9,10))
print(soma_de_n(1, 20000))