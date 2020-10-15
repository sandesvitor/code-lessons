console.log(typeof Object) // função
console.log(typeof new Object()) // objeto criado a partir de uma função

const Cliente = function() {}
console.log(typeof Cliente)
console.log(typeof new Cliente)

class Produto {} // ES 2015 (ES6)
console.log(typeof Produto())
