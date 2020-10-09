// Map mapeia os elementos de um array para outro, mantendo
// o mesmo lenght!

const nums = [1, 2, 3, 4, 5]

let resultado = nums.map(function(e){
    return e * 2
})

console.log(resultado)
console.log(nums)

const soma10 = e => e + 10 // = (e) => {return e + 10} ---- return implícito da array function
const triplo = e => e * 3 
const paraDinheiro = e => {
    return `R$ ${parseFloat(e).toFixed(2).replace('.',',')}`
}

resultado = nums.map(soma10).map(triplo).map(paraDinheiro)
console.log(resultado)