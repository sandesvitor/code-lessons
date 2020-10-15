// Funcao sem retorno
function imprimirSoma(a, b) { // funções sempre tem blocos associados
    console.log(a + b)
}

imprimirSoma(2, 3)
imprimirSoma(2) // soma um numero inteiro com um undefined = NaN
imprimirSoma(2, 3, 4, 5) // soma os primeiros parâmetros e ignora o resto

// Funcao com retorno
function soma(a, b = 1) {// pode definir um padrão de valor para um dos parâmetro
    return a + b // retorna o valor dessa soma, porém é preciso chamar o console.log pra imprimir
}

console.log(soma(2, 3))
console.log(soma(2)) // aqui ela já usa o valor padrão, então retorna a soma