// pessoa --> endereço1 -->{...}
const pessoa = {nome: 'João'}
pessoa.nome = "Pedro"
pessoa.end = "Rua ABC"
console.log(pessoa)

// pessoa --> endereço2 --> {...}

//pessoa = { nome: "Ana"}

// como "pessoa" é uma constante, ela não pode apontar para
// um objeto em outro endereço!

Object.freeze(pessoa) // método para "congelar" objeto pessoa

pessoa.nome = 'Maria' 
console.log(pessoa.nome)

// para alterar o endereço, basta usar "let"
let pessoa2 = {nome: "Flávio"}
pessoa2.nome = "Thiago"
console.log(pessoa2)

pessoa2 = {nome: "Tenório"}
console.log(pessoa2)