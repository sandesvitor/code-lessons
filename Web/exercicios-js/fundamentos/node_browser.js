/* Um dos principais desafios do Javascript
 * é entender em que runtime voc~e está e 
 * as especificidades de cada ambiente!
*/


let a = 3

global.b = 123
this.c = 456
this.d = false
this.e = 'teste'

console.log(a)
console.log(global.b)
console.log(this.c)
console.log(module.exports.c)
console.log(module.exports === this)
console.log(module.exports)

// criando uma variável "maluca": sem var e let
// você está colocando uma variável no objeto global do NODE
// NÃO FAÇA ISSO!!!
abc = 3
console.log(global.abc)