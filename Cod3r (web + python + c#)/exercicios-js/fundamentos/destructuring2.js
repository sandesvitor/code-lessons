// destructuring em array

// do lado esquerdo é o operador de desestruturação;
// do lado esquerdo está atribuindo o valor do array.
const [a] = [10]
console.log(a)

const [n1, , n3, , n5, n6 = 0] = [10, 7, 9, 8]
// pegar múltiplos elementos de dentro de um array, desestruturar
// e atribuir esses valores a variáveis.
console.log(n1, n3, n5, n6)

const [, [, nota]] = [[, 8, 8], [9, 6, 8]]
// desestruturação pouco útil, apenas para níveis didáticos
console.log(nota)
