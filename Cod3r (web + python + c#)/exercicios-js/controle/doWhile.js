function getInteiroAleatorioEntre(min, max) {
    const valor = Math.random() * (max - min) + min
    return Math.floor(valor)
}

let opção = 0 

do {
    opcao = getInteiroAleatorioEntre(-1, 10)
    console.log(`Opção escolhida foi ${opcao}.`)
} while (opção != -1)

console.log('Até a próxima!')
// por algum motivo ficou rodando pra sempre!!!!!