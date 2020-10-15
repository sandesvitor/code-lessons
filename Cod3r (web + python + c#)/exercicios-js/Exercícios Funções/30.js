function getMaxMin(vetorInput=[]) {
    valorBaseMax = vetorInput[0]
    valorBaseMin = vetorInput[0]

    for (i =  1; i < vetorInput.length; i++){
        if (vetorInput[i] - valorBaseMax > 0) {
            valorBaseMax = vetorInput[i]
        }
    }

    for (i =  1; i < vetorInput.length; i++){
        if (vetorInput[i] - valorBaseMin < 0) {
            valorBaseMin = vetorInput[i]
        }
    }
    
    console.log(`Valor Mínimo: ${valorBaseMin} e Valor Máximo: ${valorBaseMax}`)
}

vetor = [2, 2, 1, 4, 1000, 5, 6, 67, 177]

getMaxMin(vetor)
