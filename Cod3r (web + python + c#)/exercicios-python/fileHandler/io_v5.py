# Streaming de arquivos ==> ler o arquivo sob demanda!


# neste caso o bloco "with" abre e fecha os recursos
with open('pessoas.csv') as arquivo:
    for registro in arquivo:
        print('Nome: {}, Idade: {}'.format(*registro.strip().split(',')))

if arquivo.closed:
    print("Arquivo foi fechado!")