let stringPontuacoes = '10, 20, 20, 8, 25, 3, 0, 30, 1'

function getMaxmim(){
    let pontuacoes = stringPontuacoes.split(", ")
    console.log(pontuacoes, typeof pontuacoes[0])
    let qtdQuebraDeRecords = 0
    let piorJogo = 1
    let maiorPontuacao = pontuacoes[0]
    let menorPontuacao = pontuacoes[0]
    console.log(typeof menorPontuacao)
    
    for (let i = 1; i < pontuacoes.length; i++) {
        if(pontuacoes[i] > maiorPontuacao) {
            maiorPontuacao = pontuacoes[i]
            qtdQuebraDeRecords++
        }else if (pontuacoes[i] < menorPontuacao) {
            menorPontuacao = pontuacoes[i]
            piorJogo = i+1;
        }
    }
    return [qtdQuebraDeRecords, piorJogo]
}
 
console.log(getMaxmim(stringPontuacoes))