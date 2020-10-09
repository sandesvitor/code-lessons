let isAtivo = false
console.log(isAtivo)

isAtivo = true
console.log(isAtivo)

isAtivo = 1
console.log(!isAtivo) // transforma o valor em booleano, "!" é negação
console.log(!!isAtivo) // falso

// todos os números inteiro, com exceção do "0" são "true"
console.log('os verdadeiros...')
console.log(!!3)
console.log(!!-1)
console.log(!!' ') // vazio. Basta ter um em branco que já funciona
console.log(!![]) // array
console.log(!!Infinity) // infinito
console.log(!!(isAtivo = true))

console.log('os falsos...')
console.log(!!0)
console.log(!!'') // string vazia - pode ser utilizado para testar strings
console.log(!!null) // nulo
console.log(!!NaN) // Not a Number
console.log(!!undefined) 
console.log(!!(isAtivo = false))

console.log('para finalizar...')
console.log(!!('' || null || 0 || ' ')) // "||" significa "ou" em operações lógicas

// exemplo prático de "ou"
let nome = ''
console.log(nome || 'Desconhecido')
