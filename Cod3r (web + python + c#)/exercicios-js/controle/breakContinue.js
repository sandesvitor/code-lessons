const nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

for (x in nums) {
    if (x == 5) {
        break
    }
    console.log(`Índice ${x} = ${nums[x]}`)
}

for (y in nums) {
    if (y == 5) continue // pula o índice "5"
    console.log(`Índice ${y} = ${nums[y]}`)
}

// "break" causa um desvio de fluxo do laço corrente "for"
// "continue" interrompe a repetição corrente e vai para a próxima

// cria um rótulo para a estrutura de repetição
externo: for (a in nums) {
    for (b in nums) {
        if(a == 2 && b == 3) break externo
        console.log(`Par = ${a}, ${b}`)
    }

}
// não é uma boa estrutura!!!