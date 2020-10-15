const filhas = [ 'Valeska', 'Cibalena']
const filhos = [ 'Washington', 'Weskley']

const todos = filhos.concat(filhas, 'Fulano')
console.log(todos, filhas, filhos)

console.log([].concat([1,2], [3,4], 5, [[6,7]]))