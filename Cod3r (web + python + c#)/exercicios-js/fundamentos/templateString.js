const nome = 'Rebeca'
const concatenacao = 'Olá ' + nome + '!'
const template = `
    Olá
    ${nome}!`
console.log(concatenacao, template)

// expressões...
console.log(`1 + 1 = ${1 + 1}`)

const up = texto => texto.toUpperCase() // função Arroy
console.log(`Ei... ${up('cuidado')}!`)