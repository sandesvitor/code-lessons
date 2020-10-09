// "hoisting" = içar
// Hoisting is JavaScript's default behavior of moving declarations to the top

// console.log('a =', a)
// var a = 2
// console.log('a =', a)

/* utilizando "var", por mais que seja embaixo, ocorre o hoisting (içamento)
 * da variável var. Na primeira linha fica "undefined" pq ela ainda 
 *não tem valor
 * o efeito é o mesmo do código abaixo:
*/

// var a 
// console.log('a =', a)
// a = 2
// console.log('a =', a)

// function teste() {
//    console.log('a =', a)
//    var a = 2
//    console.log('a =', a)
//}

// teste()

/* neste caso, mesmo dentro da função ela sofre o içamento
 * se colocar um "console.log('a =', a)" depois da chamada de "teste()"
 * irá ocorrer um erro, pois ela não tem escopo fora de função
*/

console.log('a =', a)
var a = 2
console.log('a =', a)