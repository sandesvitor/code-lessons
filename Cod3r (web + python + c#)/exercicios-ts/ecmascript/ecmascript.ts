// let & const:
// console.log(seraQuePode)
var seraQuePode = '?' // hoisting (só ocorre em 'var')


let estaFrio = true
if(estaFrio){
    let acao = 'Colocar o casaco'
    console.log(acao)
}

// let ==> escopo de bloco
// var ==> escopo de função (mais global)

// ex1:
{
    var x = 'x'
}
console.log(x)

// ex2:
{
    let y = 'y'
    console.log(y)
}

// ex3:
// for(var i = 0; i < 500; i++){
//     //
// }

// for(let j = 0; j < 5; j++){
//     //
// }

// console.log(i)
// console.log(j)




// CONST:
const cpf:string = '123.111.333.44-20' 
// também tem escopo de bloco!
// não sofre hoisting
// tem que inicializar e atribuir
// cpf = 1 //---> não pode reatribuir!

{
    const def = 'DENTRO DO BLOCO'
    console.log(def)
}
const def = 'FORA DO BLOCO'
console.log(def)

// ARROW FUNCTION:
const somar = function(n1:number, n2:number): number{
    return n1 + n2
}
console.log(somar(2,2))

const subtrair = (n1:number, n2:number):number => n1 - n2
console.log(subtrair(2,3))

const saudacao = () => console.log('Olá!')
saudacao()

const falarCom = (pessoa:string) => console.log("Olá " + pessoa)

// // this
// function normalComThis(){
//     console.log(this)
// }

// const normalComThisEspecial = normalComThis.bind({nome: 'Anna'})

// normalComThisEspecial()

// // this???
// console.log(this)
// const arrowComThis = () => console.log(this) // não dá pra fazer bind!
// arrowComThis()

// Operador Spread e Rest:
const numbers = [1,2,99,-5]
console.log(Math.max(...numbers)) // ---> Spread

const turmaA:string[] = ['Joao', 'Maria', 'Fabio']
const turmaB:string[] = ['Fernando', 'Clara', ...turmaA]
console.log(turmaB)

function retornarArray(...arg1:number[]):number[]{ // ---> Rest
    return [...arg1]
}

const numeros = retornarArray(1, 2, 4, 5, 5, 100)
console.log(numeros)

// Rest & Spread (Tupla)

const tupla: [number, string, boolean] = [1, 'abc', false]

function tuplaParam1(a: number, b: string, c: boolean): void {
    console.log(`1) ${a} ${b} ${c}` )
}

tuplaParam1(...tupla)

function tuplaParam2(...params: [number, string, boolean]): void {
    console.log(Array.isArray(params))
    console.log(`2) ${params[0]} ${params[1]} ${params[2]}` )
}

tuplaParam2(...tupla)


// Destructuring (array):
const caracteristicas = ['Motor Zetec 1.8', 2020]
// const motor = caracteristicas[0]
// const ano = caracteristicas[1]

const [motor, ano] = caracteristicas 
console.log(motor)
console.log(ano)

// Destructuring (objeto):
const item = {
    nome: 'SSD 480GB',
    preco: 200,
    data: {
        w: 'importado'
    }
}

const nomeItem = item.nome
const precoItem = item.preco

const {nome: n, preco: p, data: { w }} = item
console.log(n)
console.log(p)
console.log(w)

// DESAFIO:


// Exercicio 1
const dobro = (valor:number):number => valor * 2
console.log(dobro(10))
 
// Exercicio 2
const dizerOla = (nome:string = 'Pessoa'):void => {
    console.log("Ola, " + nome)
}
 
dizerOla()
dizerOla("Anna")
 
// Exercicio 3
const nums = [-3, 33, 38, 5]
console.log(Math.min(...nums))
 
// Exercicio 4
const array = [55, 20]
array.push(...nums)
console.log(array)
 
// Exercicio 5
const notas = [8.5, 6.3, 9.4]
const notas1 = notas[0]
const notas2 = notas[1]
const notas3 = notas[2] 
console.log(...notas)
 
// Exercicio 6
const cientista = {primeiroNome: "Will", experiencia: 12}
const primeiroNome = cientista.primeiroNome
const experiencia = cientista.experiencia

const {primeiroNome: first, experiencia: xp} = cientista

console.log(primeiroNome, experiencia)
console.log(first)
console.log(xp)

// Callcack p/ resolver assincronismo!

// function esperar3s(callback: (dado:string) => void){
//     setTimeout(() => {
//         callback('3s depois...')
//     }, 3000)
// }

// esperar3s( function(resultado: string){
//     console.log(resultado)
// })

// // Usando Promises!
// function esperar3sPromises(){
//     return new Promise((resolve, reject) => {
//         setTimeout(() => {
//             resolve('3s depois promise...')
//         }, 3000)
//     })
// }

// esperar3sPromises()
//     .then(dado => console.log(dado))

// ex: API DO STAR WARS

// fetch('https://swapi.dev/api/people/1')
//     .then(res => console.log(res))