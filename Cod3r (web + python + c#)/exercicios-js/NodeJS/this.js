console.log(this === global)
console.log(this === module)
console.log(this === module.exports)
console.log(this === exports)
// fora de uma função aponta para "module.exports"

function logThis() {
    console.log('Dentro de uma função...')
    console.log(this === exports)
    console.log(this === module.exports)
    console.log(this === global)
    // dentro de uma função aponta para "global"

    this.perigo = '...' //---> está colocando dentro do escopo global
}

logThis()

console.log(global.perigo)