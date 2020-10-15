const ferrari = {
    modelo: 'f40',
    velMax: 324
}

const volvo = {
    modelo: 'v40',
    velMax: '200'
}

console.log(ferrari.__proto__)
// "__proto__" ---> atributo no qual é possível acessar o protótipo
// desse objeto, ous eja, o "super" objeto, objeto pai!

// se não encontrar ele vai procurando em toda a cadeia de protótipo
// até encontrar, se não encontrar volta "undefined"

console.log(ferrari.__proto__ === Object.prototype)
console.log(volvo.__proto__ === Object.prototype)
console.log(Object.prototype.__proto__ === null)

function MeuObjeto() {}

console.log(typeof Object, typeof MeuObjeto)
console.log(Object.prototype, MeuObjeto.prototype)