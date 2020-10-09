const carrinho = [
    '{ "nome": "Borracha", "preco": 3.45 }',
    '{ "nome": "Caderno", "preco": 13.90 }',
    '{ "nome": "Kit de lapis", "preco": 41.22 }',
    '{ "nome": "Caneta", "preco": 7.50 }'
]

// Retornar um array apenas com os preços:

let resultado = carrinho.map( (e) => {
    let a = JSON.parse(e)
    return a.preco
})


console.log(resultado)

// ou usando dois "maps"

const paraObjeto = json => JSON.parse(json)
const apenasObjeto = produto => produto.preco

const resultado2 = carrinho.map(paraObjeto).map(apenasObjeto)
console.log(resultado2)