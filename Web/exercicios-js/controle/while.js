// pode ser usado para número indeterminado de repetiçõas;
function getInteiroAleatorioEntre(min, max) {
    const valor = Math.random() * (max - min) + min
    return Math.floor(valor)
}

let opcao = 0

while (opcao != -1) {
    opcao = getInteiroAleatorioEntre(-1, 10)
    console.log(`Opção escolhida foi ${opcao}.`) 
    // funciona como o print(f'....{}') do Python
}

console.log('Até a próxima!')