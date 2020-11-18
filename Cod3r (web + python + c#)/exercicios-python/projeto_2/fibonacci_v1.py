def fibonacci(quantidade:int):
    resultado = [0, 1]

    while True:
        resultado.append(sum(resultado[-2:]))
        if len(resultado) == quantidade:
            break
    return resultado

if __name__ == "__main__":
    # Listar os n primeiros números da sequência:
    qut = int(input("Insira máximo número de elementos: "))
    limite = qut if (qut > 0) else 1 
    for fib in fibonacci(limite):
        print(fib)