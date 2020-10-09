function gerarNumerosEntre(min, max, tempo) {
    if (min > max) {
        // Destructuring array!
        [max, min] = [min, max]
    }

    return new Promise(resolve => {
        setTimeout(() => {
            const fator = max - min + 1
            const aleatorio = parseInt(Math.random() * fator) + min
            resolve(aleatorio)
        }, tempo)
    })
}

function gerarVariosNumeros() {
    // função que gera promessas!
    return Promise.all([
        gerarNumerosEntre(1, 60, 1000),
        gerarNumerosEntre(1, 60, 500),
        gerarNumerosEntre(1, 60, 3000),
        gerarNumerosEntre(1, 60, 100),
        gerarNumerosEntre(1, 60, 1500)
    ])
}

console.time('promise')
gerarVariosNumeros()
    .then(console.log)
    .then(() => {
        console.timeEnd('promise')
    })
