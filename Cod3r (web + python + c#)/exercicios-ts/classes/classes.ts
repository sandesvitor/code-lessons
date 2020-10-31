class Data{
    dia: number
    mes: number
    ano: number

    constructor(dia: number = 1, mes: number = 1, ano: number = 1970){
        this.dia = dia
        this.mes = mes
        this.ano = ano
    }
}

const aniversario: Data = new Data(3, 11, 1991)
aniversario.dia = 4
console.log(aniversario.dia)
console.log(aniversario)

const casamento: Data = new Data(31)


class DataEsperta{
    constructor(
        public dia: number = 1, 
        public mes: number = 1, 
        public ano: number = 1970
    ){}
}

const aniversarioEsperto: DataEsperta = new DataEsperta(3, 11, 1991)
aniversarioEsperto.dia = 4
console.log(aniversarioEsperto.dia)
console.log(aniversarioEsperto)

const casamentoEsperto: DataEsperta = new DataEsperta(31)
console.log(casamentoEsperto)
console.log(casamentoEsperto)


console.debug('########################################')

// Desafio classe "Produto":

class Produto{
    constructor(
        public nome:string, 
        public preco:number, 
        public desconto: number = 0
    ){}

    public precoComDesconto():number{
        return this.preco * (1 - this.desconto)
    }

    public resumo(): string {
        return `${this.nome} custa R$${this.precoComDesconto()} (${this.desconto * 100}% off)`
    }
}

const produto1: Produto = new Produto('Caneta', 1.99, 0.1)
console.log(produto1.resumo())
const produto2: Produto = new Produto('Celular', 1000.99, 0.5)
console.log(produto2.resumo())
console.log("Hello Pop! Os")

console.debug('########################################')

class Carro {
    private velocidadeAtual: number = 0

    constructor(public marca: string, public modelo: string,
        private velocidadeMaxima: number = 200){
        
    }

    private alterarVelocidade(delta: number): number {
        const novaVelocidade = this.velocidadeAtual + delta
        const velocidadeValidade = novaVelocidade >= 0
            && novaVelocidade <= this.velocidadeMaxima

        if(velocidadeValidade){
            this.velocidadeAtual = novaVelocidade
        } else {
            this.velocidadeAtual = delta > 0 ? this.velocidadeMaxima : 0
        }

        return this.velocidadeAtual
    }

    public acelerar(): number {
        return this.alterarVelocidade(5)
    }

    public frear(): number {
        return this.alterarVelocidade(-5)
    }
}

const carro1 = new Carro('Ford', 'Ka', 185)
Array(50).fill(0).forEach(() => carro1.acelerar())
console.log(carro1.acelerar())

Array(50).fill(0).forEach(() => carro1.frear())
console.log(carro1.frear())