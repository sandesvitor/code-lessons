function quantosPares(a=[]) {
    countPar = 0

    for (i=0; i<a.length; i++) {
        if (a[i] % 2 == 0) {
            countPar++
        }
    }

    console.log(`O vetor tem ${countPar} número(s) par(es) e ${a.length - countPar} número(s) ímpar(es).`)
}

const vetorInt = [1,2,3,4,5,6,7,8,9,10]

quantosPares(vetorInt)