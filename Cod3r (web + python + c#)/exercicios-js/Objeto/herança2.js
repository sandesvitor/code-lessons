// Cadeia de Protótipos (prototype chain)
Object.prototype.attr0 = 'Z' // evite fazer este tipo de manipulação!

const avo = { attr1: 'A'}
const pai = { __proto__: avo, attr2: 'B', attr3: '3'}
const filho = { __proto__: pai, attr3: 'C'}

console.log(avo.__proto__ === Object.prototype)
console.log(pai.__proto__ === avo)
console.log(filho.__proto__ === pai)

console.log(filho.attr0, filho.attr1, filho.attr2, filho.attr3)

// #############################

const carro = {
    velAtual: 0,
    velMax: 200,
    acelerarMais(delta) {
        if (this.velAtual + delta <= this.velMax) {
            this.velAtual += delta
        } else {
           this.velAtual = this.velMax 
        }
    },
    status(){
        return `${this.velAtual}km/h de ${this.velMax}km/h`
    }
}

const ferrari = {
    modelo: 'f40',
    velMax: 324 // shadowing
}

const volvo = {
    modelo: 'v40',
    status() {
        return `${this.modelo}: ${super.status()}` // "super faz chamar o método do protótipo"

    }
}

Object.setPrototypeOf(ferrari, carro)
Object.setPrototypeOf(volvo, carro)

console.log(ferrari)
console.log(volvo)

volvo.acelerarMais(100)
console.log(volvo.status())

ferrari.acelerarMais(300)
console.log(ferrari.status())
