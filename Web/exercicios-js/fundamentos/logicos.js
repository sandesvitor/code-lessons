function compras(trabalho1, trabalho2) {
    const comprarSorvete = trabalho1 || trabalho2 // "or"
    const comprarTv50 = trabalho1 && trabalho2 // "and"
    // const comprarTv32 = !!(trabalho1 ^ trabalho2) // bitwise xor
    const comprarTv32 = trabalho1 != trabalho2
    const manterSaudavel = !comprarSorvete // operador unário

    // quando você omite o valor na criação do objeto, o nome
    // já é a chave e o valor ele já aponta para a constante
    return { comprarSorvete, comprarTv50, comprarTv32, manterSaudavel }
}

console.log(compras(true, true))
console.log(compras(true, false))
console.log(compras(false, true))
console.log(compras(false, false))
