const pessoa = {
    nome: 'Rebeca',
    idade: 2,
    peso: 13
}

console.log(Object.keys(pessoa))
console.log(Object.values(pessoa))
console.log(Object.entries(pessoa))


Object.entries(pessoa).forEach(e => {
    console.log(`${e[0]}: ${e[1]}`)
});

Object.entries(pessoa).forEach(([chave, valor]) => {
    console.log(`${chave}: ${valor}`)
}) // destructuring - fica mais claro - está desestruturando os elementos de um array!

Object.defineProperty(pessoa, 'dataNascimento', {
    enumerable: false, // fica não enumerável
    writable: false, // funciona mais ou menos como "freeza"
    value: '01/01/2019'
})

pessoa.dataNascimento = '01/01/2017'
console.log(pessoa.dataNascimento)
console.log(Object.keys(pessoa))

// Object.assign (ECMAScript 2015)

const dest = {a: 1}
const o1 = {b: 2}
const o2 = {c: 3, a: 4}
const obj = Object.assign(dest, o1, o2)
// coloca dentro do objeto de destino, nesse caso o "dest", os atributos dos
// objetos que voc~e passar! Se tiver algum atributo igual, ele sobrescreve!

console.log(obj)

Object.freeze(obj)
obj.c = 1234

console.log(obj)