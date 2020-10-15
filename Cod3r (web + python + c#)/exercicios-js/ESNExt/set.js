// não aceita repetição/não é indexado

const times = new Set()
times.add('Vasco').add('Sao Paulo')
times.add('Flamengo')
times.add('Vasco')

console.log(times)
console.log(times.size)
console.log(times.has('vasco'))
console.log(times.has('Vasco'))
times.delete('Flamengo')
console.log(times.has('Flamengo'))

const nomes = ['Rauel', 'Maria', 'Anna']
const nomesSet = new Set(nomes)
console.log(nomesSet)