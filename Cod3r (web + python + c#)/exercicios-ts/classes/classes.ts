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