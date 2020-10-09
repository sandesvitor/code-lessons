// Arrow Function
const soma1 = (a, b) => a + b
console.log(soma1(4,50))

const soma2 = (a, b) => {
    return a + b
}
console.log(soma2(4,50))

const expo = b => b**2
console.log(expo(5))

// Arrow Function (this)
const lexico1 = () => console.log(this === exports)
const lexico2 = lexico1.bind({})
lexico1()
lexico2()

// parametro default
function log(texto = 'Node') {
    console.log(texto)
}

log()
log(undefined)
log(null)
log('Olá Bicho')

// operador rest (spread e rest, no contexto da função é "rest")
function total(...nums) {
    let total = 0
    nums.forEach(n => total += n)
    return total
}

console.log(total(2,3,4,5))