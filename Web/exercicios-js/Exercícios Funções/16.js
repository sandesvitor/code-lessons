function calculadora(a,sinal, b) {
    switch(sinal) {
        case('+'):
            console.log(a + b)
            break
        case('-'):
            console.log(a - b)
            break 
        case('*'):
            console.log(a * b)
            break
        default:
            console.log('Operação inválida!')
    }
}

calculadora(2, '+', 8)
calculadora(2, '-', 8)
calculadora(2, '*', 8)
calculadora(2, '/', 8)
