# Streaming de arquivos ==> ler o arquivo sob demanda!


try:
    arquivo = open('pessoas.csv')

    for registro in arquivo:
        print('Nome: {}, Idade: {}'.format(*registro.strip().split(',')))
except IndexError:
    pass
finally:
    arquivo.close()

if arquivo.closed:
    print("Arquivo foi fechado!")