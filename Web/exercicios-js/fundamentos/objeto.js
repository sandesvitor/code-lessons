/* Objeto em javascript é uma coleção de chaves
 * e valores;
 * É possível atribuir valores de
 * forma dinâmica
*/

const prod1 = {} // par de "{}" representa um objeto de forma literal
prod1.nome = 'Celular Ultra Mega'
prod1.preco = 4998.90
prod1['desconto legal'] = 0.40 // evitar atributos com espaço

console.log(prod1)

const prod2 = {
    nome: 'Camisa Polo',
    preco: 79.90
}

console.log(prod2)

// não é a mesma coisa que JSON
const prod3 = {
    nome: 'Sapato Preto',
    preco: 100.99,
    tipo: {
        marca: 'Raph Lauren',
        id: '456'
    }
}

console.log(prod3)

// Exemplo de JSON*:
{' "nome": "Camisa Polo", "preco": 79.90'}
// *JSON é o formato textual de um objeto, para trocar dados entre sistemas
