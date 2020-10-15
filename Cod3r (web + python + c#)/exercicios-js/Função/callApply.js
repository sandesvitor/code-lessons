function getPreco(imposto = 0, moeda = 'R$') {
    return `${this.nome} custa ${moeda} ${this.preco * (1 - this.desc) * (1 + imposto)}`
}

const produto = {
    nome: 'notebook',
    preco: 4589,
    desc: 0.15,
    getPreco
}

global.nome = 'notebook'
global.preco = 20
global.desc = 0.1
console.log(getPreco())
console.log(produto.getPreco())

const carro = {nome: 'Volvo', preco: 45000, desc: 0.20}

console.log(getPreco.call(carro))
console.log(getPreco.apply(carro)) // objeto usado como this

console.log(getPreco.call(carro, 0.17, '$'))
console.log(getPreco.apply(carro, [0.17, '$']))