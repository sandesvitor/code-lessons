// Função em JS é First-Class Object (First-Class Citizen)
// tratando a função como um dado, e assim pode passar a função 
// como parâmetro, retornar como respota deoutra função, pode
// criar uma função e armazenar numa variável


// Criar de forma literal:
function fun1(a, b) {
    sum = a + b
    return sum
}

console.log(fun1(50, 100))

// Armazenar em uma variável:
const fun2 = function() {}

// Armazenar em um array:
const array = [function(a, b) {return a + b}, fun1, fun2]
console.log(array[0](2,3, array[1](50, 10)))

// Armazenar em um atributo de objeto
 const obj = {
     nome: 'Ana',
     idade: 34,
     endereço: {
         logradouro: 'Rua ABC',
         numero: 123
     }
 }
 obj.falar = function() { return 'Opa'}
 console.log(obj.falar(), obj.nome, obj.endereço)

// Passar função como parâmetro dentro de uma outra função:
function run(fun) {
    fun()
}

run(function(){console.log('Executando...')})

// Uma função pode retornar/conter uma função
function soma(a, b) {
    return function (c) {
        console.log(a + b + c)
    }
}

soma(2, 3)(10)
const cincoMais = soma(2, 3)
cincoMais(10)

//
