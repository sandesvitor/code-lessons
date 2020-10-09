// par nome/valor (chave/valor)
const saudacao = 'Opa' // contexto léxico 1

function exec() {
    const saudacao = 'Falaaa' // contexto léxico 2
    return saudacao
}

// Objetos são grupos alinhados de pares nome/valor
const cliente = { // contexto léxico 3
    nome: 'Pedro',
    idade: 32,
    peso: 90,
    endereço: {
        logradouro: 'Rua Muito Legal',
        numero: 123
    }
}

console.log(saudacao)
console.log(exec())
console.log(cliente)


/* Obs >>> se usássemos o mesmo identificador
 * para chamar a "const" em um mesmo contexto léxico
 * o programa daria erro.
 * Porém, com "var" poderíamos aplicar, porque o
 * valor seria sobrescrito.
*/