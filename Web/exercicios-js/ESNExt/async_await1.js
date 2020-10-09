const esperarPor = (tempo = 2000) => {
    return new Promise(resolve => {
        setTimeout(() => resolve(), tempo)
    })
}

// esperarPor(2000)
//     .then(() => console.log('Executando promise 1...'))
//     .then(esperarPor)
//     .then(() => console.log('Executando promise 2...'))
//     .then(esperarPor)
//     .then(() => console.log('Executando promise 3...'))

function retornarValor() {
    return new Promise(resolve => {
        setTimeout(() => resolve(10), 5000)
    })
}

// Faz o código parecer síncrono!
async function executar() {
    try {
        let valor = await retornarValor()

        await esperarPor(1500)
        console.log(`Async/Await 1 ${valor}...`)

        await esperarPor(1500)
        console.log(`Async/Await 1 ${valor + 1}...`)

        await esperarPor(1500)
        console.log(`Async/Await 1 ${valor + 2}...`)

        return valor + 3

    } catch (ex) {
        console.log('Erro: ', ex)
    }
}

executar().then(console.log)