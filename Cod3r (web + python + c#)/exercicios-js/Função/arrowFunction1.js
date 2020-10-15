let dobro = function(a) {
    return 2 * a
}

console.log(dobro(Math.PI))

dobro = (a) => {
    return 2 * a
}
console.log(dobro(Math.PI))

dobro = a => 2 * a 
// se tiver apenas 1 parâmetro não precisa de "()"
// "return" se só tiver uma única linha, fica impícito, então
// se pode usar se "{}", ou seja, sem definir o corpo.
console.log(dobro(Math.PI))

let ola = function(){
    return 'Olá'
}
console.log(ola())

ola = () => 'Olá'
console.log(ola())

ola = _ => 'Olá'
console.log(ola())
