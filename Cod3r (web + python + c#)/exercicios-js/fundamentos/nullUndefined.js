let valor // não inicializada
console.log(valor) // undefined
// console.log(valor2) // it's not defined

valor = null 
// ausência de valor* não aponta para nenhum objeto na memória
// se quiser zerar o valor de uma variável que aponte para uma referência
// usar o "null"
console.log(valor)
// console.log(valor.toString()) vai dar erro!

const produto = {}
console.log(produto.preco) // undefinied

produto.preco = 3.50
console.log(produto)

produto.preco = undefined // evite atribuir "undefined"
console.log(!!produto.preco) // a dupla negação vai dar false pois não tem nada definido
console.log(produto)

produto.preco = null // sem preço
console.log(!!produto.preco)
console.log(produto)