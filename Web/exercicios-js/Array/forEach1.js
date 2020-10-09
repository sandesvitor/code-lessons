// forEache() ---> começa com uma função callback que recebe 3 parâmetros
// elemento, índice e array completo!


const aprovados = ['Agatha', 'Aldo', 'Daniel', 'Raquel']

aprovados.forEach(function(nome, indice) {
    console.log(`${indice + 1}) ${nome}`)
})

aprovados.forEach(nome => console.log(nome))

const exibirAprovados = ((aprovado, indice) => console.log(`${indice}) ${aprovado}`))
aprovados.forEach(exibirAprovados)