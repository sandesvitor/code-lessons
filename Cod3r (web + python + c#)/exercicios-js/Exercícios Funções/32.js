function mediaArray(vetor=[]) {
    let vetorSoma = 0
    
    for (i = 0; i < vetor.length; i++) {
        vetorSoma = vetorSoma + vetor[i]
    }

    mediaInt = (vetorSoma / vetor.length)

    console.log(mediaInt)
}

const vetorInt = [1, 2, 3, 4, 5]
mediaArray(vetorInt)