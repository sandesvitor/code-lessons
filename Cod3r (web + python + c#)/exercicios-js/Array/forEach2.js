// definir o métoido "forEach2()" para ser igual ao forEach()

const aprovados = ['Agatha', 'Aldo', 'Daniel', 'Raquel']


Array.prototype.forEach2 = function(callback) {
    for (let i = 0; i < this.length; i++){
        callback(this[i], i, this)
    }
}


aprovados.forEach2(function(nome, indice, array) {
    console.log(`${indice + 1}) ${nome}`)
    console.log(array)
})

// Montando outras funções não-built ins, utilizando prototypes:
// Object, Number e String:

Number.prototype.complexSqrt = function() {
    if (this < 0){
        return ((-1*this) ** 0.5) + " i"
    } else {
        return this**0.5
    }
} 

const num1 = 10
const num2 = -10

console.log(num1.complexSqrt()) 
console.log(num2.complexSqrt())


