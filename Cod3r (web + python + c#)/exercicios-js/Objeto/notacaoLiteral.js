const a = 1
const b = 2
const c = 3

const obj1 = {a: a, b: b, c: c}// notação antiga!
const obj2 = {a, b, c}//notação nova! 

console.log(obj1, obj2)

const nomeAttr = 'nota'
const valorAttr = 7.87

const objt3 = {}
objt3[nomeAttr] = valorAttr
console.log(objt3)

const obj4 = {[nomeAttr]: valorAttr}
console.log(obj4)

const obj5 = {
    funcao1: function (x, y) {
        return x + y
    },
    funcao2(x, y) {
        return x ** y
    }
}

console.log(obj5.funcao1(10,20), obj5.funcao2(4,5))

