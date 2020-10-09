function soma() {
    let soma = 0
    for (i in arguments) {
        soma += arguments[i]
    }
    return soma
}

console.log()
console.log(1)
console.log(soma(1,2,3))
console.log(soma(1.1, 2.2, " Teste"))

// "arguments" é um array interno de uma função
// ele serve para colocar parâmetros dinamicamente.
// quando nenhum parâmetro é passado este array fica vazio.

