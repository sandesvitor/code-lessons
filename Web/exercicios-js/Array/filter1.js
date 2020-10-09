const produtos = [
    { nome: 'Notebook', preco: 2499, fragil: true },
    { nome: 'iPad Pro', preco: 4190, fragil: true },
    { nome: 'Copo de Vidro', preco: 12.49, fragil: true },
    { nome: 'Copo de Plástico', preco: 18.99, fragil: false }
]

console.log(produtos.filter( (p) => {
    return true // nenhum é filtrado
}))

console.log(produtos.filter( (p) => {
    return false // tudo filtrado 
}))

console.log("Método 1 - ", produtos.filter( (p) => {
    return  (p.preco > 500) && (p.fragil === true)
}))

// ou...

const filtroCaro = (p) => p.preco > 500
const filtroFragil = (p) => p.fragil // tb pode ser p.fragil === true

resultado = produtos.filter(filtroFragil).filter(filtroCaro)

console.log("Método 2 - ", resultado)