console.log(module.exports)
console.log(module.exports === this)
console.log(module.exports === exports)

this.a = 1
exports.b = 2
module.exports.c = 3

exports = null
console.log(module.exports)

exports = {
    nome: 'Teste'
}

console.log(module.exports)

module.exports = {
    publico: true
}

// Resumindo: o "this" e o "exports" são apenas duas referÊncias
// para o mesmo objeto que o "module.exports" aponta! 