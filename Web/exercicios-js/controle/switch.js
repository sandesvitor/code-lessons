// o "switch" é feito para múltiplas seleções
// a expressão, diferente do "if" e "else", não retornar "true" ou "false"

const imprimirResultado = function (nota) {
    switch (Math.floor(nota)) {
        case 10:
        case 9:
            // se for "10" ou "9" ele executa a linha abaixo
            console.log('Quadro de Honra')
            break // quebra o efeito de "fall trought", que sai do primeiro e passa a executar todos abaixo
        case 8: case 7:
            console.log('Aprovado')
            break
        case 6: case 5: case 4:
            console.log('Recuperação')
            break
        case 3: case 2: case 1: case 0:
            console.log('Reprovado')
            break
        default: // se não for nenhum outro
        // pode ficar em qualquer outra posíção, mas precisa do break
            console.log('Nota Inválida')
    }
}

imprimirResultado(10)
imprimirResultado(9)
imprimirResultado(8)
imprimirResultado(6.55)
imprimirResultado(1)
imprimirResultado(-1)