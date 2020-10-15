function countDentroFora(vetorInt) {
    let countDentroDoVetor = 0
    let countForaDoVetor = 0
    
    for (i = 0; i < vetorInt.length; i++) {
        if (vetorInt[i] >= 10 && vetorInt[i] <= 20){
            countDentroDoVetor++
        } else {
            countForaDoVetor++
        }
    }

    console.log(`${countDentroDoVetor} elemento(s) dentro do intervalo e ${countForaDoVetor} elemento(s) fora do intervala`)
        
}

inputArray = [1, 5, 6, 12, 14, 19, 30]

countDentroFora(inputArray)