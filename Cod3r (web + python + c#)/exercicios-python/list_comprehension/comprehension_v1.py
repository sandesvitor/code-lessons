# [ <expression> for item in list, if <condition>]
dobros = [i * 2 for i in range(10) if i % 2 == 0]
print(dobros)

# generators:
generator = (i ** 2 for i in range(10) if i % 2 == 0)
# print(next(generator)) # saida 0
# print(next(generator)) # saida 4
# print(next(generator)) # saida 16
# print(next(generator)) # saida 36
# print(next(generator)) # saida 64
#print(next(generator)) # saida Erro!

for numero in generator:
    print(numero)



# consome menos memória:
import sys

a = [i * 2 for i in range(1000) if i % 2 == 0]
b = (i * 2 for i in range(1000) if i % 2 == 0)

print(sys.getsizeof(a))
print(sys.getsizeof(b))