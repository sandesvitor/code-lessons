// string
let nome:string = 'João'
console.log(nome)
// nome = 28

// numbers
let idade:number = 27
// idade = 'Ana'
idade = 27.5
console.log(idade)

// boolean
let possuiHobbies:boolean = false
// possuiHobbies = 1
console.log(possuiHobbies)

// tipos explícitos
let minhaIdade:number
minhaIdade = 27
console.log(typeof minhaIdade)
// minhaIdade = 'idade é 27'

// array
let hobbies: any[] = ["Cozinhar", "Praticar Esportes"]
console.log(hobbies[0])
console.log(typeof hobbies)

hobbies = [100]
// hobbies = 100
console.log(hobbies)

// tuplas
let endereco:[string, number, string] = ["Av Principal", 99, ""]
console.log(typeof endereco)
console.log(endereco)

endereco = ["Rua Importante", 1260, "Bloco A"]
console.log(endereco)

// enums
enum Cor {
    Cinza, // 0
    Verde = 101, // 1
    Azul = 2, // 2
    Laranja,
    Amarelo,
    Vermelho   
}

let minhaCor: Cor = Cor.Verde
console.log(minhaCor)

console.log(Cor.Azul)

// any
let carro: any = 'BMW'
console.log(carro)

carro = { marca: 'BMW', ano: 2019}
console.log(carro)

// funções
function retornaMeuNome():string{
    // return minhaIdade
    return nome
}

console.log(retornaMeuNome())

function digaOi():void {
    console.log("Oi!")
    // return minhaIdade
}

digaOi()

function multiplicar(numA:number, numB:number): number {
    return numA * numB
}

// console.log(multiplicar(2, 'Bia')) ---> NaN
console.log(multiplicar(2, 12))

// tipo função
let calculo: (numeroA:number, numeroB:number) => number
// calculo = digaOi
// calculo()

calculo = multiplicar
console.log(calculo(5, 6))

// objeto
let usuario:{nome: string, idade: number} = {
    nome: 'João',
    idade: 27
}

console.log(usuario)
// usuario = {}

// usuario = {
    //     name: 'Maria',
    //     age: 31
    // }
    
usuario = {
    idade: 31,
    nome: 'Maria'
}

console.log(usuario)

// Desafio
/*
    Criar um objeto funcionário com:
        - Array de string com os nomes dos supervisores;
        - Função de bater ponto que recebe a hora (number) e retorna
            uma string
                -> Ponto Normal (<= 8);
                -> Fora do horário (> 8);
*/

// Alias
type Funcionario = {
    supervisores:string[], 
    baterPonto:(hora:number) => string
}
const funcionario:Funcionario = {
    supervisores:['Anna', 'Helio', 'Jonas'],
    baterPonto(hora:number){
        if(hora <= 8) return 'Ponto Normal'
        return 'Fora do Horário'
    }
}

console.log(funcionario.supervisores)
console.log(funcionario.baterPonto(9))
console.log(funcionario.baterPonto(2))

const funcionario2:Funcionario = {
    supervisores:['Joao'],
    baterPonto(hora:number){
        if(hora <= 8) return 'Ponto Normal'
        return 'Fora do Horário'
    }
}

console.log(funcionario2.supervisores)
console.log(funcionario2.baterPonto(9))
console.log(funcionario2.baterPonto(2))

// funcionario = {}

// Union Types
let nota: number | string = 10
console.log(`Minha nota é ${nota}`)
nota = '10'
console.log(`Minha nota é ${nota}`)
// nota = true ---> cenário não desejável!

// Checando tipos em runtime
let valor = 30

if (typeof valor === "number"){
    console.log('É um valor number!')
} else {
    console.log(typeof valor)
}

// tipo never
function falha(msg: string): never{
    throw new Error(msg)
}

const produto = {
    nome: 'Sabão',
    preco: 4,
    validarProduto(){
        if(!this.nome || this.nome.trim().length == 0){
            falha('Precisa ter um nome')
        }
        if(this.preco <= 0){
            falha('Preco inválido')
        }
    }
}

produto.validarProduto()

// valor nulo
let altura = 12
// altura = null

let alturaOpcional: null | number = 12
alturaOpcional = null

type Contato = {
    nome: string,
    tel1: string,
    tel2: string | null
}

const contato1: Contato = {
    nome: 'Fulano',
    tel1: '98893902',
    tel2: null
}

console.log(contato1)

let podeSerNulo = null // tipo any


// Desafio!
type ContaBancaria = {
    saldo: number,
    depositar: (valor:number) => void
}
type Correntista = {
    nome: string,
    contaBancaria: ContaBancaria,
    contatos: string[]
}

let contaBancaria: ContaBancaria = {
    saldo: 3456,
    depositar(valor: number){
        this.saldo += valor
    }
}

let correntista: Correntista = {
    nome: 'Ana Silva',
    contaBancaria: contaBancaria,
    contatos: ['345141556', '918982900']
}

correntista.contaBancaria.depositar(3000)
console.log(correntista)