// exemplos de notação "ponto"
console.log(Math.ceil(6.1)) // funcao para arredondar para cima
console.log(Math.floor(6.9)) // funcao para arredondar para baixo

const obj1 = {}
obj1.nome = 'Bola'
// podemos usar também esta notação "obj1['nome'] = 'Bola'"" 

console.log(obj1)

function Obj(nome) {
    this.nome = nome 
    this.exec = function(){
        console.log(nome)
    }
    /* "this" é uma palavra reservada que torna o atributo "público" 
     * ficando visível para o resto do código (diferente de "var" que 
     * ficaria restrita {à função})
    */   
}

const obj2 = new Obj('Cadeira')
const obj3 = new Obj('Mesa')
obj2.exec()
obj3.exec()