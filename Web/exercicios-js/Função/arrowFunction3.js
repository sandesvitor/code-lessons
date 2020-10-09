// "global" é o Objeto Global do Node.
// No browser é o "window"

let comparaComThis = function(param) {
    console.log(this === param)
}

comparaComThis(global)
comparaComThis(this)
// CUIDADO!
// em uma função normal o 'this' sempre aponta para 
// o OBJETO GLOBAL!

const obj = {}
comparaComThis = comparaComThis.bind(obj)

comparaComThis(global)

let comparaComThisArrow = param => console.log(this === param)
comparaComThisArrow(global)
comparaComThisArrow(module.exports)
comparaComThisArrow(this)

comparaComThisArrow = comparaComThisArrow.bind(obj)
comparaComThisArrow(obj)
comparaComThisArrow(module.exports)