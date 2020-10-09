// junto do operador destructuring,
// é possível colocar um parâmetro padrão,
// como feito em "max"
function rand({ min = 0, max = 1000}){
    const valor = Math.random() * (max - min) + min
    return Math.floor(valor)
}

const obj = { max: 20, min: 15 }
console.log(rand(obj))

console.log(rand({ max: 50, min: 40}))

const test = Math.random()
console.log(test)
