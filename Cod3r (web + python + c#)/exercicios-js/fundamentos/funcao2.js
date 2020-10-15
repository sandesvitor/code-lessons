// Armazenando uma funcao em uma variável
const imprimirSoma = function (a, b) { //a constante recebe o corpo da função anonima
    console.log(a + b)
}

imprimirSoma(2, 3)

// Armazenando uma funcao arrow em uma variavel
const soma = (a, b) => { // também está armazenando dentro da variável soma
    return a + b
}

console.log(soma(2, 3))

// retorno implícito com arrow function
const subtracao = (a, b) => a - b // qunado não temos as chaves (os blocos) a funca executa apenas uma linha de código
console.log(subtracao(2, 3))

const imprimir2 = a => console.log(a)
imprimir2('Legal!!!')
