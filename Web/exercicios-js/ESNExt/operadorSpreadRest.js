// operador ...rest(juntar)/spread(espalhar)
// usar rest como parâmetro de função

// usar spread com objeto:
const funcionario = { nome: 'maria', salario: 23424}
const clone = { ativo: true, ...funcionario} //o operador está espalhando todos os atributos de funcionário no objeto clone

console.log(funcionario)
console.log(clone)

// usar spread com array:
const grupoA = ['Joao', 'Pedro', 'Gloria']
const grupoFinal = ['Maria', ...grupoA, 'Rafaela']
console.log(grupoFinal)