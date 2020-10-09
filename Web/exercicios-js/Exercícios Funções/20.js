let countCem = 0
let countCinquenta = 0
let countDez = 0
let countCinco = 0
let countUm = 0

function otimizaTroca(valor) {
    
    switch(valor) {
        case(valor >= 100): 
            countCem += 1
            otimizaTroca(valor - 100)
            break
        case(valor >= 50):
            countCinquenta += 1
            otimizaTroca(valor - 50)
            break
        case(valor >= 10):
            countDez += 1
            otimizaTroca(valor - 10)
            break
        case(valor >= 5):
            countCinco += 1
            otimizaTroca(valor - 5)
            break
        case(valor >= 1):
            countUm += 1
            otimizaTroca(valor - 1)
            break
        }
    return console.log(`Você recebe ${countCem} nota(s) de R$100,00, ${countCinquenta} nota(s) de R$50,00, ${countDez} nota(s) de R$10,00, ${countCinco} nota(s) de R$5,00  e ${countUm} nota(s) de R$1,00`)

}

otimizaTroca(500)