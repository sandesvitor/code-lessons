#!/bin/python3
import math
import sys
import errno

class BashColor:
    ERRO = '\033[91m'
    NORMAL = '\033[0m'

def help():
    print('É necessário informar o raio do círculo.')
    print('Sintaxe: {} <raio>'.format(sys.argv[0][2:]))

def imprimirArea(raio):
    return math.pi * float(raio) ** 2

if __name__ == '__main__':
    if len(sys.argv) < 2:
        help()
        sys.exit(errno.EPERM)
    elif not sys.argv[1].isnumeric():
        help()
        print(BashColor.ERRO + 
              'O raio deve ser um valor numérico' + 
              BashColor.NORMAL)
        
        sys.exit(errno.EINVAL)
    else:
        userInput = sys.argv[1]
        raio = float(userInput)
        area = math.pi * raio**2
        print('Área do círculo ', area)

