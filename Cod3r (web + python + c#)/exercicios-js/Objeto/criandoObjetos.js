// usando a notação literal (!= JSON)
const obj1 = {}
console.log(obj1)

// Object em JS
console.log(typeof Object, typeof new Object)
const obj2 = new Object
console.log(obj2)

// Função Construtora
function Produto(nome, preco, desconto) {
    this.nome = nome
    // "preco" e "desconto" estão encapsulados
    // bem parecido com o "__preco" do Python!
    this.getPrecoComDesconto = () => { // "getter"!!!
        return preco * (1 - desconto)
    }
}

const p1 = new Produto('Caneta', 7.99, 0.15)
const p2 = new Produto('Notebook', 2998.99, 0.25)
console.log(p1.getPrecoComDesconto())
console.log(p2.getPrecoComDesconto())

// Função Factory
function criarFuncionario(nome,salarioBase, faltas){
    return {
        nome,
        salarioBase,
        faltas,
        getSalario(){
            return (salarioBase/30) * (30 - faltas)
        }
    }
}

const f1 = criarFuncionario('Joao', 7980, 4)
const f2 = criarFuncionario('Maria', 11000, 1)
console.log(f1.getSalario().toFixed(2), f2.getSalario().toFixed(2))

// Object.create
const filha = Object.create(null)
filha.nome = 'Ana'
console.log(filha)

// Uma função famosa que retorna Objeto...
const fromJSON = JSON.parse('{"info": "Sou um JSON"}')
console.log(fromJSON)
