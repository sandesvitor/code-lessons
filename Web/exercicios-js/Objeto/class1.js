class Lancamento {
    constructor(nome = 'Genérico', valor = 0){ // mesmo que o "def __init__(self)" do Python
        this.nome = nome
        this.valor = valor
    }
}

class CicloFinanceiro {
    constructor(mes, ano){
        this.mes = mes
        this.ano = ano
        this.lancamentos = []
    }

    addLancamentos(...lancamentos) {
        this.lancamentos.forEach(l => this.lancamentos.push(l))
    }

    sumario() {
        let valorConsolidado = 0
        this.lancamentos.forEach(l => {
            valorConsolidado += l.valor
        })
        return valorConsolidado 
    }
}


const salario = new Lancamento('Salário', 45000)
const contadeLuz = new Lancamento('Luz', -220)

const contas = new CicloFinanceiro(6, 2018)
contas.addLancamentos(salario, contadeLuz)

console.log(salario.valor)
console.log(contadeLuz.valor)
console.log(contas.lancamentos)