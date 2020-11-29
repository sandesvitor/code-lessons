

# Streaming de arquivos ==> ler o arquivo sob demanda!

arquivo = open('pessoas.csv')
for registro in arquivo:
    print('Nome: {}, Idade: {}'.format(*registro.split(',')))
arquivo.close()