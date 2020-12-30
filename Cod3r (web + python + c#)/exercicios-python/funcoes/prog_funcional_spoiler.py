def executar(funcao):
    if callable(funcao):
        funcao()

def oloko_meu():
    print("OLOKU MEU!")

def boa_tarde():
    print("Boa tarde, meu guerreiro!")

if __name__ == '__main__':
    executar(oloko_meu)
    executar(boa_tarde)
    executar(1) # '1' não é passível de ser executado/called