function pilha(vetor=[]){
    let vetorPilha = [1,2,3,4,5]

    for (i = 0; i < vetor.length; i++) {
        vetorPilha.push(vetor[i])
    }

    return vetorPilha
}

vetorAdiciona = [6,7,8,9,10]

console.log(pilha(vetorAdiciona))