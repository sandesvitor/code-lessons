// console.log("Callbackhell Example:")
// setTimeout(function () {
//     console.log('Executando callback 1...')

//     setTimeout(function () {
//         console.log('Executando callback 2...')

//         setTimeout(function () {
//             console.log('Executando callback 3...')
//         }, 2000)

//     }, 2000)

// }, 2000)

console.log("\n...Using Promises:")

const esperarPor = (tempo = 2000) => {
    return new Promise(resolve => {
        setTimeout(() => {
            console.log('Executando promise...')
            resolve('Vishhhh!')
        }, tempo)
    })
}

esperarPor()
    .then(() => esperarPor())
    .then(esperarPor)