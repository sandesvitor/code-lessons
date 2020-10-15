// Estrategia 1 para gerar valor padrão (usando operador "or")
function soma1(a, b, c) {
    a = a || 1 // se a primeira parte for "true" retorna "a", se "false" retorna "1"
    b = b || 1
    c = c || 1
    return a + b + c
}

console.log(soma1(), soma1(3), soma1(3,4), soma1(3,4,5), soma1(0,0,0))

// Estratégia 2, 3 e 4 para gerar valor padrão, usando operadores ternários
function soma2(a, b, c) {
    a = a !== undefined ? a : 1 // 2) se a for estritamente diferente de endefined pegue "a" senão pegue "1"
    b = 1 in arguments ? b : 1 // 3) dentro de arguments existe o índice "1"? se exister pegue o valor "b" senão pegue "1" 
    c = isNaN(c) ? 1 : c // se a variável "c" is Not a Number retorne "1", senão retorne "c"
    return a + b + c
}

// a melhor estratégia é a (4)

console.log(soma2(), soma2(3), soma2(1, 2, 3), soma2(0,0,0))

// Valor Padrão ES2015 (se tiver diferença de "tipo" não vai funcionar)
function soma3(a = 1, b = 1, c = 1) {
    return a + b + c
}

console.log(soma3(), soma3(3), soma3(1, 2, 3), soma3(0,0,0))