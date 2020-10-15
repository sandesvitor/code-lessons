// ES8: Object.values/Object.entries

const obj = {
    nome: 'Vitor',
    idade: 30,
    profissao: 'gamer'
}

console.log(Object.keys(obj))
console.log(Object.values(obj))
console.log(Object.entries(obj))

// Melhorias na Notação Literarl de Objetos
const nome = 'Carla'
const pessoa = {
    nome,
    ola() { // = ola: function()
        return 'Oi gente'
    }
}

console.log(pessoa.nome, pessoa.ola)

// Class
class Animal {
    latir() {
        return 'Au au'
    }
}
class Cachorro extends Animal {
    falar(){
        return 'Au au'
    }
}

console.log(new Cachorro().falar())
console.log(new Cachorro().latir())