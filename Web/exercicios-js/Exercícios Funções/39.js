function trocaTroca(vetor1=[1, 2, 3], vetor2=[4, 5, 6]) {
    
    for (i = 0; i < vetor2.length; i++) {
        vetor1.push(vetor2[i]) 
        vetor2[i] = vetor1[0]
        vetor1.shift()
    }

    console.log(vetor1, vetor2)

}

trocaTroca()