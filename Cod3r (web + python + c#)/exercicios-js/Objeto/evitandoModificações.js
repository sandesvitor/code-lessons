// Object.preventExtensions --> pode ser modificado e excluir atributos, mas não pdoe adicionar
const produto = Object.preventExtensions({
    nome: 'QUalquer',
    preco: 1.99,
    tag:'promoção'
})

console.log('Extensível', Object.isExtensible(produto))

produto.nome = 'Borracha'
produto.descricao = 'BOrracha Escolar Branca'
delete produto.tag
console.log(produto)

// Object.seal ----> não consegue adicionar nem excluir, mas pode alerar
const pessoa = { nome:'Juliana', idade: 35}
Object.seal(pessoa)

console.log('Selado', Object.isSealed(pessoa))

pessoa.sobrenome = 'Silva'
delete pessoa.nome
pessoa.idade = 29
console.log(pessoa)

// Object.freeze ----> não consegue adicionar, excluir ou alterar

// tds os atributos marcados como "writable" == false